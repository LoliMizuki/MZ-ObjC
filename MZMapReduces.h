#import <Foundation/Foundation.h>

typedef id (^MZMapFunc)(id iter);
typedef void (^MZForEachAction)(id iter);


@interface MZMapReduces : NSObject
+ (NSArray *)mapWithArray:(NSArray* )array func:(MZMapFunc)func;
+ (void)forEachWithArray:(NSArray* )array action:(MZForEachAction)action;
@end
