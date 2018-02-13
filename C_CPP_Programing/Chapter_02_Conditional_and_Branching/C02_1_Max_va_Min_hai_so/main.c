#include <stdio.h>

/*
** Input    : Hai số
** Output   : Min, Max
** IDE      : Visual Studio 2017
*/

int main()
{
	// Input
	int a, b;
	printf("Nhap a = ");
	scanf("%d", &a);
	printf("Nhap b = ");
	scanf("%d", &b);

	int Min, Max;
	// Cách 1: Sử dụng toán tử 3 ngôi (Đã làm bài trước)
	// Cách 2: Sử dụng câu lệnh điều kiện
#if 0 // 2.1: Max, Min hai số
	if (a > b)
	{
		Max = a;
		Min = b;
	}
	else if (a < b)
	{
		Max = b;
		Min = a;
	}
	else
	{
		Min = Max = a;
	}
#endif // 1 // 2.1: Max, Min hai số

#if 1 // 2.2: Max, Min ba số
	int c;
	printf("Nhap c = ");
	scanf("%d", &c);

	Min = Max = a;
	if (b > Max) Max = b;
	if (b < Min) Min = b;
	if (c > Max) Max = c;
	if (c < Min) Min = c;
#endif // 1 // 2.2: Max, Min ba số

	printf("Min = %d\n", Min);
	printf("Max = %d\n", Max);

	getch();
	return 0;
}