#include<stdio.h>
#include<stdlib.h>

int main()
{
	char x;
	printf("請輸入英文字母\n");
	scanf_s("%c", &x);
	if(x >= 97)
		x= x - 32;
	else
		x = x + 32;
	printf("%c\n", x);
	system("pause");
	return 0;
}