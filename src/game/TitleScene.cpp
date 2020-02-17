#include "TitleScene.hpp"
#include <ofGraphics.h>
#include <ofMatrixStack.h>

TitleScene::TitleScene() : canvas(), titleLabel(), newWorldImage(), openWorldImage()  {
	this->nextScene = "Play";
}

void TitleScene::mousePressed(int x, int y, int button) {
	if (button != 0) {
		return;
	}
	newWorldImage->mousePressed(x, y, button);
	openWorldImage->mousePressed(x, y, button);
}

void TitleScene::keyPressed(int key) {
}

void TitleScene::keyReleased(int key) {
}

void TitleScene::onInit() {
	int w = 1280;
	int h = 720;
	ofEnableAlphaBlending();
	this->newWorldImage = canvas.addComponent<ofxGameUI::Button>();
	this->openWorldImage = canvas.addComponent<ofxGameUI::Button>();
	newWorldImage->text = u8"ワールドを作成";
	openWorldImage->text = u8"ワールドを開く";
	canvas.load();
	newWorldImage->center(w, h);
	newWorldImage->position += glm::vec3(0, 150, 0);
	newWorldImage->callback = std::bind(&TitleScene::on_create, this);
	openWorldImage->center(w, h);
	openWorldImage->position += glm::vec3(0, 250, 0);
	openWorldImage->callback = std::bind(&TitleScene::on_open, this);
}

void TitleScene::onShow() {
}

void TitleScene::onUpdate() {
}

void TitleScene::onDraw() {
	ofEnableAlphaBlending();
	canvas.draw();
}

void TitleScene::on_create() {
	this->transition("Create");
}

void TitleScene::on_open() {
	this->transition("Open");
}
