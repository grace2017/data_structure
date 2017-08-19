#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dstring.h"

#define __DEBUG

//创建
int
DSTRING_create(PDString *dstring_pp, const char *str)
{
	if(NULL == dstring_pp) {
#ifdef __DEBUG
		printf("实参为空指针 \n");
#endif
		return -1;
	}

	PDString p = (PDString)calloc(1, sizeof(DString));
	if(NULL == p) {
#ifdef __DEBUG
		perror("calloc failed");
#endif
		return -1;
	}

	if(NULL == str) {
		p->buff = NULL;

		p->len = p->free = 0;
	} else {
		p->free = 0;
		p->len = strlen(str);

		p->buff = (char *)calloc(1, p->len + 1);
		if(NULL == p->buff) {
#ifdef __DEBUG
			printf("%s(%d): calloc failed. \n", __FILE__, __LINE__);
#endif
			return 0;
		}

		memcpy(p->buff, str, p->len + 1);
	}

	*dstring_pp = p;

	return 1;
}

//创建空DString
int
DSTRING_create_empty(PDString *dstring_pp)
{
	return DSTRING_create(dstring_pp, NULL);	
}

//释放
void
DSTRING_free(PDString dstring_p)
{
	if(NULL == dstring_p) return;

	if(NULL != dstring_p->buff) {
		free(dstring_p->buff);

		dstring_p->buff = NULL;
	}

	free(dstring_p);
	dstring_p = NULL;
}

//获取字节数
int
DSTRING_len(PDString dstring_p)
{
	if(NULL == dstring_p) return -1;

	return dstring_p->len;
}

//获取剩余可用字节数
int
DSTRING_avail(PDString dstring_p)
{
	if(NULL == dstring_p) return -1;

	return dstring_p->free;
}

//获取str
const
char *
DSTRING_val(PDString dstring_p)
{
	if(NULL == dstring_p) return NULL;

	return dstring_p->buff;
}

//清空
void
DSTRING_clear(PDString dstring_p)
{
	if(NULL == dstring_p) return;

	if(NULL != dstring_p->buff) {
		free(dstring_p->buff);

		dstring_p->buff = NULL;
	}

	dstring_p->free += dstring_p->len;
	dstring_p->len = 0;
}

/*
	监测是否需要扩容

	free: DString成员
	srcLen: 操作的字符串长度
*/
static
int
need_resize(int free, int srcLen)
{
	return (free > srcLen)? 0 : 1;
}

/*
	扩容
		超过1M，多分配1M
		不超过，双倍分配
*/
static
int
resize(PDString dstring_p, int len)
{
	if(NULL == dstring_p) return -1;

	int newLen = dstring_p->len + len;
	if(newLen > (1024 * 1024)) {
		newLen += 1024 * 1024;
	} else {
		newLen *= 2;
	}

	//用于存放结尾的\0
	newLen += 1;

	//新的buff
	char *tmp_p = (char *)calloc(1, newLen);
	if(NULL == tmp_p) {
#ifdef __DEBUG
		printf("%s(%d): calloc failed \n", __FILE__, __LINE__);
#endif
		return -1;
	}

	//将数据拷贝到新的buff中
	memcpy(tmp_p, dstring_p->buff, dstring_p->len);

	//释放老的buff
	free(dstring_p->buff);

	dstring_p->buff = tmp_p;

	//-1表示\0占的一字节
	dstring_p->free = newLen - dstring_p->len - 1;

	return 1;
}

//拼接c字符串
int
DSTRING_cat_cstring(PDString dstring_p, const char *str)
{
	if(NULL == dstring_p) return -1;

	int len = strlen(str);

	if(need_resize(dstring_p->free, len)) {
		if(-1 == resize(dstring_p, len)) {
#ifdef __DEBUG
			printf("%s(%d): 扩容失败 \n", __FILE__, __LINE__);
#endif			
			return -1;
		}
	}

	//+1表示拷贝\0
	memcpy((dstring_p->buff) + dstring_p->len, str, len + 1);

	dstring_p->len += len;
	dstring_p->free -= len;

	return 1;
}

/*
	拼接DString
*/
int
DSTRING_cat_dstring(PDString dstring_dest, PDString dstring_src)
{
	if((NULL == dstring_dest) || (NULL == dstring_src)) return -1;

	if(0 == dstring_src->len) return 1;

	int result = DSTRING_cat_cstring(dstring_dest, dstring_src->buff);

	DSTRING_free(dstring_src);

	return result;	
}

//对比DString与c字符串
int
DSTRING_cmp_cstring(PDString dstring_p, const char *str)
{
	if((NULL == dstring_p) || (NULL == str)) return -1;

	return strcmp(dstring_p->buff, str);
}

//对比两个DString
int
DSTRING_cmp_dstring(PDString dstring_p1, PDString dstring_p2)
{
	if((NULL == dstring_p1) || (NULL == dstring_p2)) return -1;

	return strcmp(dstring_p1->buff, dstring_p2->buff);
}

//将DString扩充至指定大小
int
DSTRING_resize(PDString dstring_p, int len)
{
	return resize(dstring_p, len);
}

//覆盖
int
DSTRING_cover(PDString dstring_p, const char *str)
{
	if((NULL == dstring_p) || (NULL == dstring_p->buff)) return -1;

	memset(dstring_p->buff, 0, dstring_p->len);

	dstring_p->free += dstring_p->len;
	dstring_p->len = 0;

	if(NULL != str) {
		memcpy(dstring_p->buff, str, strlen(str) + 1);
	}

	dstring_p->len = strlen(str);
	dstring_p->free -= dstring_p->len;

	return 1;
}
