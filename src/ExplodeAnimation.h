//
//  ExplodeAnimation.h
//  ofxAnimationUtility
//
//  Created by HirokiNaganuma on 2015/10/05.
//
//

#ifndef __ofxAnimationUtility__ExplodeAnimation__
#define __ofxAnimationUtility__ExplodeAnimation__

#include "ofMain.h"
#include "TriangleElement.h"
#include "Connection.h"
#include "TriangleConnection.h"

#define DEFAULT_NUM 20
#define DEFAULT_RANGE 10


class ExplodeAnimation{
private:
    ofVec2f position;
    vector<TriangleElement> triangles;
    float speed_range = DEFAULT_RANGE;
    ofColor color = ofColor(0,255,0,100);
    
    vector<Connection> connections;
    vector<TriangleConnection> triangleconnections;
public:
    void set_color(ofColor color);
    void set_position(ofVec2f pos);
    void set_speed_range(float range);
    void init();
    void update();
    void draw();
};

#endif /* defined(__ofxAnimationUtility__ExplodeAnimation__) */
