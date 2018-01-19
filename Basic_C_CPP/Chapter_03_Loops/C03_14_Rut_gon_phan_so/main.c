#include <stdio.h>
#include <math.h>

/*
** Input    : Nhập hai phân số
** Output   : Tính tổng, hiệu, tích, thương và kết quả là phân số rút gọn
** IDE      : Visual Studio 2017
*/

int TimUocChungLonNhat(int a, int b)
{
	a = abs(a);
	b = abs(b);
	while (a != b)
	{
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	return a;
}

int main()
{
	int TuSo1, MauSo1, TuSo2, MauSo2;
	printf("Nhap tu so 1: ");
	scanf("%d", &TuSo1);
	do
	{
		printf("Nhap mau so 1: ");
		scanf("%d", &MauSo1);
		if (MauSo1 == 0)
			printf("Mau so phai khac 0\n");
	} while (MauSo1 == 0);

	printf("Nhap tu so 2: ");
	scanf("%d", &TuSo2);
	do
	{
		printf("Nhap mau so 2: ");
		scanf("%d", &MauSo2);
		if (MauSo2 == 0)
			printf("Mau so phai khac 0\n");
	} while (MauSo2 == 0);

	int MauSoTong, MauSoHieu, MauSoTich, MauSoThuong;
	int TuSoTong, TuSoHieu, TuSoTich, TuSoThuong;
	TuSoTong = (TuSo1 * MauSo2) + (TuSo2 * MauSo1);
	MauSoTong = MauSo1 * MauSo2;
	TuSoHieu = (TuSo1 * MauSo2) - (MauSo1 * TuSo2);
	MauSoHieu = MauSo1 * MauSo2;
	TuSoTich = TuSo1 * TuSo2;
	MauSoTich = MauSo1 * MauSo2;
	TuSoThuong = TuSo1 * MauSo2;
	MauSoThuong = MauSo1 * TuSo2;

	printf("-------------\n");
	printf("Ket qua khi chua rut gon\n");
	printf("Tong: %d/%d\n", TuSoTong, MauSoTong);
	printf("Hieu: %d/%d\n", TuSoHieu, MauSoHieu);
	printf("Tich: %d/%d\n", TuSoTich, MauSoTich);
	printf("Thuong: %d/%d\n", TuSoThuong, MauSoThuong);

	// Rút gọn kết quả Tổng, hiệu, tích, thương bằng cách chia cho ưcln
	int UclnTong, UclnHieu, UclnTich, UclnThuong;
	UclnTong = TimUocChungLonNhat(TuSoTong, MauSoTong);
	UclnHieu = TimUocChungLonNhat(TuSoHieu, MauSoHieu);
	UclnTich = TimUocChungLonNhat(TuSoTich, MauSoTich);
	UclnThuong = TimUocChungLonNhat(TuSoThuong, MauSoThuong);

	printf("-------------\n");
	printf("Ket qua sau khi rut gon\n");
	printf("Tong: %d/%d\n", TuSoTong / UclnTong, MauSoTong / UclnTong);
	printf("Hieu: %d/%d\n", TuSoHieu / UclnHieu, MauSoHieu / UclnHieu);
	printf("Tich: %d/%d\n", TuSoTich / UclnTich, MauSoTich / UclnTich);
	printf("Thuong: %d/%d\n", TuSoThuong / UclnThuong, MauSoThuong / UclnThuong);

	getch();
	return 0;
}