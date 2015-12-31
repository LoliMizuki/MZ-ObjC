#import <Foundation/Foundation.h>

#define mz_mapreduce_common_return_check if( array == nil || array.count == 0 || action == nil ) return false;

typedef void (^MZActionBlock)(void);
typedef void (^MZMapActionBlock)(id iter);
typedef void (^MZMapActionBlockWithIndex)(int index, id iter, id array);

static inline bool MZMap(NSArray* array, MZMapActionBlock action) {
    mz_mapreduce_common_return_check;
    for(id iter in array) action(iter);
    return true;
}

static inline bool MZMapWithIndex(NSArray* array, MZMapActionBlockWithIndex action) {
    mz_mapreduce_common_return_check;
    for(int index = 0; index < array.count; index++) {
        id iter = array[index];
        action(index, iter, array);
    }

    return true;
}

static inline bool MZMapWithRange(NSArray* array, MZMapActionBlockWithIndex action, int start, int end) {
    mz_mapreduce_common_return_check;
    if(start < 0 || end >= array.count) return false;

    for(int index = start; index < end; index++) {
        id iter = array[index];
        action(index, iter, array);
    }

    return true;
}

@interface MZMapReduces : NSObject
+(bool)mapWithArray:(NSArray* )array action:(MZMapActionBlock)action;
+(bool)mapWithArray:(NSArray *)array actionWithIndex:(MZMapActionBlockWithIndex)action;
+(bool)mapWithArray:(NSArray *)array actionWithIndex:(MZMapActionBlockWithIndex)action start:(int)start end:(int)end;
@end