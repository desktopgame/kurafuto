#pragma once
#ifndef GAME_PLAYERHAND_HPP
#define GAME_PLAYERHAND_HPP
#include <glm/glm.hpp>
#include <of3dGraphics.h>
#include <ofxPlanet.h>
#include <memory>
#include "../common/FirstPersonController.hpp"
#include "../common/Camera.hpp"

class PlayerHand {
public:
	explicit PlayerHand(std::shared_ptr<ofxPlanet::Planet> planet, planet::FirstPersonController& fpsCon, Camera& camera);

	void drawPutBlock();
	void drawDestroyBlock();

	bool rayPutBlock();
	bool rayDestroyBlock();

	void doPutBlock(int blockId);
	void doDestroyBlock();

	glm::vec3 getPutAt() const;
	glm::vec3 getDestroyAt() const;
private:
	static void drawBlock(const Camera& camera, ofBoxPrimitive& box, ofColor color, glm::vec3 pos);

	std::shared_ptr<ofxPlanet::Planet> planet;
	planet::FirstPersonController& fpsCon;
	Camera& camera;

	glm::vec3 putAt;
	glm::vec3 destroyAt;
	ofBoxPrimitive putBox;
	ofBoxPrimitive destroyBox;
};
#endif