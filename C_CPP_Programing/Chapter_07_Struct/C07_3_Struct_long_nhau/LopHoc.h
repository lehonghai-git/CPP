#include "SinhVien.h"

typedef struct LopHoc
{
	char TenLop[10];
	int SiSo;
	SINHVIEN Sinhvien; // Hoặc một mảng sinh viên
}LOPHOC;

void NhapLopHoc(LOPHOC &);
void XuatLopHoc(LOPHOC);