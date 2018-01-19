#include <stdio.h>
#include <conio.h>
#include <math.h>

typedef struct PhanSo
{
	int TuSo;
	int MauSo;
}PHANSO;

void NhapPhanSo(PHANSO &);
void XuatPhanSo(PHANSO);
int TimUocChungLonNhat(int, int);
void RutGonPhanSo(PHANSO &);
PHANSO TinhPhanSo(PHANSO, PHANSO, char);
bool KiemTraPhanSoToiGian(PHANSO);
bool KiemTraPhanSoAmDuong(PHANSO);
int SoSanhHaiPhanSo(PHANSO, PHANSO);

int main()
{
	PHANSO ps1;

	NhapPhanSo(ps1);
	printf("Phan so 1: ");
	XuatPhanSo(ps1);

#if 0 // Rút gọn phân số
	printf("\nPhan so rut gon: ");
	RutGonPhanSo(ps1);
	XuatPhanSo(ps1);
#endif // 0 // Rút gọn phân số

#if 0 // Tổng, hiệu, tích, thương hai phân số
	PHANSO ps2;
	NhapPhanSo(ps2);
	printf("Phan so 2: ");
	XuatPhanSo(ps2);

	PHANSO ps3, ps4, ps5, ps6;

	ps3 = TinhPhanSo(ps1, ps2, '+');
	printf("\nTong hai phan so: ");
	XuatPhanSo(ps3);

	ps4 = TinhPhanSo(ps1, ps2, '-');
	printf("\nHieu hai phan so: ");
	XuatPhanSo(ps4);

	ps5 = TinhPhanSo(ps1, ps2, '*');
	printf("\nTich hai phan so: ");
	XuatPhanSo(ps5);

	ps6 = TinhPhanSo(ps1, ps2, '/');
	printf("\nThuong hai phan so: ");
	XuatPhanSo(ps6);

#endif // 1 // Tổng, hiệu, tích, thương hai phân số

#if 0 // Kiểm tra phân số tối giản
	if (KiemTraPhanSoToiGian(ps1))
		printf("\nDa toi gian!");
	else
		printf("\nChua toi gian!");
#endif // 1 // Kiểm tra phân số tối giản

#if 0 // Kiểm tra âm dương
	if (KiemTraPhanSoAmDuong(ps1))
		printf("\nPhan so duong!");
	else
		printf("\nPhan so am!");
#endif // 1 // Kiểm tra âm dương

#if 1 // So sánh hai phân số
	PHANSO ps2;
	NhapPhanSo(ps2);
	printf("Phan so 2: ");
	XuatPhanSo(ps2);

	if (SoSanhHaiPhanSo(ps1, ps2) == 1)
		printf("\nPhan so 1 > Phan so 2\n");
	else if (SoSanhHaiPhanSo(ps1, ps2) == -1)
		printf("\nPhan so 1 < Phan so 2\n");
	else
		printf("\nPhan so 1 = Phan so 2\n");
#endif // 1 // So sánh hai phân số

	_getch();
	return 0;
}

void NhapPhanSo(PHANSO &ps)
{
	printf("\nNhap Tu so: ");
	scanf_s("%d", &ps.TuSo);
	do
	{
		printf("Nhap Mau so: ");
		scanf_s("%d", &ps.MauSo);
		if (ps.MauSo == 0)
			printf("Mau so phai khac 0\n");
	} while (ps.MauSo == 0);
}
void XuatPhanSo(PHANSO ps)
{
	printf("%d/%d\n", ps.TuSo, ps.MauSo);
}
int TimUocChungLonNhat(int a, int b)
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
void RutGonPhanSo(PHANSO &ps)
{
	int UCLN = TimUocChungLonNhat(ps.TuSo, ps.MauSo);
	ps.TuSo = ps.TuSo / UCLN;
	ps.MauSo = ps.MauSo / UCLN;
}
PHANSO TinhPhanSo(PHANSO ps1, PHANSO ps2, char chr)
{
	PHANSO tmpPS;
	if (chr == '+')
	{
		tmpPS.TuSo = (ps1.TuSo * ps2.MauSo + ps1.MauSo * ps2.TuSo);
		tmpPS.MauSo = (ps1.MauSo * ps2.MauSo);
	}
	else if (chr == '-')
	{
		tmpPS.TuSo = (ps1.TuSo * ps2.MauSo - ps1.MauSo * ps2.TuSo);
		tmpPS.MauSo = (ps1.MauSo * ps2.MauSo);
	}
	else if (chr == '*' || chr == 'x' || chr == 'X')
	{
		tmpPS.TuSo = (ps1.TuSo * ps2.TuSo);
		tmpPS.MauSo = (ps1.MauSo * ps2.MauSo);
	}
	else if (chr == '/' || chr == ':')
	{
		tmpPS.TuSo = (ps1.TuSo * ps2.MauSo);
		tmpPS.MauSo = (ps1.MauSo * ps2.TuSo);
	}
	else
	{
		tmpPS.TuSo = 0;
		tmpPS.MauSo = 0;
	}

	RutGonPhanSo(tmpPS);
	return tmpPS;
}
bool KiemTraPhanSoToiGian(PHANSO ps)
{
	return TimUocChungLonNhat(ps.TuSo, ps.MauSo) == 1;
}
bool KiemTraPhanSoAmDuong(PHANSO ps)
{
	if (ps.TuSo < 0 && ps.MauSo > 0)
		return false; // -
	if (ps.TuSo > 0 && ps.MauSo < 0)
		return false; // -
	return true; // +
}
int SoSanhHaiPhanSo(PHANSO ps1, PHANSO ps2)
{
	/*
	** return  0: PS1 = PS2
	** return  1: PS1 > PS2
	** return -1: PS1 < PS2
	*/

	float tmp1, tmp2;
	tmp1 = (float)ps1.TuSo / ps1.MauSo;
	tmp2 = (float)ps2.TuSo / ps2.MauSo;

	if (tmp1 > tmp2) return 1;
	else if (tmp1 < tmp2) return -1;

	return 0;
}