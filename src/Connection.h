//
//  Connection.h
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/10/06.
//
//

#ifndef __ofxAnimationUtility__Connection__
#define __ofxAnimationUtility__Connection__

#include "ofMain.h"

class Connection{
private:
    ofVec2f start_pos,end_pos;
    ofColor color;
public:
    void set_node(ofVec2f start, ofVec2f end);
    void init();
    void draw();
};

#endif /* defined(__ofxAnimationUtility__Connection__) */
