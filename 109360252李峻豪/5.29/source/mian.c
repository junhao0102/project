#include<stdio.h>
#include<stdlib.h>

int main()
{
	int x, y,z;
	printf("叫块ㄢ计\n");
	scanf_s("%d %d", &x, &y);
	for ( z = 1;z >= 1;z++)
	{
		if (z %x == 0 && z % y == 0)
		break;
	}
	printf("ㄢ计程そ计%d",z);
	system("pause");
	return 0;







}