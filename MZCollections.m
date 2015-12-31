#import "MZCollections.h"

@implementation MZCollections

+ (id)randomPickInArray:(NSArray *)array {
    if (array == nil || array.count == 0) return nil;

    NSUInteger index = arc4random() % array.count;
    return array[index];
}

@end
