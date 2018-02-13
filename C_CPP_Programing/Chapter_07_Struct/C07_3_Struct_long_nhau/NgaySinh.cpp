#include "NgaySinh.h"

void NhapNgaySinh(NGAYSINH &ns)
{
	rewind(stdin);
	printf("Ngay sinh: ");
	scanf_s("%d", &ns.NgaySinh);

	printf("Thang sinh: ");
	scanf_s("%d", &ns.ThangSinh);

	printf("Nam sinh: ");
	scanf_s("%d", &ns.NamSinh);
}
void XuatNgaySinh(NGAYSINH ns)
{
	printf("\nNgay sinh: %d", ns.NgaySinh);
	printf("\nThang sinh: %d", ns.ThangSinh);
	printf("\nNam sinh: %d", ns.NamSinh);
}