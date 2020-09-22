#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Just a random fun project */

typedef struct StringBlocks {
    char* string;
    struct StringBlocks** all_blocks;
    int amount_of_blocks;
} String_Blocks;

String_Blocks* init_string_block(char* string) {

    String_Blocks* current_block = calloc(1,sizeof(*current_block));

    current_block->amount_of_blocks = 0;
    current_block->all_blocks = calloc(1,sizeof(*current_block->all_blocks));
    current_block->string = string;
    current_block->all_blocks[current_block->amount_of_blocks] = current_block;

    current_block->amount_of_blocks++;

    return current_block;

}
String_Blocks** append_to_block(String_Blocks* current_block, String_Blocks* block_to_append) {
    current_block->amount_of_blocks++;
    current_block->all_blocks = realloc(
        current_block->all_blocks,
        current_block->amount_of_blocks*sizeof(*current_block->all_blocks)
    );
    block_to_append->amount_of_blocks = current_block->amount_of_blocks-1;

    current_block->all_blocks[current_block->amount_of_blocks-1] = block_to_append;

    return current_block->all_blocks;
}

// ToDo: Finish This
String_Blocks** append_with_setup(String_Blocks* current_block, char* string) {
    {
        
    }

    return current_block->all_blocks;
}

int main(void) {

    String_Blocks* block = init_string_block("Aidan");
    String_Blocks* block_2 = init_string_block("BOB");
    append_to_block(block,block_2);
    String_Blocks* block_3 = init_string_block("TED");
    append_to_block(block,block_3);
    
    for(int i = 0; i < block->amount_of_blocks; i++) {
        printf("%s\t%d\n",block->all_blocks[i]->string,block->all_blocks[i]->amount_of_blocks);
    }

    return 0;
}
