#include <stdio.h>
#include "OBJ.h"

typedef checker ob;

int main(void) {
	checker check;

	check.checked = true;

	s(&check,2);

	if(check.checked){
		check.chc_mod.mod_one.id = 0;
	} else {
		check.chc_mod.mod_two.label_id = 1;
	}
}
