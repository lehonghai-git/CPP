/*
** KỸ THUẬT ĐẾM TRONG MẢNG MỘT CHIỀU
*/
#include "NhapXuat.h"
#include "DemSo.h"
#include "KiemTraSo.h"
#include "XuatKetQua.h"
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
	// Bài 1. Phần tử phân biệt
	printf("Cac gia tri phan biet: ");
	PhanTuPhanBiet(a, n);
#endif // 0

#if 0
#if 0
	// Bài 2a. Đếm số lần xuất hiện của phần tử
	DemTanSuatXuatHien(a, n);
#endif // 1

#if 0
	// Bài 2b. Tìm ra các phần tử có tần xuất xuất hiện nhiều nhất
	LietKeTanSuatXuatHienNhieuNhat(a, n);
#endif // 1
#endif // 1

#if 0
	// Bài 3. Đếm số chẵn
	printf("\nSo luong phan tu chan: %d\n", DemSoChan(a, n));
#endif // 1

	getch();
	return 0;
}