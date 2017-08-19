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

	DLL_insert(dlink_list_p, 30, 70);

	DLL_traverse_from_top(dlink_list_p);

	printf("%d \n", DLL_get_elenum(dlink_list_p));

	DLL_free_from_top(dlink_list_p);
	
	return 0;
}
