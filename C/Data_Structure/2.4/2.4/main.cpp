#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50

typedef char ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
} LinkList;

void CreateList(LinkList *&L, ElemType a[], int n);
void DestroyList(LinkList *&L);
void DispList(LinkList *L);
void Inverse(LinkList *&L);

int main(void)
{
	ElemType site[11] = { 'a', 'n', 'o', 't', 'h', 'e', 'r', 'h', 'o', 'm', 'e' };
	LinkList *Link;

	CreateList(Link, site, 11);
	DispList(Link);
	Inverse(Link);
	DispList(Link);
	DestroyList(Link);

	return 0;
}

//尾插法建表
void CreateList(LinkList *&L, ElemType a[], int n)
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

//将所有节点逆置
void Inverse(LinkList *&L)
{
	LinkList *p = L->next;
	ElemType a[50];
	int i;
	for (i = 0; p != NULL; i++)
	{
		a[i] = p->data;
		p = p->next;
	}
	p = L->next;
	for (int j = 0; p != NULL; j++)
	{
		p->data = a[i - 1 - j];
		p = p->next;
	}
}