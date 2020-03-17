#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

enum accountable {Start=0, end=1};

static char * database_names[] = {"aidan"};

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

static int * check_mated(checker *ch) {
	static bool tathered;
	db_delay db;

	if(db.mate_id == ch->chc_mod.mod_one.id) {
		tathered = true;
		sprintf(database_names[db.mate_id],"rando_db_%d",rand());
		printf("Done\n\tDATABASE:\t%s\n\tTATHERED:\t%s",database_names[db.mate_id],(tathered) ? "TRUE" : "FALSE");
	} else {
		tathered = false;
		database_names[db.mate_id] = "NO_DATABASE_AVAILABLE";
		printf("Done\n\tDATABASE:\t%s\n\tTATHERED:\t%s",database_names[db.mate_id],(tathered) ? "TRUE" : "FALSE");
	}

	return 0;
}

int * set_mated_id(int mated_id) {

	db_delay db;

	db.mate_id = mated_id;

	return 0;
}

checker *s(checker *s, int mated_id) {

	s->checked = true;
	s->chc_mod.mod_one.id = 0;

	db_delay db;

	set_mated_id(mated_id);

	check_mated(s);
	
	return 0;
}
