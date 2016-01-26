//
//  MZCodeMiracle.h
//  MZ-ObjC
//
//  Created by Inaba Mizuki on 2016/1/26.
//  Copyright © 2016年 Inaba Mizuki. All rights reserved.
//

#ifndef MZCodeMiracle_h
#define MZCodeMiracle_h

#define mz_gen_var(lhs, rhs) __typeof(rhs) lhs = rhs

#define mz_guard_let_return(lhs, rhs) \
mz_gen_var(lhs, rhs); \
if (lhs == nil) { return; }

// TODO: 檢討/試作/失敗
#define mz_guard_let_with_action(lhs, rhs, elseAction) __typeof(rhs) lhs; if (rhs == nil) { if (elseAction) { elseAction(); } return }

#endif /* MZCodeMiracle_h */


