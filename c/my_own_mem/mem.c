#include "BASIC.h"

void* allocate(size_t size) {
    __MEMORY_BLOCK_* block = (__MEMORY_BLOCK_*)sbrk(0);

    void* addr = (void*)sbrk(0);
    void* memory = (void*)sbrk(size + BLOCK_SIZE);

    if(size == 0) return addr;

    if(memory == (void*)-1) {
        return (void*)0;
    }
    else {
        block->next_block = (void*)0;
        block->mem_addr = addr+BLOCK_SIZE;
        block->block_size = size;

        return block->mem_addr;
    }

}

/* Allocates a new block of memory using allocate */
void* m_allocate(size_t size, __MEMORY_BLOCK_** last_block) {
    __MEMORY_BLOCK_* block = *last_block;
    
    void* mem = (void*)0;
    void* addr = (void*)sbrk(0);

    if(block == (void*)0) {
        *last_block = allocate(size);
        return *last_block;
    }
    else {
        while(block->next_block != (void*)0)
            block = block->next_block;
        
        __MEMORY_BLOCK_* new_block = (__MEMORY_BLOCK_*)sbrk(0);

        mem = (void*)sbrk(size+BLOCK_SIZE);

        if(mem == (void*)-1) return block;
        else {
            new_block->mem_addr = addr+BLOCK_SIZE;
            new_block->block_size = size;
            new_block->next_block = (void*)0;
            block->next_block = new_block;

            return new_block->mem_addr;
        }
    }
    return block;
}

void* c_allocate(size_t items, size_t size, __MEMORY_BLOCK_** curr_block) {
    __MEMORY_BLOCK_* curr = *curr_block;

    void* memory = (void*)0;
    void* addr = (void*)sbrk(0);
    void* ptr;

    if(curr == (void*)0)
        curr = allocate(items*size);
    else {
        while(curr->next_block != (void*)0)
            curr = curr->next_block;

       memory = (void*)sbrk((items*size)+BLOCK_SIZE);

       if(memory == (void*)-1) return curr;
       else {
           __MEMORY_BLOCK_* new_block = (__MEMORY_BLOCK_*)sbrk(0);

           new_block->mem_addr = addr+BLOCK_SIZE;
           new_block->block_size = items * size;
           new_block->next_block = (void*)0;
           curr->next_block = new_block;

           ptr = allocate(new_block->block_size);
           return ptr;
       }
    }
    return curr;
}

void* re_allocate(void* ptr, size_t new_size, __MEMORY_BLOCK_* curr_block) {

    size_t memory = (size_t)sbrk(new_size+BLOCK_SIZE);

    if(memory) {
        void* new_ptr = allocate(new_size);

        if(curr_block == (void*)0)
            curr_block = allocate(new_size);
        
        curr_block->block_size = new_size;

        bcopy(ptr,new_ptr, BLOCK_SIZE);
        curr_block->mem_addr = (void*)new_ptr;

        return curr_block->mem_addr;
    }

    return ptr;
}

void* strict_resize(__MEMORY_BLOCK_* current_block, void* ptr) {

    current_block->block_size = (size_t)sbrk(-current_block->block_size);

    ptr = allocate(current_block->block_size >> 2);

    //bcopy(new_ptr, ptr, BLOCK_SIZE);

    //ptr = allocate(current_block->block_size);
    return ptr;

}

void* grab(__MEMORY_BLOCK_* block, size_t size) {
    size_t from_heap = block->resize_heap_pool;
    size_t memory = (size_t)sbrk(from_heap-size);

    if(memory) {
        __MEMORY_BLOCK_* block = (__MEMORY_BLOCK_*)sbrk(0);

        block->mem_addr = (void*)sbrk(0);
        block->block_size = (size_t)memory;
        block->next_block = (void*)0;

        block->resize_heap_pool = (size_t)sbrk(from_heap-size);

        return block->mem_addr;
    }
}

void* _free(__MEMORY_BLOCK_* blocks, void* ptr) {

    __MEMORY_BLOCK_* block = blocks;
    size_t current_block_size;

    if(block != (void*)0) {
        current_block_size = block->block_size;

        if(block->next_block != (void*)0)
            block = block->next_block;
        
        block->resize_heap_pool = (size_t)sbrk(0)+(size_t)block->mem_addr;
    }
    
    //block->resize_heap_pool = current_block_size + block->block_size + BLOCK_SIZE;

    //printf("%ld",block->resize_heap_pool);

    return ptr;
}
