#include "Condition_Branch.h"

/*
** Description  : Giải các bài tập chương câu lệnh điều kiện, rẽ nhánh bằng hàm
** IDE			: Visual Studio 2017
*/

int main()
{
#if 0 // Chuyển đổi ký tự
	// 1a
	char key;
	printf("Nhap ky tu: ");
	scanf("%c", &key);
	printf("Truoc khi chuyen doi: %c\n", key);
	printf("Sau khi chuyen doi: %c\n", DoiKiTu(key));
#endif // Chuyển đổi ký tự

#if 0 // Giải PT bậc 1
	// 1b
	float a, b;
	printf("Nhap a =  ");
	scanf("%f", &a);
	printf("Nhap b =  ");
	scanf("%f", &b);
	GiaiPhuongTrinhBacNhat(a, b);
#endif // Giải PT bậc 1

#if 0 // Giải PT bậc 2
	// 1c
	float a, b, c;
	printf("Nhap he so =  ");
	scanf("%f%f%f", &a, &b, &c);
	GiaiPhuongTrinhBacHai(a, b, c);

#endif // Giải PT bậc 2

#if 0 // Min 4 số
	// 1d
	int a, b, c, d;
	printf("Nhap 4 so nguyen: ");
	scanf("%d%d%d%d", &a, &b, &c, &d);
	printf("Min 4 so: %d\n", MinHaiSo(d, MinHaiSo(c, MinHaiSo(a, b))));

#endif // Min 4 số

#if 0 // Hoán vị
	// 1e
	int a, b;
	printf("Nhap 2 so: ");
	scanf("%d%d", &a, &b);
	printf("Truoc khi hoan vi: %d  %d\n", a, b);
	HoanVi(&a, &b);
	printf("Sau khi hoan vi: %d  %d\n", a, b);
#endif // Hoán vị

#if 0 // Sắp xếp
	// 1f
	int a, b, c, d;
	printf("Nhap 4 so nguyen: ");
	scanf("%d%d%d%d", &a, &b, &c, &d);
	printf("Trc khi sap xep: %d %d %d %d\n", a, b, c, d);
	SapXepBonSo(&a, &b, &c, &d);
	printf("Sau khi sap xep: %d %d %d %d\n", a, b, c, d);
#endif // Sắp xếp

#if 1 // Tìm ngày hôm trước
	int Ngay, Thang, Nam;
	do
	{
		printf("Nhap ngay: ");
		scanf("%d", &Ngay);
		printf("Nhap thang: ");
		scanf("%d", &Thang);
		printf("Nhap nam: ");
		scanf("%d", &Nam);
	} while (!KiemTraNgayHopLe(Ngay, Thang, Nam));

	printf("\nNgay nhap: %d/%d/%d", Ngay, Thang, Nam);
	TinhNgayHomTruoc(&Ngay, &Thang, &Nam);
	printf("\nNgay hom truoc: %d/%d/%d", Ngay, Thang, Nam);

	/*printf("\nNgay nhap: %d/%d/%d", Ngay, Thang, Nam);
	TinhNgayHomSau(&Ngay, &Thang, &Nam);
	printf("\nNgay hom sau: %d/%d/%d", Ngay, Thang, Nam);*/
#endif // Tìm ngày hôm trước

	getch();
	return 0;
}