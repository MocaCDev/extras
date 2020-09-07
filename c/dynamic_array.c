#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Array struct that will store ItemTitle and ItemDetails */
typedef struct DynamicArray {
    char** ItemTitles; // this will always be a string
    void** ItemDetails; // we don't know what we're storing
    size_t current_size; // this will be the allocated size for the current ItemDetail
    size_t amount_of_items;
} DynamicArray_;

DynamicArray_* init_array() {
    DynamicArray_* array = calloc(1,sizeof(*array));
    array->ItemTitles = calloc(1,sizeof(*array->ItemTitles));
    array->ItemDetails = calloc(1,sizeof(*array->ItemDetails));
    array->amount_of_items = 0;
    
    return array;
}


DynamicArray_* append(DynamicArray_* array, char* _title, void* _item, size_t item_size) {
    array->amount_of_items++;
    
    /* Reallocating */
    array->ItemTitles = realloc(
        array->ItemTitles,
        array->amount_of_items*item_size
    );
    array->ItemDetails = realloc(
        array->ItemDetails,
        array->amount_of_items*item_size
    );
    
    /* Assigning */
    array->ItemTitles[array->amount_of_items-1] = _title;
    array->ItemDetails[array->amount_of_items-1] = _item; 
}

typedef struct Name {
    char* my_name;
} name_;

name_* init_name(char* name) {
    name_* MyName = calloc(1,sizeof(*MyName));
    MyName->my_name = name;
    return MyName;
}

int main(void) {
    DynamicArray_* array = init_array();
    append(array,"Name",init_name("Aidan"),sizeof(name_*));
    append(array,"Name2",init_name("Aidan2"),sizeof(name_*));
    append(array,"Name3",init_name("Aidan3"),sizeof(name_*));
    append(array,"Name4",init_name("Aidan4"),sizeof(name_*));
    
    for(int i = 0; i < array->amount_of_items; i++) {
        printf("%s:%s\n",array->ItemTitles[i],((name_*)array->ItemDetails[i])->my_name);
    }
}
