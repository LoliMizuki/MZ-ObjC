// Requires
//  - CoreGraphics.framework

#ifndef MZCGExtensions_h
#define MZCGExtensions_h

#import <OpenGLES/ES2/gl.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKit.h>

#pragma mark - CGPoint

#define CGPointInvalid CGPointMake(-9999, -9999)

#define CGPointOne CGPointMake(1, 1)

static inline CGPoint CGPointAdd(CGPoint lhs, CGPoint rhs) {
    return CGPointMake(lhs.x + rhs.x, lhs.y + rhs.y);
}

static inline CGPoint CGPointSub(const CGPoint lhs, const CGPoint rhs) {
    return CGPointMake(lhs.x - rhs.x, lhs.y - rhs.y);
}

static inline CGPoint CGPointMul(const CGPoint lhs, const CGFloat rhs) {
    return CGPointMake(lhs.x * rhs, lhs.y * rhs);
}

static inline CGPoint CGPointDiv(const CGPoint lhs, const CGFloat rhs) {
    return CGPointMake(lhs.x / rhs, lhs.y / rhs);
}

#pragma NS Support

static inline NSValue* NSValueFromCGPoint(CGPoint p) { return [NSValue valueWithCGPoint:p]; }

static inline NSValue* NSCGPointValueFromXY(const GLfloat x, const GLfloat y) {
    return [NSValue valueWithCGPoint:CGPointMake(x, y)];
}

#pragma mark - CGRect

static inline CGRect CGRectSetScale(CGRect rect, float scale) {
    if (scale == 0) return CGRectZero;

    float w = rect.size.width * scale;
    float h = rect.size.height * scale;
    CGPoint offset = CGPointMake((rect.size.width - w) / 2.0, (rect.size.height - h) / 2.0);

    return CGRectMake(rect.origin.x + offset.x, rect.origin.y + offset.y, w, h);
}

static inline CGRect CGRectSetScaleXY(CGRect rect, float scaleX, float scaleY) {
    float w = rect.size.width * scaleX;
    float h = rect.size.height * scaleY;
    CGPoint offset = CGPointMake((rect.size.width - w) / 2.0, (rect.size.height - h) / 2.0);

    return CGRectMake(rect.origin.x + offset.x, rect.origin.y + offset.y, w, h);
}

static inline CGPoint CGRectGetLeftBottom(CGRect rect) { return CGPointMake(rect.origin.x, rect.origin.y); }

static inline CGPoint CGRectGetRightBottom(CGRect rect) {
    return CGPointMake(rect.origin.x + rect.size.width, rect.origin.y);
}

static inline CGPoint CGRectGetLeftTop(CGRect rect) {
    return CGPointMake(rect.origin.x, rect.origin.y + rect.size.height);
}

static inline CGPoint CGRectGetRightTop(CGRect rect) {
    return CGPointMake(rect.origin.x + rect.size.width, rect.origin.y + rect.size.height);
}

static inline CGPoint CGRectGetCenter(CGRect rect) {
    return CGPointMake(rect.origin.x + rect.size.width / 2, rect.origin.y + rect.size.height / 2);
}

#endif