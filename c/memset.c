#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 50
static int Index;

typedef struct {
    char STRING_TO_SAVE[100][MAX_STRING_SIZE];
} SaveString;

char * GET(char str[], SaveString *String) {
    static char NEW_STRING[MAX_STRING_SIZE];
    if(!(strlen(str)>MAX_STRING_SIZE)) {
        memset(NEW_STRING,'_',strlen(str)+2); // Adding 2 to it so we have 5 left over underscores
        for(int i = 0; i < strlen(str); i++) {
            memset(&NEW_STRING[i],str[i],1);
        }
        strcpy(String->STRING_TO_SAVE[Index],NEW_STRING);
        memset(NEW_STRING,'_',sizeof(char*)); // Setting it back to '_' of length char*
        return String->STRING_TO_SAVE[Index];
    } else {
       sprintf(NEW_STRING,"CANNOT GET STRING OF SIZE GREATER THEN %d",MAX_STRING_SIZE);
    }
    Index++;
    return NEW_STRING;
}

int main(void) {
    // Local Ideals
    SaveString *String = (SaveString *) malloc(sizeof(SaveString));
    
    // Getting input
    char ITEM[MAX_STRING_SIZE];
    printf("INPUT: ");
    scanf("%s",ITEM);
    
    // Printing it
    puts(GET(ITEM,String));
}
