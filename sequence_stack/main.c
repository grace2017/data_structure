#include <stdio.h>
#include <stdlib.h>
#include "sequence_stack.h"

int main()
{
	PSequenceStack sstack_p = NULL;
	SSTACK_create(&sstack_p);

	SSTACK_push(sstack_p, 1);
	SSTACK_push(sstack_p, 2);
	SSTACK_push(sstack_p, 3);

	printf("出栈元素：%d \n", SSTACK_pop(sstack_p));

	SSTACK_push(sstack_p, 4);
	SSTACK_push(sstack_p, 5);
	SSTACK_push(sstack_p, 6);
	SSTACK_push(sstack_p, 7);
	SSTACK_push(sstack_p, 8);

	printf("栈顶元素：%d \n", SSTACK_get_top(sstack_p));

	SSTACK_traverse(sstack_p);

	free(sstack_p);
	sstack_p = NULL;

	return 0;
}
