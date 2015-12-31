#import "MZMapReduces.h"

@implementation MZMapReduces

+(bool)mapWithArray:(NSArray* )array action:(MZMapActionBlock)action {
    return MZMap(array, action);
}

+(bool)mapWithArray:(NSArray *)array actionWithIndex:(MZMapActionBlockWithIndex)action {
    return MZMapWithIndex(array, action);
}

+(bool)mapWithArray:(NSArray *)array actionWithIndex:(MZMapActionBlockWithIndex)action start:(int)start end:(int)end {
    return MZMapWithRange(array, action, start, end);
}

+(void)__fixWarnings {
    MZMap(nil, nil);
    MZMapWithIndex(nil, nil);
    MZMapWithRange(nil, nil, 0, 0);
}

@end