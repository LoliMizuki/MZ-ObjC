#import "MZDictionaryArray.h"
#import "MZLogs.h"

@implementation MZDictionaryArray {
    NSMutableArray* array;
    NSMutableDictionary* dictionary;
}

@synthesize count;
@synthesize array;
@synthesize dictionary;

#pragma mark - init and dealloc

+(instancetype)dictionaryArray {
    return [[self alloc] init];
}

#pragma mark - properties

-(NSInteger)count {
    return (array != nil)? [array count] : -1;
}

#pragma mark - methods (override)

-(id)objectAtIndexedSubscript:(NSUInteger)index {
    return array[index];
}

-(void)setObject:(id)obj atIndexedSubscript:(NSUInteger)index {
    array[index] = obj;
}

-(id)objectForKeyedSubscript:(id)key {
    return dictionary[key];
}

-(void)setObject:(id)obj forKeyedSubscript:(id<NSCopying>)key {
    dictionary[key] = obj;
}

#pragma mark - methods

-(void)addObject:(id)object key:(id<NSCopying>)key {
    if(array == nil || dictionary == nil) {
        if(array != nil) array = nil;
        if(dictionary != nil) dictionary = nil;

        array = [[NSMutableArray alloc] initWithCapacity: 0];
        dictionary = [[NSMutableDictionary alloc] initWithCapacity: 0];
    }

    [array addObject: object];
    [dictionary setObject: object forKey: key];
}

-(void)removeObjectAtIndex:(NSUInteger)index {
    MZAssertFalse(@"not yet");
    if(array == nil || dictionary == nil) return;
}

-(void)removeObjectForKey:(id)aKey {
    MZAssertFalse(@"not yet");
    if(array == nil || dictionary == nil) return;
}

-(id)objectAtIndex:(NSInteger)index {
    if(array == nil) return nil;
    MZAssert(0 <= index && index < [array count], @"index = %ld, array count = %lu", index, [array count]);

    return [array objectAtIndex: index];
}

-(id)objectForKey:(id)key {
    if(dictionary == nil) return nil;
    if([[dictionary allKeys] containsObject: key] == false) return nil;

    return [dictionary objectForKey: key];
}

-(bool)containKey:(id)key {
    return (dictionary != nil)? [[dictionary allKeys] containsObject: key] : false;
}

-(NSInteger)indexOfObject:(id)object {
    if(array == nil || [array count]) return -1;
    return [array indexOfObject: object];
}

@end
 