#include <stdio.h>
#include <math.h>
/*
** Input    : Biển số xe 5 chữ số
** Output   : Số nước
** IDE      : Visual Studio 2017
*/

int main()
{
NhapBienSo:
	int BienSo;
	printf("Nhap 5 so cua bien: ");
	scanf("%d", &BienSo);

	// Tính số chữ số
	int SoChuSo = log10((double)BienSo) + 1;
	if (SoChuSo != 5)
		goto NhapBienSo;

	int SoNuoc = 0;
TinhSoNuoc:
	SoNuoc += BienSo % 10;
	BienSo /= 10;
	if (BienSo != 0)
		goto TinhSoNuoc;

	printf("\nSo nuoc: %d", SoNuoc);

	getch();
	return 0;
}