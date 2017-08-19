#include <stdio.h>
#include "dlink_list.h"

int main()
{
	PDLinkList dlink_list_p = DLL_create();

	DLL_add(dlink_list_p, 10);
	DLL_add(dlink_list_p, 20);
	DLL_add(dlink_list_p, 30);
	DLL_add(dlink_list_p, 40);
	DLL_add(dlink_list_p, 50);

	PDLinkNode node_p = DLL_find(dlink_list_p, 30);
	printf("%d \n", node_p->data);

	DLL_free_from_top(dlink_list_p);
	
	return 0;
}
