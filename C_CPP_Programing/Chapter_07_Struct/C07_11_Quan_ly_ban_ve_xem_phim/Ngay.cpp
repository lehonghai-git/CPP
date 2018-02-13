#include "Ngay.h"

void NhapNgay(NGAY & ng)
{

	do
	{
		printf("\nNhap nam: ");
		scanf_s("%d", &ng.Year);
	} while (ng.Year < 1900);

	do
	{
		printf("\nNhap thang: ");
		scanf_s("%d", &ng.Month);
	} while (ng.Month < 0 || ng.Month > 12);

	do
	{
		// Cần kiểm tra kỹ hơn với ngày: 28, 29, 30 , 31 ngày..v.v.
		printf("\nNhap ngay: ");
		scanf_s("%d", &ng.Day);
	} while (ng.Day < 0 || ng.Day > 31);

}

void XuatNgay(NGAY ng)
{
	printf(" %d/%d/%d", ng.Day, ng.Month, ng.Year);
}