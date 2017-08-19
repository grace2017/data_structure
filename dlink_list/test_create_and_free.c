#include <stdio.h>
#include "dlink_list.h"

int main()
{
	PDLinkList dlink_list_p = DLL_create();

	DLL_free_from_top(dlink_list_p);
	
	return 0;
}
