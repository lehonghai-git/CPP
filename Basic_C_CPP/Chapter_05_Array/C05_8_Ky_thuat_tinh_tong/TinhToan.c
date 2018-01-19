#include "TinhToan.h"

int TinhTong(int a[], int n)
{
	int Tong = 0;
	for (int i = 0; i < n; i++)
		if (KiemTraChuSoHangChuc(a[i]))
			Tong += a[i];
	return Tong;
}
int TongCacSoNguyenTo(int a[], int n)
{
	int Tong = 0;
	for (int i = 0; i < n; i++)
		if (KiemTraNguyenTo(a[i]))
			Tong += a[i];
	return Tong;
}
int SoLuongSoChiaHetThoaMan(int a[], int n)
{
	int SoLuong = 0;
	for (int i = 0; i < n; i++)
		if (a[i] % 4 == 0 && a[i] % 5 != 0) // Chia hết cho 4 nhưng không chia hết cho 5
			SoLuong++;
	return SoLuong;
}