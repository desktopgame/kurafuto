#include "BaseScene.hpp"

BaseScene::BaseScene() : nextScene(), isFinished(false), isInitialized(false) {
}

BaseScene::~BaseScene() {
}

void BaseScene::show() {
	if (!this->isInitialized) {
		onInit();
		this->isInitialized = true;
	}
	this->isFinished = false;
	onShow();
}

void BaseScene::hide() {
	this->isFinished = false;
	onHide();
}

void BaseScene::update() {
	onUpdate();
}

void BaseScene::draw() {
	onDraw();
}

bool BaseScene::isFinish() {
	return this->isFinished;
}

std::string BaseScene::getNextScene() {
	return this->nextScene;
}

void BaseScene::keyPressed(int key) {
}

void BaseScene::keyReleased(int key) {
}

void BaseScene::mouseMoved(int x, int y) {
}

void BaseScene::mouseDragged(int x, int y, int button) {
}

void BaseScene::mousePressed(int x, int y, int button) {
}

void BaseScene::mouseReleased(int x, int y, int button) {
}

void BaseScene::mouseEntered(int x, int y) {
}

void BaseScene::mouseExited(int x, int y) {
}

void BaseScene::windowResized(int w, int h) {
}

void BaseScene::dragEvent(ofDragInfo dragInfo) {
}

void BaseScene::gotMessage(ofMessage msg) {
}

// protected
void BaseScene::onInit() {
}

void BaseScene::onShow() {
}

void BaseScene::onHide() {
}

void BaseScene::onUpdate() {
}

void BaseScene::onDraw() {
}

void BaseScene::transition(const std::string & nextScene) {
	this->isFinished = true;
	this->nextScene = nextScene;
}
