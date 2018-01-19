#include "DanhSachLuanVan.h"
#include <conio.h>

int main()
{
	DANHSACHLUANVAN ds;
	NhapDanhSachLuanVan(ds);
	XuatDanhSachLuanVan(ds);

	printf("\n\nNam co nhieu luan van nhat: ");
	int TanSuatMax = DemTanSoXuatHienMax(ds);
	TimNamCoNhieuLuanVan(ds, TanSuatMax);

	printf("\n\nCac luan van gan day: ");
	LietKeCacLuanVanGanNhat(ds);
	_getch();
	return 0;
}