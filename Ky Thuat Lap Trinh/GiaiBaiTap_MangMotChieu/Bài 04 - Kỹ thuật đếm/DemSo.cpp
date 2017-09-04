#include "DemSo.h"
#include "KiemTraSo.h"

void PhanTuPhanBiet(int a[], int n)
{
	/*
	Đứng từ 1 vị trí, xét lùi lại các vị trí trước đó đã xét.
	Nếu có sự trùng lặp => cập nhật cờ hiệu và dưng xét.
	Đến cuối cùng kiểm tra cờ hiệu để biết có bị trùng hay không
	*/
	int dem = 1;
	printf("%d   ", a[0]);
	for (int i = 1; i < n; i++)
	{
		int Check = 1;
		for (int j = i - 1; j >= 0; j--)
		{
			if (a[i] == a[j])
			{
				Check = 0; // Bị trùng
				break;
			}
		}
		if (Check == 1) // Trường hợp không bị trùng
		{
			dem++;
			printf("%d   ", a[i]);
		}
	}
	printf("\nCo %d phan tu phan biet\n", dem);
}
int DemSoPhanTuTrung(int a[], int n, int vtht)
{
	// Đếm từ vị trí hiện tại (vtht) trở về sau xem có bao nhiêu phần tử trùng
	int dem = 1;
	for (int i = vtht + 1; i < n; i++)
		if (a[i] == a[vtht])
			dem++;
	return dem;
}
void DemTanSuatXuatHien(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int Check = KiemTraBiTrung(a, n, i);
		if (Check == 0) // Không trùng
		{
			int dem = DemSoPhanTuTrung(a, n, i);
			printf("Phan tu %d xuat hien %d lan\n", a[i], dem);
		}
	}
}
int DemTanSuatXuatHienNhieuNhat(int a[], int n)
{
	// Đếm xem số lần xuất hiện nhiều nhất của một phần tử trong mảng là bao nhiêu lần
	int Max = 1;
#if 0
	// Cách 1:
	for (int i = 0; i < n; i++)
	{
		int Check = KiemTraBiTrung(a, n, i);
		if (Check == 0) // Không trùng
		{
			int dem = DemSoPhanTuTrung(a, n, i);
			if (dem > Max)
				Max = dem;
		}
	}
#endif // 0

#if 1
	// Cách 2
	for (int i = 0; i < n; i++)
	{
		int dem = 1;
		for (int j = i + 1; j < n; j++)
			if (a[i] == a[j])
				dem++;
		if (dem > Max)
			Max = dem;
	}
#endif // 1

	return Max;
}
int DemSoChan(int a[], int n)
{
	int SoLuongSoChan = 0;
	for (int i = 0; i < n; i++)
		if (a[i] % 2 == 0) // Chẵn
			SoLuongSoChan++;
	return SoLuongSoChan;
}