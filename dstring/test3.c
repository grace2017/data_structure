#include <stdio.h>
#include <stdlib.h>

#include "dstring.h"

int main()
{
	PDString dstring_p = NULL;
	if(!DSTRING_create_empty(&dstring_p)) {
		printf("DSTRING_create failed \n");
		exit(0);
	}

	printf("len->%d, free->%d, buff->%s \n", DSTRING_len(dstring_p), DSTRING_avail(dstring_p), DSTRING_val(dstring_p));

	DSTRING_free(dstring_p);

	return 0;
}
