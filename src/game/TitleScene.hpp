#pragma once
#ifndef GAME_TITLESCENE_HPP
#define GAME_TITLESCENE_HPP
#include "../scene/BaseScene.hpp"
#include <ofxGameUI.h>
#include <ofCamera.h>

class TitleScene : public BaseScene {
public:
	TitleScene();
	void mousePressed(int x, int y, int button) override;
	void keyPressed(int key) override;
	void keyReleased(int key)override;
protected:
	void onInit() override;
	void onShow() override;
	void onUpdate() override;
	void onDraw() override;
	void on_create();
	void on_open();
private:
	ofxGameUI::Canvas canvas;
	std::shared_ptr<ofxGameUI::Label> titleLabel;
	std::shared_ptr<ofxGameUI::Button> newWorldImage;
	std::shared_ptr<ofxGameUI::Button> openWorldImage;
};
#endif