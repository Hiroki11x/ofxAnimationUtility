//
//  PostGlitch.cpp
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/10/05.
//
//

#include "PostGlitch.h"

void PostGlitch::init(ofFbo *argFbo){
    ofSetVerticalSync(true); //垂直同期（処理するフレームと描画するフレームを合わせる）
    mFbo = argFbo;
    mFbo->allocate(ofGetWidth(), ofGetHeight());
    mGlitch.setup(mFbo);
    shaderIndex=0;
    shaderSwitch=false;
}

void PostGlitch::adapt_glitch_begin(){
}

void PostGlitch::adapt_glitch_end(){
    if(shaderSwitch){
        shaderIndex=ofRandom(1,17);
        if(ofGetElapsedTimeMillis()%1000<300){
            if (shaderIndex == 1) mGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE	, true);
            if (shaderIndex == 2) mGlitch.setFx(OFXPOSTGLITCH_GLOW			, true);
            if (shaderIndex == 3) mGlitch.setFx(OFXPOSTGLITCH_SHAKER			, true);
            if (shaderIndex == 4) mGlitch.setFx(OFXPOSTGLITCH_CUTSLIDER		, true);
            if (shaderIndex == 7) mGlitch.setFx(OFXPOSTGLITCH_NOISE			, true);
            if (shaderIndex == 8) mGlitch.setFx(OFXPOSTGLITCH_SLITSCAN		, true);
            if (shaderIndex == 10) mGlitch.setFx(OFXPOSTGLITCH_INVERT			, true);
            if (shaderIndex == 11) mGlitch.setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST, true);
        }else{
            if (shaderIndex == 1) mGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE	, false);
            if (shaderIndex == 2) mGlitch.setFx(OFXPOSTGLITCH_GLOW			, false);
            if (shaderIndex == 3) mGlitch.setFx(OFXPOSTGLITCH_SHAKER			, false);
            if (shaderIndex == 4) mGlitch.setFx(OFXPOSTGLITCH_CUTSLIDER		, false);
            if (shaderIndex == 7) mGlitch.setFx(OFXPOSTGLITCH_NOISE			, false);
            if (shaderIndex == 8) mGlitch.setFx(OFXPOSTGLITCH_SLITSCAN		, false);
            if (shaderIndex == 10) mGlitch.setFx(OFXPOSTGLITCH_INVERT			, false);
            if (shaderIndex == 11) mGlitch.setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST, false);

        }
    }
    else{
        mGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE	, false);
        mGlitch.setFx(OFXPOSTGLITCH_GLOW			, false);
        mGlitch.setFx(OFXPOSTGLITCH_SHAKER			, false);
        mGlitch.setFx(OFXPOSTGLITCH_CUTSLIDER		, false);
        mGlitch.setFx(OFXPOSTGLITCH_TWIST			, false);
        mGlitch.setFx(OFXPOSTGLITCH_OUTLINE		, false);
        mGlitch.setFx(OFXPOSTGLITCH_NOISE			, false);
        mGlitch.setFx(OFXPOSTGLITCH_SLITSCAN		, false);
        mGlitch.setFx(OFXPOSTGLITCH_SWELL			, false);
        mGlitch.setFx(OFXPOSTGLITCH_INVERT			, false);
    }

}

void PostGlitch::draw_glitch(){
    mGlitch.generateFx();
    ofSetColor(255, 255, 255);
    mFbo->draw(0, 0);
}

void PostGlitch::keyPressed(int key){
    if(key=='s'){
        shaderSwitch = true;
    }else if(key=='e'){
        shaderSwitch = false;
    }
}