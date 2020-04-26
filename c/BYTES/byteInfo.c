#define MAX_BIT_SIZE          99999999

static char CopiedString[MAX_STRING_LENGTH]; /*9000 is the total length of a string allowed*/
//int ByteLength(char *String);

/*
    This macro takes in a string, an array of integers, parses through each character
    of the string as a "bit", then assigns that index, or "bit", minus one into the
    byteOutput of that character index.
    
    Then, if byteOutput[0] is -1(which it should always be -1), it will parse through the string
    again, only then adding in 2 bits of memory both being zero.
    
    If StrictBit is true, then the macro will check for MAX_BIT_SIZE, and if the total bit size passes
    MAX_BIT_SIZE, everything is going to be reset
*/
#define MakeByte(outOfString,byteOutput,StrictBit) \
    /* Setting size if null */\
    static int Total;\
    if(byteOutput==NULL) {\
        byteOutput=malloc(strlen(outOfString)*sizeof(int*));\
    }\
    for(int i = 0;i < strlen(outOfString); i++) {\
        byteOutput[i]=i-1;\
        if(i==strlen(outOfString)-1) break;\
    }\
    if(byteOutput[0]==-1) {\
        for(int i = 0;i < strlen(outOfString); i++) {\
            if(!(i==100)) {\
                byteOutput[i]=byteOutput[i]+2;\
            } else {\
                byteOutput[i] = byteOutput[i]+4;/*Adding 4 bits of memory to every hundred bits*/\
            }\
            Total+=byteOutput[i];\
            if(i==strlen(outOfString)-1) {\
                /* adding 2 more bits of memory */\
                byteOutput[strlen(outOfString)+1]=0;\
                byteOutput[strlen(outOfString)+2]=0;\
                Total+=2;/*Adding 2 to Total since there is 2 extra bits of memory*/\
                break;\
            }\
        }\
    }\
    if(StrictBit){\
        /*Checking to see if there is more than 99999999 bytes*/\
        if(Total>MAX_BIT_SIZE) {\
            /*Copying string*/\
            memcpy(CopiedString,outOfString,sizeof(outOfString));\
            /*Assigning the string to an empty string*/\
            strcpy(outOfString,"");\
            /*Assigning bytes to zero*/\
            Total=0;\
            /*Freeing memory out of byteOutput since bytes are erased*/\
            if(byteOutput!=NULL) free(byteOutput);\
            printf("No bits aquired");\
        } else {\
            printf("TOTAL BITS: %d\nBYTES:%d",Total,Total/8);\
        }\
    } else {\
        printf("TOTAL BITS: %d\nBYTES:%d",Total,Total/8);\
    }

#define MemoryAbstract(bytes,fromBit,outcomeBytes) \
if(outcomeBytes==NULL) outcomeBytes=malloc(bytes*sizeof(int));\
for(int i = 0; i < bytes; i++) {\
    /* Always adds, if negative..will subtract */\
    outcomeBytes[i]=i+fromBit;\
    /* Checking for negatives */\
    if(outcomeBytes[i]<=0) {\
        outcomeBytes=malloc(bytes+outcomeBytes[i]*sizeof(int));\
        if(!(i+fromBit)<0) outcomeBytes[i]=i+fromBit;\
        continue;\
    }\
    printf("%d\n",outcomeBytes[i]);\
}
