#include "LopHoc.h"

typedef struct TruongHoc
{
	char TenTruong[50], DiaChi[50];
	LOPHOC Lophoc; // Hoặc một mảng lớp học
}TRUONGHOC;

void NhapTruong(TRUONGHOC &);
void XuatTruong(TRUONGHOC);