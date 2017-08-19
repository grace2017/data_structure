#include <stdio.h>
#include <stdlib.h>

#include "dstring.h"

int main()
{
	PDString dstring_p = NULL;
	if(!DSTRING_create(NULL, NULL)) {
		printf("DSTRING_create failed \n");
		exit(0);
	}

	return 0;
}
