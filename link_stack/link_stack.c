#include <stdio.h>
#include <stdlib.h>
#include "link_stack.h"

#define __DEBUG

//创建栈item
PLStackItem
LSTACK_create_item(datatype val, PLStackItem next)
{
	PLStackItem p = (PLStackItem)calloc(1, sizeof(LStackItem));
	if(NULL == p) {
		perror("calloc failed");

		exit(0);
	}

	p->data = val;
	p->next = next;

	return p;
}

//创建栈
PLStack LSTACK_create_stack()
{
	PLStack p = (PLStack)calloc(1, sizeof(LStack));
	if(NULL == p) {
                perror("calloc failed");

                exit(0);
        }

	p->top = p->bottom = NULL;

	return p;
}

//判断是不是空栈
int LSTACK_is_empty(PLStack lstack_p)
{
	return (NULL == lstack_p->top)? 1 : 0;
}

//设为空栈
void LSTACK_set_empty(PLStack lstack_p)
{
	LSTACK_free(lstack_p);

	lstack_p->top = lstack_p->bottom = NULL;
}

//入栈
PLStackItem LSTACK_push(PLStack lstack_p, datatype val)
{
	if(NULL == lstack_p) {
		printf("实参是空指针 \n");
	
		exit(0);
	}

	PLStackItem lstack_item_p = LSTACK_create_item(val, lstack_p->top);

	//如果是第一次入栈
	if(NULL == lstack_p->bottom) {
		lstack_p->bottom = lstack_item_p;
	}

	lstack_p->top = lstack_item_p;

	return lstack_item_p;
}

/*
	出栈

	注：出栈的item使用完后记得释放内存
*/
void
LSTACK_pop(PLStack lstack_p, PLStackItem *lstack_item_pp)
{
	if(NULL == lstack_p) {
                printf("实参是空指针 \n");

                exit(0);
        }

	if(LSTACK_is_empty(lstack_p)) return;

	PLStackItem tmp = lstack_p->top;

	lstack_p->top = lstack_p->top->next;

	if(NULL == lstack_item_pp) {
		free(tmp);
	} else {
		*lstack_item_pp = tmp;
	}
}

//遍历栈
void LSTACK_traverse(PLStack lstack_p)
{
	if(NULL == lstack_p) {
                printf("实参是空指针 \n");

                exit(0);
        }

	//如果是空栈，释放栈自身占据的内存
	if(LSTACK_is_empty(lstack_p)) {
		return;
	}

	PLStackItem current_p = lstack_p->top;
	while(1) {
		printf("traverse->%d \n", current_p->data);		

		if(current_p == lstack_p->bottom) {
			break;
		} else {
			current_p = current_p->next;
		}
	}
}

//释放栈
void
LSTACK_free(PLStack lstack_p)
{
	if(NULL == lstack_p) {
                printf("实参是空指针 \n");

                exit(0);
        }       

	//如果是空栈，释放栈自身占据的内存
	if(LSTACK_is_empty(lstack_p)) {
		free(lstack_p);
		return;
	}

        PLStackItem current_p = lstack_p->top;
        while(1) {
		if(NULL == current_p) break;

		free(current_p);          

		//如果只有一个元素
                if(current_p == lstack_p->bottom) {
			lstack_p->top = lstack_p->bottom = NULL;

                        break;  
                } else {       
                	if(NULL != current_p) {
				current_p = current_p->next;
			} else {
				current_p = NULL;
			}
		}
        }

	free(lstack_p);
}
