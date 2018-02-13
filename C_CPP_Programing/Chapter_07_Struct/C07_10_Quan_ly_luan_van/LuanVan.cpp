#include "LuanVan.h"

void NhapLuanVan(LUANVAN &lv)
{
	rewind(stdin);
	/*printf("\nNhap Ma luan van: ");
	gets_s(lv.MaLuanVan);*/

	printf("\nNhap Ten luan van: ");
	gets_s(lv.TenLuanVan);

	printf("\nNhap Ten sinh vien thuc hien: ");
	gets_s(lv.TenSinhVien);

	printf("\nNhap Giang vien huong dan: ");
	gets_s(lv.TenGiangVien);

	printf("Nhap ngay thuc hien: ");
	NhapNgay(lv.NgayThucHien);
}
void XuatLuanVan(LUANVAN lv)
{
	printf("\nMa luan van: %s", lv.MaLuanVan);
	printf("\nTen luan van: %s", lv.TenLuanVan);
	printf("\nTen sinh vien thuc hien: %s", lv.TenSinhVien);
	printf("\nGiang vien huong dan: %s", lv.TenGiangVien);
	printf("\nNgay thuc hien: ");
	XuatNgay(lv.NgayThucHien);
}