//
//  MZCGExtensions.h
//  MZ-ObjC
//
//  Created by Inaba Mizuki on 2013/11/29.
//  Copyright (c) 2013年 Inaba Mizuki. All rights reserved.
//

#ifndef MZCGExtensions_h
#define MZCGExtensions_h

#import <OpenGLES/ES2/gl.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKit.h>

#pragma mark - CGPoint

#define CGPointInvalid CGPointMake(-9999, -9999)

#define CGPointOne CGPointMake(1, 1)

NS_INLINE CGPoint CGPointAdd(CGPoint lhs, CGPoint rhs) {
    return CGPointMake(lhs.x + rhs.x, lhs.y + rhs.y);
}

NS_INLINE CGPoint CGPointSub(const CGPoint lhs, const CGPoint rhs) {
    return CGPointMake(lhs.x - rhs.x, lhs.y - rhs.y);
}

NS_INLINE CGPoint CGPointMul(const CGPoint lhs, const CGFloat rhs) {
    return CGPointMake(lhs.x * rhs, lhs.y * rhs);
}

NS_INLINE CGPoint CGPointDiv(const CGPoint lhs, const CGFloat rhs) {
    return CGPointMake(lhs.x / rhs, lhs.y / rhs);
}

#pragma NS Support

NS_INLINE NSValue* NSValueFromCGPoint(CGPoint p) { return [NSValue valueWithCGPoint:p]; }

NS_INLINE NSValue* NSCGPointValueFromXY(const GLfloat x, const GLfloat y) {
    return [NSValue valueWithCGPoint:CGPointMake(x, y)];
}

#pragma mark - CGRect

NS_INLINE CGRect CGRectFromSize(const CGSize size) {
    return CGRectMake(0, 0, size.width, size.height);
}

NS_INLINE CGRect CGRectWithOrigin(const CGRect rect, const CGPoint origin) {
    return CGRectMake(origin.x, origin.y, rect.size.width, rect.size.height);
}

NS_INLINE CGRect CGRectWithSize(const CGRect rect, const CGSize size) {
    return CGRectMake(rect.origin.x, rect.origin.y, size.width, size.height);
}

NS_INLINE CGRect CGRectWithScale(const CGRect rect, const float scale) {
    if (scale == 0) return CGRectZero;

    float w = rect.size.width*scale;
    float h = rect.size.height*scale;
    CGPoint offset = CGPointMake((rect.size.width - w) / 2.0, (rect.size.height - h) / 2.0);

    return CGRectMake(rect.origin.x + offset.x, rect.origin.y + offset.y, w, h);
}

NS_INLINE CGRect CGRectWithScaleXY(const CGRect rect, const float scaleX, const float scaleY) {
    float w = rect.size.width * scaleX;
    float h = rect.size.height * scaleY;
    CGPoint offset = CGPointMake((rect.size.width - w) / 2.0, (rect.size.height - h) / 2.0);

    return CGRectMake(rect.origin.x + offset.x, rect.origin.y + offset.y, w, h);
}

NS_INLINE CGPoint CGRectGetBottomLeft(const CGRect rect) {
    return CGPointMake(rect.origin.x, rect.origin.y);
}

NS_INLINE CGPoint CGRectGetBottomRight(const CGRect rect) {
    return CGPointMake(rect.origin.x + rect.size.width, rect.origin.y);
}

NS_INLINE CGPoint CGRectGetTopLeft(const CGRect rect) {
    return CGPointMake(rect.origin.x, rect.origin.y + rect.size.height);
}

NS_INLINE CGPoint CGRectGetTopRight(const CGRect rect) {
    return CGPointMake(rect.origin.x + rect.size.width, rect.origin.y + rect.size.height);
}

NS_INLINE CGPoint CGRectGetCenter(const CGRect rect) {
    return CGPointMake(rect.origin.x + rect.size.width / 2, rect.origin.y + rect.size.height / 2);
}

#endif