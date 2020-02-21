#pragma once
#ifndef GAME_GAMEPAUSEUI_HPP
#define GAME_GAMEPAUSEUI_HPP
#include <ofxGameUI.h>
#include <functional>

struct BlockImage {
	explicit BlockImage();
	std::shared_ptr<ofxGameUI::Image> image;
	int id;
};

class GamePauseUI {
public:
	explicit GamePauseUI();
	void init();
	void draw();
	void mousePressed(int x, int y, int button);

	int getPutBlockId() const;

	std::function<void()> onSave;
	std::function<void()> onResume;
	std::function<void()> onBack;
private:
	ofxGameUI::Canvas canvas;
	std::shared_ptr<ofxGameUI::Button> saveButton;
	std::shared_ptr<ofxGameUI::Button> backButton;
	std::shared_ptr<ofxGameUI::Button> resumeButton;
	std::shared_ptr<ofxGameUI::Image> invBackImage;
	std::shared_ptr<ofxGameUI::Image> cellImage;
	std::vector<BlockImage> blockImages;
	int putBlockId;
};
#endif