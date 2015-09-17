//
//  TrianglePoints.h
//  oF_Fade_Sample
//
//  Created by HirokiNaganuma on 2015/09/17.
//
//

#ifndef __oF_Fade_Sample__TrianglePoints__
#define __oF_Fade_Sample__TrianglePoints__

#include <stdio.h>

class TrianglePoints
{
public:
    TrianglePoints(int t1,
                   int t2,
                   int t3){
        tri1 = t1;
        tri2 = t2;
        tri3 = t3;
    };
    void setup0(int t1,
                int t2,
                int t3){
        tri1 = t1;
        tri2 = t2;
        tri3 = t3;
    };
    int tri1;
    int tri2;
    int tri3;
protected:
private:
};

#endif /* defined(__oF_Fade_Sample__TrianglePoints__) */
