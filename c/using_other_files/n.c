#include <stdio.h>

static int *glob;
static int max_index;

char * password() {
	static char pass[100];
	
	scanf("%s",pass);

	return pass;
}

int * age(int len) {
	int ages[len];
	
	for(int i = 0; i < len; i++) {
		int number;

		printf("\nNumber #%d -> ",i+1);

		scanf("%d",&number);

		ages[i] = number;
	}

	glob = ages;
	max_index = len;

	return glob;
}

void print(int index) {
	if(index > max_index) {
		printf("Printing default index 0.\n%d",glob[0]);
	} else {
		printf("Found -> %d",glob[index]);
	}
}
