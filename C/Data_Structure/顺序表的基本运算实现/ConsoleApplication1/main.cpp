#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50

typedef char ElemType;
typedef struct
{
	ElemType name[MaxSize];
	int length;
}SqList;

void CreateList(SqList *&L, ElemType a[], int n);
void InitList(SqList *&L);
void DestroyList(SqList *&L);
bool ListEmpty(SqList *L);
int ListLength(SqList *L);
void DispList(SqList *L);
bool GetElem(SqList *L, int i, ElemType &e);
int LocateElem(SqList *L, ElemType e);
bool ListInsert(SqList *&L, int i, ElemType e);
bool ListDelete(SqList *L, int i, ElemType &e);

int main(void)
{
	ElemType web[7] = { 'a', 'n', 'o', 't', 'h', 'e', 'r' };
	SqList *sitename;
	CreateList(sitename, web, 7);
	if (ListEmpty(sitename))
	{
		printf("List is empty\n");
	}
	else
	{
		printf("List isn't empty\n");
	}
	printf("ListLength: %d\n", ListLength(sitename));
	DispList(sitename);
	printf("The location of 't' is %d\n", LocateElem(sitename, 't'));
	ElemType a;
	GetElem(sitename, sitename->length, a);
	ListInsert(sitename, 1, a);
	DispList(sitename);
	ListDelete(sitename, 2, a);
	DispList(sitename);
}

//建立顺序表
void CreateList(SqList *&L, ElemType a[], int n)
{
	L = (SqList *)malloc(sizeof(SqList));
	for (int i = 0; i < n; i++)
	{
		L->name[i] = a[i];
	}
	L->length = n;
}

//初始化线性表
void InitList(SqList *&L)
{
	L = (SqList *)malloc(sizeof(SqList));
	L->length = 0;
}

//销毁线性表
void DestroyList(SqList *&L)
{
	free(L);
}

//判断线性表是否为空表
bool ListEmpty(SqList *L)
{
	return (L->length == 0);
}

//求线性表的长度
int ListLength(SqList *L)
{
	return (L->length);
}

//输出线性表
void DispList(SqList *L)
{
	for (int i = 0; i < L->length; i++)
	{
		printf("%c", L->name[i]);
	}
	printf("\n");
}

//求线性表中某个数据元素值
bool GetElem(SqList *L, int i, ElemType &e)
{
	if (i < 0 || i > L->length)
		return false;
	e = L->name[i - 1];
	return true;
}

//按元素值查找
int LocateElem(SqList *L, ElemType e)
{
	int i = 0;
	while (i < L->length && L->name[i] != e)
	{
		i++;
	}
	if (i == L->length)
		return 0;
	else
		return i + 1;
}

//插入数据元素
bool ListInsert(SqList *&L, int i, ElemType e)
{
	if (i < 0 || i > L->length)
		return false;
	i--;
	for (int j = L->length - 1; j > i - 1; j--)
	{
		L->name[j + 1] = L->name[j];
	}
	L->name[i] = e;
	L->length++;
	return true;
}

//删除数据元素
bool ListDelete(SqList *L, int i, ElemType &e)
{
	if (i < 0 || i > L->length)
		return false;
	i--;
	e = L->name[i];
	for (int j = i; j < L->length - 1; j++)
	{
		L->name[j] = L->name[j + 1];
	}
	L->length--;
	return true;
}