#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SET_OS {
    char* os_name;
    size_t OS_MEMORY_SIZE_TOTAL;
    size_t memory_total;
    unsigned long int OS_CONFIG_ID;
} set_os;

typedef struct OS {
    size_t* memory;
    size_t* memory_recent;
    size_t* memory_last;
    float* total_memory_usage;
    float* memory_usage_total;
    enum {
        OS_LINUX = 18080,
        OS_VIRTUAL = 12020,
        OS_MACOS = 8040,
        OS_UNIQUE = 784,
        OS_UBUNTU = 18060
    } OS_CONFIGURE_ID;
    set_os* SET_OS;
} OS_CONFIGURATION;

OS_CONFIGURATION* setup_os_config() {
    OS_CONFIGURATION* os_config = calloc(1,sizeof(OS_CONFIGURATION));
    
    os_config->memory = malloc(sizeof(os_config->memory));
    os_config->memory_recent = malloc(sizeof(os_config->memory_recent));
    os_config->memory_last = malloc(sizeof(os_config->memory_last));
    os_config->total_memory_usage = malloc(sizeof(os_config->total_memory_usage));
    os_config->memory_usage_total = malloc(sizeof(os_config->memory_usage_total));
    os_config->SET_OS = calloc(1,sizeof(os_config->SET_OS));
    
    return os_config;
}

static inline float configure_os(char* os_name, OS_CONFIGURATION* os_config) {
    set_os* set_os_ = calloc(1,sizeof(set_os));
    
    if(strcmp(os_name,"linux")==0) {
        os_config->memory = (void*)0;
        os_config->memory_recent = (void*)0;
        os_config->OS_CONFIGURE_ID = OS_LINUX;
        
        set_os_->os_name = os_name;
        set_os_->OS_MEMORY_SIZE_TOTAL = (size_t)os_config->memory;
        set_os_->memory_total = (size_t)os_config->memory_recent;
        set_os_->OS_CONFIG_ID = os_config->OS_CONFIGURE_ID;
        
        os_config->SET_OS = set_os_;
    }
}

int main(void) {
    
    OS_CONFIGURATION* os_config = setup_os_config();
    configure_os("linux",os_config);
    
    return 0;
}
