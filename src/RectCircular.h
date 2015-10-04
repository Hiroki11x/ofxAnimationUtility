//
//  RectSwiper.h
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/10/04.
//
//

#ifndef ofxAnimationUtility_RectSwiper_h
#define ofxAnimationUtility_RectSwiper_h

#include "ofMain.h"
//#include "ofxTweenUtil.h"

class RectCircular{
private:
    float angle;
    float speed_x,speed_y;
    float start_x,start_y;
    float rect_width,rect_height;
    ofTrueTypeFont font;
    
public:
    void set_start_pos(float x, float y);
    void set_speed(float x, float y);
    void set_start_rect_size(float w, float h);
    void set_angle(float angle);
    
    void update();
    void init();
    void draw();
    
    RectCircular(){};
};

#endif
