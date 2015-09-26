//
//  CircularAnimation.h
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/09/26.
//
//

#ifndef __ofxAnimationUtility__CircularAnimation__
#define __ofxAnimationUtility__CircularAnimation__

#include "ofMain.h"

class CircularAnimation{
    
private:
    ofVec2f position;
    float max_size;
    float duration;
    float elapsed_time;
    float is_animation;//これがtrueのときはアニメーションする
    
    void set_duration();//msで入れて欲しい
    void set_max_size();
    
    void update_duration();
    void update();
    
private:
    void setup(ofVec2f position);
    void draw_circular_animation(bool);//trueとなるタイミングからanimationスタート

};
#endif /* defined(__ofxAnimationUtility__CircularAnimation__) */
