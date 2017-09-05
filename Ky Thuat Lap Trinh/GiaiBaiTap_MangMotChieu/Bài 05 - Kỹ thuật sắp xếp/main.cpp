/*
** KỸ THUẬT SẮP XẾP TRÊN MẢNG MỘT CHIỀU
*/
#include "NhapXuat.h"
#include "SapXep.h"
#include <conio.h>

#define MAX 100

int main()
{
	int a[MAX], n;
	do
	{
		printf("Nhap so luong phan tu: ");
		scanf("%d", &n);
		if (n <= 0 || n > 100)
			printf("Nhap lai n\n");
	} while (n <= 0 || n > MAX);

	//NhapMang(a, n);
	NhapMangNgauNhien(a, n);
	printf("\nMang vua nhap:\n");
	XuatMang(a, n);

#if 0
	// Bài 1. Sắp xếp
#if 0
	// 1a. Sắp xếp tăng
	SapXepTangDan(a, n);
	printf("\nSap xep tang:\n");
	XuatMang(a, n);
#endif // 0
#if 0
	// 1b. Sắp xếp giảm
	SapXepGiamDan(a, n);
	printf("\nSap xep giam:\n");
	XuatMang(a, n);
#endif // 1
#if 0
	// 1c. Sắp xếp các số lẻ tăng
	SapXepLeTang(a, n);
	printf("\nSap xep so le tang dan:\n");
	XuatMang(a, n);
#endif // 1
#endif // 1


	getch();
	return 0;
}