#import <Foundation/Foundation.h>

typedef void (^MZPoolObjectActionBlock)(id object);

@interface MZPool : NSObject 

-(int)addObject:(id)object;
-(id)getInactiveObject;
-(void)returnObject:(id)object;

@property (nonatomic, readwrite) bool disableAssertAtGetFail;
@property (nonatomic, readwrite, copy) MZPoolObjectActionBlock activeActionBlock;
@property (nonatomic, readwrite, copy) MZPoolObjectActionBlock inactiveActionBlock;
@property (nonatomic, readwrite, copy) MZPoolObjectActionBlock deallocActionBlock;

@end

#pragma mark

@interface MZPool (Protected)
@end

/*
 設定驗證 class 的功能 ... 
 */