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
void DispList(LinkList *L);
void Synthesis(LinkList *&L, LinkList *&R, int i);

int main(void)
{
	ElemType site[11] = { 'a', 'n', 'o', 't', 'h', 'e', 'r', 'h', 'o', 'm', 'e' };
	LinkList *LinkF, *LinkR;

	CreateListF(LinkF, site, 11);
	CreateListR(LinkR, site, 11);
	Synthesis(LinkR, LinkF, 2);
	DispList(LinkR);

	return 0;
}

//ͷ�巨����
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

//β�巨����
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

//������Ա�
void DispList(LinkList *L)
{
	LinkList *p = L->next;
	while (p != L)
	{
		printf("%c", p->data);
		p = p->next;
	}
	printf("\n");
}

//��R���뵽L�ĵ�i��Ԫ�غ��棬�ϲ�Ϊ��ͷ����ѭ�����б�
void Synthesis(LinkList *&L, LinkList *&R, int i)
{
	LinkList *p = L, *q = R->next;
	int count = 0;
	while (count < i && p->next != NULL)
	{
		p = p->next;
		count++;
	}
	LinkList *r = p->next, *s = q, *t = p;
	while (s->next != NULL)
	{
		s = s->next;
	}
	if (r = NULL)
	{
		s->next = L;
	}
	else
	{
		while (t->next != NULL)
		{
			t = t->next;
		}
		s->next = p->next;
		t->next = L;
	}
	p->next = q;
	free(R);
}