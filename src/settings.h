//
//  settings.hpp
//  faceOSC02
//
//  Created by Noriyuki Fujimura on 8/14/16.
//
//


#pragma once
#include "ofMain.h"

class settings{
public:
    settings(){}
    ~settings(){}
    void load();
    
    bool bUseCamera=false;
    string movFilename;
    float movVolume;
    float movSpeed;
    int movWidth;
    int movHeight;
    bool bMovPaused=false;
    
    bool bUseWebcam;
    bool bUseFaceTime;
    bool bUseKinect;
    bool bUseKinectIr;
    
    int camDeviceID;
    float camFrameRate;
    float camWidth;
    float camHeight;
    
    int screenWidth=1280;
    int screenHeight=720;
    int screenFrameRate=20;
    float camScreenRatio=1;
    float screenSizeToCMRatio=0.33;
    
    float trackerRescale;
    float trackerIterations;
    float trackerClamp;
    float trackerTolerance;
    float trackerAttempts;
    float trackerHaarMinSize;
    
    bool bDrawMesh=true;;
    bool bDrawBG=false;
    bool bYFlip=false;
    
    
    string host;
    int port;
    
};