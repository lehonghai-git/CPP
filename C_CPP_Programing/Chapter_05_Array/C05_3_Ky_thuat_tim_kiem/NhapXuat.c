#include "NhapXuat.h"

void NhapMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Nhap a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}
void XuatMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d   ", a[i]);
	printf("\n");
}
void NhapMangNgauNhien(int a[], int n)
{
	srand(time(0));
	for (int i = 0; i < n; i++)
		a[i] = 10 + rand() % (99 - 10 + 1); // [10..99]
	printf("Nhap xong mang ngau nhien.\n");
}
void NhapNhanVien(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int Check;
		do
		{
			Check = 1;
			printf("Nhap ma nhan vien thu %d: ", i + 1);
			scanf("%d", &a[i]);
			for (int j = i - 1; j >= 0; j--)
			{
				if (a[i] == a[j])
				{
					printf("Ma nhan vien bi trung\n");
					Check = 0;
					break;
				}
			}
		} while (Check == 0);
	}
}
void XuatNhanVien(int a[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d   ", a[i]);
	printf("\n");
}