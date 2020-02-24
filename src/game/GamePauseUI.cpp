#include "GamePauseUI.hpp"
#include <ofxPlanet.h>

GamePauseUI::GamePauseUI() : 
	canvas(), 
	exportButton(),
	saveButton(),
	backButton(), 
	invBackImage(),
	cellImage() ,
	blockImages(),
	putBlockId(5),
	onSave(),
	onResume(),
	onBack() {
}

void GamePauseUI::init() {
	this->exportButton = canvas.addComponent<ofxGameUI::Button>();
	exportButton->text = u8"出力";
	this->saveButton = canvas.addComponent<ofxGameUI::Button>();
	saveButton->text = u8"保存";
	this->resumeButton = canvas.addComponent<ofxGameUI::Button>();
	resumeButton->text = u8"再開";
	this->backButton = canvas.addComponent<ofxGameUI::Button>();
	backButton->text = u8"戻る";
	this->invBackImage = canvas.addComponent<ofxGameUI::Image>();
	invBackImage->icon = "static/inv.png";
	//ブロック一覧を保存する
	glm::vec3 offset = glm::vec3(1280 - 600, 720 - 450, 0) / 2;
	glm::vec3 cellPos(0,0,0);
	offset.x += 10;
	offset.y += 10;
	auto bp = ofxPlanet::BlockPack::getCurrent();
	for (int i = 0; i < bp->getBlockCount(); i++) {
		int row = i / 10;
		int col = i % 10;
		auto block = bp->getBlock(i);
		auto path = block->getTextureSet().getTopImage()->getPath();
		auto comp = path.substr(0, 5);
		if (comp == "data\\" || comp == "data/") {
			path = path.substr(5);
		}
		BlockImage blockImg;
		blockImg.image = canvas.addComponent<ofxGameUI::Image>();
		blockImg.image->icon = path;
		blockImg.image->forceOverwriteSize = true;
		blockImg.id = block->getID();
		blockImg.image->position = glm::vec3(offset.x + (col * 48), offset.y + (row * 48), 0);
		blockImg.image->size = glm::vec2(48, 48);
		blockImages.emplace_back(blockImg);
		if (block->getID() == this->putBlockId) {
			cellPos = blockImg.image->position;
		}
	}
	this->cellImage = canvas.addComponent<ofxGameUI::Image>();
	cellImage->icon = "static/cell.png";
	cellImage->position = cellPos;
	canvas.load();
	// レイアウト
	exportButton->right(1280);
	saveButton->right(1280);
	resumeButton->right(1280);
	backButton->right(1280);
	invBackImage->center(1280, 720);
	//ボタンを並べる
	exportButton->position.y = 720 - saveButton->getSize().y - backButton->getSize().y - resumeButton->getSize().y - saveButton->getSize().y - 15;
	saveButton->position.y = 720 - saveButton->getSize().y - backButton->getSize().y - resumeButton->getSize().y - 10;
	resumeButton->position.y = 720 - resumeButton->getSize().y - backButton->getSize().y - 5;
	backButton->position.y = 720 - backButton->getSize().y;
	exportButton->callback = onExport;
	saveButton->callback = onSave;
	resumeButton->callback = onResume;
	backButton->callback = onBack;
}

void GamePauseUI::draw() {
	canvas.draw();
}

void GamePauseUI::mousePressed(int x, int y, int button) {
	canvas.mousePressed(x, y, button);
	//ブロック選択処理
	glm::vec3 offset = glm::vec3(1280 - 600, 720 - 450, 0) / 2;
	offset.x += 10;
	offset.y += 10;
	for (int i = 0; i < static_cast<int>(blockImages.size()); i++) {
		auto blockImg = blockImages.at(i);
		bool hit = blockImg.image->isContains(x, y);
		if (hit) {
			this->putBlockId = blockImg.id;
			this->cellImage->position = blockImg.image->position;
			break;
		}
	}
}

int GamePauseUI::getPutBlockId() const {
	return putBlockId;
}
