#include <stdio.h>
#include<stdlib.h>

 char map[100] = {
		'~','~','~','~','~','~','~','~','~','~',
		'~','~','~','~','~','~','~','~','~','~',
		'~','~','~','~','~','~','~','~','~','~',
		'~','~','~','~','~','~','~','~','~','~',
		'~','~','~','~','~','~','~','~','~','~',
		'~','~','~','~','~','~','~','~','~','~',
		'~','~','~','~','~','~','~','~','~','~',
		'~','~','~','~','~','~','~','~','~','~',
		'~','~','~','~','~','~','~','~','~','~',
		'~','~','~','~','~','~','~','~','~','~'
};
int  PlayerLocation = 62, B1 = 61, B2 = 51, B3 = 41, T1 = 40, T2 = 60, T3 = 20;
int PrintMap(void);
int nextstep(char in);
int boxpushed(char i,int pl, int box1, int box2, int box3);
int targethit();
int goal();
int main(void)
{

	char input = ' ';
	map[PlayerLocation] = 'P', map[B1] = 'B', map[B2] = 'B', map[B3] = 'B', map[T1] = 'T', map[T2] = 'T', map[T3] = 'T';
	
	printf("把箱子B推到目標T以完成遊戲(T不能踩上去)\n");
	printf("請輸入指令:R(往右)L(往左)U(往上)D(往下)Q(離開)\n");
	PrintMap();
	
	while (1)
	{

		
		scanf_s(" %c", &input);
		if (input == 'Q')
		{
			break;
		}
		system("CLS");
		nextstep(input);
		targethit();
		printf("請輸入指令:R(往右)L(往左)U(往上)D(往下)Q(離開)\n");
		PrintMap();
		
		
		


	}
	system("pause");

	return 0;
}
int nextstep(in)
{
	switch (in)
	{
	case 'R':
		if (PlayerLocation % 10 ==9  
			|| (PlayerLocation % 10 == 8 && (PlayerLocation + 1 == B1 | PlayerLocation  +1 == B2 | PlayerLocation + 1 == B3))
			|| (B1 +1 == B2 || B2 + 1 == B1 || B1 + 1 == B3 || B3 + 1 == B1 || B2 + 1 == B3 || B3 + 1 == B2)&(PlayerLocation + 1 == B1 | PlayerLocation + 1 == B2 | PlayerLocation + 1 == B3)
			|| (PlayerLocation + 1 == T1 | PlayerLocation + 1 == T2 | PlayerLocation + 1 == T3))
		{
			printf("Can't move\n");
		}
		else
		{
			map[PlayerLocation] = '~';
			PlayerLocation += 1;
			boxpushed(in, PlayerLocation, B1, B2, B3);
		}
		
		break;
	case 'L':
		if (PlayerLocation % 10 == 0 
			|| (PlayerLocation % 10 == 1 && (PlayerLocation - 1 == B1 | PlayerLocation - 1 == B2 | PlayerLocation - 1 == B3))
			||(B1-1==B2|| B2 - 1 == B1 || B1 - 1 == B3 || B3 - 1 == B1 || B2 - 1 == B3 || B3 - 1 == B2)&(PlayerLocation - 1 == B1 | PlayerLocation - 1 == B2 | PlayerLocation - 1 == B3)
			|| (PlayerLocation - 1 == T1 | PlayerLocation - 1 == T2 | PlayerLocation - 1 == T3))
		{
			printf("Can't move\n");
		}
		else
		{

			map[PlayerLocation] = '~';
			PlayerLocation -= 1;
			boxpushed(in, PlayerLocation, B1, B2, B3);
		}
		break;
	case 'U':
		if (PlayerLocation - 10 <= 0 
			|| (PlayerLocation - 10 <= 10 && (PlayerLocation - 10 == B1 | PlayerLocation - 10 == B2 | PlayerLocation - 10 == B3))
			||( B1 - 10 == B2 || B2 - 10 == B1 || B1 - 10 == B3 || B3 - 10 == B1 || B2 - 10 == B3 || B3 - 10 == B2)&(PlayerLocation - 10 == B1 | PlayerLocation - 10 == B2 | PlayerLocation - 10 == B3)
			|| (PlayerLocation - 10 == T1 | PlayerLocation - 10 == T2 | PlayerLocation - 10 == T3))
		{
			printf("Can't move\n");
		}
		else
		{
			map[PlayerLocation] = '~';
			PlayerLocation -= 10;
			boxpushed(in, PlayerLocation, B1, B2, B3);
		}
		
		break;
	case 'D':
		if (PlayerLocation + 10 >=100
			|| (PlayerLocation + 10 >= 90 & (PlayerLocation + 10 == B1 | PlayerLocation + 10 == B2 | PlayerLocation + 10 == B3))
			|| (B1 + 10 == B2 || B2 + 10 == B1 || B1 + 10 == B3 || B3 + 10 == B1 || B2 + 10 == B3 || B3 + 10 == B2)&(PlayerLocation + 10 == B1 | PlayerLocation + 10 == B2 | PlayerLocation + 10 == B3)
			|| (PlayerLocation + 10 == T1 | PlayerLocation + 10 == T2 | PlayerLocation + 10 == T3))
		{
			printf("Can't move\n");
		}
		else
		{
			map[PlayerLocation] = '~';
			PlayerLocation += 10;
			boxpushed(in, PlayerLocation, B1, B2, B3);
		}
		
		break;
	case 'Q':
		break;
	}
	map[PlayerLocation] = 'P', map[B1] = 'B', map[B2] = 'B', map[B3] = 'B', map[T1] = 'T', map[T2] = 'T', map[T3] = 'T';
	return 0;
}
int boxpushed(char in,int pl, int box1, int box2, int box3)
{
	if (pl == box1)
	{
		switch (in)
		{
			case 'R':
				map[B1] = '~';
				B1+=1;
				break;
			case 'L':
				map[B1] = '~';
				B1 -= 1;
				break;
			case 'U':
				map[B1] = '~';
				B1 -= 10;
				break;
			case 'D':
				map[B1] = '~';
				B1 += 10;
				break;
		}
	}
	if (pl == box2)
	{
		switch (in)
		{
		case 'R':
			map[B2] = '~';
			B2 += 1;
			break;
		case 'L':
			map[B2] = '~';
			B2 -= 1;
			break;
		case 'U':
			map[B2] = '~';
			B2 -= 10;
			break;
		case 'D':
			map[B2] = '~';
			B2 += 10;
			break;
		}
	}
	if (pl == box3)
	{
		switch (in)
		{
		case 'R':
			map[B3] = '~';
			B3 += 1;
			break;
		case 'L':
			map[B3] = '~';
			B3 -= 1;
			break;
		case 'U':
			map[B3] = '~';
			B3 -= 10;
			break;
		case 'D':
			map[B3] = '~';
			B3 += 10;
			break;
		}
	}
	
	return 0;
}
int targethit()
{
	if (T1 == B1 || T1 == B2 || T1 == B3)
	{
		map[T1] = 'G';
	}

	if (T2 == B1 || T2 == B2 || T2 == B3)
	{
		map[T2] = 'G';
	}

	if (T3 == B1 || T3 == B2 || T3 == B3)
	{
		map[T3] = 'G';
	}
	goal();
	
}
int goal()
{
	if (map[T1] == 'G' && map[T2] == 'G' && map[T3] == 'G')
	{
		printf("complete!!!\n");
		system("pause");
		
	}
}
int PrintMap(void)
{
	int i = 0;
	for (i; i < 100; i++)
	{
		if (i % 10 == 0 & i != 0)
		{
			printf("\n");
			
		}
		printf("%5c", map[i]);

	}
	printf("\n");
	return 0;
}