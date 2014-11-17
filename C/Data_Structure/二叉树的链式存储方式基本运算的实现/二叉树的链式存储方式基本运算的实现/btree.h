#define ElemType char
#define MaxSize 70

typedef struct node
{
	ElemType data;
	struct node * lchild;
	struct node * rchild;
} BTNode;