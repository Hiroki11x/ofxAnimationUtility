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
#include "SemiCirclePath.h"

class StrechyRectSwiper{
private:
    ofxTweenUtil TweenUtil;
    SwipeMode::Mode mode;
    SemiCirclePath semipath[3];
    ofColor color;
public:
    void set_mode(SwipeMode::Mode mode);
    void init();
    void draw();
    void update();
    void set_color(ofColor color);
    
    void draw_semi_circular(float radius);
    
    void init_path();
    void draw_semi_circle_path(float radius);
};

