//
//  MZCodeMiracle.h
//  MZ-ObjC
//
//  Created by Inaba Mizuki on 2016/1/26.
//  Copyright © 2016年 Inaba Mizuki. All rights reserved.
//

#ifndef MZCodeMiracle_h
#define MZCodeMiracle_h

// as Swift: var x = MyClass()
#define mz_gen_var(lhs, rhs) __typeof(rhs) lhs = rhs

// as Swift: guard let x = y else { return }
#define mz_guard_let_return(lhs, rhs) \
    mz_gen_var(lhs, rhs); \
    if (lhs == nil) { return; }


#define mz_guard_let_action_return(lhs, rhs, action) \
    mz_gen_var(lhs, rhs); \
    if (lhs == nil) { \
        if ((action)) { action(); } \
        return; \
    }

#endif /* MZCodeMiracle_h */


