#include "LopHoc.h"

void NhapLopHoc(LOPHOC &lh)
{
	rewind(stdin);
	printf("Nhap Ten lop: ");
	gets_s(lh.TenLop);

	printf("Nhap Si so: ");
	scanf_s("%d", &lh.SiSo);
	NhapSinhVien(lh.Sinhvien);
}
void XuatLopHoc(LOPHOC lh)
{
	XuatSinhVien(lh.Sinhvien);
	printf("\nTen lop: %s", lh.TenLop);
	printf("\nSi so: %d", lh.SiSo);
}