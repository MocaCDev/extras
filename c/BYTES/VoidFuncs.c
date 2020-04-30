#include "byteInfo.h"

/* 
	Every function declared in this file are for command-line-arguments.

	None return anything
*/

const char * const Types[] = {
	"-file",
	"-integer",
	"-strings",
	"-characters"
};

/* 
	Functions with no white space between them usually are for the same CLA(Command-Line-Argument)
*/
static int bytes=0; // zero by default
void CreateByte(int ofAmmount) {
	// CREATES ONE BYTE
	if(ofAmmount < 8) ofAmmount=8;
	bytes=ofAmmount/8;

	printf("Created Bytes: \t%d\n",bytes);
}

#if !defined(Bytes)
#define Bytes        bytes
#elif defined(Byted)
// RE-DEFINING
#undef Bytes
#define Bytes        bytes
#endif
void checkName(const char *checkFor) {
	int ErrStatus;
	for(int i = 0; i < 4; i++) {
		if(strcmp(checkFor,Types[i])==0) {

#ifdef Bytes
		ErrStatus=0;// Meaning it is successful
		break;
#endif
		}
	}
	if(ErrStatus==0) {
#if !defined(TYPE)
#define TYPE        checkFor
#endif
	}

	printf("Type assigned with %d bytes: \t%s\n\n",Bytes,TYPE);
}
