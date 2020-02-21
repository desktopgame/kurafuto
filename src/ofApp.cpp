
#include "ofApp.h"
#include "ofxPlanet.h"
#include "biome/StairsBiome.hpp"
#include "game/TitleScene.hpp"
#include "game/PlayScene.hpp"
#include "game/WorldCreateScene.hpp"
#include "game/WorldOpenScene.hpp"
#include <ofTrueTypeFont.h>


ofApp::ofApp()
	: sceneManager() {
}

//--------------------------------------------------------------
void ofApp::setup() {
	ofTrueTypeFont::setGlobalDpi(72);
#if _DEBUG
	glDebugMessageCallback(
		reinterpret_cast<GLDEBUGPROC>(ofApp::bridgeDebugMessage), NULL);
	glEnable(GL_DEBUG_OUTPUT);
#endif
	auto createScene = std::make_shared<WorldCreateScene>();
	auto openScene = std::make_shared<WorldOpenScene>();
	sceneManager.add("Title", std::make_shared<TitleScene>());
	sceneManager.add("Play", std::make_shared<PlayScene>(createScene, openScene));
	sceneManager.add("Create", createScene);
	sceneManager.add("Open", openScene);
	sceneManager.bind("Title");
}

//--------------------------------------------------------------
void ofApp::update() {
	if (ofGetKeyPressed(ofKey::OF_KEY_ESC) && ofGetKeyPressed(ofKey::OF_KEY_SHIFT)) {
		std::exit(0);
	}
	sceneManager.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
	sceneManager.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	sceneManager.keyPressed(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
	sceneManager.keyReleased(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
	sceneManager.mouseMoved(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
	sceneManager.mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	sceneManager.mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
	sceneManager.mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {
	sceneManager.mouseEntered(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {
	sceneManager.mouseExited(x, y);
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
	sceneManager.windowResized(w, h);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {
	sceneManager.gotMessage(msg);
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {
	sceneManager.dragEvent(dragInfo);
}
#ifdef _DEBUG
void ofApp::bridgeDebugMessage(GLenum source, GLenum type, GLuint eid,
	GLenum severity, GLsizei length,
	const GLchar* message, GLvoid* user_param) {
	// https://gist.github.com/liam-middlebrook/c52b069e4be2d87a6d2f
	const char* _source;
	const char* _type;
	const char* _severity;
	if (eid == 131218) {
		return;
	}
	switch (source) {
	case GL_DEBUG_SOURCE_API:
		_source = "API";
		break;

	case GL_DEBUG_SOURCE_WINDOW_SYSTEM:
		_source = "WINDOW SYSTEM";
		break;

	case GL_DEBUG_SOURCE_SHADER_COMPILER:
		_source = "SHADER COMPILER";
		break;

	case GL_DEBUG_SOURCE_THIRD_PARTY:
		_source = "THIRD PARTY";
		break;

	case GL_DEBUG_SOURCE_APPLICATION:
		_source = "APPLICATION";
		break;

	case GL_DEBUG_SOURCE_OTHER:
		_source = "UNKNOWN";
		break;

	default:
		_source = "UNKNOWN";
		break;
	}

	switch (type) {
	case GL_DEBUG_TYPE_ERROR:
		_type = "ERROR";
		break;

	case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
		_type = "DEPRECATED BEHAVIOR";
		break;

	case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
		_type = "UDEFINED BEHAVIOR";
		break;

	case GL_DEBUG_TYPE_PORTABILITY:
		_type = "PORTABILITY";
		break;

	case GL_DEBUG_TYPE_PERFORMANCE:
		_type = "PERFORMANCE";
		break;

	case GL_DEBUG_TYPE_OTHER:
		_type = "OTHER";
		break;

	case GL_DEBUG_TYPE_MARKER:
		_type = "MARKER";
		break;

	default:
		_type = "UNKNOWN";
		break;
	}

	switch (severity) {
	case GL_DEBUG_SEVERITY_HIGH:
		_severity = "HIGH";
		break;

	case GL_DEBUG_SEVERITY_MEDIUM:
		_severity = "MEDIUM";
		break;

	case GL_DEBUG_SEVERITY_LOW:
		_severity = "LOW";
		break;

	case GL_DEBUG_SEVERITY_NOTIFICATION:
		_severity = "NOTIFICATION";
		break;

	default:
		_severity = "UNKNOWN";
		break;
	}
	bool outputDebugMessage = true;
	if (outputDebugMessage) {
		std::stringstream ss;
		ss << "source(" << _source << ") ";
		ss << "type(" << _type << ") ";
		ss << "eid(" << eid << ") ";
		ss << "severity(" << _severity << ") ";
		ss << "length(" << length << ") ";
		ss << "message(" << message << ")";
		std::cout << ss.str() << std::endl;
	}
}

#endif