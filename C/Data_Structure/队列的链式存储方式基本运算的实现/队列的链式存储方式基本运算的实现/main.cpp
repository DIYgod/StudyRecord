#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct qnode
{
	ElemType data;
	struct qnode * next;
} QNode;
typedef struct
{
	QNode * front;
	QNode * rear;
} LiQueue;

void InitQueue(LiQueue * &q);
void DestroyQueue(LiQueue * &q);
bool QueueEmpty(LiQueue * q);
void enQueue(LiQueue * &q, ElemType e);
bool deQueue(LiQueue * &q, ElemType &e);
void DispQueue(LiQueue * q);

int main(void)
{
	LiQueue *q;
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
void InitQueue(LiQueue * &q)
{
	q = (LiQueue *)malloc(sizeof(LiQueue));
	q->front = q->rear = NULL;
}

//销毁队列
void DestroyQueue(LiQueue * &q)
{
	QNode * p = q->front, * r;
	if (p != NULL)
	{
		r = p->next;
		while (r != NULL)
		{
			free(p);
			p = r;
			r = p->next;
		}
		free(p);
		free(q);
	}
}

//判断队列是否为空
bool QueueEmpty(LiQueue * q)
{
	return (q->front == NULL);
}

//进队列
void enQueue(LiQueue * &q, ElemType e)
{
	QNode * p;
	p = (QNode *)malloc(sizeof(QNode));
	p->data = e;
	p->next = NULL;
	if (q->front == NULL)
		q->front = q->rear = p;
	else
	{
		q->rear->next = p;
		q->rear = p;
	}
}

//出队列
bool deQueue(LiQueue * &q, ElemType &e)
{
	QNode * t;
	if (q->front == NULL)
		return false;
	t = q->front;
	e = q->front->data;
	if (q->front == q->rear)
		q->front = q->rear = NULL;
	else
		q->front = q->front->next;
	free(t);
	return true;
}

//输出队列
void DispQueue(LiQueue * q)
{
	QNode * t = q->front;
	if (q->front == NULL)
		printf("SqQueue is empty!\n");
	else
	{
		while (t != NULL)
		{
			printf("%c", t->data);
			t = t->next;
		}
		printf("\n");
	}
}