#include <stdio.h>
#include <stdbool.h>

#define NAME "Bob"
#define port "180.14.9"

int main() {
    const bool is_live_port = port == "180.14.09" ? true : false;
    
    char value = is_live_port == true ? 'y' : 'n';
    
    char name[100];
    
    printf("Name: ");
    scanf("%s",name);
    
    printf("%s has a connected port: %s\nAssociated with %s\n",name,port,NAME);
    
    printf("Returned: %s",value == 'n' ? "n -> false" : "y -> true");
    
    return 0;
}
