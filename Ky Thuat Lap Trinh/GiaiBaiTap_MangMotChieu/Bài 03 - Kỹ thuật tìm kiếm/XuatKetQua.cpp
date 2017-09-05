#include "XuatKetQua.h"

void XuatSoDoiXung(int a[], int n)
{
	for (int i = 0; i < n; i++)
		if (KiemTraSoDoiXung(a[i]))
			printf("%d  ", a[i]);
}
void XuatSoAmstrong(int a[], int n)
{
	for (int i = 0; i < n; i++)
		if (KiemTraSoAmstrong(a[i]))
			printf("%d  ", a[i]);
}
void XuatSoHoanThien(int a[], int n)
{
	int Check = 0;
	for (int i = 0; i < n; i++)
		if (KiemTraSoHoanThien(a[i]))
		{
			printf("%d   ", a[i]);
			Check = 1;
		}
	if (Check == 0)
		printf("Khong co so hoan thien\n");
}
void XuatCacSoDangAMuK(int a[], int n, int coso)
{
	for (int i = 0; i < n; i++)
		if (KiemTraSoDangAMuK(a[i], coso))
			printf("%d   ", a[i]);
	printf("\n");
}