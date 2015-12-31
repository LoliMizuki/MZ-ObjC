#import <Foundation/Foundation.h>

static inline NSString* NSStringFromBool(bool boolValue) {
    return [NSString stringWithFormat: @"%@", ( boolValue )? @"TRUE" : @"FALSE"];
}

@interface MZConverts : NSObject
+(NSString* )stringFromBool:(bool)boolValue;
@end