#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50

typedef char ElemType;
typedef struct linknode
{
	ElemType data[MaxSize];
	int top;
};

