#include "NgaySinh.h"

typedef struct SinhVien
{
	char MaSo[20], Hoten[50];
	NGAYSINH Ngaysinh;
} SINHVIEN;

void NhapSinhVien(SINHVIEN &);
void XuatSinhVien(SINHVIEN);