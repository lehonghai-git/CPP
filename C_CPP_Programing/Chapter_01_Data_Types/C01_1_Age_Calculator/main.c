#include <stdio.h>
#include <time.h>

/*
** Input	: Năm sinh một người
** Output	: Tuổi người đó
** IDE      : Visual Studio 2017
*/

int main()
{
	// Get time system
	time_t t = time(0);
	struct tm *Now = localtime(&t);
	int CurrentYear = Now->tm_year + 1900;
	
	int BornYear;
	printf("Nhap nam sinh: ");
	scanf("%d", &BornYear);

	printf("\nTuoi hien tai: %d", CurrentYear - BornYear);

	getch();
	return 0;
}