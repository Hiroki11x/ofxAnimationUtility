//
//  ofxTweenUtil.h
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/10/03.
//
//

#ifndef __ofxAnimationUtility__ofxTweenUtil__
#define __ofxAnimationUtility__ofxTweenUtil__

#include "ofMain.h"
#include "ofxTween.h"

class ofxTweenUtil{
private:
    unsigned delay = 0;
    unsigned duration = 1000;
    float easing_max;
    
    void draw();
public:
    void setup();
    void init();
    
    void update();
    
    float get_update_value();
    
    void set_max(float max);
    void set_delay(unsigned int delay);
    void set_duration(unsigned int duration);
    
//    ofxTween tweencubic;
//    ofxEasingCubic 	easingcubic;
    
    ofxTween tweenlinear;
    ofxEasingLinear elasticlinnear;
    
};
#endif /* defined(__ofxAnimationUtility__ofxTweenUtil__) */
