#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50

typedef char ElemType;
typedef struct linknode
{
	ElemType data[MaxSize];
	int top;
} SqStack;

void InitStack(SqStack *&s);
void DestroyStack(SqStack *&s);
bool StackEmpty(SqStack *s);
bool Push(SqStack *&s, ElemType e);
bool Pop(SqStack *&s, ElemType &e);
bool GetTop(SqStack *s, ElemType &e);

int main(void)
{
	SqStack *s;
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

//��ʼ��ջ
void InitStack(SqStack *&s)
{
	s = (SqStack *)malloc(sizeof(SqStack));
	s->top = -1;
}

//����ջ
void DestroyStack(SqStack *&s)
{
	free(s);
}

//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(SqStack *s)
{
	return (s->top == -1);
}

//��ջ
bool Push(SqStack *&s, ElemType e)
{
	if (s->top == MaxSize - 1)
		return false;
	s->top++;
	s->data[s->top] = e;
	return true;
}

//��ջ
bool Pop(SqStack *&s, ElemType &e)
{
	if (s->top == -1)
		return false;
	e = s->data[s->top];
	s->top--;
	return true;
}

//ȡջ��Ԫ��
bool GetTop(SqStack *s, ElemType &e)
{
	if (s->top == -1)
		return false;
	e = s->data[s->top];
	return true;
}