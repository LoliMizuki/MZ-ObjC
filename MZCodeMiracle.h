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
#define mz_var(lhs, rhs) __typeof(rhs) lhs = rhs

// as Swift: guard let x = y else { return }
#define mz_guard_let_return(lhs, rhs) \
    mz_var(lhs, rhs); \
    if (lhs == nil) { return; }

#define mz_guard_let_return_with_action(lhs, rhs, elseAction) \
    mz_var(lhs, rhs); \
    if (lhs == nil) { \
        if ((elseAction)) { elseAction(); } \
        return; \
    }

// e.g: NSString* str = mz_value_with_default([self getString], @"default string");
// as Swift: let str = getString() ?? "default string"
#define mz_value_with_default(value, default_value) \
    (value != nil) ? value : default_value

// e.g: mz_var_with_default(str, [self getString], @"default string");
#define mz_var_with_default(lhs, rhs, default_value) \
    mz_var(lhs, mz_value_with_default(rhs, default_value))

#endif /* MZCodeMiracle_h */


