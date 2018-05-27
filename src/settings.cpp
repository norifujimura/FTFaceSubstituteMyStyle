//
//  settings.cpp
//  faceOSC02
//
//  Created by Noriyuki Fujimura on 8/14/16.
//
//

#include "settings.h"

void settings::load(){
    ofXml xml;
    if(!xml.load("settings.xml")) {
        return;
    }
    
    //xml.setToParent();
    xml.setTo("source");
    if(xml.exists("useCamera")) {
        bUseCamera = xml.getValue("useCamera",false);
    }

    xml.setToParent();
    
    xml.setTo("movie");
    if(xml.exists("filename")) {
        movFilename = ofToDataPath((string)xml.getValue("filename", ""));
    }else {
        ofLog(OF_LOG_ERROR, "Movie filename tag not set in settings, reverting to camera input");
        bUseCamera = true;
    }
    if(xml.exists("volume")) {
        float movVolume = ofClamp(xml.getValue("volume", 1.0), 0, 1.0);
        //movie.setVolume(movieVolume);
    }
    if(xml.exists("speed")) {
        float movSpeed = ofClamp(xml.getValue("speed", 1.0), -16, 16);
        //movie.setSpeed(movieSpeed);
    }
    bMovPaused = false;
    //movieWidth = movie.getWidth();
    //movieHeight = movie.getHeight();
    xml.setToParent();
    
    
    xml.setTo("camera");
    
    if(xml.exists("webCam")) {
        bUseWebcam= xml.getValue("webCam",false);
        if(bUseWebcam){
            camDeviceID=1;
        }
    }
    if(xml.exists("faceTime")) {
        bUseFaceTime = xml.getValue("faceTime",true);
        if(bUseFaceTime ){
            camDeviceID=0;
        }
    }
    if(xml.exists("kinect")) {
        bUseKinect=(xml.getValue("kinect", false));
    }
    if(xml.exists("kinectIR")) {
        bUseKinectIr=(xml.getValue("kinectIR", false));
    }
    if(xml.exists("framerate")) {
        camFrameRate=(xml.getValue("framerate", 30));
    }
    
    camWidth = xml.getValue("width", 640);
    camHeight = xml.getValue("height", 480);

    xml.setToParent();

    xml.setTo("screen");
    if(xml.exists("width")) {
        screenWidth=(xml.getValue("width", 1280));
    }
    if(xml.exists("height")) {
        screenHeight=(xml.getValue("height", 720));
    }
    if(xml.exists("frameRate")) {
        screenFrameRate=(xml.getValue("frameRate", 20));
    }
    if(xml.exists("sizeToCmRatio")) {
        screenSizeToCMRatio=(xml.getValue("sizeToCmRatio", 0.33));
    }
    
    camScreenRatio=screenWidth/camWidth;
    
    /*
    if(bUseCamera) {
        ofSetWindowShape(camWidth, camHeight);
        setVideoSource(true);
    }
    else {
        ofSetWindowShape(movieWidth, movieHeight);
        setVideoSource(false);
    }*/
    
    xml.setToParent();
    
    xml.setTo("face");
    if(xml.exists("rescale")) {
        trackerRescale=(xml.getValue("rescale", 1.0));
    }
    if(xml.exists("iterations")) {
        trackerIterations=(xml.getValue("iterations", 5));
    }
    if(xml.exists("clamp")) {
        trackerClamp=(xml.getValue("clamp", 3.0));
    }
    if(xml.exists("tolerance")) {
        trackerTolerance=(xml.getValue("tolerance", 0.01));
    }
    if(xml.exists("attempts")) {
        trackerAttempts=(xml.getValue("attempts", 1));
    }
    
    //Nori. not sure meaning of range of the float,though
    if(xml.exists("haarminsize")) {
        trackerHaarMinSize=(xml.getValue("haarminsize", 0.1));
    }
    
    bDrawMesh = true;
    if(xml.exists("drawMesh")) {
        bDrawMesh = (bool) xml.getValue("drawMesh", 1);
    }
    
    
    xml.setToParent();
    
    xml.setTo("osc");
    host = xml.getValue("host", "localhost");
    port = xml.getValue("port", 8338);
    xml.setToParent();
    
    xml.clear();
}
