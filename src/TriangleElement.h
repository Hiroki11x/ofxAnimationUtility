//
//  TriangleElement.h
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/10/05.
//
//

#ifndef __ofxAnimationUtility__TriangleElement__
#define __ofxAnimationUtility__TriangleElement__

#include "ofMain.h"

#define OFFSET 100
#define DEFAULT_SIZE 1

class TriangleElement{
private:
    ofColor color;
    ofVec2f speed;
    ofVec2f position;
    float angle;//ここはRandomな
    float size = DEFAULT_SIZE;
    bool isfade = false;
public:
    void set_color(ofColor arg_color);
    void init();
    void update();
    void draw();
    
    ofVec2f* get_position();
    void set_size(float size);
    void set_speed(ofVec2f speed);
    void set_position(ofVec2f position);
    bool is_fade();
    
    TriangleElement(){
        angle = ofRandom(60);
    };
};

#endif /* defined(__ofxAnimationUtility__TriangleElement__) */
