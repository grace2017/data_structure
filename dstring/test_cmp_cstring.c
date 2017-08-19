#include <stdio.h>
#include <stdlib.h>

#include "dstring.h"

int main()
{
	PDString dstring_p = NULL;
	DSTRING_create(&dstring_p, "hello");

	printf("len->%d, free->%d, buff->%s \n", DSTRING_len(dstring_p), DSTRING_avail(dstring_p), DSTRING_val(dstring_p));

	if(0 == DSTRING_cmp_cstring(dstring_p, "hello")) {
		printf("相等 \n");
	}

	DSTRING_free(dstring_p);

	return 0;
}
