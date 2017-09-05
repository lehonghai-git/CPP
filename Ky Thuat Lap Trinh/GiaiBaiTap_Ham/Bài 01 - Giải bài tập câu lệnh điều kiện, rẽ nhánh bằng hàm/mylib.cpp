#include "mylib.h"

void SapXepBonSo(int &a, int &b, int &c, int &d)
{
	if (a > b)
		HoanVi(a, b);
	if (a > c)
		HoanVi(a, c);
	if (a > d)
		HoanVi(a, d);
	if (b > c)
		HoanVi(b, c);
	if (b > d)
		HoanVi(b, d);
	if (c > d)
		HoanVi(c, d);
	/*
	Sau mỗi lần so sánh thì các số nhỏ đều được dồn hết về đầu
	VD: 3 9 1 7 6
	Lần 1: 3vs9 => 3 9 1 7 6
	Lần 2: 3vs1 => 1 9 3 7 6
	Lần 3, 4: 1vs7 và 1vs6 => giữ nguyên
	Lần 5: 9vs3 => 1 3 9 7 6
	Lần 6, 7: 3vs7 và 3vs6 => giữ nguyên
	Lần 8: 9vs7 => 1 3 7 9 6
	Lần 9: 7vs6 => 1 3 6 9 7
	Lần 10: 9vs7 => 1 3 6 7 9 => end
	*/
}
void HoanVi(int &a, int &b)
{
#if 1 // Cách 1
	int tmp = a;
	a = b;
	b = tmp;
#endif // 0

#if 0 // Cách 2: chỉ dùng cho số, VD: 6	9
	a = a + b; // 6 + 9 = 15
	b = a - b; // 15 - 9 = 6
	a = a - b; // 15 - 6 = 9
#endif // 1
}
int MinHaiSo(int a, int b)
{
	return a < b ? a : b;
}
void GiaiPhuongTrinhBacHai(float a, float b, float c)
{
	if (a == 0) // PT bậc nhất b.x + c = 0
		GiaiPhuongTrinhBacNhat(b, c);
	else
	{
		float Delta = b * b - 4 * a * c;
		if (Delta > 0)
		{
			float x1 = (-b - sqrt(Delta)) / (2 * a);
			float x2 = (-b + sqrt(Delta)) / (2 * a);
			printf("X1 = %f\n", x1);
			printf("X2 = %f\n", x2);
		}
		else if (Delta == 0)
			printf("X1 = X2 = %f", -b / (2 * a));
		else
			printf("VN");
	}
}
void GiaiPhuongTrinhBacNhat(float a, float b)
{
	if (a == 0)
	{
		if (b == 0) printf("VSN\n");
		else printf("VN\n");
	}
	else printf("x = %.3f\n", (float)-b / a);
}
char DoiKiTu(char chr)
{
	if (chr >= 'A' && chr <= 'Z')
		return chr += 32;
	if (chr >= 'a' && chr <= 'z')
		return chr -= 32;
	return chr;
}