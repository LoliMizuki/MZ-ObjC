//
//  MZMapReduces.h
//  MZ-ObjC
//
//  Created by Inaba Mizuki on 2013/11/29.
//  Copyright (c) 2013年 Inaba Mizuki. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef id (^MZMapFunc)(id element);
typedef void (^MZForEachAction)(id element);
typedef BOOL MZFilterFunc(id element);


@interface MZMapReduces : NSObject
+ (NSArray *)mapWithArray:(NSArray* )array func:(MZMapFunc)func;
+ (void)forEachWithArray:(NSArray* )array action:(MZForEachAction)action;
@end



@interface NSArray (MZExtension)

- (NSArray *)mapWithFunc:(MZMapFunc)func;
- (NSArray *)filterWithFunc:(MZFilterFunc)func;

@end


@interface NSDictionary (MZExtension)

- (NSArray *)filterWithFunc:(BOOL (^)(id key, id value))func;

@end
