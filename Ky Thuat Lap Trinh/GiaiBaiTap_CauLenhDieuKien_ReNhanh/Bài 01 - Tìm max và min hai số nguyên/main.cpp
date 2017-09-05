#include <stdio.h>
#include <conio.h>

int main()
{
	int a, b;
	printf("Nhap a = ");
	scanf("%d", &a);

	printf("Nhap b = ");
	scanf("%d", &b);

	int Min, Max;

#if 0
	// Cách 1: Dùng câu lệnh điều kiện
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
#endif // 0

#if 0
	// Cách 2: Dùng toán tử ba ngôi
	Min = Max = a;
	if (b > Max) Max = b;
	if (b < Min) Min = b;
#endif // 0

#if 1
	// Cách 2 có thể dễ dàng áp dụng với tìm Min, Max nhiều số hơn.
	int c;
	printf("Nhap c = ");
	scanf("%d", &c);

	Min = Max = a;
	if (b > Max) Max = b;
	if (b < Min) Min = b;
	if (c > Max) Max = c;
	if (c < Min) Min = c;
#endif // 1

	printf("---------------\n");
	printf("Min = %d\n", Min);
	printf("Max = %d\n", Max);

	getch();
	return 0;
}