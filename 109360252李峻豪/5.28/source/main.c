#include<stdio.h>
#include<stdlib.h>

int main()
{
	char x;
	printf("�п�J�^��r��\n");
	scanf_s("%c", &x);
	if(x >= 97)
		x= x - 32;
	else
		x = x + 32;
	printf("%c\n", x);
	system("pause");
	return 0;
}