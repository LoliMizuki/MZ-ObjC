#import <Foundation/Foundation.h>

@interface NSMutableArray (MZQueue)
+(instancetype)queue;
-(id)pop;
-(id)peek;
-(void)push:(id)obj;
-(NSString* )remains;
@end

typedef NSMutableArray MZQueue;