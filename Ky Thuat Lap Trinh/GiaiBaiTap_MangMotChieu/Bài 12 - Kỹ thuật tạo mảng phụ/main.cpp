/*
** KỸ THUẬT TẠO MẢNG PHỤ
*/
#include "NhapXuat.h"
#include "mylib.h"
#include <conio.h>

#define MAX 100

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
	//NhapMang(a, n);
	NhapMangNgauNhien(a, n);
	printf("Mang vua nhap: \n");
	XuatMang(a, n);

#if 0
	// Đếm tần suất xuất hiện của mỗi chữ số
	int b[10] = { 0 };
	DemTanSuatChuSo(a, n, b);
	// Xuất kết quả
	printf("\n");
	for (int i = 0; i < 10; i++)
		if (b[i] != 0)
			printf("So %d xuat hien: %d lan\n", i, b[i]);
#endif // 1

#if 1
	// Phần tử xa nhất
	int b[MAX], x;
	printf("\nNhap x = ");
	scanf("%d", &x);
	TaoMangPhu(a, n, b, x);
	LietKeKhoangCachMax(a, n, b);
#endif // 1

	getch();
	return 0;
}