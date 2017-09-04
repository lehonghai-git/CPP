/*
In ra n phần tử của dãy Fibonacy
*/
#include <stdio.h>
#include <conio.h>

void InDayFib(int);

int main()
{
	int n;
	do
	{
		printf("Nhap n (n >= 1) = ");
		scanf("%d", &n);
		if (n < 1)
			printf("Nhap lai n\n");
	} while (n < 1);
	InDayFib(n);

	getch();
	return 0;
}

void InDayFib(int n)
{
	int A0, A1, An;
	A0 = A1 = 1;
	if (n == 1)
		printf("%d  \n", A0);
	else if (n == 2)
		printf("%d  %d\n", A0, A1);
	else
	{
		printf("%d  %d  ", A0, A1);
		for (int i = 1; i <= n - 2; i++) // n-2 vì trừ đi 2 số đã in là A0 và A1
		{
			An = A0 + A1;
			A0 = A1; // Cập nhập số
			A1 = An; // Cập nhập số
			printf("%d  ", An);
		}
		printf("\n");
	}
}