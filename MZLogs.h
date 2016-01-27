//
//  MZLogs.h
//  MZ-ObjC
//
//  Created by Inaba Mizuki on 2013/11/29.
//  Copyright (c) 2013年 Inaba Mizuki. All rights reserved.
//

// Log 不使用 inline function:
// - 要保持 MZDEBUG flag 不成立時, 不會產生任何 code
// - 除非 objc 有和 swift 一樣, 對於無內容的函數會作最佳化處理

#ifndef MZDEBUG
#define MZDEBUG 0
#endif

#if MZDEBUG
#define MZLog(desc, ...) \
    printf("%s(%d): %s\n", __func__, __LINE__, [[NSString stringWithFormat:(desc), ##__VA_ARGS__] UTF8String])
#define MZLogString(str) MZLog(@"%@", str)
#define MZLogFunctionName() MZLog(@"")
#define MZLogPoint(point) MZLog(@"%@", NSStringFromCGPoint(point))
#define MZLogSize(size) MZLog(@"%@", NSStringFromCGSize(size))
#define MZLogRect(rect) MZLog(@"%@", NSStringFromCGRect(rect))
#define MZLogMessagePoint(message, point) MZLog(@"%@: %@", message, NSStringFromCGPoint(point))
#define MZLogBool(boolValue) MZLog(@"%@", (boolValue) ? @"TRUE" : @"FALSE")
#define MZLogMessageBool(message, boolValue) MZLog(@"%@: %@", message, (boolValue) ? @"TRUE" : @"FALSE")
#else
#define MZLog(desc, ...)
#define MZLogString(str)
#define MZLogFunctionName()
#define MZLogPoint(point)
#define MZLogSize(size)
#define MZLogRect(rect)
#define MZLogMessagePoint(message, point)
#define MZLogBool(boolValue)
#define MZLogMessageBool(message, boolValue)
#endif

#if MZDEBUG
#define MZAssert(condition, desc, ...) \
    if (!(condition)) { \
        printf("** Assert Fail **\n"); \
        printf("  message: %s\n", [[NSString stringWithFormat:(desc), ##__VA_ARGS__] UTF8String]); \
        printf("  in %s(%d)\n", __func__, __LINE__); \
        printf("** ** ** ** ** **\n"); \
        abort(); \
    }

#define MZWarning(condition, desc, ...) \
if (!(condition)) { \
NSLog(@"*** Warning in %s: %@", __FUNCTION__, [NSString stringWithFormat:(desc), ##__VA_ARGS__]); \
}
#else
#define MZAssert(condition, desc, ...)
#endif

#if MZDEBUG
#define MZAssertIfNil(object) MZAssert(object != nil, @"object is nil")
#define MZAssertIfNilWithMessage(object, desc, ...) MZAssert(object != nil, desc, ##__VA_ARGS__)
#else
#define MZAssertIfNil(object)
#define MZAssertIfNilWithMessage(object, desc, ...)
#endif

#if MZDEBUG
#define MZAssertFalse(desc, ...) MZAssert(false, desc, ##__VA_ARGS__)
#else
#define MZAssertFalse(desc, ...)
#endif

#if MZDEBUG
#define MZAssertOverrideMe() MZAssert(false, @"Override me!!!")
#else
#define MZAssertOverrideMe(desc, ...)
#endif

#if MZDEBUG
#define MZAssertSingleton(sharedSingletonInstance) \
MZAssert(sharedSingletonInstance == nil, @"I am singleton pattern!!!!, you suck to init me twice")
#else
#define MZAssertSingleton(sharedSingletonInstance)
#endif

// MRC, ARC
#if !__has_feature(objc_arc)
#define MZGetRetainCount(obj) [objc_arc retainCount]
#else
#define MZGetRetainCount(obj) CFGetRetainCount((__bridge CFTypeRef)obj)
#endif

#if MZDEBUG
#define MZLogRetainCount(tag, obj) MZLog(@"%@(rc=%ld)", tag, MZGetRetainCount(obj))
#else
#define MZLogRetainCount(tag, obj)
#endif