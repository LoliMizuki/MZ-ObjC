#define mz_block_exec(block, ...) \
    if (block != nil) block(__VA_ARGS__)

#define __mz_weak_block __weak __block

#define __mz_gen_block(b, obj) __typeof(obj) __block b = obj
#define __mz_gen_weak(w, obj) __typeof(obj) __weak w = obj
#define __mz_gen_weak_block(wb, obj) __typeof(obj) __mz_weak_block wb = obj
#define __mz_weak_block_type(type) __weak __block type
