//
//  MZUIExtensions.h
//  MZ-ObjC
//
//  Created by Inaba Mizuki on 2016/3/3.
//  Copyright (c) 2013年 Inaba Mizuki. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIColor (MZUIExtensions)

- (BOOL)isEqualToColor:(UIColor *)anotherColor ignoreAlpha:(BOOL)ignoreAlpha;
- (BOOL)isEqualToColor:(UIColor *)anotherColor;

@end
