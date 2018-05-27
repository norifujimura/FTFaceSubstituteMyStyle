#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxCv.h"
#include "FaceOsc.h"
#include "ofxOpenCv.h"

class ofApp : public ofBaseApp, public FaceOsc {
public:
	void loadSettings();

	void setup();
	void update();
	void draw();
	void keyPressed(int key);

	void setVideoSource(bool useCamera);
    
    ofRectangle getScreenRectangle(float FOV,int width,int height,float depth);
    ofRectangle camRect;
    
	bool bUseCamera, bPaused;

	int camWidth, camHeight;
	int movieWidth, movieHeight;
	int sourceWidth, sourceHeight;

	ofVideoGrabber cam;
	ofVideoPlayer movie;
	ofBaseVideoDraws *videoSource;
    
    ofImage camImage;
    ofxCvColorImage camCvImage;
    
	ofxFaceTracker tracker;
	ofMatrix4x4 rotationMatrix;
	
	bool bDrawMesh;
    
    ofxPanel gui;
    bool bGuiVisible;
    
    ofImage ofLogo; // the OF logo
    
    //Cams
    ofEasyCam myEasyCam;
};
