#include<stdio.h>
#include<stdlib.h>

int main()
{
	int x, y,z;
	printf("請輸入兩數\n");
	scanf_s("%d %d", &x, &y);
	for ( z = 1;z >= 1;z++)
	{
		if (z %x == 0 && z % y == 0)
		break;
	}
	printf("兩數最小公倍數為%d",z);
	system("pause");
	return 0;







}