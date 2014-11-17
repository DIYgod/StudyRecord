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
void DeleteData(SqList *&L, int x, int y);

int main(void)
{
	ElemType web[7] = { 3, 7, 9, 6, 8, 5, 1};
	SqList *sitename;
	CreateList(sitename, web, 7);
	DispList(sitename);
	DeleteData(sitename, 2, 6);
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
		printf("%d", L->data[i]);
	}
	printf("\n");
}

//删除元素值在[ x, y ]之间的所有元素
void DeleteData(SqList *&L, int x, int y)
{
	int k = 0;
	for (int i = 0; i < L->length; i++)
	{
		if (L->data[i] <= x || L->data[i] >= y)
		{
			L->data[k] = L->data[i];
			k++;
		}
	}
	L->length = k;
}