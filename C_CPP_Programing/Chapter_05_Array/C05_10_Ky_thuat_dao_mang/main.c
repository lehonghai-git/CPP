#include "NhapXuat.h"
#include "DaoMang.h"
#define MAX 100

/*
** ĐẢO
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

	// Đảo ngược mảng
	DaoNguoc(a, n);
	printf("Mang sau khi dao: \n");
	XuatMang(a, n);

	getch();
	return 0;
}