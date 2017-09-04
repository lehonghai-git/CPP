#include "KiemTraSo.h"

int KiemTraSoDoiXung(int n)
{
	int SoDao = 0, tmp = n;
	while (n != 0)
	{
		SoDao = SoDao * 10 + n % 10;
		n /= 10;
	}
	return SoDao == tmp; // 1 or 0
}
int KiemTraSoAmstrong(int n)
{
	int ChuSo, tmp = n;
	int SoLuongChuSo = log10(float(n)) + 1;
	int Tong = 0;
	while (tmp != 0)
	{
		ChuSo = tmp % 10;
		Tong += pow(ChuSo, SoLuongChuSo);
		tmp /= 10;
	}
	return Tong == n; // 1 or 0
}
int KiemTraMangChan(int a[], int n)
{
	for (int i = 0; i < n; i++)
		if (a[i] % 2 != 0)
			return 0; // Có phần tử lẻ
	return 1; // Mảng chẵn
}
int KiemTraSoHoanThien(int n)
{
	int Tong = 0;
	for (int i = 1; i <= n / 2; i++)
		if (n % i == 0)
			Tong += i;
	return Tong == n; // 1 or 0
}
int KiemTraSoDangAMuK(int x, int coso)
{
	/*
	Hàm kiểm tra xem một số nào đó có dạng a^k hay không
	Trong đó a là cơ số và k là số mũ
	*/
	double kq = log10((double)x) / log10((double)coso);
	return kq == (int)kq; // = 1: Có dạng a^k hoặc ngược lại = 0 : không có dạng a^k
}
int KiemTraNguyenTo(int n)
{
	if (n < 2)
		return 0;
	else if (n > 2)
	{
		if (n % 2 == 0)
			return 0;
		for (int i = 3; i <= (int)sqrt((double)n); i += 2)
			if (n % i == 0)
				return 0;
	}
	return 1;
}
