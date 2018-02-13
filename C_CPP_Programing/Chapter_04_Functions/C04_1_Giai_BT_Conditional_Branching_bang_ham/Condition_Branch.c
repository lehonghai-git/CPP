#include "Condition_Branch.h"

char DoiKiTu(char chr)
{
	if (chr >= 'A' && chr <= 'Z')
		return chr += 32;
	if (chr >= 'a' && chr <= 'z')
		return chr -= 32;
	return chr;
}
void GiaiPhuongTrinhBacNhat(float a, float b)
{
	if (a == 0)
	{
		if (b == 0) printf("Vo So Nghiem\n");
		else printf("Vo Nghiem\n");
	}
	else printf("x = %.3f\n", (float)-b / a);
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
			printf("Vo Nghiem");
	}
}
int MinHaiSo(int a, int b)
{
	return a < b ? a : b;
}
void HoanVi(int *a, int *b)
{
#if 1 // Cách 1
	int tmp = *a;
	*a = *b;
	*b = tmp;
#endif // 0

#if 0 // Cách 2: chỉ dùng cho số, VD: 6	9
	*a = *a + *b; // 6 + 9 = 15
	*b = *a - *b; // 15 - 9 = 6
	*a = *a - *b; // 15 - 6 = 9
#endif // 1
}
void SapXepBonSo(int *a, int *b, int *c, int *d)
{
	if (*a > *b)
		HoanVi(a, b);
	if (*a > *c)
		HoanVi(a, c);
	if (*a > *d)
		HoanVi(a, d);
	if (*b > *c)
		HoanVi(b, c);
	if (*b > *d)
		HoanVi(b, d);
	if (*c > *d)
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

int KiemTraNamNhuan(int Nam)
{
	return ((Nam % 4 == 0 && Nam % 100 != 0) || Nam % 400 == 0);
}
int TinhSoNgayTrongThang(int Thang, int Nam)
{
	int SoNgay;
	switch (Thang)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		SoNgay = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		SoNgay = 30;
		break;
	case 2:
	{
		if (KiemTraNamNhuan(Nam)) SoNgay = 29;
		else SoNgay = 28;
		break;
	}
	default:
		break;
	}
	return SoNgay;
}
int KiemTraNgayHopLe(int Ngay, int Thang, int Nam)
{
	if (Nam < 0) return 0;
	if (Thang < 1 || Thang > 12) return 0;
	if (Ngay < 1 || Ngay > TinhSoNgayTrongThang(Thang, Nam)) return 0;
	return 1;
}
void TinhNgayHomTruoc(int *Ngay, int *Thang, int *Nam)
{
	(*Ngay)--;
	if (*Ngay == 0)
	{
		(*Thang)--;
		if (*Thang == 0)
		{
			*Thang = 12;
			*Nam--;
		}
		*Ngay = TinhSoNgayTrongThang(*Thang, *Nam);
	}
}

void TinhNgayHomSau(int *Ngay, int *Thang, int *Nam)
{
	(*Ngay)++;
	if (*Ngay > TinhSoNgayTrongThang(*Thang, *Nam))
	{
		*Ngay = 1;
		(*Thang)++;
		if (*Thang > 12)
		{
			*Thang = 1;
			(*Nam)++;
		}
	}
}