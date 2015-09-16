//
//  LinePoints.h
//  oF_Fade_Sample
//
//  Created by HirokiNaganuma on 2015/09/17.
//
//

#ifndef __oF_Fade_Sample__LinePoints__
#define __oF_Fade_Sample__LinePoints__

#include <stdio.h>

class LinePoints{
public:
    LinePoints(int l1,int l2){
        li1 = l1;
        li2 = l2;
    };
    void setup0(int l1,int l2){
        li1 = l1;
        li2 = l2;
    };
    int li1;
    int li2;
protected:
private:
};


#endif /* defined(__oF_Fade_Sample__LinePoints__) */
