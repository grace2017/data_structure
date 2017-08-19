#include <stdio.h>
#include <stdlib.h>
#include "dlink_list.h"

//创建节点
PDLinkNode
DLL_create_node(datatype val)
{
	PDLinkNode p = (PDLinkNode)calloc(1, sizeof(DLinkNode));	
	if(NULL == p) {
#ifdef __DEBUG
		printf("%s(%d): calloc failed \n", __FILE__, __LINE__);
#endif
		return NULL;
	}

	p->prev = p->next = NULL;
	p->data = val;

	return p;
}

//创建双向链表
PDLinkList
DLL_create()
{
	PDLinkList p = (PDLinkList)calloc(1, sizeof(DLinkList));
	if(NULL == p) {
#ifdef __DEBUG
		printf("%s(%d): calloc failed \n", __FILE__, __LINE__);
#endif
		return NULL;
	}

	p->top = DLL_create_node(0);
	p->top->prev = p->top->next = NULL;

	p->bottom = DLL_create_node(0);
	p->bottom->prev = p->bottom->next = NULL;

	p->top->next = p->bottom;
	p->bottom->prev = p->top;

	p->eleNum = 0;

	return p;
}

//是否空链表
int
DLL_empty(PDLinkList dlink_list_p)
{
	if(NULL == dlink_list_p) {
#ifdef __DEBUG
		printf("%s(%d): 实参是空指针 \n", __FILE__, __LINE__);
#endif	
		return -1;
	}

	return (dlink_list_p->bottom == dlink_list_p->top->next)? 1 : 0;
}

//释放
void
DLL_free_from_top(PDLinkList dlink_list_p)
{
	if(NULL == dlink_list_p) {
#ifdef __DEBUG
		printf("%s(%d): 实参为空指针 \n", __FILE__, __LINE__);
#endif
		return;
	}

	if(DLL_empty(dlink_list_p)) {
		free(dlink_list_p->top);
		free(dlink_list_p->bottom);

		free(dlink_list_p);

		return;
	}

	PDLinkNode current_p = dlink_list_p->top->next;
	while(current_p != dlink_list_p->bottom) {
		free(current_p);

                current_p = current_p->next;
        }

	free(dlink_list_p->top);
        free(dlink_list_p->bottom);

        free(dlink_list_p);
}

//添加
int
DLL_add(PDLinkList dlink_list_p, datatype val)
{
	if(NULL == dlink_list_p) {
#ifdef __DEBUG
                printf("%s(%d): 实参为空指针 \n", __FILE__, __LINE__);
#endif
                return 0;
        }

	PDLinkNode node_p = DLL_create_node(val);

	dlink_list_p->top->next->prev = node_p;
	
	node_p->next = dlink_list_p->top->next;
	node_p->prev = dlink_list_p->top;
	
	dlink_list_p->top->next = node_p;

	dlink_list_p->eleNum++;

	return 1;
}

//遍历
void
DLL_traverse_from_top(PDLinkList dlink_list_p)
{
	if(NULL == dlink_list_p) {
#ifdef __DEBUG
                printf("%s(%d): 实参为空指针 \n", __FILE__, __LINE__);
#endif
                return;
        }

	 if(DLL_empty(dlink_list_p)) {
                return;
        }

        PDLinkNode current_p = dlink_list_p->top->next;
	while(current_p != dlink_list_p->bottom) {
		printf("%d \n", current_p->data);

		current_p = current_p->next;
	}
}

//遍历
void
DLL_traverse_from_bottom(PDLinkList dlink_list_p)
{
	if(NULL == dlink_list_p) {
#ifdef __DEBUG
                printf("%s(%d): 实参为空指针 \n", __FILE__, __LINE__);
#endif
                return;
        }

         if(DLL_empty(dlink_list_p)) {
                return;
        }

        PDLinkNode current_p = dlink_list_p->bottom->prev;
        while(current_p != dlink_list_p->top) {
                printf("%d \n", current_p->data);

                current_p = current_p->prev;
        }
}

//查找
PDLinkNode
DLL_find(PDLinkList dlink_list_p, datatype dlink_node_val)
{
	if(NULL == dlink_list_p) {
#ifdef __DEBUG
                printf("%s(%d): 实参为空指针 \n", __FILE__, __LINE__);
#endif
                return NULL;
        }

         if(DLL_empty(dlink_list_p)) {
                return NULL;
        }

        PDLinkNode current_p = dlink_list_p->bottom->prev;
        while(current_p != dlink_list_p->top) {
                if(dlink_node_val == current_p->data) {
			return current_p;
		}

                current_p = current_p->prev;
        }

	return NULL;
}

//获取上一个节点
PDLinkNode
DLL_get_prev(PDLinkList dlink_list_p, datatype dlink_node_val)
{
	if(NULL == dlink_list_p) {
#ifdef __DEBUG
                printf("%s(%d): 实参为空指针 \n", __FILE__, __LINE__);
#endif
                return;
        }

	PDLinkNode node_p = DLL_find(dlink_list_p, dlink_node_val);
	if(NULL != node_p) {
		return node_p->prev;
	}

	return NULL;
}

//获取下一个节点
PDLinkNode
DLL_get_next(PDLinkList dlink_list_p, datatype dlink_node_val)
{
	if(NULL == dlink_list_p) {
#ifdef __DEBUG
                printf("%s(%d): 实参为空指针 \n", __FILE__, __LINE__);
#endif
                return;
        }

        PDLinkNode node_p = DLL_find(dlink_list_p, dlink_node_val);
        if(NULL != node_p) {
                return node_p->next;
        }

        return NULL;
}

//获取元素个数
int
DLL_get_elenum(PDLinkList dlink_list_p)
{
	if(NULL == dlink_list_p) {
#ifdef __DEBUG
                printf("%s(%d): 实参为空指针 \n", __FILE__, __LINE__);
#endif
                return 0;
        }

	return dlink_list_p->eleNum;
}

//删除元素
int
DLL_delete(PDLinkList dlink_list_p, datatype dlink_node_val)
{
	if(NULL == dlink_list_p) {
#ifdef __DEBUG
                printf("%s(%d): 实参为空指针 \n", __FILE__, __LINE__);
#endif
                return -1;
        }

        PDLinkNode node_p = DLL_find(dlink_list_p, dlink_node_val);
        if(NULL != node_p) {
                PDLinkNode node_prev = node_p->prev;
                PDLinkNode node_next = node_p->next;

		node_prev->next = node_next;
		node_next->prev = node_prev;

		free(node_p);

		dlink_list_p->eleNum--;

		return 1;
        } else {
        	return -1;
	}	
}

/*
	插入元素（指定节点后面插入）
*/
int
DLL_insert(PDLinkList dlink_list_p, datatype dlink_node_val, datatype val)
{
	if(NULL == dlink_list_p) {
#ifdef __DEBUG
                printf("%s(%d): 实参为空指针 \n", __FILE__, __LINE__);
#endif
                return -1;
        }

        PDLinkNode node_p = DLL_find(dlink_list_p, dlink_node_val);
        if(NULL != node_p) {
		PDLinkNode insert_node_p = DLL_create_node(val);
		insert_node_p->prev = node_p;
		insert_node_p->next = node_p->next;

		node_p->next->prev = insert_node_p;

		node_p->next = insert_node_p;

		dlink_list_p->eleNum++;

                return 1;
        } else {
                return -1;
        }
}
