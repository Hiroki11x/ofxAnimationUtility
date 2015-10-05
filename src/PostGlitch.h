//
//  PostGlitch.h
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/10/05.
//
//

#ifndef __ofxAnimationUtility__PostGlitch__
#define __ofxAnimationUtility__PostGlitch__

#include "ofMain.h"
#include "ofxPostGlitch.h"

class PostGlitch{
private:
    ofFbo *mFbo;
    ofxPostGlitch mGlitch;
    int shaderIndex;
    bool shaderSwitch;
public:
    void init(ofFbo &argFbo);
    void adapt_glitch_begin();
    void adapt_glitch_end();
    void draw_glitch();
    void keyPressed(int key);
};

#endif /* defined(__ofxAnimationUtility__PostGlitch__) */
