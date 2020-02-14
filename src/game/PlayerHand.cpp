#include "PlayerHand.hpp"
#include <ofGraphics.h>
#include <ofAppRunner.h>

PlayerHand::PlayerHand(std::shared_ptr<ofxPlanet::Planet> planet, planet::FirstPersonController& fpsCon, Camera& camera)
 : planet(planet), 
   fpsCon(fpsCon),
   camera(camera),
   putBox(),
   destroyBox(){
	putBox.set(2.0f);
	destroyBox.set(2.0f);
}

void PlayerHand::drawPutBlock() {
	if (rayPutBlock()) {
		drawBlock(camera, putBox, ofColor::white, putAt);
	}
}

void PlayerHand::drawDestroyBlock() {
	if (rayDestroyBlock()) {
		drawBlock(camera, destroyBox, ofColor::red, destroyAt);
	}
}

bool PlayerHand::rayPutBlock() {
	bool hit = false;
	auto w = planet->getWorld();
	planet::Transform& t = fpsCon.getTransform();
	glm::vec3 pos = camera.getPosition();
	glm::vec3 dir = t.forward();
	auto rayhit = w->raycast(pos, dir, 128.0f);
	if (rayhit.hit) {
		this->putAt = glm::vec3(rayhit.position) + rayhit.normal;
	}
	return rayhit.hit;
}

bool PlayerHand::rayDestroyBlock() {
	bool hit = false;
	auto w = planet->getWorld();
	planet::Transform& t = fpsCon.getTransform();
	glm::vec3 pos = camera.getPosition();
	glm::vec3 dir = t.forward();
	auto rayhit = w->raycast(pos, dir, 128.0f);
	if (rayhit.hit) {
		this->destroyAt = glm::vec3(rayhit.position);
	}
	return rayhit.hit;
}

void PlayerHand::doPutBlock(int blockId) {
	auto w = planet->getWorld();
	if (ofGetMousePressed(2) && rayPutBlock()) {
		w->setBlock(putAt, ofxPlanet::BlockPack::getCurrent()->getBlock(blockId));
	}
}

void PlayerHand::doDestroyBlock() {
	auto w = planet->getWorld();
	if (ofGetMousePressed(0) && rayDestroyBlock()) {
		w->setBlock(destroyAt, nullptr);
	}
}

glm::vec3 PlayerHand::getPutAt() const {
	return putAt;
}

glm::vec3 PlayerHand::getDestroyAt() const {
	return destroyAt;
}
// private
void PlayerHand::drawBlock(const Camera& camera, ofBoxPrimitive & box, ofColor color, glm::vec3 pos) {
	ofSetMatrixMode(ofMatrixMode::OF_MATRIX_PROJECTION);
	ofPushMatrix();
	ofLoadIdentityMatrix();
	ofLoadMatrix(camera.getProjectionMatrix());

	ofSetMatrixMode(ofMatrixMode::OF_MATRIX_MODELVIEW);
	ofPushMatrix();
	ofLoadIdentityMatrix();
	ofLoadMatrix(camera.getViewMatrix() * glm::translate(glm::mat4(1.0f), pos * 2.0f));

	ofSetColor(color);
	box.drawWireframe();

	ofSetMatrixMode(ofMatrixMode::OF_MATRIX_PROJECTION);
	ofPopMatrix();

	ofSetMatrixMode(ofMatrixMode::OF_MATRIX_MODELVIEW);
	ofPopMatrix();
}
