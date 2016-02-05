//
//  MZDevUtilities.h
//  MZ-ObjC
//
//  Created by Inaba Mizuki on 2016/2/5.
//  Copyright (c) 2013年 Inaba Mizuki. All rights reserved.
//

#import "MZLogs.h"

NS_INLINE void MZLogDocumentsDirectory() {
#if MZDEBUG
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *documentsDirectory = [paths objectAtIndex:0];

    MZLog(@"%@", documentsDirectory);
#endif
}
