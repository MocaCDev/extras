int 
len(char *String);

int main(void) {
    char STRING[MAX_STRING_LENGTH];
    int *Bytes;
    
    // Getting String
    printf("STRING: ");
    fgets(STRING,MAX_STRING_LENGTH,stdin);
    
    int LENGTH = len(STRING);
    
    MakeByte(STRING,Bytes,true);
}

int
len(char *String) {
    int length=strlen(String);
    return length;
}
