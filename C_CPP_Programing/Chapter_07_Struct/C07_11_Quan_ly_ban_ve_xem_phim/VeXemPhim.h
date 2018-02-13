#pragma once
#include "Gio.h"
#include "Ngay.h"

typedef struct VeXemPhim
{
	char MaVe[10], Rap[20], TenPhim[30];
	float GiaBan;
	NGAY NgayChieu;
	GIO GioChieu;
}VEXEMPHIM;

void NhapVeXemPhim(VEXEMPHIM &);
void XuatVeXemPhim(VEXEMPHIM);