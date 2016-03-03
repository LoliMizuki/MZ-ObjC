//
//  MZUIExtensions.h
//  AsenseTek
//
//  Created by Inaba Mizuki on 2016/3/3.
//  Copyright © 2016年 Inaba Mizuki. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIColor (MZUIExtensions)

- (BOOL)isEqualToColor:(UIColor *)anotherColor ignoreAlpha:(BOOL)ignoreAlpha;
- (BOOL)isEqualToColor:(UIColor *)anotherColor;

@end
