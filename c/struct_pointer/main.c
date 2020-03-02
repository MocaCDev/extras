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

int upd(int *length, int dup_by) {
    new_ = *length * dup_by;
    return 0;
}

void print_all(loggin l,char eq[100]) {
    printf("\n\tDATA:\n\tPassword:\t%s\n\tOriginal Number:\t%d\n\tNumber:\t%d\n\tEquation to get %d:\t%s",l.password,original,new_,new_,eq);
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
    
    upd(&m->arr[0],m->duplex_by);
    
    m->new__ = new_;
    sprintf(m->equation,"%d*%d",m->arr[0],m->duplex_by);
    
    for(int i = 0; i < length; i++) {
        if(p[i] == ' ') {
            p[i++] = '_';
        }
    }
    
    strcpy(l_one.password,p);
    
    print_all(l_one,m->equation);
}
