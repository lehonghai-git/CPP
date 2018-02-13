#include "NhapXuat.h"
#include "DemSo.h"
#include "KiemTraSo.h"
#include "XuatKetQua.h"
#define MAX 100

/*
** ĐẾM TRONG MẢNG
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

#if 0 // Bài 1. Phần tử phân biệt
	printf("Cac gia tri phan biet: ");
	PhanTuPhanBiet(a, n);
#endif // Bài 1. Phần tử phân biệt

#if 0 // Bài 2a. Đếm số lần xuất hiện của phần tử
	DemTanSuatXuatHien(a, n);
#endif // Bài 2a. Đếm số lần xuất hiện của phần tử

#if 0 // Bài 2b. Tìm ra các phần tử có tần xuất xuất hiện nhiều nhất
	LietKeTanSuatXuatHienNhieuNhat(a, n);
#endif // Bài 2b. Tìm ra các phần tử có tần xuất xuất hiện nhiều nhất

#if 0 // Bài 3. Đếm số chẵn
	printf("\nSo luong phan tu chan: %d\n", DemSoChan(a, n));
#endif // Bài 3. Đếm số chẵn

	getch();
	return 0;
}