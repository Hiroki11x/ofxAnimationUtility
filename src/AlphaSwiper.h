//
//  AlphaSwiper.h
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/10/04.
//
//

#ifndef __ofxAnimationUtility__AlphaSwiper__
#define __ofxAnimationUtility__AlphaSwiper__

#include "ofMain.h"
#include "ofxTweenUtil.h"

class AlphaSwiper{
private:
    ofxTweenUtil TweenUtil;
    
public:
    void init();
    void update();
    void draw();
};

#endif /* defined(__ofxAnimationUtility__AlphaSwiper__) */
