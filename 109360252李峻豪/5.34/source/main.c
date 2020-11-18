#include<stdio.h>
#include<stdlib.h>

int fun(int y, int z);

int main(void)
{
	int  y, z;
	
	printf("請輸入指數跟底數\n");
	scanf_s("%d%d", &y,&z);
	printf("%d\n", fun(y,z));
	system("pause");
	return 0;
}
int fun (int y,int z) 
{

	int a=1;
	for (int i = 1;i <= y;i++)
		a = z * a;
	return a;
	
}