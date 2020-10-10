#ifndef BASIC
#define BASIC
#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct __MEMORY_BLOCK {
    size_t block_size;
    struct __MEMORY_BLOCK* next_block;
    void* mem_addr;
    size_t resize_heap_pool;
} __MEMORY_BLOCK_;

void* c_allocate(size_t items, size_t size, __MEMORY_BLOCK_** curr_block);
void* m_allocate(size_t size, __MEMORY_BLOCK_** last_block);
void* re_allocate(void* ptr, size_t new_size, __MEMORY_BLOCK_* curr_block);
void* strict_resize(__MEMORY_BLOCK_* current_block, void* ptr);
void* _free(__MEMORY_BLOCK_* blocks, void* ptr);

#define BLOCK_SIZE sizeof(__MEMORY_BLOCK_)
#define SHIFT_RIGHT_CHECK(size) ( (size >= 32) ? 0:1 )
#define SHIFT_RIGHT(size) ( size >> 2 )

#endif
