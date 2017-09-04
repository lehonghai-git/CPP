/*
Nhập n (n >= 1). In ra n số đầu tiên trong dãy Fibonacci.
Dãy Fibonacci là dãy có nguyên tắc
a[0] = a[1] = 1
a[n] = a[n-1]+a[n-2]
VD: 1,2,3,5,8,13,21,34,55...
*/
#include <stdio.h>
#include <conio.h>

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

	int A0, A1, An;
	A0 = A1 = 1;
	if (n == 1)
		printf("%d  ", A0);
	else if (n == 2)
		printf("%d  %d", A0, A1);
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
	}

	getch();
	return 0;
}