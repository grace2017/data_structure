#ifndef __DSTRING_H_
#define __DSTRING_H_

typedef struct
{
	int	len;
	int	free;
	char	*buff;
}DString, *PDString;

//创建
int DSTRING_create(PDString *, const char *);

//创建空DString
int DSTRING_create_empty(PDString *);

//释放
void DSTRING_free(PDString);

//获取字节数
int DSTRING_len(PDString);

//获取剩余可用字节数
int DSTRING_avail(PDString);

//获取str
const char * DSTRING_val(PDString);

//清空
void DSTRING_clear(PDString);

//拼接c字符串
int DSTRING_cat_cstring(PDString, const char *);

//拼接DString
int DSTRING_cat_dstring(PDString, PDString);

//比较DString与c字符串
int DSTRING_cmp_cstring(PDString, const char *);

//比较两个DString
int DSTRING_cmp_dstring(PDString, PDString);

//将DString扩充至指定大小
int DSTRING_resize(PDString, int);

//覆盖
int DSTRING_cover(PDString, const char *);

#endif
