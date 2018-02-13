#include "RapChieuPhim.h"
#include <conio.h>

int main()
{
	RAPCHIEUPHIM rap;
	NhapDanhSachVe(rap);
	XuatDanhSachVe(rap);
	float TongTien = TinhTongTienBanVe(rap);
	printf("\nTong tien ban ve: %.2f", TongTien);

	_getch();
	return 0;
}