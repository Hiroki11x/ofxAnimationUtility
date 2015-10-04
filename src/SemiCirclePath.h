//
//  SemiCirclePath.h
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/10/04.
//
//

#ifndef __ofxAnimationUtility__SemiCirclePath__
#define __ofxAnimationUtility__SemiCirclePath__

#include "ofMain.h"

class SemiCirclePath{
private:
    ofPath green_path;
    ofPath black_path;
public:
    void init();
    void draw();
    void set_width();
    
    
};

#endif /* defined(__ofxAnimationUtility__SemiCirclePath__) */
