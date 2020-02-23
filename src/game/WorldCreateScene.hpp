#pragma once
#ifndef GAME_NEWWORLDSCENE_HPP
#define GAME_NEWWORLDSCENE_HPP
#include "../scene/BaseScene.hpp"
#include <ofxGameUI.h>

class WorldCreateScene : public BaseScene {
public:
	explicit WorldCreateScene();
	void mousePressed(int x, int y, int button) override;
	void keyPressed(int key) override;
	void keyReleased(int key)override;

	std::string getWorldName() const;
	std::string getBiome() const;
	std::string getSize() const;
protected:
	void onInit() override;
	void onShow() override;
	void onUpdate() override;
	void onDraw() override;
	void on_generate();
	void on_back();
private:
	ofxGameUI::Canvas canvas;
	std::shared_ptr<ofxGameUI::Label> biomeLabel;
	std::shared_ptr<ofxGameUI::Label> worldNameLabel;
	std::shared_ptr<ofxGameUI::Label> sizeLabel;
	std::shared_ptr<ofxGameUI::InputField> worldNameInputField;
	std::shared_ptr<ofxGameUI::Dropdown> biomeDropdown;
	std::shared_ptr<ofxGameUI::Dropdown> sizeDropdown;
	std::shared_ptr<ofxGameUI::Button> createButton;
	std::shared_ptr<ofxGameUI::Button> backButton;
};
#endif