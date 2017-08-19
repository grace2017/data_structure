/*
	注意：
		1、非循环双向链表
		2、内容不得重复
*/

#ifndef __DLINK_LIST_H_
#define __DLINK_LIST_H_

#define __DEBUG

typedef int datatype;

struct dlink_node
{
	struct dlink_node	*prev;
	struct dlink_node	*next;
	datatype		data;
};

typedef struct dlink_node DLinkNode, *PDLinkNode;

typedef struct
{
	struct dlink_node	*top;
	struct dlink_node	*bottom;
	int			eleNum;
}DLinkList, *PDLinkList;

//创建结点
PDLinkNode DLL_create_node(datatype);

//创建双向链表
PDLinkList DLL_create();

//是否是空链表
int DLL_empty(PDLinkList);

//释放
void DLL_free_from_top(PDLinkList);

//获取链表头节点
PDLinkNode DLL_get_top(PDLinkList);

//获取链表尾节点
PDLinkNode DLL_get_bottom(PDLinkList);

//获取链表中的元素个数
int DLL_get_elenum(PDLinkList);

//获取上一个结点
PDLinkNode DLL_get_prev(PDLinkList, datatype);

//获取下一个结点
PDLinkNode DLL_get_next(PDLinkList, datatype);

//查找
PDLinkNode DLL_find(PDLinkList, datatype);

//添加
int DLL_add(PDLinkList, datatype);

//插入
int DLL_insert(PDLinkList, datatype, datatype);

//从头节点变量
void DLL_traverse_from_top(PDLinkList);

//从尾节点遍历
void DLL_traverse_from_bottom(PDLinkList);

//删除元素
int DLL_delete(PDLinkList, datatype);

#endif

