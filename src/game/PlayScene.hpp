#pragma once
#ifndef GAME_PLAYSCENE_HPP
#define GAME_PLAYSCENE_HPP
#include <ofxPlanet.h>
#include <ofShader.h>
#include <ofImage.h>
#include <of3dPrimitives.h>
#include <memory>
#include <unordered_map>
#include <vector>
#include <functional>
#include "../common/FirstPersonController.hpp"
#include "../common/Camera.hpp"
#include "../scene/BaseScene.hpp"
#include "../gui/Button.hpp"
#include "../gui/Image.hpp"
#include "../gui/Canvas.hpp"
#include "GamePlayUI.hpp"
#include "GamePauseUI.hpp"
#include "PlayerHand.hpp"
#include "Planet.hpp"

class WorldOpenScene;
class WorldCreateScene;

class PlayScene : public BaseScene {
public:
	using BiomeFactory = std::function<std::shared_ptr<ofxPlanet::Biome>()>;
	PlayScene(std::weak_ptr<WorldCreateScene> createSceneRef, std::weak_ptr<WorldOpenScene> openSceneRef);
	void mousePressed(int x, int y, int button) override;
	void keyPressed(int key) override;
protected:
	void onInit();
	void onShow();
	void onHide();
	void onUpdate();
	void onDraw();
	void on_export();
	void on_save();
	void on_resume();
	void on_back();
private:
	void keycodePressed(ofKeyEventArgs& e);
	void loadWorld();
	void saveWorld();
	std::weak_ptr<WorldCreateScene> createSceneRef;
	std::weak_ptr<WorldOpenScene> openSceneRef;
	std::string fileName;
	glm::ivec3 size;
	ofShader shader;
	Camera camera;
	planet::FirstPersonController fpsCon;
	bool playSceneNow;

	GamePlayUI playUI;
	GamePauseUI pauseUI;
	std::shared_ptr<PlayerHand> playerHand;

	std::shared_ptr<Planet> planet;
	std::unordered_map<std::string, BiomeFactory > biomeMap;
	bool playMode;
};
#endif