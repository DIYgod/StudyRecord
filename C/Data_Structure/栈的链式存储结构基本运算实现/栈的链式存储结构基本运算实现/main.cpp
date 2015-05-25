#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct linknode
{
	ElemType data;
	struct linknode * next;
} LiStack;

void InitStack(LiStack * &s);
void DestroyStack(LiStack * &s);
bool StackEmpty(LiStack * s);
void Push(LiStack * &s, ElemType e);
bool Pop(LiStack * &s, ElemType &e);
bool GetTop(LiStack * s, ElemType &e);

int main(void)
{
	LiStack *s;
	ElemType e;
	InitStack(s);
	StackEmpty(s) ? printf("Empty!\n") : printf("Not empty!\n");
	Push(s, 'a');
	Push(s, 'n');
	Push(s, 'o');
	Push(s, 't');
	Push(s, 'h');
	Push(s, 'e');
	Push(s, 'r');
	Pop(s, e);
	Pop(s, e);
	StackEmpty(s) ? printf("Empty!\n") : printf("Not empty!\n");
	GetTop(s, e);
	printf("Top : %c\n", e);
	DestroyStack(s);

	return 0;
}

void InitStack(LiStack * &s)
{
	s = (LiStack *)malloc(sizeof(LiStack));
	s->next = NULL;
}

void DestroyStack(LiStack * &s)
{
	LiStack * p = s, *q = s->next;
	while (q != NULL)
	{
		free(p);
		p = q;
		q = p->next;
	}
	free(p);
}

bool StackEmpty(LiStack * s)
{
	return (s->next == NULL);
}

void Push(LiStack * &s, ElemType e)
{
	LiStack * p;
	p = (LiStack *)malloc(sizeof(LiStack));
	p->data = e;
	p->next = s->next;
	s->next = p;
}

bool Pop(LiStack * &s, ElemType &e)
{
	if (s->next == NULL)
		return false;
	LiStack * p;
	p = s->next;
	e = p->data;
	s->next = p->next;
	free(p);
	return true;
}

bool GetTop(LiStack * s, ElemType &e)
{
	if (s->next == NULL)
		return false;
	e = s->next->data;
	return true;
}