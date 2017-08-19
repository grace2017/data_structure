#include <stdio.h>
#include <stdlib.h>

#include "dstring.h"

int main()
{
	PDString dstring_p = NULL;
	if(!DSTRING_create(&dstring_p, "hello")) {
		printf("DSTRING_create failed \n");
		exit(0);
	}

	DSTRING_cat_cstring(dstring_p, " world");

	printf("len->%d, free->%d, buff->%s \n", DSTRING_len(dstring_p), DSTRING_avail(dstring_p), DSTRING_val(dstring_p));

	DSTRING_free(dstring_p);

	return 0;
}
