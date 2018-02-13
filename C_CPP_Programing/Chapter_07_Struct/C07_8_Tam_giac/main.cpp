#include <stdio.h>
#include <conio.h>
#include <math.h>

typedef struct Diem
{
	float x, y;
}DIEM;
typedef struct TamGiac
{
	DIEM a, b, c;
}TAMGIAC;

void NhapDiem(DIEM &d)
{
	printf("\nNhap toa do x: ");
	scanf_s("%f", &d.x);
	printf("Nhap toa do y: ");
	scanf_s("%f", &d.y);
}
void XuatDiem(DIEM d)
{
	printf("(%f, %f)", d.x, d.y);
}
float TinhKhoangCachHaiDiem(DIEM d1, DIEM d2)
{
	return sqrt(pow(d2.x - d1.x, 2) + pow(d2.y - d1.y, 2));
}
void NhapTamGiac(TAMGIAC &tg)
{
	float a, b, c;
	do
	{
		printf("Nhap diem A ");
		NhapDiem(tg.a);
		printf("Nhap diem B ");
		NhapDiem(tg.b);
		printf("Nhap diem C ");
		NhapDiem(tg.c);

		a = TinhKhoangCachHaiDiem(tg.a, tg.b);
		b = TinhKhoangCachHaiDiem(tg.a, tg.c);
		c = TinhKhoangCachHaiDiem(tg.c, tg.b);

		if (a + b <= c || a + c <= b || b + c <= a)
		{
			printf("3 diem khong tao thanh tam giac!\n");
		}
	} while (a + b <= c || a + c <= b || b + c <= a);

}
void XuatTamGiac(TAMGIAC tg)
{
	printf("\nA");
	XuatDiem(tg.a);
	printf("\nB");
	XuatDiem(tg.b);
	printf("\nC");
	XuatDiem(tg.c);
}
float TinhChuViTamGiac(TAMGIAC tg)
{
	float AB = TinhKhoangCachHaiDiem(tg.a, tg.b);
	float AC = TinhKhoangCachHaiDiem(tg.a, tg.c);
	float BC = TinhKhoangCachHaiDiem(tg.c, tg.b);
	return  AB + AC + BC;
}
float TinhDienTichTamGiac(TAMGIAC tg)
{
	float p, a, b, c;
	p = TinhChuViTamGiac(tg) / 2;
	a = TinhKhoangCachHaiDiem(tg.a, tg.b);
	b = TinhKhoangCachHaiDiem(tg.a, tg.c);
	c = TinhKhoangCachHaiDiem(tg.c, tg.b);
	return sqrt(p*(p - a)*(p - b)*(p - c));
}

int main()
{
	TAMGIAC tg;
	NhapTamGiac(tg);
	XuatTamGiac(tg);
	float Chuvi = TinhChuViTamGiac(tg);
	float Dientich = TinhDienTichTamGiac(tg);
	printf("\nChu vi: %f", Chuvi);
	printf("\nDien tich: %f", Dientich);

	_getch();
	return 0;
}