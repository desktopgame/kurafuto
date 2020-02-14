#include "ofMain.h"
#include "ofApp.h"
#ifndef _DEBUG
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
#endif

//========================================================================
int main( ){
	ofGLFWWindowSettings settings;
	settings.glVersionMajor = 4;
	settings.glVersionMinor = 1;
	settings.setSize(1280, 720);
//	settings.resizable = false;
	settings.windowMode = ofWindowMode::OF_WINDOW;
	settings.title = "cube";
#ifdef _DEBUG
	ofSetLogLevel(ofLogLevel::OF_LOG_VERBOSE);
#endif
	ofCreateWindow(settings);
	ofRunApp(new ofApp());

}
