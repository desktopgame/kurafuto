#pragma once
#ifndef GAME_WORLDOPENSCENE_HPP
#define GAME_WORLDOPENSCENE_HPP
#include "../scene/BaseScene.hpp"
#include <ofxGameUI.h>
#include <vector>
#include <ofFileUtils.h>

class WorldOpenScene : public BaseScene {
public:
	explicit WorldOpenScene();
	void mousePressed(int x, int y, int button) override;
	void keyPressed(int key) override;
	void keyReleased(int key)override;

	void reset();
	bool isOpened() const;
	ofFile getOpenFile() const;
protected:
	void onInit() override;
	void onDraw() override;
	void on_open();
	void on_back();
private:
	bool opened;
	ofxGameUI::Canvas canvas;
	std::shared_ptr<ofxGameUI::Dropdown> worldDropdown;
	std::shared_ptr<ofxGameUI::Button> openButton;
	std::shared_ptr<ofxGameUI::Button> backButton;
	std::vector<ofFile> fileVec;
};
#endif