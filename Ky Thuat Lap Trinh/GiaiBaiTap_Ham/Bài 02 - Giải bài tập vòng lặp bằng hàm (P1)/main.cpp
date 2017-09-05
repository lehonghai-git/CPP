#include "KiemTraSo.h"
#include "TinhToan.h"
#include <stdio.h>
#include <conio.h>

int main()
{
	// Nhập n
	int n;
	do
	{
		printf("Nhap n (n > 0): ");
		scanf("%d", &n);
		if (n <= 0)
			printf("Nhap lai n\n");
	} while (n <= 0);
#if 0
	// a. Số đảo
	printf("So n trc khi dao = %d\n", n);
	printf("So n sau khi dao = %d\n", SoDao(n));
#endif // 1

#if 0
	// b. Số đối xứng
	if (SoDoiXung(n))
		printf("So %d la so doi xung\n", n);
	else
		printf("So %d khong phai so doi xung\n", n);
#endif // 1

#if 0
	// c. Số chính phương
	if (SoChinhPhuong(n))
		printf("So %d la so chinh phuong\n", n);
	else
		printf("So %d khong phai so chinh phuong\n", n);
#endif // 1

#if 0
	// d. Số nguyên tố
	if (SoNguyenTo(n))
		printf("So %d la so nguyen to\n", n);
	else
		printf("So %d khong la so nguyen to\n", n);
#endif // 1

#if 0
	// e. Tổng các chữ số lẻ
	printf("So vua nhap: %d\n", n);
	int TongLe = TongChuSoLe(n);
	if (TongLe == 0)
		printf("Khong co chu so le\n");
	else
		printf("Tong cac chu so le: %d\n", TongLe);
#endif // 1

#if 0
	// f. Tổng các chữ số nguyên tố
	printf("So vua nhap: %d\n", n);
	int TongNT = TongChuSoNguyenTo(n);
	if (TongNT == 0)
		printf("Khong co chu so nguyen to\n");
	else
		printf("Tong cac chu so nguyen to: %d\n", TongNT);
#endif // 1

#if 1
	// g. Tổng các chữ số chính phương: Lưu ý là số 0 cũng là số chính phương
	printf("So vua nhap: %d\n", n);
	int zero = 0, TongCP = TongChuSoChinhPhuong(n, zero);
	if (zero == 0)
		printf("Khong co chu so chinh phuong\n");
	else
		printf("Tong cac chu so chinh phuong: %d\n", TongCP);
#endif // 1

	getch();
	return 0;
}