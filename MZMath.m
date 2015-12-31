#import "MZMath.h"
#import "MZFormula.h"

@implementation MZMath

+(float)lerpWithNumerator:(float)n denominator:(float)d {
    if(d == 0) return 1.0;
    
    float base = n/d;
    return (base > 1)? 1 : base;
}

+(bool)isPoint:(CGPoint)point inCircle:(CGPoint)center radius:(float)radius {
    return ([MZMath distancePow2FromP1: center toPoint2: point] <= radius*radius)? true : false;
}

+(bool)isPointValid:(CGPoint)point {
    if([NSStringFromCGPoint(point) isEqualToString: @"{nan, nan}"]) return false;
    return true;
}

+(int)randomIntInRangeMin:(int)min max:(int)max {
    int length = max - min + 1;
    return min + (arc4random()%length);
}

+(int)quadrantNumberOfDegrees:(float)degrees {
    float _deg = [MZMath formatDegrees: degrees];

    if(_deg/90 == 0) return 0;
    
    for(int i = 0; i < 4; i++) {
        float startDegrees = 90*i;
        if(startDegrees < _deg && _deg < startDegrees + 90)
            return (i + 1);
    }

    return 0;
}

+(int)quadrantNumberOfPoint:(CGPoint)point {
    if(point.x*point.y == 0) return 0;
    return (point.x > 0)? (point.y > 0)? 1 : 4 : (point.y > 0)? 2 : 3;
}

+(float)degreesFromRadians:(float)radians {
	return radians * 180 / M_PI;
}

+(float)radiansFromDegrees:(float)degrees {
	return degrees * M_PI / 180;
}

+(float)lengthOfVector:(CGPoint)vector {
	return sqrt(pow(vector.x, 2) + pow(vector.y, 2));
}

+(float)p1:(CGPoint)p1 dotP2:(CGPoint)p2 {
	return (p1.x * p2.x) + (p1.y * p2.y);
}

+(float)floatX:(float)x modFloatY:(float)y {
	if(y == 0)
		return 0;
	
	float _x = x;
	float _y = y;
	
	while(YES) if(_x > _y) _x -= _y; else return _x;
}

+(float)degreesFromVector1:(CGPoint)vector1 toVector2:(CGPoint)vector2 {
	float v1Dotv2 = [MZMath p1: vector1 dotP2: vector2];
	float v1lenMulv2len = [MZMath lengthOfVector: vector1] * [MZMath lengthOfVector: vector2];
    
    if(v1lenMulv2len == 0)
        return 0;
	
	float result = acos(v1Dotv2 / v1lenMulv2len);
	result = [MZMath degreesFromRadians: result];
        
	return result;
}

+(float)degreesFromXAxisToVector:(CGPoint)vector {
	if(vector.x == 0) {
		if(vector.y > 0) return 90;
		if(vector.y < 0) return 270;
	}
	
	if(vector.y == 0) {
		if(vector.x > 0) return 0;
		if(vector.x < 0) return 180;
	}

    float result = [MZMath degreesFromVector1: CGPointMake(1, 0) toVector2: vector];
    return (vector.y >= 0)? result : 360 - result;
}

+(float)degreesFromP1:(CGPoint)p1 toP2:(CGPoint)p2 {
    return [MZMath degreesFromXAxisToVector:CGPointMake(p2.x - p1.x, p2.y - p1.y)];
}

+(float)distancePow2FromP1:(CGPoint)p1 toPoint2:(CGPoint)p2 {
	return (p2.x-p1.x)*(p2.x-p1.x) + (p2.y-p1.y)*(p2.y-p1.y);
}

+(float)distanceFromP1:(CGPoint)p1 toPoint2:(CGPoint)p2 {
	return sqrtf((p2.x-p1.x)*(p2.x-p1.x) + (p2.y-p1.y)*(p2.y-p1.y));
}

+(float)formatDegrees:(float)origin {
    if(0 <= origin && origin < 360) return origin;

    float _origin = fmodf(origin, 360.0f);
    return (_origin >= 0)? _origin : 360 + _origin;
}

+(float)degreesCcwDistanceFromDegrees1:(float)degrees1 toDegrees2:(float)degrees2 {
    float d1 = [MZMath formatDegrees:degrees1];
    float d2 = [MZMath formatDegrees:degrees2];
    
    float result = d2 - d1;
    return (result >= 0)? result : 360 + result;
}

+(float)shortestDistanceFromDegrees:(float)from toDegrees:(float)to {
    float fromDeg = [MZMath formatDegrees:from];
    float toDeg = [MZMath formatDegrees:to];

    if(toDeg < fromDeg) {
        toDeg = toDeg + 360;
    }

    float distance = toDeg - fromDeg;
    if(fabsf(distance) > 180) distance = -(360 - distance);

    return distance;
}

+(CGPoint)vectorFromVector:(CGPoint)v mapToRadians:(float)radians {
	float c = cos(radians);
	float s = sin(radians);

	CGPoint v2 = CGPointMake(v.x*c - v.y*s, v.x*s + v.y*c);

    return v2;
}

+(CGPoint)vectorFromVector:(CGPoint)v mapToDegrees:(float)degrees {
    float _deg = fmodf(degrees, 360.0);
    
    if(_deg == 0) return v;
    if(_deg == 90) return CGPointMake(v.y, v.x);
    if(_deg == 180) return CGPointMake(-v.x, -v.y);
    if(_deg == 270) return CGPointMake(v.y, -v.x);
    
	float radians = [MZMath radiansFromDegrees: degrees];
	
	float c = cos(radians);
	float s = sin(radians);
	
	CGPoint v2 = CGPointMake(v.x*c - v.y*s, v.x*s + v.y*c);
    
    return v2;
}

+(CGPoint)unitVectorFromVector:(CGPoint)vector {
	float length = [MZMath lengthOfVector:vector];
	return CGPointMake(vector.x / length, vector.y / length);
}

+(CGPoint)unitVectorFromPoint1:(CGPoint)p1 toPoint2:(CGPoint)p2 {
    float diffY = p2.y - p1.y;
    float diffX = p2.x - p1.x;
    
    if(diffY == 0) {
        if(diffX > 0)
            return CGPointMake(1, 0) ;
        else if(diffX < 0)
            return CGPointMake(-1, 0);
        else
            return CGPointZero;
    }
    
	float length = sqrt(pow(diffX, 2) + pow(diffY, 2));
	
	return CGPointMake(diffX/length, diffY/length);
}

+(CGPoint)unitVectorFromVector:(CGPoint)v mapToDegrees:(float)degrees {
    return [MZMath unitVectorFromVector: [MZMath vectorFromVector: v mapToDegrees: degrees]];
}

+(CGPoint)unitVectorFromDegrees:(float)degrees {
    float degrees_ = ((int)degrees)%360;
    
	if(degrees_ == 90) return CGPointMake(0, 1);
	if(degrees_ == 270) return CGPointMake(0, -1);
	if(degrees_ == 0) return CGPointMake(1, 0);
	if(degrees_ == 180) return CGPointMake(-1, 0);
	
	float radians = [MZMath radiansFromDegrees: degrees];
	return CGPointMake(cos(radians), sin(radians));
}

+(CGPoint)unitVectorFromRadians:(float)radians {
	return CGPointMake(cos(radians), sin(radians));
}
		   
@end
