#include <stdio.h>

/*
** Input    : Các hệ số của phương trình ax + b = 0
** Output   : Nghiệm x của phương trình
** IDE      : Visual Studio 2017
*/

int main()
{
	int a, b;
	printf("Nhap a = ");
	scanf("%d", &a);
	printf("Nhap b = ");
	scanf("%d", &b);

	if (a == 0)
	{
		if (b == 0) printf("Vo so nghiem\n");
		else printf("Vo nghiem\n");
	}
	else
	{
		printf("x = %.3f\n", (float)-b / a);
	}

	getch();
	return 0;
}