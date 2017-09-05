/*
Nhập số nguyên dương. Đếm xem số đó có bao nhiêu chữ số?
Tìm ra chữ số lớn nhất
Tìm ra chữ số nhỏ nhất
VD: 972017
=> Có 6 chữ số
=> Chữ số lớn nhất = 9
=> Chữ số nhỏ nhất = 0
*/
#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
	int n;
	do
	{
		printf("Nhap n (n > 0) = ");
		scanf("%d", &n);
		if (n < 0)
			printf("Kiem tra lai n\n");
	} while (n < 0);

	int SoChuSo = n == 0 ? 1 : (int)log10((float)n) + 1;
	printf("So %d co %d chu so\n", n, SoChuSo);

	int Min, Max;
	Min = Max = n % 10;
	while (n > 0)
	{
		Min = (n % 10) < Min ? (n % 10) : Min;
		Max = (n % 10) > Max ? (n % 10) : Max;
		n /= 10;
	}

	printf("Min = %d\nMax = %d\n", Min, Max);

	getch();
	return 0;
}
/*
VD: 972017
972017 % 10 = 7
972017 / 10 = 97201

97201 % 10 = 1
97201 / 10 = 9720

9720 % 10 = 0
9720 / 10 = 972

972 % 10 = 2
972 / 10 = 97

97 % 10 = 7
97 / 10 = 9

9 % 10 = 9
9 / 10 = 0
*/