#include "PlayScene.hpp"
#include <ofAppRunner.h>
#include <ofEvents.h>
#include <ofGraphics.h>
#include <ofBaseApp.h>
#include <ofAppGLFWWindow.h>
#include <iostream>
#include <glm/glm.hpp>
#include <ofFileUtils.h>
#include <ofxPlanet.h>
#include <ofUtils.h>
#include "../common/glfw.hpp"
#include "../biome/PlainBiome.hpp"
#include "../biome/StairsBiome.hpp"
#include "../biome/HillBiome.hpp"
#include "WorldCreateScene.hpp"
#include "WorldOpenScene.hpp"
#include "Shaders.hpp"
#include "Structs.hpp"

PlayScene::PlayScene(std::weak_ptr<WorldCreateScene> createSceneRef, std::weak_ptr<WorldOpenScene> openSceneRef) :
	createSceneRef(createSceneRef),
	openSceneRef(openSceneRef), 
	planet(nullptr),
	biomeMap(),
	fileName(),
	size(),
	shader(),
	camera(), 
	playUI(),
	pauseUI(),
	fpsCon(), playMode(false), playSceneNow(false), playerHand(){
	fpsCon.setRotateSpeed(1.0f);
	fpsCon.setMoveSpeed(1.0f);
	fpsCon.setMode(planet::FirstPersonController::Mode::Key);
	ofAddListener(ofGetWindowPtr()->events().keyPressed, this,
		&PlayScene::keycodePressed);
}

void PlayScene::mousePressed(int x, int y, int button) {
	if (playMode) {
		playerHand->doPutBlock(pauseUI.getPutBlockId());
		playerHand->doDestroyBlock();
		return;
	}
	pauseUI.mousePressed(x, y, button);
}

void PlayScene::keyPressed(int key) {
}

// protected
void PlayScene::onInit() {
	// ブロック定義ファイルの読み込み
	auto texBuf = ofBufferFromFile("textures.json");
	auto blockBuf = ofBufferFromFile("blocks.json");
	ofxPlanet::TextureInfoCollection tic;
	tic.deserialize(std::string(texBuf.getData()));
	ofxPlanet::BlockInfoCollection bic;
	bic.deserialize(std::string(blockBuf.getData()));
	ofxPlanet::BlockPack::load(bic)->select();
	ofxPlanet::TexturePack::load(tic)->select();
	ofxPlanet::TexturePack::getCurrent()->resolve();
	//UIの初期化
	pauseUI.onExport = std::bind(&PlayScene::on_export, this);
	pauseUI.onSave = std::bind(&PlayScene::on_save, this);
	pauseUI.onResume = std::bind(&PlayScene::on_resume, this);
	pauseUI.onBack = std::bind(&PlayScene::on_back, this);
	playUI.init();
	pauseUI.init();
	//シェーダー読み込み
	shader.setupShaderFromSource(GL_VERTEX_SHADER,Shaders::WORLD_VERTEX_SHADER);
	shader.setupShaderFromSource(GL_FRAGMENT_SHADER,Shaders::WORLD_FRAGMENT_SHADER);
	shader.bindDefaults();
	shader.linkProgram();
	this->planet = std::make_shared<ofxPlanet::Planet>(shader);
	biomeMap.insert_or_assign("Stairs/Tree", []() { return std::make_shared<StairsBiome>(Structs::TREE, 12); });
	biomeMap.insert_or_assign("Stairs/House", []() { return std::make_shared<StairsBiome>(Structs::HOUSE, 12); });
	biomeMap.insert_or_assign("Plain/Tree", []() { return std::make_shared<PlainBiome>(Structs::TREE, 12); });
	biomeMap.insert_or_assign("Plain/House", [] {return std::make_shared<PlainBiome>(Structs::HOUSE, 36); });
	biomeMap.insert_or_assign("Hill", []() {return std::make_shared<HillBiome>(); });
	this->playerHand = std::make_shared<PlayerHand>(planet, fpsCon, camera);
}

void PlayScene::onShow() {
	loadWorld();
	this->playMode = true;
	this->playSceneNow = true;
	fpsCon.setRotateSpeed(0.05f);
	fpsCon.setMode(planet::FirstPersonController::Mode::Mouse);
	fpsCon.enable();
	saveWorld();
}

void PlayScene::onHide() {
	fpsCon.setMode(planet::FirstPersonController::Mode::Key);
	fpsCon.disable();
	this->playSceneNow = false;
}

void PlayScene::onUpdate() {
	if (!this->playMode) {
		return;
	}
	// カメラを更新
	auto w = planet->getWorld();
	const int wsx = w->getXSize();
	const int wsy = w->getYSize();
	const int wsz = w->getZSize();
	const int OF_KEY_SPACE = 32;
	// WASD, 矢印キーによる移動と回転
	fpsCon.update();
	camera.setPosition(camera.getPosition() + fpsCon.getVelocity());
	// 上昇, 下降
	if (ofGetKeyPressed(OF_KEY_SPACE)) {
		camera.setPosition(camera.getPosition() +
			glm::vec3(0, 0.8f, 0));
	}
	else if (planet::glfw::getKey(planet::glfw::Key_left_shift) ||
		planet::glfw::getKey(planet::glfw::Key_z)) {
		camera.setPosition(camera.getPosition() +
			glm::vec3(0, -0.8f, 0));
	}
	camera.setLookAt(camera.getPosition() +
		fpsCon.getTransform().forward());
	camera.rehash();
}

void PlayScene::onDraw() {
	// シェーダーを更新
	camera.rehash();
	shader.begin();
	shader.setUniform4f("uAmbient", glm::vec4(0.5f, 0.5f, 0.5f, 1.0f));
	shader.setUniform4f("uDiffuse", glm::vec4(0.5f, 0.5f, 0.5f, 1.0f));
	shader.setUniform4f("uSpecular", glm::vec4(0.f, 0.f, 0.f, 1.0f));
	shader.setUniform1f("uShininess", 50);
	shader.setUniformMatrix4f("uMVPMatrix", (camera.getProjectionMatrix() * camera.getViewMatrix()));
	shader.setUniformMatrix4f("uNormalMatrix", (camera.computeNormalMatrix(glm::mat4(1.0f))));
	shader.end();

	ofSetOrientation(OF_ORIENTATION_DEFAULT, false);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	planet->getWorld()->getChunk()->draw();

	playerHand->drawPutBlock();
	playerHand->drawDestroyBlock();
	
	ofSetColor(ofColor::white);
	if (playMode) {
		playUI.draw();
	} else {
		pauseUI.draw();
	}
}

void PlayScene::on_export() {
	ofxPlanet::WorldIO::saveObj(this->fileName, planet->getWorld());
	this->playMode = true;
}

void PlayScene::on_save() {
	saveWorld();
	this->playMode = true;
	fpsCon.setMode(planet::FirstPersonController::Mode::Mouse);
}

void PlayScene::on_resume() {
	this->playMode = true;
	fpsCon.setMode(planet::FirstPersonController::Mode::Mouse);
}

void PlayScene::on_back() {
	transition("Title");
}

// private
void PlayScene::keycodePressed(ofKeyEventArgs & e) {
	if (!playSceneNow) {
		return;
	}
	if (e.keycode == 'E') {
		if (fpsCon.getMode() == planet::FirstPersonController::Mode::Key) {
			fpsCon.setMode(planet::FirstPersonController::Mode::Mouse);
			this->playMode = true;
		}
		else {
			fpsCon.setMode(planet::FirstPersonController::Mode::Key);
			this->playMode = false;
		}
	}
}
void PlayScene::loadWorld() {
	auto createScene = this->createSceneRef.lock();
	auto openScene = this->openSceneRef.lock();
	if (openScene->isOpened()) {
		openScene->reset();
		// 読み込み
		ofxPlanet::BlockTable table(128, 64, 128);
		int lineIndex = 0;
		ofFile file = openScene->getOpenFile();
		std::ifstream ifs(file.getAbsolutePath());
		std::string line;
		while (std::getline(ifs, line)) {
			if (lineIndex == 0) {
				this->fileName = line;
			} else if (lineIndex == 1) {
				size.x = std::stoi(line);
			} else if (lineIndex == 2) {
				size.y = std::stoi(line);
			} else if (lineIndex == 3) {
				size.z = std::stoi(line);
				table = ofxPlanet::BlockTable(size.x, size.y, size.z);
			} else {
				auto columns = ofSplitString(line, " ");
				int x = std::stoi(columns.at(0));
				int y = std::stoi(columns.at(1));
				int z = std::stoi(columns.at(2));
				int id = std::stoi(columns.at(3));
				table.setBlock(x, y, z, ofxPlanet::BlockPrefab(id, false));
			}
			lineIndex++;
		}
		planet->allocate(size);
		planet->getWorld()->load(table);
		planet->getWorld()->getChunk()->split(32);
		ifs.close();
	} else {
		auto sizeStr = createScene->getSize();
		if (sizeStr == "Small") {
			this->size = glm::ivec3(64, 64, 64);
		}
		else if (sizeStr == "Medium") {
			this->size = glm::ivec3(128, 64, 128);
		}
		else if (sizeStr == "Big") {
			this->size = glm::ivec3(160, 64, 160);
		}
		planet->generate(size, biomeMap.at(createScene->getBiome())());
		planet->getWorld()->getChunk()->split(32);
		this->fileName = createScene->getWorldName();
	}
	camera.setScreenSize(glm::vec2(1280, 720));
	camera.setPosition(glm::vec3(size.x, size.y*2, size.z));
	auto& t = fpsCon.getTransform();
	t.rotation = glm::vec3(90, -90, 0);
}

void PlayScene::saveWorld() {
	auto createScene = this->createSceneRef.lock();
	auto w = planet->getWorld();
	ofDirectory playDir("play");
	if (!playDir.exists()) {
		playDir.create();
	}
	std::ofstream ofs(ofFilePath::join("./data/play/", fileName + ".dat"));
	ofs << fileName << std::endl;
	ofs << size.x << std::endl;
	ofs << size.y << std::endl;
	ofs << size.z << std::endl;
	for (int x = 0; x < w->getXSize(); x++) {
		for (int y = 0; y < w->getYSize(); y++) {
			for (int z = 0; z < w->getZSize(); z++) {
				auto block = w->getBlock(x, y, z);
				if (block == nullptr) continue;
				ofs << x << " " << y << " " << z << " " << block->getID() << std::endl;
			}
		}
	}
	ofs.close();
}

BlockImage::BlockImage() : image(), id(0) {
}
