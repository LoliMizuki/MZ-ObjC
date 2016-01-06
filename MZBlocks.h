//
//  MZBlocks.h
//  MZ-ObjC
//
//  Created by Inaba Mizuki on 2013/11/29.
//  Copyright (c) 2013年 Inaba Mizuki. All rights reserved.
//

#define mz_block_exec(block, ...) \
if (block != nil) block(__VA_ARGS__)

#define __mz_weak_block __weak __block

#define __mz_gen_block(b, obj) __block __typeof(obj) b = obj

#define __mz_gen_weak(w, obj) __weak __typeof(obj) w = obj

#define __mz_gen_weak_block(wb, obj) __mz_weak_block __typeof(obj) wb = obj

#define __mz_weak_block_type(type) __weak __block type
