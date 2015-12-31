#import "MZQueue.h"

@implementation NSMutableArray (MZQueue)

+(instancetype)queue {
    return [MZQueue arrayWithCapacity: 0];
}

-(id)pop {
    if([self count] <= 0) return nil;
    
    id firstObject = [self firstObject];
    if(firstObject != nil) [self removeObjectAtIndex: 0];
    return firstObject;
}

-(id)peek {
    if([self count] <= 0) return nil;
    
    id firstObject = [self firstObject];
    return firstObject;
}

-(void)push:(id)obj {
    [self addObject: obj];
}

-(NSString* )remains {
    if(self.count == 0) return @"[]";

    NSMutableString* remains = [NSMutableString stringWithCapacity: 0];

    for(id obj in self) {
        [remains appendString: obj];
        [remains appendString: @","];
    }

    remains = [[remains substringToIndex: remains.length - 1] mutableCopy];

    return [NSString stringWithFormat: @"[%@]", remains];
}

@end
