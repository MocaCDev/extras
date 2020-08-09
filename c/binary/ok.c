#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    In Header File: BIT.h
    
    This will set bits to the correct, or more opposable, spot
*/
#define ExpandRight(from,to) (from>>to)
#define ExpandLeft(from,to) (from<<to)

/* Will change the memory block of a variable.
    
    Extends the block from the sizeof from, and then adds to ammount of bytes to it, then re-assigns a default value of the block_size.
    
    Correct Syntax Example(using a integer):
        int a = ExpandBlock(sizeof(a),a,65);
        a will then be 69. sizeof(int) = 4, 65 + 4 = 69.
    When using it for allocations:
        int* a = malloc(ExpandBlock(sizeof(a),*a,32); // Using malloc as an example
*/
#define ExpandBlock(block_size,from,to) ((block_size&sizeof(from)) ? sizeof(from) | to^block_size>>from : sizeof(from) << block_size ^ to)

int main(void) {
    int* a = malloc(ExpandBlock(sizeof(a),*a,32));
}
