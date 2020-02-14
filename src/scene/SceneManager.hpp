#pragma once
#ifndef SCENE_SCENEMANAGER_HPP
#define SCENE_SCENEMANAGER_HPP
#include <memory>
#include <string>
#include <unordered_map>
#include <ofEvent.h>
#include <ofEvents.h>

class IScene;
class SceneManager {
public:
	explicit SceneManager();

	void add(const std::string& name, const std::shared_ptr<IScene>& scene);
	void bind(const std::string& name);

	void update();
	void draw();


	void keyPressed(int key) ;
	void keyReleased(int key) ;
	void mouseMoved(int x, int y) ;
	void mouseDragged(int x, int y, int button) ;
	void mousePressed(int x, int y, int button) ;
	void mouseReleased(int x, int y, int button) ;
	void mouseEntered(int x, int y) ;
	void mouseExited(int x, int y) ;
	void windowResized(int w, int h) ;
	void dragEvent(ofDragInfo dragInfo) ;
	void gotMessage(ofMessage msg) ;
private:
	std::string currentScene;
	std::unordered_map<std::string, std::shared_ptr<IScene> > map;
};
#endif