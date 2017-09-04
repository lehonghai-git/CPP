/*
- Nhập vào biển số xe (5 chữ số)
- Tính và in ra số nước
*/
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>

int main()
{
lehonghai:
	system("cls");
	unsigned int SoXe, SoNut = 0, SoChuSo;
	printf("Nhap bien so xe: ");
	scanf("%u", &SoXe);

	// Tính số chữ số của SoXe nhập vào
	SoChuSo = log10((double)SoXe) + 1;

	SoNut += SoXe % 10;
	SoXe /= 10;

	SoNut += SoXe % 10;
	SoXe /= 10;

	SoNut += SoXe % 10;
	SoXe /= 10;

	SoNut += SoXe % 10;
	SoXe /= 10;

	SoNut += SoXe % 10;
	SoXe /= 10;

	/*while (SoXe > 0)
	{
	tmp = SoXe % 10;
	SoNut += tmp;
	SoXe /= 10;
	}*/

	SoChuSo == 5 ? printf("So nut = %d\n", SoNut % 10) : printf("So xe phai la 5 chu so\n");

	printf("Nhap 'c' hoac 'C' de tiep tuc! Nhap phim bat ky de thoat!\n");
	char input = getch();
	if (input == 'c' || input == 'C') goto lehonghai;

	return 0;
}