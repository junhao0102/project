#include<stdio.h>
#include<stdlib.h>

typedef struct _dates {
	int years, month, day;
}date;
typedef struct _order{
	char num[11];
	date date;
	int amout;
}order;
