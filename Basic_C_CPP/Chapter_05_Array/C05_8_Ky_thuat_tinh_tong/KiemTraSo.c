#include "KiemTraSo.h"

int KiemTraChuSoHangChuc(int x)
{
	x /= 10;
	int ChuSo = x % 10;
	return ChuSo == 5;
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