//
//  ShiseidoLifeClock.h
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/10/12.
//
//

#ifndef __ofxAnimationUtility__ShiseidoLifeClock__
#define __ofxAnimationUtility__ShiseidoLifeClock__

#include "ofMain.h"

class ShiseidoLifeClock{
public:
    void draw();
    void init();
    void update();
private:
    ofPath path;
    int mode = 0;
    vector<ofVec2f> vec;
    
    void draw_default_circle();
    
    void draw_bezier_map();
};

#endif /* defined(__ofxAnimationUtility__ShiseidoLifeClock__) */
