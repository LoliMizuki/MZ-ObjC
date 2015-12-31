#import "MZPool.h"
#import "MZLogMacro.h"
#import "MZIterationsMacro.h"

@interface MZPool (Private)
@end

#pragma mark

@implementation MZPool {
    NSMutableArray *objectsArray;
    NSMutableArray *objectActiveStatesArray;
}

@synthesize disableAssertAtGetFail;
@synthesize activeActionBlock, inactiveActionBlock, deallocActionBlock;

#pragma mark - init and dealloc

-(void)dealloc
{
    if( deallocActionBlock != nil ) for( id object in objectsArray ) deallocActionBlock( object );
    [objectsArray release];
    [objectActiveStatesArray release];

    [inactiveActionBlock release];
    [activeActionBlock release];
    
    [super dealloc];
}

#pragma mark - properties

#pragma mark - methods

-(int)addObject:(id)object
{
    MZAssert( object, @"add object is nil" );
    
    if( objectsArray == nil )
    {
        MZAssert( objectActiveStatesArray == nil, @"something wrong" );
        
        objectsArray = [[NSMutableArray alloc] initWithCapacity: 0];
        objectActiveStatesArray = [[NSMutableArray alloc] initWithCapacity: 0];
    }

    [objectsArray addObject: object];
    [objectActiveStatesArray addObject: @false];
    
    if( inactiveActionBlock != nil ) inactiveActionBlock( object );
    
    MZAssert( objectsArray.count == objectActiveStatesArray.count, @"something wrong with objects and states not equal!!!" );
    
    return objectsArray.count;
}

-(id)getInactiveObject
{
    MZAssert( objectsArray != nil, @"not object" );

    for( int i = 0; i < objectActiveStatesArray.count; i++ )
    {
        if( [objectActiveStatesArray[i] boolValue] == false )
        {
            objectActiveStatesArray[i] = @true;
            if( activeActionBlock != nil ) activeActionBlock( objectsArray[i] );
            
            return objectsArray[i];
        }
    }
    
    if( !self.disableAssertAtGetFail )
        MZAssert( false, @"can not found inactive object(capacity=%d)", objectsArray.count );

    return nil;
}

-(void)returnObject:(id)object
{
    MZAssert( [objectsArray containsObject: object], @"not contain this object(%@)", [object description] );
    
    int index = [objectsArray indexOfObject: object]; // 有更有效率, 但是不增加狀態的方法嗎?
    objectActiveStatesArray[index] = @false;
    
    if( inactiveActionBlock != nil ) inactiveActionBlock( object );
}

@end

#pragma mark

@implementation MZPool (Protected)

#pragma mark - override

#pragma mark - methods

@end

#pragma mark

@implementation MZPool (Private)

#pragma mark - init

#pragma mark - methods

@end
