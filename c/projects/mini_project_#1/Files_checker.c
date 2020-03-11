#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* 
	The function in between start and end are for the !!FILE ONLY!!
*/
// START: 
typedef struct {
	int *id;
	char *existing_file_name;
	char *official_id;
} exists;
// For struct exists
void * free_exists(exists *to_free) {
	free(&to_free->id);
	free(&to_free->existing_file_name);
	return 0;
}
void * write_file(char file_name[100], char type_[4], exists *to_write) {
	FILE *Write_To_File;

	if(type_[0] == 'r' || (type_[0] == 'r' && type_[1] == 'b')) {
		printf("Cannot have types of rb or r for function write_file\n");
	} else if(type_[0] != 'r' && type_[0] != 'w') {
		printf("\n\n\tTypes wb and w are used in the function write_file\n\tTypes rb and r cannot be used\n\tType %s cannot be used what so ever\n\nError: Type %s does not exists",type_,type_);
	} else {
		Write_To_File = fopen(file_name,type_);
		fprintf(Write_To_File,"ID~\t%d:\nFILE_NAME~\t%s:\nOFFICIA_ID~\t%s",to_write->id[0],to_write->existing_file_name,to_write->official_id);
		fclose(Write_To_File);
	}
	return 0;
}

// END

/*
	This function will return true if the file exists, else false.
	Please use scanf with this function
*/
bool file_exist(char file_name[100]) {
	FILE *Check;

	Check = fopen(file_name, "r");
	if(Check != NULL) {
		fclose(Check);
		return true;
	} else {
		return false;
	}
}

/* 
	If you like to be a little more complex, use this ffile_exists function.
	
	What does it do:
		If the file exists, it returns 0. If it doesn't exist it returns 5.
		If it exists, it will then be assigned an id through the struct "exists", and the name will be stored in the struct "exists". Then it will write into a file the existing information.
*/
int ffile_exists(char file_name[100]) {
	FILE *Check;
	exists ex;
	char changed[100];
	char of_id[50];

	ex.id = calloc(1,(sizeof(int)*150));
	ex.existing_file_name = malloc(sizeof(char)*sizeof(char)*40);
	ex.official_id = malloc(sizeof(char)*sizeof(char)*50);

	for(int i = 0; i < strlen(file_name); i++) {
		if(i%2 == 0) {
			changed[i] = '*';
		} else {
			changed[i] = '^';
		}
	}

	Check = fopen(file_name,"r");
	if(Check != NULL) {
		ex.id[0] = strlen(file_name)*sizeof(int);
		strcpy(ex.existing_file_name,file_name);
		sprintf(of_id,"%d~%s~%d",ex.id[0],changed,(int)ex.id[0]
		/4*2);
		strcpy(ex.official_id,of_id);

		write_file("data.dt", "wb",&ex);
		fclose(Check);
		return 0;
	} else {
		return sizeof(&file_name)*sizeof(char)-(sizeof(int)-sizeof(char));
	}
}
