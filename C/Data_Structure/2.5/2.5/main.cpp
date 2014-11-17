#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50

typedef char ElemType;
typedef struct LNode
{
	ElemType data;
	int freq;
	struct LNode *prior;
	struct LNode *next;
} DLinkList;

void CreateList(DLinkList *&L, ElemType a[], int n);
void DispList(DLinkList *L);
bool LocateNode(DLinkList *&L, ElemType e);
int main(void)
{
	ElemType site[11] = { 'a', 'n', 'o', 't', 'h', 'e', 'r', 'h', 'o', 'm', 'e' };
	DLinkList *Link;
	
	CreateList(Link, site, 11);
	DispList(Link);
	LocateNode(Link, 'n');
	LocateNode(Link, 'm');
	LocateNode(Link, 'n');
	LocateNode(Link, 'r');
	DispList(Link);

	return 0;
}

//β�巨����
void CreateList(DLinkList *&L, ElemType a[], int n)
{
	DLinkList *s, *r;
	L = (DLinkList *)malloc(sizeof(DLinkList));
	r = L;
	for (int i = 0; i < n; i++)
	{
		s = (DLinkList *)malloc(sizeof(DLinkList));
		s->data = a[i];
		s->prior = r;
		s->freq = 0;
		r->next = s;
		r = s;
	}
	r->next = NULL;
}

//������Ա�
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

//��Ԫ��ֵΪe�Ľڵ���freq��ֵ��1�������ڵ���򰴷���Ƶ�ʵݼ�
bool LocateNode(DLinkList *&L, ElemType e)
{
	DLinkList *p = L->next, *q = L->next;
	while (p != NULL && p->data != e)
	{
		p = p->next;
	}
	if (p == NULL)
	{
		return false;
	}
	else
	{
		p->freq++;
		p->prior->next = p->next;
		p->next->prior = p->prior;
		while (q->freq > p->freq)
		{
			q = q->next;
		}
		q->prior->next = p;
		p->prior = q->prior;
		q->prior = p;
		p->next = q;
	}
	return true;
}