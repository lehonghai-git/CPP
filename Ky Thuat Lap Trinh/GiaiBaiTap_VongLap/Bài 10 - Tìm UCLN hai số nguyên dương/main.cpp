/*
Tìm ước chung lớn nhất của hai số nguyên dương nhập từ bàn phím
*/
#include <stdio.h>
#include <conio.h>

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

	/*
	Ước số của n là các số mà n chia hết.
	VD:
	- Các ước số của 2 là: 1,2
	- Các ước số của 6 là: 1,2,3,6
	*/

#if 0
	// Cách 1
	int Min = a < b ? a : b;
	int Max = a > b ? a : b;
	for (int i = Min; i >= 1; i--)
	{
		if (Min % i == 0 && Max % i == 0)
		{
			printf("UCLN: %d\n", i);
			break;
		}
	}
#endif // 0

#if 0
	// Cách 2: Cải tiến từ cách 1. vì chắc chắn Min % Min == 0
	// Nên xét từ Min/2
	int Min = a < b ? a : b;
	int Max = a > b ? a : b;
	if (Max % Min == 0)
		printf("UCLN: %d\n", Min);
	else
	{
		for (int i = Min / 2; i >= 1; i--)
		{
			if (Min % i == 0 && Max % i == 0)
			{
				printf("UCLN: %d\n", i);
				break;
			}
		}
	}
#endif // 1

#if 1
	/*Cách 3: Giải thuật Euclid
	So sánh hai số với nhau và lấy số lớn trừ đi số bé
	Kết quả lại đem so sánh tiếp và lại lấy số lớn trừ số bé
	Lặp lại các thao tác so sánh và số lớn - số bé cho đến khi hai số bằng nhau
	Khi đó: UCLN = a = b;
	VD: a = 12, b = 16
	Lần 1: b > a => b = b - a => b = 16 - 12 = 4
	Lần 2: a > b => a = a - b => a = 12 - 4 = 8
	Lần 3: a > b => a = a - b => a = 8 - 4 = 4
	Lần 4: a = b = 4 => Ước chung = 4
	*/
	while (a != b)
	{
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	printf("UCLN: %d\n", a); // a == b
#endif // 1

	getch();
	return 0;
}