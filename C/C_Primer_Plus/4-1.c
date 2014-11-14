#include <stdio.h>

int main(viod)
{
    char fname[40], lname[40];

    printf("请输入您的名字和姓氏，用空格隔开\n");
    scanf("%s %s", fname, lname);
    printf("%s,%s", fname, lname);

    return 0;
}
