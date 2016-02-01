//
//  MZNSCollectionExtensions.h
//  MZ-ObjC
//
//  Created by Inaba Mizuki on 2013/11/29.
//  Copyright (c) 2013年 Inaba Mizuki. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MZPair : NSObject
@property (nonatomic, readonly) id first;
@property (nonatomic, readonly) id second;
- (instancetype)initWithFirst:(id)aFirst second:(id)aSecond;
@end

@interface NSArray (MZExtension)
- (NSArray *)mapWithFunc:(id (^)(id element))func;
- (void)forEachWithAction:(void (^)(id element))action;
- (NSArray *)filterWithFunc:(bool (^)(id element))func;
- (NSArray *)reversedArray;
@end

@interface NSDictionary (MZExtension)
- (NSArray *)filterWithFunc:(BOOL (^)(id key, id value))func;
@end

NS_ASSUME_NONNULL_END
