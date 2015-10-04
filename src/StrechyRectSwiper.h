//
//  StrechyRectSwiper.h
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/10/04.
//
//

#include "ofMain.h"
#include "ofxTweenUtil.h"
#include "SwipeMode.h"

class StrechyRectSwiper{
private:
    ofxTweenUtil TweenUtil;
    ofColor color;
    SwipeMode::Mode mode;
public:
    void set_mode(SwipeMode::Mode mode);
    void init();
    void draw();
    void update();
    void set_color(ofColor color);
    
    void draw_semi_circular(float radius);
};

