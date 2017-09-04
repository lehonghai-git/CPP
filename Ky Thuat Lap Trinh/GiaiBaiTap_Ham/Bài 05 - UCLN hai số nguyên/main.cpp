/*
Hàm trả về USCLN của 2 số nguyên
*/
#include <stdio.h>
#include <conio.h>

int UocSoChungLonNhat(int, int);

int main()
{
	int a, b;
	do
	{
		printf("Nhap a (a > 0) = ");
		scanf("%d", &a);
		if (a <= 0)
			printf("Nhap lai a\n");
	} while (a <= 0);

	do
	{
		printf("Nhap b (b > 0) = ");
		scanf("%d", &b);
		if (b <= 0)
			printf("Nhap lai b\n");
	} while (b <= 0);

	printf("Uoc so chung lon nhat cua %d va %d = %d\n", a, b, UocSoChungLonNhat(a, b));

	getch();
	return 0;
}

int UocSoChungLonNhat(int a, int b)
{
	while (a != b)
	{
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	return a;
}