#include <stdio.h>
#include <stdlib.h>
#include "link_stack.h"

int main()
{
	PLStackItem lstack_item_p = NULL;

	PLStack lstack_p = LSTACK_create_stack();
printf("栈地址：%08X \n", lstack_p);

	LSTACK_push(lstack_p, 10);
	LSTACK_push(lstack_p, 20);

	LSTACK_pop(lstack_p, &lstack_item_p);	
	if(NULL != lstack_item_p) {
		printf("pop->%d \n", lstack_item_p->data);
		free(lstack_item_p);
	}

	LSTACK_push(lstack_p, 30);
//	LSTACK_push(lstack_p, 40);
//	LSTACK_push(lstack_p, 50);

	LSTACK_traverse(lstack_p);

	LSTACK_free(lstack_p);	

printf("free后栈地址：%08X \n", lstack_p);

//	遍历释放后的栈
//	LSTACK_traverse(lstack_p);

	return 0;
}
