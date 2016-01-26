//
//  MZMapReduces.m
//  MZ-ObjC
//
//  Created by Inaba Mizuki on 2013/11/29.
//  Copyright (c) 2013年 Inaba Mizuki. All rights reserved.
//


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


@implementation NSArray (MZExtension)

- (NSArray *)mapWithFunc:(MZMapFunc)func {
    return [MZMapReduces mapWithArray:self func:func];
}

- (NSArray *)filterWithFunc:(MZFilterFunc)func {
    NSMutableArray* result = [NSMutableArray array];

    for (id element in self) {
        if (func(element)) { [result addObject:element]; }
    }

    return result;
}

@end


@implementation NSDictionary (MZExtension)

- (NSArray *)filterWithFunc:(BOOL (^)(id key, id value))func {
    NSMutableArray* result = [NSMutableArray array];

    for (id key in self.allKeys) {
        id value = self[key];

        if (func(key, value)) {
            [result addObject:[NSDictionary dictionaryWithObject:value forKey:key]];
        }
    }

    return result;
}

@end