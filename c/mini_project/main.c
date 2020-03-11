#include <stdio.h>
#include <stdbool.h>
#include "Files_checker.h"
#include "iLog_setup.h"

int main(void) {
	char file[100];
	int c;

	printf("File: ");
	scanf("%s",file);

	int check = ffile_exists(file);
	printf("%d",check);

	if(file_exist(file)) {
		printf("Found!");
	} else {
		printf("Not Found");
	}
}
