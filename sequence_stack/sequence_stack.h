#ifndef __SEQUENCE_STACK_H_
#define __SEQUENCE_STACK_H_

#define __DEBUG
#define STACK_SIZE 0x10

typedef struct
{
	int	top;
	int	data[STACK_SIZE];
}SequenceStack, *PSequenceStack;

//创建栈
void SSTACK_create(PSequenceStack *);

//监测是否为空
int SSTACK_is_empty(PSequenceStack);

//设为空栈
void SSTACK_set_empty(PSequenceStack);

//压栈
int SSTACK_push(PSequenceStack, int);

//出栈
int SSTACK_pop(PSequenceStack);

//取栈顶元素
int SSTACK_get_top(PSequenceStack);

//遍历栈
void SSTACK_traverse(PSequenceStack);

#endif
