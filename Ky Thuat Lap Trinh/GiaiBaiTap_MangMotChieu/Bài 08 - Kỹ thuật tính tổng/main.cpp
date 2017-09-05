/*
** KỸ THUẬT TÍNH TỔNG
*/
#include "NhapXuat.h"
#include "TinhToan.h"
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
	// Tổng các phần tử có chữ số hàng chục là 5
	int Tong = TinhTong(a, n);
	printf("\nTong cac p.tu co chu so hang chuc la 5: %d\n", Tong);
#endif // 0

#if 0
	// Tổng các số nguyên tố
	int TongNguyenTo = TongCacSoNguyenTo(a, n);
	printf("Tong cac so nguyen to = %d\n", TongNguyenTo);
#endif // 1

#if 0
	// Có bao nhiêu số chia hết cho 4 nhưng không chia hết cho 5
	int Soluong = SoLuongSoChiaHetThoaMan(a, n);
	printf("Co %d so chia het cho 4 nhung khong chia het cho 5\n", Soluong);
#endif // 1


	getch();
	return 0;
}