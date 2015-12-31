#import "MZMemoryUsage.h"
#include <sys/sysctl.h>  
#import <mach/mach.h>
#import <mach/mach_host.h>

@implementation MZMemoryUsage

+(double)availableBytes {
    vm_statistics_data_t vmStats;
    mach_msg_type_number_t infoCount = HOST_VM_INFO_COUNT;
    kern_return_t kernReturn = host_statistics(mach_host_self(), HOST_VM_INFO, (host_info_t)&vmStats, &infoCount);
    
    if(kernReturn != KERN_SUCCESS) {
        return NSNotFound;
    }
    
    return (vm_page_size * vmStats.free_count);
}

+(double)availableKiloBytes {
	return [MZMemoryUsage availableBytes] / 1024.0;
}

+(double)availableMegaBytes {
	return [MZMemoryUsage availableKiloBytes] / 1024.0;
}

@end
