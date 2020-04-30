#include "byteInfo.h"

int 
len(char *String);

int main(int a, char **args) {

		PARSE_ARGS(a, args);

    char STRING[MAX_STRING_LENGTH];
    int *Bytes;
    int BYTES;

		/*New way of creating arrays!*/
		mIntBitArr(900, COUNT);
		mIntAssign(900, 40);
    
    // Getting String
    printf("STRING: ");
    fgets(STRING,MAX_STRING_LENGTH,stdin);
    
    MakeByte(STRING,Bytes,true,BYTES);
    MemoryAbstract(BYTES,-1000,Bytes,true);
}

int
len(char *String) {
    int length=strlen(String);
    return length;
}
