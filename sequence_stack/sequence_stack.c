/*
	注：
		使用top对栈元素进行操作时要减1，因为push后的top会自增1
*/

#include <stdio.h>
#include <stdlib.h>

#include "sequence_stack.h"

//创建栈
void
SSTACK_create(PSequenceStack *sstack_p)
{
	PSequenceStack tmp = (PSequenceStack)calloc(1, sizeof(SequenceStack));	
	if(NULL == tmp) {
		perror("calloc failed");

		exit(0);
	}

	tmp->top = 0;

	*sstack_p = tmp;
}

//监测是否为空
int
SSTACK_is_empty(PSequenceStack sstack_p)
{
	if(NULL == sstack_p) {
#ifdef __DEBUG
		printf("实参是空指针 \n");
#endif		
		return 0;
	}

	return (sstack_p->top > 0)? 0 : 1;
}

//设为空栈
void
SSTACK_set_empty(PSequenceStack sstack_p)
{
	if(NULL == sstack_p) {
#ifdef __DEBUG
                printf("实参是空指针 \n");
#endif
                return;
        };

	sstack_p->top = -1;
}

//压栈
int
SSTACK_push(PSequenceStack sstack_p, int val)
{
	if(NULL == sstack_p) {
#ifdef __DEBUG
                printf("实参是空指针 \n");
#endif
                return 0;
        };

	if(sstack_p->top >= (STACK_SIZE - 1)) {
#ifdef __DEBUG
                printf("%s(%d): 栈已满 \n", __FILE__, __LINE__);
#endif
		exit(0);
	}

	sstack_p->data[sstack_p->top++] = val;

	return val;
}

//出栈
int
SSTACK_pop(PSequenceStack sstack_p)
{
	if(NULL == sstack_p) {
#ifdef __DEBUG
                printf("实参是空指针 \n");
#endif
                return 0;
        };

	if(SSTACK_is_empty(sstack_p)) {
		return 0;
	}

	return sstack_p->data[--sstack_p->top];
}

//取栈顶元素
int
SSTACK_get_top(PSequenceStack sstack_p)
{
	if(NULL == sstack_p) {
#ifdef __DEBUG
                printf("实参是空指针 \n");
#endif
                return 0;
        };

	if(SSTACK_is_empty(sstack_p)) {
		return 0;
	} else {
		return sstack_p->data[sstack_p->top - 1];
	}
}

//遍历栈
void
SSTACK_traverse(PSequenceStack sstack_p)
{
	if(NULL == sstack_p) {
#ifdef __DEBUG
                printf("实参是空指针 \n");
#endif
                return;
        };

        int i = 0;
        for(; i<sstack_p->top; i++) {
                printf("%d->%d \n", i, sstack_p->data[i]);
        }
}
