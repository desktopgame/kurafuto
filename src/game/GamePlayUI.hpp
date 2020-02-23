#pragma once
#ifndef GAME_GAMEPLAYUI_HPP
#define GAME_GAMEPLAYUI_HPP
#include <ofxGameUI.h>

class GamePlayUI {
public:
	explicit GamePlayUI();
	void init();
	void draw();
private:
	ofxGameUI::Canvas playCanvas;
	std::shared_ptr<ofxGameUI::Image> crosshairImage;
};
#endif