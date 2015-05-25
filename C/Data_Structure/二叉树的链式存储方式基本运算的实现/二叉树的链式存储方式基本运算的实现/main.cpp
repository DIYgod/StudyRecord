#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

void CreateBTNode(BTNode *&b, char * str);
BTNode * FindNode(BTNode * b, ElemType e);
BTNode * LchildNode(BTNode * b);
BTNode * RchildNode(BTNode * b);
int BTNodeDepth(BTNode * b);
void DispBTNode1(BTNode * b);
void DispBTNode(BTNode * b);

int main(void)
{
	char str[] = "A(B(D(,G)),C(E,F))";
	BTNode * b, *blchild, *brchild, *find;
	ElemType e = 'E';

	CreateBTNode(b, str);
	DispBTNode(b);

	find = FindNode(b, e);
	blchild = LchildNode(b);
	brchild = RchildNode(b);
	DispBTNode(find);
	DispBTNode(blchild);
	DispBTNode(brchild);
	printf("BTNodeDepth: %d\n", BTNodeDepth(b));

	return 0;
}

//创建二叉树
void CreateBTNode(BTNode *&b, char * str)
{
	BTNode * St[MaxSize], * p;
	int top = -1, k = 0, i = 0;
	char ch = str[i];
	b = NULL;

	while (ch != '\0')
	{
		switch (ch)
		{
		case '(': 
			top++; 
			St[top] = p; 
			k = 1; 
			break;
		case ')': 
			top--; 
			break;
		case ',': 
			k = 2; 
			break;
		default: 
			p = (BTNode *)malloc(sizeof(BTNode));
			p->data = ch;
			p->lchild = p->rchild = NULL;
			if (b == NULL)
			{
				b = p;
			}
			else
			{
				switch (k)
				{
				case 1: 
					St[top]->lchild = p;
					break;
				case 2:
					St[top]->rchild = p;
					break;
				default:
					printf("Error!");
					return;
				}
			}
		}
		i++;
		ch = str[i];
	}
}

//查找节点
BTNode * FindNode(BTNode * b, ElemType e)
{
	BTNode * p;
	if (b == NULL)
		return NULL;
	else if (b->data == e)
		return b;
	else
	{
		p = FindNode(b->lchild, e);
		if (p != NULL)
			return p;
		else
			return FindNode(b->rchild, e);
	}
}

//找孩子节点
BTNode * LchildNode(BTNode * b)
{
	return b->lchild;
}

BTNode * RchildNode(BTNode * b)
{
	return b->rchild;
}

//求高度
int BTNodeDepth(BTNode * b)
{
	int lchildh, rchildh;
	if (b == NULL)
		return 0;
	else
	{
		lchildh = BTNodeDepth(b->lchild);
		rchildh = BTNodeDepth(b->rchild);
		return (lchildh > rchildh) ? (lchildh + 1) : (rchildh + 1);
	}
}

//输出二叉树
void DispBTNode1(BTNode * b)
{
	if (b != NULL)
	{
		printf("%c", b->data);
		if (b->lchild != NULL || b->rchild != NULL)
		{
			printf("(");
			DispBTNode1(b->lchild);
			if (b->rchild != NULL)
				printf(",");
			DispBTNode1(b->rchild);
			printf(")");
		}
	}
}

void DispBTNode(BTNode * b)
{
	DispBTNode1(b);
	printf("\n");
}