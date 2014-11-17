/**
*pl0�ʷ���������
*��test.txt����
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

	printf("����\t���ʷ���\n");

	if (err = fopen_s(&in, "test.txt", "r"))											/*ֻ����ʽ��test.txt�ļ�*/
	{
		printf("Are you kiding me? I couldn't open the file!\n");
		return 0;
	}

	newchar = getc(in);

	while (newchar != EOF)																/*�����ַ�����������*/
	{
		if (newchar >= 'a' && newchar <= 'z')											/*���ؼ���or��ʶ��*/
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
				printf("�ؼ���\t");
				DispStr(word);
				continue;
			}
			else
			{
				printf("��ʶ��\t");
				DispStr(word);
				continue;
			}
		}

		else if (newchar == ' ' || newchar == '\n' || newchar == '\t')					/*���ո�*/
		{
			newchar = getc(in);
			continue;
		}

		else if (newchar >= '0' && newchar <= '9')
		{
			int i = 0;
			do{																			/*��ⳣ��*/
				if (i < WordMax)
				{
					word.data[i] = newchar;
					i++;
				}
				newchar = getc(in);
			} while (newchar >= '0' && newchar <= '9');
			word.length = i;
			printf("����\t");
			DispStr(word);
			continue;
		}

		else if (newchar == ',' || newchar == '.' || newchar == ';' || newchar == '(' || newchar == ')')	/*�����*/
		{
			printf("���\t%c\n", newchar);
			newchar = getc(in);
			continue;
		}

		else if (newchar == '+' || newchar == '-' || newchar == '*' || newchar == '/' || newchar == '=')		/*��ⵥ�ַ������*/
		{
			printf("�����\t%c\n", newchar);
			newchar = getc(in);
			continue;
		}

		else if (newchar == ':')															/*��� := */
		{
			newchar = getc(in);
			if (newchar == '=')
			{
				printf("�����\t:=\n");
				newchar = getc(in);
				continue;
			}
			else
			{
				printf("��Ч�ַ�\t:\n");
				continue;
			}
		}

		else if (newchar == '>')															/*��� >= or > */
		{
			newchar = getc(in);
			if (newchar == '=')
			{
				printf("�����\t>=\n");
				newchar = getc(in);
				continue;
			}
			else
			{
				printf("�����\t>\n");
				continue;
			}
		}

		else if (newchar == '<')															/*��� <= or < */
		{
			newchar = getc(in);
			if (newchar == '=')
			{
				printf("�����\t<=\n");
				newchar = getc(in);
				continue;
			}
			else
			{
				printf("�����\t<\n");
				continue;
			}
		}

		else																				/*��Ч�ַ�*/
		{
			printf("��Ч�ַ�\t%c\n", newchar);
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