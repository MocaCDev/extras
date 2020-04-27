#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

/* 

	THE FOLLOWING MACROS ARE TO STRICTLY ASSIGN BITS TO EACH
	VARIABLE, EITHER GLOBAL OR LOCAL, SO WE DON'T EXCEED/TAKE UP
	TOO MUCH MEMORY

	TYPE: integer
	INFORMATION:
		mIntBitArr:
			- Creating int of a variable i_##y(y being the name)
			- Assigning size of array to the variable
		mIntAssign:
			- Assigning an index of the array to a number
*/
static int *Y;// Assigning Y to y below
static int X;// Assigning X to x below. Used for mIntAssign
#define mIntBitArr(x,y) \
	int i_##y[x+1];/*Adding one so we have a max array*/\
	Y=i_##y;\
	X=x;/*Subtracting one, else it would be one above max*/\
	printf("created i_%s\n",#y)
#define mIntAssign(atIndex,assignToNum) \
if(!(X<=0)) {\
	/*If the index is less than zero, we will asign a number to each index*/\
	if(atIndex<0) {\
		for(int i=0;i<=X;i++) {\
			Y[i]=assignToNum+i;\
			if(Y[i]==X) X-=Y[i];\
		}\
	}\
	else if(atIndex>X-1) {\
		Y[X]=assignToNum;\
		X-=1;/*One less bit*/\
	}\
	else Y[atIndex]=assignToNum;X-=1;/*One less bit*/\
} else {\
	printf("Cannot assign any more numbers to the array. It is of max length.\n");\
}

#define MAX_STRING_LENGTH     9000
#define MAX_BIT_SIZE          99999999

static char CopiedString[MAX_STRING_LENGTH]; /*9000 is the total length of a string allowed*/
/*
    This macro takes in a string, an array of integers, parses through each character
    of the string as a "bit", then assigns that index, or "bit", minus one into the
    byteOutput of that character index.
    
    Then, if byteOutput[0] is -1(which it should always be -1), it will parse through the string
    again, only then adding in 2 bits of memory both being zero.
    
    If StrictBit is true, then the macro will check for MAX_BIT_SIZE, and if the total bit size passes
    MAX_BIT_SIZE, everything is going to be reset
*/
#define MakeByte(outOfString,byteOutput,StrictBit,bytesAfter) \
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
		if(Total<50) {\
			fprintf(stderr,"\033[0;31mERR on line %d\nBits below 50\nInstead got %d bits\n",__LINE__,Total);\
			exit(EXIT_FAILURE);\
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
            bytesAfter=Total/8;\
            printf("TOTAL BITS: %d\nBYTES:%d",Total,Total/8);\
        }\
    } else {\
        bytesAfter=Total/8;\
        printf("TOTAL BITS: %d\nBYTES:%d",Total,Total/8);\
    }

static int MemAbstTotal;
/* 
    You can either add bytes or remove bytes.
    If you have array that is already storing data, and want to use,
    then you can..but all data will be released and new memory will be assigned.
*/
#define MemoryAbstract(bytes,fromBit,outcomeBytes,returnAsBits) \
/*Making bytes into bits*/\
if(outcomeBytes==NULL) outcomeBytes=malloc(bytes*sizeof(int));\
/* Allocating block of memory anyway, just in case of repetition*/\
else {\
    free(outcomeBytes);\
    outcomeBytes=malloc(bytes*sizeof(int));\
}\
static int Err;\
if(fromBit+bytes<=0) {\
  Err=1;\
}\
if(Err!=1) {\
  for(int i = 0; i < bytes; i++) {\
      /* Always adds, if negative..will subtract */\
      outcomeBytes[i]=i+fromBit;\
      /* Checking for negatives */\
      if(outcomeBytes[i]<=0) {\
          outcomeBytes=malloc(bytes+outcomeBytes[i]*sizeof(int));\
          if(!(i+fromBit<=0)) outcomeBytes[i]=i+fromBit;\
          continue;\
      }\
      /* For some reason it always comes one off, so we just defaulty add one */\
      if(i==bytes-1) MemAbstTotal+=outcomeBytes[i]+1;\
  }\
  if(returnAsBits) printf("\n\nTotal bits(out of %d bytes): %d\nTotal bits after(out of %d bytes): %d\n\n",bytes,bytes*8,MemAbstTotal,MemAbstTotal*8);\
  printf("\nfrom: %d\nto: %d",bytes,MemAbstTotal);\
  /*Assigning bytes to the new ammount of bytes*/\
  bytes=MemAbstTotal;\
} else {\
  printf("\n\033[0;31mERR: value of fromBit(%d) subtracted into bytes(%d) returns value below zero, thusly returning %d\n",fromBit,bytes,fromBit+bytes);\
  exit(EXIT_FAILURE);\
}
