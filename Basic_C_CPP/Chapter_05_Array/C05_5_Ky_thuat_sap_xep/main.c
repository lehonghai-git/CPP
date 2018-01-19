#include "NhapXuat.h"
#include "SapXep.h"
#define MAX 100

/*
** SẮP XẾP TRONG MẢNG
*/

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

#if 0 // 1a. Sắp xếp tăng
	SapXepTangDan(a, n);
	printf("\nSap xep tang:\n");
	XuatMang(a, n);
#endif // 1a. Sắp xếp tăng

#if 0 // 1b. Sắp xếp giảm
	SapXepGiamDan(a, n);
	printf("\nSap xep giam:\n");
	XuatMang(a, n);
#endif // 1b. Sắp xếp giảm

#if 0 // 1c. Sắp xếp các số lẻ tăng
	SapXepLeTang(a, n);
	printf("\nSap xep so le tang dan:\n");
	XuatMang(a, n);
#endif // 1c. Sắp xếp các số lẻ tăng

	getch();
	return 0;
}