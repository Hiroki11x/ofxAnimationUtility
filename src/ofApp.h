#pragma once

#include "ofMain.h"

#include "AlphaSwiper.h"
#include "FadeBackgroundUtil.h"
#include "DelaunayUtil.h"
#include "PathManager.h"
#include "LineBelt.h"
#include "CircularAnimationManager.h"
#include "CircularVertexes.h"
#include "FadeMotionGraphics.h"
#include "RectSwiper.h"
#include "StrechyRectSwiper.h"
#include "ofxSuperLogUtil.h"
#include "GraphLog.h"
#include "PostGlitch.h"
#include "JsonScene.h"

#include "ExplodeAnimation.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofxSuperLogUtil logutil;
    GraphLog graphLog;
    PostGlitch postglitch;
    ofFbo mFbo;
    int mode;
    
    //0
    AlphaSwiper alphaswiper;
  
    //1
    FadeBackgroundUtil animation;
    
    //2
    DelaunayUtil delaunay;
    
    //3
    PathManager pathmanager;
    
    //4
    LineBelt linebelt;
    
    //5
    CircularAnimationManager circularannimationmanager;
    
    //6
    CircularVertexes circularvertexes;
    ExplodeAnimation explodeanimation;
    
    //7
    FadeMotionGraphics fademotiongraphics;
    
    //8
    RectSwiper rectswiper;
    
    //9
    StrechyRectSwiper strechyrectswiper;
    JsonScene jsonscene;
};
