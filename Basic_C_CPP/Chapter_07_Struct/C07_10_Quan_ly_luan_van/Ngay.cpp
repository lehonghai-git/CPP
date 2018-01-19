#include "Ngay.h"

void NhapNgay(NGAY &n)
{
	// Cần phải có điều kiện ngày, tháng, năm xem có hợp lệ không
	printf("\nNhap ngay: ");
	scanf_s("%d", &n.Day);

	printf("Nhap thang: ");
	scanf_s("%d", &n.Month);

	printf("Nhap nam: ");
	scanf_s("%d", &n.Year);
}
void XuatNgay(NGAY n)
{
	printf("%d/%d/%d", n.Day, n.Month, n.Year);
}