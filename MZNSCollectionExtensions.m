//
//  MZNSCollectionExtensions.m
//  MZ-ObjC
//
//  Created by Inaba Mizuki on 2013/11/29.
//  Copyright (c) 2013年 Inaba Mizuki. All rights reserved.
//


#import "MZNSCollectionExtensions.h"

@implementation MZPair

@synthesize first, second;

- (instancetype)initWithFirst:(id)aFirst second:(id)aSecond {
    self = [super init];

    first = aFirst;
    second = aSecond;

    return self;
}

@end

@implementation NSArray (MZExtension)

- (NSArray *)mapWithFunc:(id (^)(id element))func {
    NSMutableArray* result = [NSMutableArray array];
    for (id element in self) { [result addObject:func(element)]; }

    return result;
}

- (void)forEachWithAction:(void (^)(id element))action {
    for (id element in self) { action(element); }
}

- (NSArray *)filterWithFunc:(bool (^)(id element))func {
    NSMutableArray* result = [NSMutableArray array];

    for (id element in self) {
        if (func(element)) { [result addObject:element]; }
    }

    return result;
}

- (NSArray *)reversedArray {
    NSMutableArray* array = [NSMutableArray arrayWithCapacity:[self count]];
    NSEnumerator* enumerator = [self reverseObjectEnumerator];
    for (id element in enumerator) {
        [array addObject:element];
    }
    return array;
}

@end

@implementation NSDictionary (MZExtension)

- (NSArray *)filterWithFunc:(BOOL (^)(id key, id value))func {
    NSMutableArray* result = [NSMutableArray array];

    for (id key in self.allKeys) {
        id value = self[key];

        if (func(key, value)) {
            [result addObject:[[MZPair alloc] initWithFirst:key second:value]];
        }
    }

    return result;
}

@end