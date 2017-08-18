#ifndef __LINK_STACK_H_
#define __LINK_STACK_H_

typedef int datatype;

typedef struct list_stack_item LStackItem, *PLStackItem;

struct list_stack_item
{
	datatype	data;
	PLStackItem 	next;
};

typedef struct
{
	PLStackItem	top;
	PLStackItem	bottom;
}LStack, *PLStack;

//创建栈item
PLStackItem LSTACK_create_item(datatype, PLStackItem);

//创建栈
PLStack LSTACK_create_stack();

//判断是不是空栈
int LSTACK_is_empty(PLStack);

//设为空栈
void LSTACK_set_empty(PLStack);

//入栈
PLStackItem LSTACK_push(PLStack, datatype);

//出栈
void LSTACK_pop(PLStack, PLStackItem *);

//遍历栈
void LSTACK_traverse(PLStack);

//释放栈
void LSTACK_free(PLStack);

#endif
