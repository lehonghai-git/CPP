#include "Loops.h"

int SoDoiXung(int n)
{
	int tmp = SoDao(n);
	if (n == tmp)
		return 1;
	return 0;
}
int SoChinhPhuong(int n)
{
	if (sqrt((float)n) == (int)sqrt((float)n))
		return 1;
	return 0;
}
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
int TongChuSoChinhPhuong(int n, int *Zero)
{
	int TongChinhPhuong = 0, ChuSo;
	while (n != 0)
	{
		ChuSo = n % 10;
		if (SoChinhPhuong(ChuSo))
		{
			*Zero = 1;
			TongChinhPhuong += ChuSo;
		}
		n /= 10;
	}

	return TongChinhPhuong;
}

float Sf(int n)
{
	/*
	n = 1 => sqrt(2);
	n = 2 => sqrt(2 + sqrt(2));
	n = 3 => sqrt(2 + sqrt(2 + sqrt(2)));
	=> S(n) = sqrt(2 + S(n - 1))
	*/
	float Sf = sqrt((float)2);
	for (int i = 2; i <= n; i++)
	{
		Sf = sqrt(2 + Sf);
	}
	return Sf;
}
int Se(int n)
{
#if 0
	// Cách 1
	int Se = 0;
	for (int i = 1; i <= n; i++)
	{
		Se += Sd(i);
	}
#endif // 0

#if 1
	// Cách 2
	int Se = 0, Tich = 1;
	for (int i = 1; i <= n; i++)
	{
		Tich *= i;
		Se += Tich;
	}
#endif // 1
	return Se;
}
int Sd(int n)
{
	int Sd = 1;
	for (int i = 1; i <= n; i++)
		Sd *= i;
	return Sd;
}
float Sc(int n)
{
	float Sc = 0;
	for (int i = 1; i <= n; i++)
		Sc += (float)1 / i;
	return Sc;
}
int Sb(int n)
{
	int Sb = 0;
	for (int i = 1; i <= n; i++)
		Sb += i * i;
	return Sb;
}
int Sa(int n)
{
	// Có một công thức để tính nhanh trong bài này:
	// 1+2+..+n = (n * (n + 1)) / 2 
	int Sa = 0;
	for (int i = 1; i <= n; i++)
		Sa += i;
	return Sa;
}

int TinhGiaiThua(int n)
{
	int Tich = 1;
	for (int i = 2; i <= n; i++)
		Tich *= i;
	return Tich;
}
int UocSoChungLonNhat(int a, int b)
{
	a = abs(a);
	b = abs(b);

	if (a == 0 || b == 0)
		return a + b;
	while (a != b)
	{
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	return a;
}
void InDayFib(int n)
{
	int A0, A1, An;
	A0 = A1 = 1;
	if (n == 1)
		printf("%d  \n", A0);
	else if (n == 2)
		printf("%d  %d\n", A0, A1);
	else
	{
		printf("%d  %d  ", A0, A1);
		for (int i = 1; i <= n - 2; i++) // n-2 vì trừ đi 2 số đã in là A0 và A1
		{
			An = A0 + A1;
			A0 = A1; // Cập nhập số
			A1 = An; // Cập nhập số
			printf("%d  ", An);
		}
		printf("\n");
	}
}