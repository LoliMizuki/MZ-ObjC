#import "MZFormula.h"

@implementation MZFormula

@synthesize isDoNotCare;
@synthesize a;
@synthesize b;
@synthesize c;

#pragma mark - init and dealloc

+(MZFormula *)formulaWithPoint1:(CGPoint)p1 point2:(CGPoint)p2 {
    return [[self alloc] initWithPoint1: p1 point2: p2];
}

-(id)initWithPoint1:(CGPoint)p1 point2:(CGPoint)p2 {
	if( ( self = [super init] ) ) {
		b = 1;
        a = ( p1.x == p2.x )? 0 : ( p1.y - p2.y )/( p2.x - p1.x );
		c = -a*p1.x - ( b*p1.y );
	}
    
	return self;
}

#pragma mark - methods

-(float)getResult:(CGPoint)p; {
	return (a*p.x) + (b*p.y) + c;
}

-(float)getResultWithX:(float)x y:(float)y {
    return a*x + b*y + c;
}

-(float)getXWithY:(float)y {
    isDoNotCare = ( a == 0 )? true : false;    
    return -( b*y + c ) / a;
}

-(float)getYWithX:(float)x {
    isDoNotCare = ( b == 0 )? true : false;
    return -( a*x + c ) / b;
}

@end

// 判斷某點 p0 是否在任意三點 p1, p2, p3 所構成的三角形內
// 原本是 MZMath 的函數, 暫時搬出
//+(bool)isPoint0:(CGPoint)p0 innerTriangleWithTopPoint1:(CGPoint)p1 point2:(CGPoint)p2 point3:(CGPoint)p3 {
//    MZFormula *p1p2Formula = [MZFormula formulaWithPoint1: p1 point2: p2];
//	MZFormula *p2p3Formula = [MZFormula formulaWithPoint1: p2 point2: p3];
//	MZFormula *p1p3Formula = [MZFormula formulaWithPoint1: p1 point2: p3];
//    
//	if( ( [p1p2Formula getResult:p0] * [p1p2Formula getResult:p3] ) > 0 ) {
//		if( ( [p2p3Formula getResult:p0] * [p2p3Formula getResult:p1] ) > 0 ) {
//			if( ( [p1p3Formula getResult:p0] * [p1p3Formula getResult:p2] ) > 0 ) {
// 				return true;
//			}
//		}
//	}
//	
//	return false;
//}

