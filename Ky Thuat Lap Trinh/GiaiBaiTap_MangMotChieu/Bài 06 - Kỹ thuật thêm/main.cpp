/*
** KỸ THUẬT THÊM PHẦN TỬ TRONG MẢNG MỘT CHIỀU
*/
#include "NhapXuat.h"
#include "ThemSo.h"
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
	printf("Mang vua nhap: \n");
	XuatMang(a, n);

#if 0
	// Bài 1. Thêm phần tử
#if 0
	// 1a. Thêm 1 phần tử
	int vt, giatri;
	do
	{
		printf("Nhap vi tri muon them: ");
		scanf("%d", &vt);
		if (vt < 0 || vt > n)
			printf("Vi tri them khong hop le.\n");
	} while (vt < 0 || vt > n);

	printf("Nhap gia tri muon them: ");
	scanf("%d", &giatri);
	ThemPhanTu(a, n, vt, giatri);
	printf("Mang sau khi them: \n");
	XuatMang(a, n);
#endif // 1

#if 0
	// 1b. Thêm số 0 (hoặc số khác) vào sau phần tử là số chẵn
	int x;
	printf("Nhap so muon them sau p.tu chan: ");
	scanf("%d", &x);
	ThemSauPhanTuChan(a, n, x);
	printf("Mang sau khi them: \n");
	XuatMang(a, n);
#endif // 1

#if 0
	// 1c. Thêm sau số chính phương
	int x;
	printf("Nhap so muon them sau p.tu chinh phuong: ");
	scanf("%d", &x);
	ThemSauPhanTuChinhPhuong(a, n, x);
	printf("Mang sau khi them: \n");
	XuatMang(a, n);
#endif // 1

#if 0
	// 1d. Thêm số 69 vào sau phần tử có số tận cùng là 9
	int x;
	printf("Nhap so muon them sau p.tu co chu so tan cung la 9: ");
	scanf("%d", &x);
	ThemSauSoTanCung(a, n, x);
	printf("Mang sau khi them: \n");
	XuatMang(a, n);
#endif // 1
#endif // 1

	getch();
	return 0;
}