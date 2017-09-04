#include "XuatKetQua.h"

void LietKeTanSuatXuatHienNhieuNhat(int a[], int n)
{
	int TanSuatNhieuNhat = DemTanSuatXuatHienNhieuNhat(a, n);
	printf("Cac phan tu xuat hien nhieu nhat: ");
	for (int i = 0; i < n; i++)
	{
		int Check = KiemTraBiTrung(a, n, i);
		if (Check == 0) // Không trùng
		{
			int dem = DemSoPhanTuTrung(a, n, i);
			//printf("Phan tu %d xuat hien %d lan\n", a[i], dem);
			if (dem == TanSuatNhieuNhat)
				printf("%d ", a[i]);
		}
	}
	printf("=> tan suat = %d\n", TanSuatNhieuNhat);
}