#include "GamePlayUI.hpp"

GamePlayUI::GamePlayUI() : playCanvas(), crosshairImage() {
}

void GamePlayUI::init() {
	this->crosshairImage = playCanvas.addComponent<ofxGameUI::Image>();
	crosshairImage->icon = "static/crosshair.png";
	playCanvas.load();
	crosshairImage->center(1280, 720);
}

void GamePlayUI::draw() {
	playCanvas.draw();
}
