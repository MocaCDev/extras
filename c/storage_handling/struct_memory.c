#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *memory;
    int *numbers;
    bool is_freed;
    // This union will go with is_freed. If true, the ammount of memory freed is stored in ammount_freed
    union {
        int *ammount_freed;
    } iLog_mem_freed;
} iLog_memory;

// These will be needed to keep memory, and to recyle the structur
static int *keep_numbers;
static int memory;
static int memory_freed;

// Functions
// Function 1:
/*
    This function will take the iLog_mem and set it's total storage to ammount, and the
    memory it can hold to sizeof int * sizeof int
*/
void * setup_memory(iLog_memory *iLog_mem, const int ammount);
/*
    Update memory will update the memory of things within the struct.
    Takes anything from within the struct, multiplies it by by_ammount and sizeof the struct
*/
void * update_memory(iLog_memory *iLog_mem, const int by_ammount);
/*
    This function will free data, setting is_freed to true, thus adding up total memory
*/
void * free_memory(iLog_memory *iLog_mem);

/* 
    This will acces the union within the struct, update the total ammount of memory stored/freed
    then free it up
*/
void * total_ammount_of_memory(iLog_memory *iLog_mem);

int main(void) {
    iLog_memory iLog_mem;
    
    // iLog_mem.memory is set to a memory size of 40*150
    iLog_mem.memory = malloc(sizeof(int)*150);
    iLog_mem.iLog_mem_freed.ammount_freed = malloc(sizeof(int)*150);
    
    int c[50];
    
    setup_memory(&iLog_mem,1);
    // This is going to be the memory stored
    iLog_mem.memory[0] = sizeof(iLog_mem);
    for(int i = 0; i < iLog_mem.memory[0]; i++) {
        int b = (int)i+1*10/5;
        if(b == 15) {
            update_memory(&iLog_mem,iLog_mem.memory[0]);
        }
    }
    keep_numbers = calloc(iLog_mem.memory[0],sizeof(int)*sizeof(int));
    
    for(int i = 0; i < iLog_mem.memory[0]; i++) {
        c[i] = (int)i+1*10/5;
        iLog_mem.numbers[i] = c[i];
        keep_numbers[i] = iLog_mem.numbers[i];
    }
    memory = iLog_mem.memory[0];
    
    // All data is stored, lets clear the memory beig stored within the struct items
    free_memory(&iLog_mem);
}

void * setup_memory(iLog_memory *iLog_mem, const int ammount) {
    iLog_mem = calloc(ammount,sizeof(int)*sizeof(int));
    iLog_mem->numbers = calloc(ammount,sizeof(int)*sizeof(int));
    
    return 0;
}

void * update_memory(iLog_memory *iLog_mem,const int by_ammount) {
    iLog_mem->numbers = realloc(iLog_mem->numbers,by_ammount*sizeof(*iLog_mem));
    
    return 0;
}

void * free_memory(iLog_memory *iLog_mem) {
    
    free(iLog_mem->memory);
    free(iLog_mem->numbers);
    
    iLog_mem->is_freed = true;
    total_ammount_of_memory(iLog_mem);
    
    return 0;
}

void * total_ammount_of_memory(iLog_memory *iLog_mem) {
    
    if(iLog_mem->is_freed) {
        iLog_mem->iLog_mem_freed.ammount_freed[0] = sizeof(memory)+sizeof(keep_numbers);
    }
    
    memory_freed = iLog_mem->iLog_mem_freed.ammount_freed[0]+sizeof(keep_numbers)+sizeof(iLog_mem->iLog_mem_freed.ammount_freed);
    printf("%d",memory_freed);
    
    free(iLog_mem->iLog_mem_freed.ammount_freed);
    
    return 0;
}
