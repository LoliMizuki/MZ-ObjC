#import "MZMapReduces.h"

@implementation MZMapReduces

+ (NSArray *)mapWithArray:(NSArray* )array func:(MZMapFunc)func {
    NSMutableArray* resultArray = [NSMutableArray array];
    for (id element in array) { [resultArray addObject:func(element)]; }

    return resultArray;
}

+ (void)forEachWithArray:(NSArray* )array action:(MZForEachAction)action {
    for (id element in array) {
        action(element);
    }
}

@end