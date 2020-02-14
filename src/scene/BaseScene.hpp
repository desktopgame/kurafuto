#pragma once
#ifndef SCENE_BASESCENE_HPP
#define SCENE_BASESCENE_HPP
#include "IScene.hpp"


class BaseScene : public IScene {
public:
	BaseScene();
	virtual ~BaseScene();

	void show() override;
	void hide() override;
	void update() override;
	void draw() override;
	bool isFinish()  override;
	std::string getNextScene() override;


	void keyPressed(int key) override;
	void keyReleased(int key) override;
	void mouseMoved(int x, int y) override;
	void mouseDragged(int x, int y, int button) override;
	void mousePressed(int x, int y, int button) override;
	void mouseReleased(int x, int y, int button) override;
	void mouseEntered(int x, int y) override;
	void mouseExited(int x, int y) override;
	void windowResized(int w, int h) override;
	void dragEvent(ofDragInfo dragInfo) override;
	void gotMessage(ofMessage msg) override;
protected:
	virtual void onInit();
	virtual void onShow();
	virtual void onHide();
	virtual void onUpdate();
	virtual void onDraw();
	void transition(const std::string& nextScene);
	bool isFinished;
	std::string nextScene;
private:
	bool isInitialized;
};
#endif