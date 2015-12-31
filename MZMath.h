// TODO: 角度計算函數需要重新設計, 使之更加直觀, 簡短 ...

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKit.h>

@interface MZMath : NSObject

+(float)lerpWithNumerator:(float)n denominator:(float)d;

+(bool)isPoint:(CGPoint)point inCircle:(CGPoint)center radius:(float)radius;
+(bool)isPointValid:(CGPoint)point;

+(int)randomIntInRangeMin:(int)min max:(int)max;

// 判斷傳入角度位於第幾象限(無法判斷 0, 90, 180, 270)
+(int)quadrantNumberOfDegrees:(float)degrees;
+(int)quadrantNumberOfPoint:(CGPoint)point;

+(float)degreesFromRadians:(float)radians;
+(float)radiansFromDegrees:(float)degrees;

+(float)lengthOfVector:(CGPoint)vector;

+(float)p1:(CGPoint)p1 dotP2:(CGPoint)p2;

+(float)floatX:(float)x modFloatY:(float)y;

+(float)degreesFromVector1:(CGPoint)vector1 toVector2:(CGPoint)vector2;
+(float)degreesFromXAxisToVector:(CGPoint)vector;
+(float)degreesFromP1:(CGPoint)p1 toP2:(CGPoint)p2;

+(float)distancePow2FromP1:(CGPoint)p1 toPoint2:(CGPoint)p2;
+(float)distanceFromP1:(CGPoint)p1 toPoint2:(CGPoint)p2;

+(float)formatDegrees:(float)origin; // 將任何角度化為 0.0~359.9 ...
+(float)degreesCcwDistanceFromDegrees1:(float)degrees1 toDegrees2:(float)degrees2;
+(float)shortestDistanceFromDegrees:(float)from toDegrees:(float)to;

+(CGPoint)vectorFromVector:(CGPoint)v mapToRadians:(float)radians;
+(CGPoint)vectorFromVector:(CGPoint)v mapToDegrees:(float)degrees;

+(CGPoint)unitVectorFromVector:(CGPoint)vector;
+(CGPoint)unitVectorFromPoint1:(CGPoint)p1 toPoint2:(CGPoint)p2;
+(CGPoint)unitVectorFromVector:(CGPoint)v mapToDegrees:(float)degrees;
+(CGPoint)unitVectorFromDegrees:(float)degrees;
+(CGPoint)unitVectorFromRadians:(float)radians;

@end
