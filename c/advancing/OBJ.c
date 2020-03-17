#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "CHK.h"

enum accountable {Start=0, end=1};

static char * database_names[] = {"aidan"};
static char * append_db_names[] = {"RANDOM"};

extern int return_msg;

int * END(bool failed) {
	enum accountable a;
	if(!(failed)) {
		exit(a = Start);
	} else {
		printf("Exit from status 1\n");
		exit(a = end);
	}
	return 0;
}

typedef struct {
	bool checked;
	union {
		struct {
			int id;
		} mod_one;
		struct {
			int label_id;
		} mod_two;
	} chc_mod;
	union {
		int together_id;
	} tather;
} checker;

// meant for mating id
typedef struct {
	int mate_id;
	// this union will be used if mate_id is equal to mod_one id
	union {
		checker s;
	} mate;
} db_delay;

static void * write_stored_db_names(char *file_name, char type[2], char *db_names) {
	FILE *Write_Db_Names;

	if(type[0] == 'r') {
		printf("Cannot have type of r/rb for writing to a file\n");
		exit(1);
	} else {
		file_exists(file_name,"r");

		if(return_msg == 42) {
			Write_Db_Names = fopen(file_name, type);
			fwrite(db_names,sizeof(db_names),sizeof(db_names)/sizeof(db_names[0]),Write_Db_Names);
			fclose(Write_Db_Names);
		} else {
			return NULL;
		}
	}

	return 0;
}

static int * check_mated(checker *ch) {
	static bool tathered;
	static char new_db_name[50];
	db_delay db;

	if(db.mate_id == ch->chc_mod.mod_one.id) {
		tathered = true;
		if(database_names[db.mate_id] == NULL) {
			sprintf(new_db_name,"rand_db%d",rand()%4);
			append_db_names[0] = new_db_name;
			printf("Done\n\t\t\tRANDOMLY_GENERATED_DATABASE\n\tDATABASE:\t%s\n\tID TATHERED:\t%s",new_db_name,(tathered) ? "TRUE" : "FALSE");
		} else {
			printf("Done\n\t\tORIGINAL_GENERATED_DATABASE\n\tDATABASE:\t%s\n\tID TATHERED:\t%s",database_names[db.mate_id],(tathered) ? "TRUE" : "FALSE");
		}

	} else {
		tathered = false;
		database_names[db.mate_id] = "NO_DATABASE_AVAILABLE";
		append_db_names[0] = database_names[db.mate_id];
		printf("Done\n\t\tERROR_GENERATING_DATABASE\n\tDATABASE:\t%s\n\tTATHERED:\t%s",database_names[db.mate_id],(tathered) ? "TRUE" : "FALSE");
	}

	return 0;
}

int * set_mated_id(int mated_id) {

	db_delay db;

	db.mate_id = mated_id;

	return 0;
}

/* 
	Using this will check if the mated id is equal to the mod_one id.
	If there isn't, a database will not be picked up and will return
		"NO_DATABASE_AVAILABLE"
*/
checker *s(checker *s, int mated_id) {

	s->checked = true;
	s->chc_mod.mod_one.id = 10;

	db_delay db;

	set_mated_id(mated_id);

	check_mated(s);

	write_stored_db_names("d.datd","wb",*append_db_names);
	
	return 0;
}
