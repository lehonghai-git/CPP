#pragma once
#include "Ngay.h"

typedef struct LuanVan
{
	char MaLuanVan[10], TenLuanVan[100], TenSinhVien[30], TenGiangVien[30];
	NGAY NgayThucHien;
}LUANVAN;

void NhapLuanVan(LUANVAN &);
void XuatLuanVan(LUANVAN);