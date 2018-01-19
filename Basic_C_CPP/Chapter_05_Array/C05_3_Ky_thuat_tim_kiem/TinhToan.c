#include "TinhToan.h"

int TongSoDoiXung(int a[], int n)
{
	int TongDX = 0;
	for (int i = 0; i < n; i++)
		if (KiemTraSoDoiXung(a[i]))
			TongDX += a[i];
	return TongDX;
}

int TongSoAmstrong(int a[], int n)
{
	int TongAS = 0;
	for (int i = 0; i < n; i++)
		if (KiemTraSoAmstrong(a[i]))
			TongAS += a[i];
	return TongAS;
}