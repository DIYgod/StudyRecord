/**
*pl0词法分析程序
*从test.txt输入
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#define WordMax 10
#define KeyWordCount 13
#define KeyWordMax 10


typedef struct
{
	char data[KeyWordMax];
	int length;
} SqString;

bool is_Keyword(char *);
void DispStr(SqString s);

int main(void)
{
	FILE *in;
	char newchar;
	SqString word;
	errno_t err;

	printf("类型\t单词符号\n");

	if (err = fopen_s(&in, "test.txt", "r"))											/*只读方式打开test.txt文件*/
	{
		printf("Are you kiding me? I couldn't open the file!\n");
		return 0;
	}

	newchar = getc(in);

	while (newchar != EOF)																/*读入字符，分析类型*/
	{
		if (newchar >= 'a' && newchar <= 'z')											/*检测关键词or标识符*/
		{
			int i = 0;
			do{
				if (i < WordMax)
				{
					word.data[i] = newchar;
					i++;
				}
				newchar = getc(in);
			} while ((newchar >= 'a' && newchar <= 'z') || (newchar >= '0' && newchar <= '9'));
			word.length = i;
			if (is_Keyword(word.data))
			{
				printf("关键词\t");
				DispStr(word);
				continue;
			}
			else
			{
				printf("标识符\t");
				DispStr(word);
				continue;
			}
		}

		else if (newchar == ' ' || newchar == '\n' || newchar == '\t')					/*检测空格*/
		{
			newchar = getc(in);
			continue;
		}

		else if (newchar >= '0' && newchar <= '9')
		{
			int i = 0;
			do{																			/*检测常数*/
				if (i < WordMax)
				{
					word.data[i] = newchar;
					i++;
				}
				newchar = getc(in);
			} while (newchar >= '0' && newchar <= '9');
			word.length = i;
			printf("常数\t");
			DispStr(word);
			continue;
		}

		else if (newchar == ',' || newchar == '.' || newchar == ';' || newchar == '(' || newchar == ')')	/*检测界符*/
		{
			printf("界符\t%c\n", newchar);
			newchar = getc(in);
			continue;
		}

		else if (newchar == '+' || newchar == '-' || newchar == '*' || newchar == '/' || newchar == '=')		/*检测单字符运算符*/
		{
			printf("运算符\t%c\n", newchar);
			newchar = getc(in);
			continue;
		}

		else if (newchar == ':')															/*检测 := */
		{
			newchar = getc(in);
			if (newchar == '=')
			{
				printf("运算符\t:=\n");
				newchar = getc(in);
				continue;
			}
			else
			{
				printf("无效字符\t:\n");
				continue;
			}
		}

		else if (newchar == '>')															/*检测 >= or > */
		{
			newchar = getc(in);
			if (newchar == '=')
			{
				printf("运算符\t>=\n");
				newchar = getc(in);
				continue;
			}
			else
			{
				printf("运算符\t>\n");
				continue;
			}
		}

		else if (newchar == '<')															/*检测 <= or < */
		{
			newchar = getc(in);
			if (newchar == '=')
			{
				printf("运算符\t<=\n");
				newchar = getc(in);
				continue;
			}
			else
			{
				printf("运算符\t<\n");
				continue;
			}
		}

		else																				/*无效字符*/
		{
			printf("无效字符\t%c\n", newchar);
			newchar = getc(in);
			continue;
		}
	}
	system("PAUSE");
	return 0;
}

bool is_Keyword(char *word)
{
	char keyword[KeyWordCount][KeyWordMax] = { "begin", "call", "const", "do", "end", "if", "odd", "procedure", "read", "then", "var", "while", "write" };

	for (int i = 0; i < KeyWordCount; i++)
	{
		char *trueword = keyword[i];
		int length = strlen(trueword);
		int j;
		for (j = 0; j < length; j++){
			if (word[j] != trueword[j]) break;
		}
		if (j == length)
			return true;
	}
	return false;
}

void DispStr(SqString s)
{
	int i = 0;
	if (s.length > 0)
	{
		for (i = 0; i < s.length; i++)
		{
			printf("%c", s.data[i]);
		}
		printf("\n");
	}
}