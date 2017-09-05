#include "TinhToan.h"

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
		Sb += i*i;
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