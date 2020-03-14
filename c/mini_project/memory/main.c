#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

static int *main_;
static int *secondary;
static int mem_id;
// 2 types:
// mem_label: for memory location
// mem_storage_label: for memory storage
static char *mem_label;
static char *mem_storage_label;

typedef struct {
    int *numbers_to_keep;
    bool memory_ammount;
    // Used if memory_ammount is true
    union {
        int *memory_id;
        char *memory_label;
    } memory_location;
    // Used if memory_ammount is false
    union {
        int *memory_id;
        char *memory_storage_label;
    } memory_storage_locaion;
} database;

void * read_(const int*);
void * free_(int*);
void * setup_location(database *db);
void * setup_storage(database *db);

int main(void) {
    database db;
    
    // Getting size of array
    int size;
    printf("Size you want: ");
    scanf("%d",&size);
    
    // Setting size of array
    main_ = calloc(size,sizeof(int)*sizeof(int)*10);
    db.numbers_to_keep = calloc(size,sizeof(int)*sizeof(int)*10);
    
    for(int i = 0; i < 2; i++) {
        main_[i] = (int)i+1*10/5;
    }
    
    read_(main_);
    free_(main_);
    
    db.numbers_to_keep = secondary;
    
    if(sizeof(db.numbers_to_keep) >= 4) {
        db.memory_ammount = true;
        setup_location(&db);
    } else {
        setup_storage(&db);
    }
}

void * read_(const int *reading) {
    
    int size = sizeof(reading)/sizeof(reading[0]);
    secondary = calloc(size,sizeof(int)*sizeof(int)*10);
    
    for(int i = 0; i < size; i++) {
        secondary[i] = reading[i];
    }
    
    return 0;
}
void * free_(int *t) {
    int before = t[0];
    free(t);
    
    if(t[0] != before) {
        return 0;
    } else {
        printf("Oops, something went wrong while freeing up memory\n-> %d",t[0]);
        return &t[0];
    }
}
void * setup_location(database *db) {
    db->memory_location.memory_id = calloc(1,sizeof(int)*sizeof(int)*10);
    db->memory_location.memory_id[0] = sizeof(db->numbers_to_keep)*sizeof(int);
    mem_id = db->memory_location.memory_id[0];
    free(db->memory_location.memory_id);
    
    db->memory_location.memory_label = malloc(sizeof(char)*sizeof(char)*10);
    
    char new_id[100];
    char chars[100];
    
    for(int i = 0; i < sizeof(db->numbers_to_keep)/sizeof(db->numbers_to_keep[0]); i++) {
        if(db->numbers_to_keep[i] % 2 == 0) {
            chars[i] = '*';
        } else {
            chars[i] = '_';
        }
    }
    
    sprintf(new_id,"%s", chars);
    strcpy(db->memory_location.memory_label,new_id);
    mem_storage_label = db->memory_storage_locaion.memory_storage_label;
    
    return 0;
}
void * setup_storage(database *db) {
    db->memory_location.memory_id = calloc(1,sizeof(int)*sizeof(int)*10);
    db->memory_storage_locaion.memory_id[0] = sizeof(db->numbers_to_keep)*sizeof(int)+sizeof(db->numbers_to_keep[0]);
    mem_id = db->memory_storage_locaion.memory_id[0];
    free(db->memory_storage_locaion.memory_id);
    
    db->memory_storage_locaion.memory_storage_label = malloc(sizeof(char)*sizeof(char)*10);
    
    char new_id[100];
    char chars[100];
    
    for(int i = 0; i < sizeof(db->numbers_to_keep)/sizeof(db->numbers_to_keep[0]); i++) {
        
        if(db->numbers_to_keep[i] % 2 == 0) {
            chars[i] = '*';
        } else {
            chars[i] = '^';
        }
    }
    
    sprintf(new_id, "%ld!%s", db->numbers_to_keep[0]*sizeof(db->numbers_to_keep), chars);
    strcpy(db->memory_storage_locaion.memory_storage_label, new_id);
    mem_storage_label = db->memory_storage_locaion.memory_storage_label;
    
    return 0;
}
