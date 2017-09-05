/*
Tính S = a! + b! + c!
Với a, b, c nhập từ bàn phím
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// function prototype
void Nhap(int &);
int TinhGiaiThua(int);

int main()
{
#if 0
	int a, b, c;
	Nhap(a);
	Nhap(b);
	Nhap(c);

	int S = TinhGiaiThua(a) + TinhGiaiThua(b) + TinhGiaiThua(c);
	printf("S = a! + b! + c! = %d! + %d! + %d! = %d\n", a, b, c, S);
#endif // 0

#if 1
	// Mở rộng
	int S = 0;
	while (true)
	{
		printf("TINH TONG CAC GIAI THUA\n");
		printf("-----------------------\n");
		printf("1. Nhap so nguyen\n");
		printf("2. Thoat chuong trinh\n");

	lehonghai:
		int choice;
		printf("Nhap lua chon: ");
		scanf("%d", &choice);
		if (choice != 1 && choice != 2)
		{
			printf("Lua chon khong hop le!\n");
			goto lehonghai;
		}
		if (choice == 1)
		{
			system("cls");
			int n;
			Nhap(n);
			S += TinhGiaiThua(n);
		}
		else
		{
			printf("S = %d\n", S);
			break;
		}
	}
#endif // 1

	getch();
	return 0;
}

void Nhap(int &n)
{
	do
	{
		printf("Nhap n (n >= 0) = ");
		scanf("%d", &n);
		if (n <= 0)
			printf("Kiem tra lai n\n");
	} while (n <= 0);
}

int TinhGiaiThua(int n)
{
	int Tich = 1;
	for (int i = 2; i <= n; i++)
		Tich *= i;
	return Tich;
}