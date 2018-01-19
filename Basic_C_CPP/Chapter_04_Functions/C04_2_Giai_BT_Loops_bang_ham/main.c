#include "Loops.h"

/*
** Description  : Giải các bài tập chương vòng lặp bằng hàm
** IDE			: Visual Studio 2017
*/

int main()
{
	int n;
	do
	{
		printf("Nhap n (n > 0): ");
		scanf("%d", &n);
		if (n <= 0)
			printf("Nhap lai n\n");
	} while (n <= 0);

#if 1 // Số đảo 
	printf("So n trc khi dao = %d\n", n);
	printf("So n sau khi dao = %d\n", SoDao(n));
#endif // Số đảo

#if 0 // Số đối xứng
	if (SoDoiXung(n))
		printf("So %d la so doi xung\n", n);
	else
		printf("So %d khong phai so doi xung\n", n);
#endif // Số đối xứng

#if 0 // Số chính phương 
	if (SoChinhPhuong(n))
		printf("So %d la so chinh phuong\n", n);
	else
		printf("So %d khong phai so chinh phuong\n", n);
#endif // Số chính phương 

#if 0 // Số nguyên tố 
	if (SoNguyenTo(n))
		printf("So %d la so nguyen to\n", n);
	else
		printf("So %d khong la so nguyen to\n", n);
#endif // Số nguyên tố 

#if 0 // Tổng các chữ số lẻ
	printf("So vua nhap: %d\n", n);
	int TongLe = TongChuSoLe(n);
	if (TongLe == 0)
		printf("Khong co chu so le\n");
	else
		printf("Tong cac chu so le: %d\n", TongLe);
#endif // Tổng các chữ số lẻ

#if 0 // Tổng các chữ số nguyên tố
	printf("So vua nhap: %d\n", n);
	int TongNT = TongChuSoNguyenTo(n);
	if (TongNT == 0)
		printf("Khong co chu so nguyen to\n");
	else
		printf("Tong cac chu so nguyen to: %d\n", TongNT);
#endif // Tổng các chữ số nguyên tố

#if 0 // Tổng các chữ số chính phương
	// Lưu ý là số 0 cũng là số chính phương
	printf("So vua nhap: %d\n", n);
	int zero = 0, TongCP = TongChuSoChinhPhuong(n, &zero);
	if (zero == 0)
		printf("Khong co chu so chinh phuong\n");
	else
		printf("Tong cac chu so chinh phuong: %d\n", TongCP);
#endif // Tổng các chữ số chính phương

#if 0 // Tính giá trị các biểu thức
	printf("Sa = %d\n", Sa(n));
	printf("Sb = %d\n", Sb(n));
	printf("Sc = %.3f\n", Sc(n));
	printf("Sd = %d\n", Sd(n));
	printf("Se = %d\n", Se(n));
	printf("Sf = %.3f\n", Sf(n));
#endif // Tính giá trị các biểu thức

#if 0 // Giai thừa
	int S = TinhGiaiThua(n);
	printf("S = n! = %d\n", S);
#endif // Giai thừa

#if 0 // Ước chung lớn nhất
	int m;
	do
	{
		printf("Nhap m (b > 0) = ");
		scanf("%d", &m);
		if (m <= 0)
			printf("Nhap lai b\n");
	} while (m <= 0);
	printf("Uoc so chung lon nhat cua %d va %d la %d\n", n, m, UocSoChungLonNhat(n, m));
#endif // Ước chung lớn nhất

#if 0 // Dãy Fibonacy
	int x;
	do
	{
		printf("Nhap x (x >= 1) = ");
		scanf("%d", &x);
		if (x < 1)
			printf("Nhap lai x\n");
	} while (x < 1);
	InDayFib(x);
#endif // Dãy Fibonacy

	getch();
	return 0;
}