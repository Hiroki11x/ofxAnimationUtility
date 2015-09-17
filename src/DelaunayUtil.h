//
//  DelaunayUtil.h
//  oF_Fade_Sample
//
//  Created by HirokiNaganuma on 2015/09/16.
//
//

#ifndef __oF_Fade_Sample__DelaunayUtil__
#define __oF_Fade_Sample__DelaunayUtil__

#include <stdio.h>
#include "ofMain.h"
#include "TrianglePoints.h"
#include "LinePoints.h"

#define NUM_BALL 80;

#endif /* defined(__oF_Fade_Sample__DelaunayUtil__) */
class DelaunayUtil{
private:

    vector<ofPoint> ps;
    vector<TrianglePoints> ts;
    
    Boolean DetDelaunay(const ofPoint& p0,const ofPoint& p1,const ofPoint& p2,const ofPoint& p3);
    
    
public:
    void setup();
    void draw();
    void generate(float x, float y);
    void update();
    
    
};