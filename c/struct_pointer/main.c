#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char password[100];
} loggin;

struct Make_Available {
    int arr[10];
    int duplex_by;
    int new__;
    char equation[100];
} m_a;

void print_data(loggin *s) {
    printf("Password:\t%s",s->password);
}

static int new_;
static int original;
static int *changed;

int upd(int *length, int dup_by) {
    new_ = *length * dup_by;
    return 0;
}

int check(const void *n_one, const void *n_two) {
    if((*(int *) n_one) == (*(int *) n_two)) {
        return 0;
    } else if((*(int *) n_one) > (*(int *) n_two)) {
        return -1;
    } else {
        return 1;
    }
}

void * sort(struct Make_Available *l) {
    int sum = sizeof(l->arr)/sizeof(l->arr[0]);
    int width = sizeof(l->arr[0]);
    qsort((void *)l->arr,sum,width,check);
    
    for(int i = 0; i < sum; i++) {
        if(l->arr[i] == 0) {
            l->arr[i] = (int)l->arr[i-1]*2;
        }
    }
    
    return l->arr;
}

void print_all(loggin l,char eq[100],struct Make_Available *s) {
    printf("\n\tDATA:\n\tPassword:\t%s\n\tOriginal Number:\t%d\n\tNumber:\t%d\n\tEquation to get %d:\t%s\n\tNumbers:",l.password,original,new_,new_,eq);
    
    int sum = sizeof(s->arr)/sizeof(s->arr[0]);
    printf("%s","->");
    for(int i = 0; i < sum; i++) {
        if(i != sum-1) {
            printf(" %d ",s->arr[i]);
        } else if(i == sum-1) {
            break;
        }
    }
    printf("%s","<-");
}

int main(void) {
    loggin l_one;
    struct Make_Available *m = &m_a;
    char p[100];
    
    fgets(p,50,stdin);
    
    int length = strlen(p);
    m->arr[0] = length;
    m->duplex_by = length/2;
    original = m->arr[0];
    
    int *sorted;
    sorted = sort(m);
    changed = sorted;
    
    upd(&m->arr[0],m->duplex_by);
    
    m->new__ = new_;
    sprintf(m->equation,"%d*%d",m->arr[0],m->duplex_by);
    
    for(int i = 0; i < length; i++) {
        if(p[i] == ' ') {
            p[i++] = '_';
        }
    }
    
    strcpy(l_one.password,p);
    
    print_all(l_one,m->equation,m);
}
