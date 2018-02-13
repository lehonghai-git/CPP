#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

/*
** - Hàm Nhập mảng
** - Hàm Xuất mảng
** - Hàm tự động nhập ngẫu nhiên các phần tử của mảng
*/

void NhapMang(int[], int);
void XuatMang(int[], int);
void NhapMangNgauNhien(int[], int);

int main()
{
	int a[MAX], n;
	do
	{
		printf("Nhap so phan tu: ");
		scanf("%d", &n);
		if (n <= 0 || n > 100)
			printf("Nhap lai n\n");
	} while (n <= 0 || n > MAX);

	//NhapMang(a, n);
	NhapMangNgauNhien(a, n);
	XuatMang(a, n);

	getch();
	return 0;
}
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
}