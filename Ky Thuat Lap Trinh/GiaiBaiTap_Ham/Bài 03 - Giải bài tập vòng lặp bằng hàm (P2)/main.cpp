#include "TinhToan.h"
#include <stdio.h>
#include <conio.h>

int main()
{
	int n;
	do
	{
		printf("Nhap n (n > 0): ");
		scanf("%d", &n);
		if (n <= 0)
			printf("Nhap lai n\n");
	} while (n <= 0);

	printf("Sa = %d\n", Sa(n));
	printf("Sb = %d\n", Sb(n));
	printf("Sc = %.3f\n", Sc(n));
	printf("Sd = %d\n", Sd(n));
	printf("Se = %d\n", Se(n));
	printf("Sf = %.3f\n", Sf(n));

	getch();
	return 0;
}