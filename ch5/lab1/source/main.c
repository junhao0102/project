#include<stdio.h>
#include<stdlib.h>

#define STUDENTS 3
#define EXAMS 4

void minimum(int grades[][EXAMS], int pupils, int test);
void maximum(int grades[][EXAMS], int pupils, int test);
void average(int grades[][EXAMS], int pupils, int test);
void printArray(int grades[][EXAMS], int pupils, int test);
void printMenu();

int main() {

	//initial std grades
	int studentGrades[STUDENTS][EXAMS] = {  {77,68,86,73},
											{96,87,89,78},
											{70,90,86,81} };
	
	void(*processGrades[4])(int[STUDENTS][EXAMS], int, int)
		= { printArray,minimum,maximum,average };


	int choice = 0;

	while (choice != 4) {
		do {
			printMenu();
			scanf_s("%d", &choice);
		} while (choice < 0 || choice>4);

		if (choice != 4)
			(*processGrades[choice])(studentGrades, STUDENTS, EXAMS);
		else
			printf("\tProgram Ended.\n");
	}
	


	system("pause");
	return 0;
}

void minimum(int grades[][EXAMS], int pupils, int test) {

	int i, j;
	int lowGrade = 100;

	for (i = 0; i < pupils; i++) {

		for (j = 0; j < test; j++) {

			if (grades[i][j] < lowGrade)
				lowGrade = grades[i][j];
		}
	}
	printf("\n\tThe lowest grade is %d", lowGrade);
	printf("\n");
}


void maximum(int grades[][EXAMS], int pupils, int test) {

	int i, j;
	int highGrade = 0;

	for (i = 0; i < pupils; i++) {
		for (j = 0; j < test; j++) {
			if (grades[i][j] >highGrade)
				highGrade = grades[i][j];
		}
	}
	printf("\n\tThe highest grade is %d", highGrade);
	printf("\n");
}


void average(int grades[][EXAMS], int pupils, int test) {

	int i, j, total;

	for (i = 0; i < pupils; i++) {
		total = 0;
		for (j = 0; j < test; j++) {
			total += grades[i][j];
		
	}
	printf("\n\tThe average grade for students %d is %.1f", i + 1, (double)total / test);
}
	printf("\n");
}

void printArray(int grades[][EXAMS], int pupils, int test) {

	int i, j;
	printf("\n\t\t\t[0]    [1]    [2]   [3]");
	for (i = 0; i < pupils; i++) {
		printf("\n\tstudentGrades[%d]", i);
		for (j = 0; j < test; j++)
			printf("%-7d", grades[i][j]);

	}
	printf("\n");
}


void printMenu() {
	printf("\n");
	printf("\tEnter a choice\n");
	printf("\t0 Print the array of grades\n");
	printf("\t1 Find the minimum grade\n");
	printf("\t2 Find the maximum grade\n");
	printf("\t3 Print the average on all test for each students\n");
	printf("\t4 End program\n");
	printf("Choice");


}