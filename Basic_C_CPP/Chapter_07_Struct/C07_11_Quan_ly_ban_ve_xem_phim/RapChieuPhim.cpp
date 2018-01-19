#include "RapChieuPhim.h"

void NhapDanhSachVe(RAPCHIEUPHIM &rap)
{
	do
	{
		printf("\nNhap so luong ve: ");
		scanf_s("%d", &rap.n);
		if (rap.n < 0 || rap.n > MAX)
		{
			printf("So luong ve khong hop le!\n");
		}
	} while (rap.n < 0 || rap.n > MAX);

	for (int i = 0; i < rap.n; i++)
	{
		printf("\nNhap Thong Tin Ve Thu %d", i + 1);
		int flag;
		char tmpMaSo[10];

		do
		{
			flag = 1;
			rewind(stdin);
			printf("\nNhap Ma ve: ");
			gets_s(tmpMaSo);

			for (int j = i - 1; j >= 0; j--)
			{
				if (strcmp(rap.DanhSachVe[j].MaVe, tmpMaSo) == 0)
				{
					flag = 0;
					break;
				}
			}
			if (flag == 0) printf("Ma ve bi trung!\n");
		} while (flag == 0);

		// Mã số không trùng.
		strcpy_s(rap.DanhSachVe[i].MaVe, tmpMaSo);
		NhapVeXemPhim(rap.DanhSachVe[i]);
	}
}
void XuatDanhSachVe(RAPCHIEUPHIM rap)
{
	for (int i = 0; i < rap.n; i++)
	{
		XuatVeXemPhim(rap.DanhSachVe[i]);

	}
}
float TinhTongTienBanVe(RAPCHIEUPHIM rap)
{
	float Tong = 0;
	for (int i = 0; i < rap.n; i++)
	{
		Tong += rap.DanhSachVe[i].GiaBan;
	}

	return Tong;
}

// Xuất ra các ngày chiếu nhiều phim nhất (Tương tự các bài trước)
// Xuất ra các vé có giá ban cao nhất (Tương tự các bài trước)