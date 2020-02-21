#pragma once
#ifndef SCENE_ISCENE_HPP
#define SCENE_ISCENE_HPP
#include <string>
#include <ofEvent.h>
#include <ofEvents.h>

class IScene {
public:
	IScene() = default;
	~IScene() {}

	virtual void show() = 0;
	virtual void hide() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual bool isFinish() = 0;
	virtual std::string getNextScene() = 0;


	virtual void keyPressed(int key) = 0;
	virtual void keyReleased(int key) = 0;
	virtual void mouseMoved(int x, int y) = 0;
	virtual void mouseDragged(int x, int y, int button) = 0;
	virtual void mousePressed(int x, int y, int button) = 0;
	virtual void mouseReleased(int x, int y, int button) = 0;
	virtual void mouseEntered(int x, int y) = 0;
	virtual void mouseExited(int x, int y) = 0;
	virtual void windowResized(int w, int h) = 0;
	virtual void dragEvent(ofDragInfo dragInfo) = 0;
	virtual void gotMessage(ofMessage msg) = 0;
private:
};
#endif // !SCENE_ISCENE_HPP
