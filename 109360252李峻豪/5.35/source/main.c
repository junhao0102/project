#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n = 0;
	printf("請輸入個數\n");
	scanf_s("%d", &n);
	int a = 0, b = 1,c;
	printf("0 1 ");
	for (int i = 1;i <= n-2;i++)
	{
		c = a + b;
		printf("%d ", c);
		a = b;
		b = c;
		
		
	}
}