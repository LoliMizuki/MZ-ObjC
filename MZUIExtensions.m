//
//  MZUIExtensions.m
//  MZ-ObjC
//
//  Created by Inaba Mizuki on 2016/3/3.
//  Copyright (c) 2013年 Inaba Mizuki. All rights reserved.
//

#import "MZUIExtensions.h"

@implementation UIColor (MZUIExtensions)

- (BOOL)isEqualToColor:(UIColor *)anotherColor ignoreAlpha:(BOOL)ignoreAlpha {
    CGFloat tolerance = 0.01;

    CGFloat r1, g1, b1, a1;
    CGFloat r2, g2, b2, a2;

    [self getRed:&r1 green:&g1 blue:&b1 alpha:&a1];
    [anotherColor getRed:&r2 green:&g2 blue:&b2 alpha:&a2];

    BOOL alphaResult = (ignoreAlpha)? true : (fabs(a1 - a2) < tolerance);

    return (fabs(r1 - r2) < tolerance) &&
           (fabs(g1 - g2) < tolerance) &&
           (fabs(b1 - b2) < tolerance) &&
           alphaResult;
}

- (BOOL)isEqualToColor:(UIColor *)anotherColor {
    return [self isEqualToColor:anotherColor ignoreAlpha:true];
}

@end
