/**
*串的链式存储方式基本运算的实现
*
*----------Dragon be here!----------/
* 　　　┏┓　　　┏┓
* 　　┏┛┻━━━┛┻┓
* 　　┃　　　　　　　┃
* 　　┃　　　━　　　┃
* 　　┃　┳┛　┗┳　┃
* 　　┃　　　　　　　┃
* 　　┃　　　┻　　　┃
* 　　┃　　　　　　　┃
* 　　┗━┓　　　┏━┛
* 　　　　┃　　　┃神兽保佑
* 　　　　┃　　　┃代码无BUG！
* 　　　　┃　　　┗━━━┓
* 　　　　┃　　　　　　　┣┓
* 　　　　┃　　　　　　　┏┛
* 　　　　┗┓┓┏━┳┓┏┛
* 　　　　　┃┫┫　┃┫┫
* 　　　　　┗┻┛　┗┻┛
* ━━━━━━神兽出没━━━━━━
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct snode
{
	char data;
	struct snode * next;
} LiString;

void StrAssign(LiString * &s, char cstr[]);
void StrCopy(LiString * &s, LiString * t);
bool StrEqual(LiString * s, LiString * t);
int StrLength(LiString * s);
LiString * Concat(LiString * s, LiString * t);
void DispStr(LiString * s);

int main(void)
{
	LiString * s, * t, * pro;
	char sstr[] = "another";
	char tstr[] = "home";
	StrAssign(t, tstr);
	printf("Prediction: home\n");
	DispStr(t);
	StrCopy(s, t);
	printf("Prediction: home\n");
	DispStr(s);
	printf("Prediction: Equal!\n");
	StrEqual ? printf("Equal!\n") : printf("Not equal!\n");
	printf("Prediction: Length: 4\n");
	printf("Length: %d\n", StrLength(t));
	StrAssign(s, sstr);
	pro = Concat(s, t);
	printf("Prediction: anotherhome\n");
	DispStr(pro);

	return 0;
}

//将字符串常量cstr赋给串s
void StrAssign(LiString * &s, char cstr[])
{
	LiString * r, *p;
	s = (LiString *)malloc(sizeof(LiString));
	r = s;
	for (int i = 0; cstr[i] != '\0'; i++)
	{
		p = (LiString *)malloc(sizeof(LiString));
		p->data = cstr[i];
		r->next = p;
		r = p;
	}
	r->next = NULL;
}

//将串t复制给串s
void StrCopy(LiString * &s, LiString * t)
{
	LiString *p = t->next, *q, *r;
	s = (LiString *)malloc(sizeof(LiString));
	r = s;
	while (p != NULL)
	{
		q = (LiString *)malloc(sizeof(LiString));
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}
	r->next = NULL;
}

//判断串相等
bool StrEqual(LiString * s, LiString * t)
{
	LiString *p = s->next, *q = s->next;
	while (p != NULL && q != NULL && p->data == q->data)
	{
		p = p->next;
		q = q->next;
	}
	if (p == NULL && q == NULL)
		return true;
	else
		return false;
}

//求串长
int StrLength(LiString * s)
{
	int i = 0;
	LiString * p = s->next;
	while (p != NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}

//串连接
LiString * Concat(LiString * s, LiString * t)
{
	LiString * str, *r, *p, *q = s->next;
	str = (LiString *)malloc(sizeof(LiString));
	r = str;
	while (q != NULL)
	{
		p = (LiString *)malloc(sizeof(LiString));
		p->data = q->data;
		r->next = p;
		r = p;
		q = q->next;
	}
	q = t->next;
	while (q != NULL)
	{
		p = (LiString *)malloc(sizeof(LiString));
		p->data = q->data;
		r->next = p;
		r = p;
		q = q->next;
	}
	r->next = NULL;
	return str;
}

//输出串
void DispStr(LiString * s)
{
	LiString * p = s->next;
	while (p != NULL)
	{
		printf("%c", p->data);
		p = p->next;
	}
	printf("\n");
}