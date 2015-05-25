#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50

typedef char ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
} LinkList;

void CreateListF(LinkList *&L, ElemType a[], int n);
void CreateListR(LinkList *&L, ElemType a[], int n);
void InitList(LinkList *&L);
void DestroyList(LinkList *&L);
bool ListEmpty(LinkList *L);
int ListLength(LinkList *L);
void DispList(LinkList *L);
bool GetElem(LinkList *L, int i, ElemType &e);
int LocateElem(LinkList *L, ElemType e);
bool ListInsert(LinkList *&L, int i, ElemType e);
bool ListDelete(LinkList *&L, int i, ElemType &e);

int main(void)
{
	ElemType site[11] = { 'a', 'n', 'o', 't', 'h', 'e', 'r', 'h', 'o', 'm', 'e' };
	LinkList *Link, *LinkR;
	ElemType e;

	CreateListF(Link, site, 11);
	CreateListR(LinkR, site, 11);
	DispList(Link);
	DispList(LinkR);
	DestroyList(LinkR);
	if (ListEmpty(Link))
	{
		printf("List is empty\n");
	}
	else
	{
		printf("List isn't empty\n");
	}
	printf("ListLength: %d\n", ListLength(Link));
	GetElem(Link, ListLength(Link), e);
	ListInsert(Link, 2, e);
	DispList(Link);
	ListDelete(Link, 3, e);
	DispList(Link);
	printf("The location of 'o' is %d\n", LocateElem(Link, 'o'));
	DestroyList(Link);

	return 0;
}

//头插法建表
void CreateListF(LinkList *&L, ElemType a[], int n)
{
	LinkList *s;
	L = (LinkList *)malloc(sizeof(LinkList));
	L->next = NULL;
	for (int i = 0; i < n; i++)
	{
		s = (LinkList *)malloc(sizeof(LinkList));
		s->data = a[i];
		s->next = L->next;
		L->next = s;
	}
}

//尾插法建表
void CreateListR(LinkList *&L, ElemType a[], int n)
{
	LinkList *s, *r;
	L = (LinkList *)malloc(sizeof(LinkList));
	r = L;
	for (int i = 0; i < n; i++)
	{
		s = (LinkList *)malloc(sizeof(LinkList));
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
}

//初始化线性表
void InitList(LinkList *&L)
{
	L = (LinkList *)malloc(sizeof(LinkList));
	L->next = NULL;
}

//销毁线性表
void DestroyList(LinkList *&L)
{
	LinkList *pre = L, *p = pre->next;
	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(pre);
}

//判断线性表是否为空表
bool ListEmpty(LinkList *L)
{
	return (L->next == NULL);
}

//求线性表的长度
int ListLength(LinkList *L)
{
	int i = 0;
	LinkList *p = L;
	while (p->next != NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}

//输出线性表
void DispList(LinkList *L)
{
	LinkList *p = L->next;
	while (p != NULL)
	{
		printf("%c", p->data);
		p = p->next;
	}
	printf("\n");
}

//求线性表中某个数据元素值
bool GetElem(LinkList *L, int i, ElemType &e)
{
	if (i < 1 && i > ListLength(L))
	{
		return false;
	}
	int j = 0;
	LinkList *p = L;
	while (j < i && p->next != NULL)
	{
		j++;
		p = p->next;
	}
	e = p->data;
	return true;
}

//按元素值查找
int LocateElem(LinkList *L, ElemType e)
{
	int i = 0;
	LinkList *p = L->next;
	while (p->next != NULL && p->data != e)
	{
		p = p->next;
		i++;
	}
	if (p->next == NULL)
	{
		return 0;
	}
	else
	{
		return (i + 1);
	}
}

//插入数据元素
bool ListInsert(LinkList *&L, int i, ElemType e)
{
	int j = 0;
	LinkList *p = L, *s;
	while (j < i - 1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
	{
		return false;
	}
	else
	{
		s = (LinkList *)malloc(sizeof(LinkList));
		s->data = e;
		s->next = p->next;
		p->next = s;
		return true;
	}
}

//删除数据元素
bool ListDelete(LinkList *&L, int i, ElemType &e)
{
	int j = 0;
	LinkList *p = L, *s;
	while (j < i - 1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
	{
		return false;
	}
	else
	{
		s = p->next;
		if (s == NULL)
		{
			return false;
		}
		e = s->data;
		p->next = s->next;
		free(s);
		return true;
	}
}