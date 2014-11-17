#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50

typedef struct
{
	char data[MaxSize];
	int length;
} SqString;

void StrAssign(SqString &s, char *cstr);
void StrCopy(SqString &s, SqString t);
bool StrEqual(SqString s, SqString t);
int StrLength(SqString s);
SqString Concat(SqString s, SqString t);
void DispStr(SqString s);

int main(void)
{
	SqString s, t, pro;
	char sstr[] = "another";
	char tstr[] = "home";
	StrAssign(t, tstr);
	printf("Prediction: home\n");
	DispStr(t);
	StrCopy(s, t);
	printf("Prediction: home\n");
	DispStr(s);
	printf("Prediction: Equal!\n");
	StrEqual(s, t) ? printf("Equal!\n") : printf("Not equal!\n");
	printf("Prediction: Length: 4\n");
	printf("Length: %d\n", StrLength(t));
	StrAssign(s, sstr);
	pro = Concat(s, t);
	printf("Prediction: anotherhome\n");
	DispStr(pro);

	return 0;
}

//将一个字符串常量赋给串s
void StrAssign(SqString &s, char *cstr)
{
	int i;
	for (i = 0; cstr[i] != '\0'; i++)
		s.data[i] = cstr[i];
	s.length = i;
}

//将串t复制给s
void StrCopy(SqString &s, SqString t)
{
	for (int i = 0; i < t.length; i++)
		s.data[i] = t.data[i];
	s.length = t.length;
}

//判断串相等
bool StrEqual(SqString s, SqString t)
{
	if (s.length != t.length)
		return false;
	else
	{
		for (int i = 0; i < s.length; i++)
		{
			if (s.data[i] != t.data[i])
				return false;
		}
	}
	return true;
}

//求串长
int StrLength(SqString s)
{
	return s.length;
}

//串连接
SqString Concat(SqString s, SqString t)
{
	SqString str;
	int i;
	str.length = s.length + t.length;
	for (i = 0; i < s.length; i++)
	{
		str.data[i] = s.data[i];
	}
	for (i = 0; i < t.length; i++)
	{
		str.data[s.length + i] = t.data[i];
	}
	return str;
}

//输出串
void DispStr(SqString s)
{
	if (s.length > 0)
	{
		for (int i = 0; i < s.length; i++)
		{
			printf("%c", s.data[i]);
		}
		printf("\n");
	}
	else
		printf("Nothing! Are you kiding me?");
}
