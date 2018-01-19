#include "NhapXuat.h"
#include "CoHieu.h"
#define MAX 100

/*
** ĐẶT CỜ HIỆU
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

	int x;
	printf("\nNhap so muon kiem tra lien tiep: ");
	scanf("%d", &x);
	int Check = KiemTraLienTiep(a, n, x);
	if (Check)
		printf("\nMang co ton tai phan tu %d lien tiep\n", x);
	else
		printf("\nMang khong co phan tu %d lien tiep\n", x);

	getch();
	return 0;
}