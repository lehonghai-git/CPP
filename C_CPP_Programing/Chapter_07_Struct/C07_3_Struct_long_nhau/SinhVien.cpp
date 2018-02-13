#include "SinhVien.h"

void NhapSinhVien(SINHVIEN &sv)
{
	rewind(stdin); // clear buff
	printf("Nhap Ho ten: ");
	gets_s(sv.Hoten);
	printf("Nhap Ma so: ");
	gets_s(sv.MaSo);
	NhapNgaySinh(sv.Ngaysinh);
}
void XuatSinhVien(SINHVIEN sv)
{
	XuatNgaySinh(sv.Ngaysinh);
	printf("\nMa so: %s", sv.MaSo);
	printf("\nHo ten: %s", sv.Hoten);
}