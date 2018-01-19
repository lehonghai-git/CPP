#include "VeXemPhim.h"

void NhapVeXemPhim(VEXEMPHIM & ve)
{
	rewind(stdin);
	/*printf("\nNhap Ma ve: ");
	gets_s(ve.MaVe);*/

	printf("\nNhap vao Rap: ");
	gets_s(ve.Rap);

	printf("\nNhap Ten phim: ");
	gets_s(ve.TenPhim);

	do
	{
		printf("\nNhap Gia ban: ");
		scanf_s("%f", &ve.GiaBan);
		if (ve.GiaBan < 0)
		{
			printf("Nhap lai gia ban!\n");
		}
	} while (ve.GiaBan < 0);

	printf("Nhap ngay chieu");
	NhapNgay(ve.NgayChieu);

	printf("Nhap gio chieu");
	NhapGio(ve.GioChieu);
}
void XuatVeXemPhim(VEXEMPHIM ve)
{
	printf("\n\nMa ve: %s", ve.MaVe);
	printf("\nRap: %s", ve.Rap);
	printf("\nTen phim: %s", ve.TenPhim);
	printf("\nGia ve: %.2f", ve.GiaBan);
	printf("\nNgay chieu:");
	XuatNgay(ve.NgayChieu);
	printf("\nGio chieu: ");
	XuatGio(ve.GioChieu);
}