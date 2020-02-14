#include "SceneManager.hpp"
#include "IScene.hpp"

SceneManager::SceneManager() : currentScene(), map() {
}

void SceneManager::add(const std::string & name, const std::shared_ptr<IScene>& scene) {
	this->currentScene = name;
	map.insert_or_assign(name, scene);
}

void SceneManager::bind(const std::string & name) {
	this->currentScene = name;
	map[currentScene]->show();
}

void SceneManager::update() {
	if (!map.count(currentScene)) {
		return;
	}
	auto scene = map[currentScene];
	scene->update();
	if (scene->isFinish()) {
		scene->hide();
		this->currentScene = scene->getNextScene();
		map[currentScene]->show();
	}
}

void SceneManager::draw() {
	if (!map.count(currentScene)) {
		return;
	}
	auto scene = map[currentScene];
	scene->draw();
}


void SceneManager::keyPressed(int key) {
	if (!map.count(currentScene)) {
		return;
	}
	auto scene = map[currentScene];
	scene->keyPressed(key);
}

void SceneManager::keyReleased(int key) {
	if (!map.count(currentScene)) {
		return;
	}
	auto scene = map[currentScene];
	scene->keyReleased(key);
}

void SceneManager::mouseMoved(int x, int y) {
	if (!map.count(currentScene)) {
		return;
	}
	auto scene = map[currentScene];
	scene->mouseMoved(x, y);
}

void SceneManager::mouseDragged(int x, int y, int button) {
	if (!map.count(currentScene)) {
		return;
	}
	auto scene = map[currentScene];
	scene->mouseDragged(x, y, button);
}

void SceneManager::mousePressed(int x, int y, int button) {
	if (!map.count(currentScene)) {
		return;
	}
	auto scene = map[currentScene];
	scene->mousePressed(x, y, button);
}

void SceneManager::mouseReleased(int x, int y, int button) {
	if (!map.count(currentScene)) {
		return;
	}
	auto scene = map[currentScene];
	scene->mouseReleased(x, y, button);
}

void SceneManager::mouseEntered(int x, int y) {
	if (!map.count(currentScene)) {
		return;
	}
	auto scene = map[currentScene];
	scene->mouseEntered(x, y);
}

void SceneManager::mouseExited(int x, int y) {
	if (!map.count(currentScene)) {
		return;
	}
	auto scene = map[currentScene];
	scene->mouseExited(x, y);
}

void SceneManager::windowResized(int w, int h) {
	if (!map.count(currentScene)) {
		return;
	}
	auto scene = map[currentScene];
	scene->windowResized(w, h);
}

void SceneManager::dragEvent(ofDragInfo dragInfo) {
	if (!map.count(currentScene)) {
		return;
	}
	auto scene = map[currentScene];
	scene->dragEvent(dragInfo);
}

void SceneManager::gotMessage(ofMessage msg) {
	if (!map.count(currentScene)) {
		return;
	}
	auto scene = map[currentScene];
	scene->gotMessage(msg);
}
