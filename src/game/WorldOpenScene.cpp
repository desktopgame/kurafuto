#include "WorldOpenScene.hpp"

WorldOpenScene::WorldOpenScene() : canvas(), worldDropdown(), openButton(), fileVec(), opened(false) {
}

void WorldOpenScene::mousePressed(int x, int y, int button) {
	worldDropdown->mousePressed(x, y, button);
	openButton->mousePressed(x, y, button);
	backButton->mousePressed(x, y, button);
}

void WorldOpenScene::keyPressed(int key) {
}

void WorldOpenScene::keyReleased(int key) {
}

void WorldOpenScene::reset() {
	this->opened = false;
}

bool WorldOpenScene::isOpened() const {
	return opened;
}

ofFile WorldOpenScene::getOpenFile() const {
	return fileVec.at(worldDropdown->selectedIndex);
}

void WorldOpenScene::onInit() {
	fileVec.clear();
	//ディレクトリを読み込む
	ofDirectory playDir("play");
	if (!playDir.exists()) {
		playDir.create();
	}
	playDir.allowExt("dat");
	int files = playDir.listDir();
	this->worldDropdown = canvas.addComponent<ofxGameUI::Dropdown>();
	worldDropdown->fontSize = 40;
	for (int i = 0; i < files; i++) {
		auto file = playDir.getFile(i);
		fileVec.emplace_back(file);
		worldDropdown->items.push_back(file.getFileName());
	}
	this->openButton = canvas.addComponent<ofxGameUI::Button>();
	openButton->text = u8"開く";
	this->backButton = canvas.addComponent<ofxGameUI::Button>();
	backButton->text = u8"戻る";
	canvas.load();
	// GUIを作成
	glm::vec3 offset = glm::vec3(-120, 0, 0);
	worldDropdown->center(1280, 720);
	//開くボタン
	openButton->center(1280, 720);
	openButton->position.x += 380;
	//戻るボタン
	backButton->center(1280, 720);
	backButton->position.y += 200;
	worldDropdown->position += offset;
	openButton->position += offset;
	openButton->callback = std::bind(&WorldOpenScene::on_open, this);
	backButton->callback = std::bind(&WorldOpenScene::on_back, this);
}

void WorldOpenScene::onShow() {
	//ディレクトリを読み込む
	ofDirectory playDir("play");
	if (!playDir.exists()) {
		playDir.create();
	}
	playDir.allowExt("dat");
	int files = playDir.listDir();
	worldDropdown->unload();
	worldDropdown->uninstallCanvas(&canvas);
	worldDropdown->items.clear();
	for (int i = 0; i < files; i++) {
		auto file = playDir.getFile(i);
		fileVec.emplace_back(file);
		worldDropdown->items.push_back(file.getFileName());
	}
	worldDropdown->load();
	worldDropdown->installCanvas(&canvas);
}

void WorldOpenScene::onDraw() {
	canvas.draw();
}
// private
void WorldOpenScene::on_open() {
	this->opened = true;
	transition("Play");
}

void WorldOpenScene::on_back() {
	transition("Title");
}
