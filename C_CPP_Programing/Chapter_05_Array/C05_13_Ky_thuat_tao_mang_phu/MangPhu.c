#include "MangPhu.h"

void DemTanSuatChuSo(int a[], int n, int b[])
{
	for (int i = 0; i < n; i++)
	{
		int tmp = a[i];
		while (tmp != 0)
		{
			int ChuSo = tmp % 10;
			b[ChuSo]++;
			tmp /= 10;
		}
	}
}
void TaoMangPhu(int a[], int n, int b[], int x)
{
	for (int i = 0; i < n; i++)
	{
		b[i] = abs(x - a[i]); // Khoảng cách
	}
}
int TimMaxKhoangCach(int b[], int nb)
{
	int Max = b[0];
	for (int i = 0; i < nb; i++)
		if (b[i] > Max)
			Max = b[i];
	return Max;
}
void LietKeKhoangCachMax(int a[], int n, int b[])
{
	printf("Gia tri xa nhat: ");
	int KhoangCachMax = TimMaxKhoangCach(b, n);
	for (int i = 0; i < n; i++)
		if (b[i] == KhoangCachMax)
			printf("%d  ", a[i]); // Vị trí phần tử  của mảng a
}