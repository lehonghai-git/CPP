#include "Gio.h"

void NhapGio(GIO &g)
{
	do
	{
		printf("\nNhap gio: ");
		scanf_s("%d", &g.Hour);
	} while (g.Hour < 0 || g.Hour > 24);

	do
	{
		printf("\nNhap phut: ");
		scanf_s("%d", &g.Minute);
	} while (g.Minute < 0 || g.Minute > 59);

	do
	{
		printf("\nNhap giay: ");
		scanf_s("%d", &g.Second);
	} while (g.Second < 0 || g.Second > 59);
}
void XuatGio(GIO g)
{
	printf(" %d:%d:%d", g.Hour, g.Minute, g.Second);
}