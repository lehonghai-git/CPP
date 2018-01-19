#include <stdio.h>

/*
** Input    : 2 Số
** Output   : Min, Max hai số
** IDE      : Visual Studio 2017
*/

int main()
{
#if 0 // Min, Max của hai số
	int a, b, c;
	printf("Nhap a = ");
	scanf("%d", &a);
	printf("Nhap b = ");
	scanf("%d", &b);

	int Min = a < b ? a : b;
	int Max = a > b ? a : b;

	printf("\nMin = %d", Min);
	printf("\nMax = %d", Max);
#endif // 1 // Min, Max của hai số

#if 1 // Min, Max của ba số
	int a, b, c;
	printf("Nhap 3 so: ");
	scanf("%d%d%d", &a, &b, &c);

	int Min = a < b ? a : b;
	Min = Min < c ? Min : c;
	int Max = a > b ? a : b;
	Max = Max > c ? Max : c;

	printf("Min = %d\n", Min);
	printf("Max = %d\n", Max);
#endif // 1 // Min, Max của ba số

	getch();
	return 0;
}