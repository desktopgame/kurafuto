#pragma once

#include <ofBaseApp.h>
#include <ofxPlanet.h>
#include <ofShader.h>
#include <vector>
#include "common/Camera.hpp"
#include "scene/SceneManager.hpp"

class ofApp : public ofBaseApp{

	public:
		explicit ofApp();
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

#ifdef _DEBUG
		static void bridgeDebugMessage(GLenum source, GLenum type, GLuint eid,
			GLenum severity, GLsizei length,
			const GLchar* message,
			GLvoid* user_param);
#endif
	private:
		SceneManager sceneManager;
};
