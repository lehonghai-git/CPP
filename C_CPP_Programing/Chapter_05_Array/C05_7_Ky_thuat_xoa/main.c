#include "NhapXuat.h"
#include "TimSo.h"
#include "XoaSo.h"
#define MAX 100

/*
** XÓA PHẦN TỬ TRONG MẢNG 
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
	printf("Mang vua nhap: \n");
	XuatMang(a, n);

#if 0 // Xóa một phần tử trong mảng
	int vt;
	do
	{
		printf("Nhap vi tri muon xoa: ");
		scanf("%d", &vt);
		if (vt < 0 || vt >= n)
			printf("Vi tri xoa khong hop le.\n");
	} while (vt < 0 || vt >= n);

	XoaPhanTu(a, &n, vt);
	printf("Mang sau khi xoa: \n");
	XuatMang(a, n);
#endif // Xóa một phần tử trong mảng

#if 0 // Xóa các phần tử chẵn
	XoaPhanTuChan(a, &n);
	printf("Mang sau khi xoa cac phan tu chan: \n");
	XuatMang(a, n);
#endif // Xóa các phần tử chẵn

#if 0 // Xóa các phần tử max
	XoaTatCaPhanTuMax(a, &n);
	printf("Mang sau khi xoa cac phan tu max: \n");
	XuatMang(a, n);
#endif // Xóa các phần tử max

#if 0 // Xóa các phần tử có chữ số đầu tiên là 5
	XoaPhanTuCoChuSoDau(a, &n, 5);
	printf("Mang sau khi xoa cac phan tu co so dau la 5: \n");
	XuatMang(a, n);
#endif // 1

	getch();
	return 0;
}