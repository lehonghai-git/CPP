/*
- Nhập vào hai số nguyên
- Tìm và in ra kết quả min, max của hai số nguyên đó
*/
#include <stdio.h>
#include <conio.h>

int main()
{
#if 0
	// Tìm Min, Max của 2 số
	int a, b, c;
	printf("Nhap a = ");
	scanf("%d", &a);
	printf("Nhap b = ");
	scanf("%d", &b);

	int Min = a < b ? a : b;
	int Max = a > b ? a : b;

	printf("---------\n");
	printf("Min = %d\n", Min);
	printf("Max = %d\n", Max);
#endif // 0

#if 1
	// Tìm Min, Max của 3 số
	int a, b, c;
	printf("Nhap a = ");
	scanf("%d", &a);
	printf("Nhap b = ");
	scanf("%d", &b);
	printf("Nhap c = ");
	scanf("%d", &c);

	int Min = a < b ? a : b;
	Min = Min < c ? Min : c;
	int Max = a > b ? a : b;
	Max = Max > c ? Max : c;

	printf("Min = %d\n", Min);
	printf("Max = %d\n", Max);
#endif // 1

	getch();
	return 0;
}