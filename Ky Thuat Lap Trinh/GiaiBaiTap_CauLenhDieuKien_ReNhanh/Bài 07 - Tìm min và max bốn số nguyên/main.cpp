#include <stdio.h>
#include <conio.h>

int main()
{
	int a, b, c, d;
	printf("Nhap 4 so nguyen: ");
	scanf("%d%d%d%d", &a, &b, &c, &d);

	int Min, Max;
	Max = Min = a;
	if (b > Max) Max = b;
	if (b < Min) Min = b;
	if (c > Max) Max = c;
	if (c < Min) Min = c;
	if (d > Max) Max = d;
	if (d < Min) Min = d;

	printf("Min = %d\nMax = %d\n", Min, Max);

	getch();
	return 0;
}