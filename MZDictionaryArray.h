#import <Foundation/Foundation.h>

@interface MZDictionaryArray : NSObject 

+(instancetype)dictionaryArray;

-(void)addObject:(id)object key:(id<NSCopying>)key;
-(void)removeObjectAtIndex:(NSUInteger)index;
-(void)removeObjectForKey:(id)aKey;

// normal add/get
-(id)objectAtIndex:(NSInteger)index;
-(id)objectForKey:(id)key;

// get/test
-(bool)containKey:(id)key;
-(NSInteger)indexOfObject:(id)object;

// array[int]
-(id)objectAtIndexedSubscript:(NSUInteger)index;
-(void)setObject:(id)obj atIndexedSubscript:(NSUInteger)index;

// dictionary[key]
-(id)objectForKeyedSubscript:(id)key;
-(void)setObject:(id)obj forKeyedSubscript:(id<NSCopying>)key;

@property (nonatomic, readonly) NSInteger count;
@property (nonatomic, readonly) NSMutableArray *array;
@property (nonatomic, readonly) NSMutableDictionary *dictionary;

@end
