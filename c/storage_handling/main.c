#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *number_of;
    char *t;
} logging;

static int *save_number;
static char *save_string;

void * free_storage(logging *free_);
void * copy_return_string(char *s, int size_of_loop);
void * grab(logging *logg_,int *arr, const void*);

int main(void) {
    logging *logg;
    int arr[2] = {1,2};
    int *after;
    
    // And now everything is stored here!
    after = grab(logg,arr,(void *)arr);
}

// This will free up logging.number_of and logging.t
void * free_storage(logging *free_) {
    
    free(free_->t);
    free(free_->number_of);
    
    return 0;
}

// This will create a string for logging.t to copy into
void * copy_return_string(char *s, int size_of_loop) {
    
    for(int i = 0; i < size_of_loop; i++) {
        sprintf(s,"adminadmin%d%d",i+1,i*3);
    }
    
    return s;
}

// This grabbs logg from main and continues to do ideals within the struct
// method
void * grab(logging *logg_,int *arr, const void *arrg) {
    int index_one = (*(int *)&arrg[0]);
    int size = sizeof(arrg)/sizeof(index_one);
    
    logg_ = calloc(size,sizeof(*logg_->number_of)*sizeof(int));
    logg_->number_of = malloc(sizeof(int)*sizeof(int));
    save_number = malloc(sizeof(int)*sizeof(int));
    
    for(int i = 0; i < size; i++) {
        logg_->number_of[i] = i+1;
        (logg_+i)->t = malloc(sizeof(char)*sizeof(char));
        (logg_+i)->t = copy_return_string(logg_->t,sizeof(logg_->number_of));
        save_number[i] = logg_->number_of[i];
    }
    save_string = logg_->t;
    
    // Since we're all done, we can free it up
    free_storage(logg_);
    
    return save_number;
}
