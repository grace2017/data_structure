#include <stdio.h>
#include <stdlib.h>

#include "dstring.h"

int main()
{
	PDString dstring_p = NULL;
	PDString dstring_p2 = NULL;

	DSTRING_create(&dstring_p, "hello");
	DSTRING_create(&dstring_p2, " world");

	DSTRING_cat_dstring(dstring_p, dstring_p2);

	printf("len->%d, free->%d, buff->%s \n", DSTRING_len(dstring_p), DSTRING_avail(dstring_p), DSTRING_val(dstring_p));

	DSTRING_free(dstring_p);

	return 0;
}
