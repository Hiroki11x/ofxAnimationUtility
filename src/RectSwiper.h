//
//  RectSwiper.h
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/10/03.
//
//

#ifndef __ofxAnimationUtility__RectSwiper__
#define __ofxAnimationUtility__RectSwiper__

#include "ofMain.h"

class RectSwiper{
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
    
    RectSwiper(){};
};

#endif /* defined(__ofxAnimationUtility__RectSwiper__) */
