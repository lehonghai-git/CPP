#include "TruongHoc.h"

void NhapTruong(TRUONGHOC &th)
{
	rewind(stdin);
	printf("Nhap Ten truong: ");
	gets_s(th.TenTruong);

	printf("Nhap Dia chi: ");
	gets_s(th.DiaChi);
	NhapLopHoc(th.Lophoc);
}
void XuatTruong(TRUONGHOC th)
{
	XuatLopHoc(th.Lophoc);
	printf("\nTen truong: %s", th.TenTruong);
	printf("\nDia chi: %s", th.DiaChi);
}