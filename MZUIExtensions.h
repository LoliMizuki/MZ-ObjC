//
//  MZUIExtensions.h
//  MZ-ObjC
//
//  Created by Inaba Mizuki on 2016/3/2.
//  Copyright © 2016年 Inaba Mizuki. All rights reserved.
//

#ifndef MZUIExtensions_h
#define MZUIExtensions_h

#import <OpenGLES/ES2/gl.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKit.h>

NS_INLINE BOOL UIColorIsEqual(UIColor* color1, UIColor* color2, BOOL ignoreAlpha) {
    CGFloat tolerance = 0.01;

    CGFloat r1, g1, b1, a1;
    CGFloat r2, g2, b2, a2;

    [color1 getRed:&r1 green:&g1 blue:&b1 alpha:&a1];
    [color2 getRed:&r2 green:&g2 blue:&b2 alpha:&a2];

    BOOL alphaResult = (ignoreAlpha)? true : (fabs(a1 - a2) < tolerance);

    return  (fabs(r1 - r2) < tolerance) &&
    (fabs(g1 - g2) < tolerance) &&
    (fabs(b1 - b2) < tolerance) &&
    alphaResult;
}



#endif /* MZUIExtensions_h */
