#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Decide {
    int Type;
    int Size;
};

/* 
    Function used for assign block of memory to the struct of relevent size
    depending on SIZE.
*/
struct Decide *SetupStructSize(struct Decide *d, int SIZE) {
    d = malloc(sizeof(*d) + SIZE);
    
    if((sizeof(d)+SIZE)>999&&(sizeof(d)+SIZE<4000)) {
        SIZE/=floor(550);
        d->Size=(sizeof(d)+SIZE);
    } else {
        if((sizeof(d)+SIZE)>4000) {
            SIZE/=floor(1050);
            // Making size relevant
            if(SIZE<200) {
                SIZE*=20;
            }
            d->Size=(sizeof(d)+SIZE/2);
        } else if((sizeof(d)+SIZE)<999&&(sizeof(d)+SIZE)>0) {
            d->Size = (sizeof(d)+SIZE/2);
        } else{
            SIZE/=floor(880);
            d->Size=(sizeof(d)+SIZE);
        }
    }
    
    return d;
}

int main() {
    struct Decide *D = SetupStructSize(D,999888);
    
    printf("%d",D->Size);
}
