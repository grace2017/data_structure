#include <stdio.h>
#include <stdlib.h>

#include "dstring.h"

int main()
{
	PDString dstring_p = NULL;

	DSTRING_create(&dstring_p, "hello");

	printf("len->%d, free->%d, buff->%s \n", DSTRING_len(dstring_p), DSTRING_avail(dstring_p), DSTRING_val(dstring_p));

	DSTRING_cover(dstring_p, "hi");
	printf("len->%d, free->%d, buff->%s \n", DSTRING_len(dstring_p), DSTRING_avail(dstring_p), DSTRING_val(dstring_p));

	DSTRING_free(dstring_p);

	return 0;
}
