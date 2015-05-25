#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50

typedef char ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int front, rear;
} SqQueue;

void InitQueue(SqQueue * &q);
void DestroyQueue(SqQueue * &q);
bool QueueEmpty(SqQueue * q);
bool enQueue(SqQueue * &q, ElemType e);
bool deQueue(SqQueue * &q, ElemType &e);
void DispQueue(SqQueue * q);

int main(void)
{
	SqQueue *q;
	ElemType e;
	InitQueue(q);
	QueueEmpty(q) ? printf("Empty!\n") : printf("Not empty!\n");
	DispQueue(q);
	enQueue(q, 'a');
	enQueue(q, 'n');
	enQueue(q, 'o');
	enQueue(q, 't');
	enQueue(q, 'h');
	enQueue(q, 'e');
	enQueue(q, 'r');
	deQueue(q, e);
	deQueue(q, e);
	QueueEmpty(q) ? printf("Empty!\n") : printf("Not empty!\n");
	DispQueue(q);
	DestroyQueue(q);

	return 0;
}

//初始化队列
void InitQueue(SqQueue * &q)
{
	q = (SqQueue *)malloc(sizeof(SqQueue));
	q->front = q->rear = -1;
}

//销毁队列
void DestroyQueue(SqQueue * &q)
{
	free(q);
}

//判断队列是否为空
bool QueueEmpty(SqQueue * q)
{
	return (q->front == q->rear);
}

//进队列
bool enQueue(SqQueue * &q, ElemType e)
{
	if (q->rear == MaxSize - 1)
		return false;
	q->rear++;
	q->data[q->rear] = e;
	return true;
}

//出队列
bool deQueue(SqQueue * &q, ElemType &e)
{
	if (q->front == q->rear)
		return false;
	q->front++;
	e = q->data[q->front];
	return true;
}

//输出队列
void DispQueue(SqQueue * q)
{
	if (q->front == q->rear)
		printf("SqQueue is empty!\n");
	else
	{
		for (int i = q->front; i <= q->rear; i++)
			printf("%c", q->data[i]);
		printf("\n");
	}
}