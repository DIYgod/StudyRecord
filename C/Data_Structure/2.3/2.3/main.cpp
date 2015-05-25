#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50

typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int length;
}SqList;

void CreateList(SqList *&L, ElemType a[], int n);
void DispList(SqList *L);
void MoveData(SqList *&L);

int main(void)
{
	ElemType web[7] = { 3, -7, 9, -6, 8, -5, 1 };
	SqList *sitename;
	CreateList(sitename, web, 7);
	DispList(sitename);
	MoveData(sitename);
	DispList(sitename);
}

//建立顺序表
void CreateList(SqList *&L, ElemType a[], int n)
{
	L = (SqList *)malloc(sizeof(SqList));
	for (int i = 0; i < n; i++)
	{
		L->data[i] = a[i];
	}
	L->length = n;
}

//输出线性表
void DispList(SqList *L)
{
	for (int i = 0; i < L->length; i++)
	{
		printf("%d ", L->data[i]);
	}
	printf("\n");
}

//将所有小于0的元素移到所有大于0的元素的前面
void MoveData(SqList *&L)
{
	int i = 0, j = L->length - 1;
	int pivot = L->data[0];
	while (i < j)
	{
		while (i < j && L->data[j] >= 0)
		{
			j--;
		}
		L->data[i] = L->data[j];
		i++;
		while (i < j && L->data[i] < 0)
		{
			i++;
		}
		L->data[j] = L->data[i];
		j--;
	}
	L->data[i] = pivot;
}