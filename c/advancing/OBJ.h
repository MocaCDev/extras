#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

enum accountable {Start=1, end=0};
int * END(bool failed);

typedef struct {
	bool checked;
	enum accountable d;
	union {
		// if checked is true
		struct {
			int id;
		} mod_one;
		// if checked is false
		struct {
			int label_id;
		} mod_two;
	} chc_mod;
} checker;

// meant for mating id
typedef struct {
	int mate_id;
	// this union will be used if mate_id is equal to mod_one id
	union {
		checker s;
	} mate;
} db_delay;

int * set_mated_id(int mated_id);
checker *s(checker *s, int mated_id);
