#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50

typedef char ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode *prior;
	struct LNode *next;
} DLinkList;

void CreateListF(DLinkList *&L, ElemType a[], int n);
void CreateListR(DLinkList *&L, ElemType a[], int n);
void DispList(DLinkList *L);
bool ListInsert(DLinkList *&L, int i, ElemType e);
bool ListDelete(DLinkList *&L, int i, ElemType &e);

int main(void)
{
	ElemType site[11] = { 'a', 'n', 'o', 't', 'h', 'e', 'r', 'h', 'o', 'm', 'e' };
	DLinkList *LinkF, *LinkR;
	ElemType e = 'd';

	CreateListF(LinkF, site, 11);
	CreateListR(LinkR, site, 11);
	DispList(LinkF);
	DispList(LinkR);
	ListInsert(LinkF, 2, e);
	DispList(LinkF);
	ListDelete(LinkF, 3, e);
	DispList(LinkF);

	return 0;
}

//头插法建表
void CreateListF(DLinkList *&L, ElemType a[], int n)
{
	DLinkList *s;
	L = (DLinkList *)malloc(sizeof(DLinkList));
	L->prior = L->next = NULL;
	for (int i = 0; i < n; i++)
	{
		s = (DLinkList *)malloc(sizeof(DLinkList));
		s->data = a[i];
		s->next = L->next;
		if (L->next != NULL)
		{
			L->next->prior = s;
		}
		L->next = s;
		s->prior = L;
	}
}

//尾插法建表
void CreateListR(DLinkList *&L, ElemType a[], int n)
{
	DLinkList *s, *r;
	L = (DLinkList *)malloc(sizeof(DLinkList));
	r = L;
	for (int i = 0; i < n; i++)
	{
		s = (DLinkList *)malloc(sizeof(DLinkList));
		s->data = a[i];
		s->prior = r;
		r->next = s;
		r = s;
	}
	r->next = NULL;
}

//输出线性表
void DispList(DLinkList *L)
{
	DLinkList *p = L->next;
	while (p != NULL)
	{
		printf("%c", p->data);
		p = p->next;
	}
	printf("\n");
}

//插入数据元素
bool ListInsert(DLinkList *&L, int i, ElemType e)
{
	int j = 0;
	DLinkList *p = L, *s;
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
		s = (DLinkList *)malloc(sizeof(DLinkList));
		s->data = e;
		s->next = p->next;
		if (p->next != NULL)
		{
			p->next->prior = s;
		}
		s->prior = p;
		p->next = s;
		return true;
	}
}

//删除数据元素
bool ListDelete(DLinkList *&L, int i, ElemType &e)
{
	int j = 0;
	DLinkList *p = L, *s;
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
		if (p->next == NULL)
		{
			p->next->prior = p;
		}
		free(s);
		return true;
	}
}