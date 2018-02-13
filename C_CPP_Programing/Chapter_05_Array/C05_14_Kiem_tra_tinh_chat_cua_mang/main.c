#include "NhapXuat.h"
#include "KiemTraMang.h"
#include "KiemTraSo.h"
#define MAX 100

/*
** KIỂM TRA TÍNH CHẤT CỦA MẢNG
*/

int main()
{
	int n, a[MAX];
	do
	{
		printf("Nhap so luong phan tu: ");
		scanf("%d", &n);
		if (n < 0 || n > MAX)
			printf("So luong phan tu khong hop le.\n");
	} while (n < 0 || n > MAX);
	NhapMang(a, n);
	//NhapMangNgauNhien(a, n);
	printf("Mang vua nhap: \n");
	XuatMang(a, n);

#if 0 // Kiểm tra mảng đối xứng
	int Check = KiemTraMangDoiXung(a, n);
	if (Check)
		printf("Mang doi xung\n");
	else
		printf("Mang khong doi xung\n");
#endif // Kiểm tra mảng đối xứng

#if 0 // Kiểm tra mảng tăng dần
	int Check = KiemTraMangTangDan(a, n);
	if (Check)
		printf("Mang tang dan\n");
	else
		printf("Mang khong tang dan\n");
#endif // Kiểm tra mảng tăng dần

#if 0 // Kiểm tra mảng toàn nguyên tố
	int Check = KiemTraMangNgyenTo(a, n);
	if (Check)
		printf("Mang toan so nguyen to\n");
	else
		printf("Mang khong phai toan so nguyen to\n");
#endif // Kiểm tra mảng toàn nguyên tố

#if 0 // Kiểm tra mảng toàn chẵn
	int Check = KiemTraMangToanChan(a, n);
	if (Check)
		printf("Mang toan so chan\n");
	else
		printf("Mang khong phai toan so chan\n");
#endif // Kiểm tra mảng toàn chẵn

	getch();
	return 0;
}