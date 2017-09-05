#include "KiemTraSo.h"

int SoNguyenTo(int n)
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
int SoChinhPhuong(int n)
{
	if (sqrt((float)n) == (int)sqrt((float)n))
		return 1; // True
	return 0; // False
}
int SoDoiXung(int n)
{
	int tmp = SoDao(n);
	if (n == tmp)
		return 1; // True
	return 0; // False
}