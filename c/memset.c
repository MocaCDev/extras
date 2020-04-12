#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 50
static int Index;

typedef struct {
    char STRING_TO_SAVE[400][MAX_STRING_SIZE];
    char SAVE_TOGETHER[1000];
} SaveString;

char * GETCAT(char str[], SaveString *String) {
    static char NEW_STRING[MAX_STRING_SIZE];
    if(!(strlen(str)>MAX_STRING_SIZE)) {
        memset(NEW_STRING,'_',strlen(str)+3); // Adding 2 to it so we have 5 left over underscores
        for(int i = 0; i < strlen(str); i++) {
            memset(&NEW_STRING[i],str[i],1);
        }
        strcpy(String->STRING_TO_SAVE[Index],NEW_STRING);
        Index++;
        return NEW_STRING;
    } else {
       sprintf(NEW_STRING,"CANNOT GET STRING OF SIZE GREATER THEN %d",MAX_STRING_SIZE);
    }
    return NEW_STRING;
}

int main(void) {
    // Local Ideals
    SaveString *String = (SaveString *) malloc(sizeof(SaveString));
    
    // Getting ammount of times
    int AmTime;
    printf("Ammount to get: ");
    scanf("%d",&AmTime);
    
    // Getting input for ammount of AmTime
    char ITEM[MAX_STRING_SIZE];
    if(!(AmTime>399)) { 
        for(int i = 0; i < AmTime; i++) {
            printf("INPUT: ");
            scanf("%s",ITEM);
            
            // getting it
            GETCAT(ITEM,String);
        }
    }
    
    for(int i = 0; i < sizeof(String->STRING_TO_SAVE)/sizeof(String->STRING_TO_SAVE[0]); i++) {
        if(!(strcmp(String->STRING_TO_SAVE[i],"")==0))strcat(String->SAVE_TOGETHER,String->STRING_TO_SAVE[i]);
        else break;
    }
    
    printf("Done!\n%s",String->SAVE_TOGETHER);
}
