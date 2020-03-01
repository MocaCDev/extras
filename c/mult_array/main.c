#include <stdio.h>
#include <string.h>

void * change_values(int *array_, const char action_type, int wid, int each_by_value);

static int mult_by;

int main(void) {
    int ages[12];
    int *ages_;
    int arr[12];
    
    for(int i = 0; i < 12; i++) {
        int x;
        scanf("%d",&x);
        ages[i] = x;
        arr[i] = x;
    }
    
    int wid = sizeof(ages)/sizeof(ages[0]);
    
    ages_ = change_values(ages,'m',wid,12);
    
    for(int b = 0; b < 12; b++) {
        printf("%d -> %d months -> %d*%d \n",arr[b],ages_[b],arr[b],mult_by);
    }
}

void * change_values(int *array_, const char action_type, int wid, int each_by_value) {
    
    for(int i = 0; i < wid; i++) {
        if(action_type == 'm') {
            array_[i] = array_[i] * each_by_value;
        } else if(action_type == 'a') {
            array_[i] = array_[i] + each_by_value;
        } else if(action_type == 'd') {
            array_[i] = array_[i] / each_by_value;
        } else if(action_type == 's') {
            array_[i] = array_[i] - each_by_value;
        }
    }
    
    mult_by = each_by_value;
    
    return array_;
}
