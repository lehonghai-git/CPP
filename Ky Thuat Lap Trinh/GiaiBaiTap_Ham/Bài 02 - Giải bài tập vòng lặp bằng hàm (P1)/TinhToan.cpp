#include "TinhToan.h"
#include "KiemTraSo.h"

int SoDao(int n)
{
	int SoDao = 0;
	while (n != 0)
	{
		SoDao = SoDao * 10 + n % 10;
		n /= 10;
	}
	return SoDao;
}
int TongChuSoChinhPhuong(int n, int &Zero)
{
	int TongChinhPhuong = 0, ChuSo;
	while (n != 0)
	{
		ChuSo = n % 10;
		if (SoChinhPhuong(ChuSo))
		{
			Zero = 1;
			TongChinhPhuong += ChuSo;
		}
		n /= 10;
	}

	return TongChinhPhuong;
}
int TongChuSoNguyenTo(int n)
{
	int TongNguyenTo = 0, ChuSo;
	while (n != 0)
	{
		ChuSo = n % 10;
		if (SoNguyenTo(ChuSo))
			TongNguyenTo += ChuSo;
		n /= 10;
	}

	return TongNguyenTo;
}
int TongChuSoLe(int n)
{
	int TongLe = 0, ChuSo;
	while (n != 0)
	{
		ChuSo = n % 10;
		if (ChuSo % 2 != 0)
			TongLe += ChuSo;
		n /= 10;
	}

	return TongLe;
}