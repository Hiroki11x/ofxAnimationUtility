//
//  FadeMotionGraphics.h
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/10/02.
//
//

#ifndef __ofxAnimationUtility__FadeMotionGraphics__
#define __ofxAnimationUtility__FadeMotionGraphics__

#include "ofMain.h"
#include "RectCircular.h"

class FadeMotionGraphics{
private:

    vector<RectCircular> rect_circular;
public:
    FadeMotionGraphics(){};
    void draw();
    void update();
    void init();
};

#endif /* defined(__ofxAnimationUtility__FadeMotionGraphics__) */
