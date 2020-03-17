#include <stdio.h>
#include <stdlib.h>

#define exists_code 10
#define can_be_created 42

int return_msg;

int file_exists(char *file_name, char type[2]) {
	FILE *Check;

	if(type[0] == 'w') {
		printf("Cannot have type of w/wb for reading a file\n");
		exit(1);
	}
	Check = fopen(file_name,type);

	if(Check != NULL) {
		return_msg = 10;
	} else if(Check == NULL) {
		return_msg = 42;
	}
	return 0;
}

// Returns a string for the user to use printf("%s",fstatus());
char * fstatus(void) {

	if(return_msg == exists_code) {
		return "\nThe file already exists\n";
	} else if(return_msg == can_be_created) {
		return "\nThe file does not exist\n";
	}

	return 0;
}

// pfstatus prints the status and returns 0
int pfstatus(void) {
	if(return_msg == exists_code) {
		printf("\nThe file already exists\n");
	} else if(return_msg == can_be_created) {
		printf("\nThe file does not exist\n");
	}
	return 0;
}
