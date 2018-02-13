#pragma warning(disable:4996)
#include "DanhSachLuanVan.h"

void NhapDanhSachLuanVan(DANHSACHLUANVAN &ds)
{
	do
	{
		printf("Nhap so luong luan van: ");
		scanf_s("%d", &ds.n);
		if (ds.n < 0 || ds.n > MAX)
			printf("So luong khong hop le!\n");
	} while (ds.n < 0 || ds.n > MAX);

	for (int i = 0; i < ds.n; i++)
	{
		printf("\nNhap Thong Tin Luan Van Thu %d", i + 1);
		int flag;
		char tmpMaSo[10];

		do
		{
			flag = 1;

			// Nhập mã số
			rewind(stdin);
			printf("\nNhap Ma luan van: ");
			gets_s(tmpMaSo);

			// Duyệt ngược lại danh sách để kiểm tra
			for (int j = i - 1; j >= 0; j--)
			{
				if (strcmp(ds.DanhSachLuanVan[j].MaLuanVan, tmpMaSo) == 0)
				{
					flag = 0; // Phát hiện trùng
					break;
				}
			}

			if (flag == 0) // Thông báo
				printf("Ma luan van bi trung!\n");
		} while (flag == 0);

		// Mã số không bị trùng.
		strcpy_s(ds.DanhSachLuanVan[i].MaLuanVan, tmpMaSo);

		NhapLuanVan(ds.DanhSachLuanVan[i]);
	}
}
void XuatDanhSachLuanVan(DANHSACHLUANVAN ds)
{
	printf("\nTong so luan van: %d", ds.n);
	for (int i = 0; i < ds.n; i++)
	{
		printf("\nThong tin Luan van thu %d", i + 1);
		XuatLuanVan(ds.DanhSachLuanVan[i]);
	}
}
int DemTanSoXuatHienMax(DANHSACHLUANVAN ds)
{
	int Max = 0;
	for (int i = 0; i < ds.n; i++)
	{
		int dem = 0;
		for (int j = 0; j < ds.n; j++)
		{
			if (ds.DanhSachLuanVan[i].NgayThucHien.Year == ds.DanhSachLuanVan[j].NgayThucHien.Year)
			{
				dem++;
			}
		}

		if (dem > Max)
		{
			Max = dem;
		}
	}

	return Max;
}
void TimNamCoNhieuLuanVan(DANHSACHLUANVAN ds, int Max)
{
	// Tìm năm có nhiều luận văn nhất
	// Max là tần suất năm xuất hiện nhiều luận văn nhất
	for (int i = 0; i < ds.n; i++)
	{
		int check = 1;
		for (int j = i - 1; j >= 0; j--)
		{
			if (ds.DanhSachLuanVan[i].NgayThucHien.Year == ds.DanhSachLuanVan[j].NgayThucHien.Year)
			{
				check = 0;
				break;
			}
		}
		if (check == 0)
		{
			continue;
		}

		int dem = 0;
		for (int j = 0; j < ds.n; j++)
		{
			if (ds.DanhSachLuanVan[i].NgayThucHien.Year == ds.DanhSachLuanVan[j].NgayThucHien.Year)
			{
				dem++;
			}
		}
		if (dem == Max)
		{
			printf("%d   ", ds.DanhSachLuanVan[i].NgayThucHien.Year);
		}
	}
}
int TimNamGanNhat(DANHSACHLUANVAN ds)
{
	// Lấy năm hiện tại trên hệ thống
	time_t t = time(0);
	struct tm *Now = localtime(&t);
	int NamHienTai = Now->tm_year + 1900;
	int idx = 0;
	int Min = NamHienTai - ds.DanhSachLuanVan[0].NgayThucHien.Year;

	for (int i = 0; i < ds.n; i++)
	{
		if (NamHienTai - ds.DanhSachLuanVan[i].NgayThucHien.Year < Min)
		{
			Min = NamHienTai - ds.DanhSachLuanVan[i].NgayThucHien.Year;
			idx = i;
		}
	}

	return ds.DanhSachLuanVan[idx].NgayThucHien.Year;
}
void LietKeCacLuanVanGanNhat(DANHSACHLUANVAN ds)
{
	int NamGanNhat = TimNamGanNhat(ds);
	for (int i = 0; i < ds.n; i++)
	{
		if (ds.DanhSachLuanVan[i].NgayThucHien.Year == NamGanNhat)
		{
			XuatLuanVan(ds.DanhSachLuanVan[i]);
		}
	}
}
/* Một số cách khác
** 1. Tìm năm có nhiều luận văn nhất
** -
** - Mảng phụ 2 là theo thứ tự các năm ở mảng một, chứa số lần xuất hiện
** VD:  arr1 =  2015, 2017, 2014, 2018	=> Các năm không dc trùng
**		arr2 =    1,   3,    2,    4	=> Số lần xuất hiện của các năm tương ứng
**	=> Tìm Max ở arr2 => chính là số năm có nhiều luận văn nhất
**
** 2. Liệt kê các luận văn gần nhất
** Tương tự như Tìm năm có nhiều luận văn nhất
** - Mảng phụ lưu các năm (Các năm phân biệt, không trùng nhau)
**	VD: arr1 =  2015, 2017, 2014, 2018	=> Các năm không dc trùng
** - Sắp xếp mảng phụ theo chiều giảm giần
**	VD: arr1 =  2018, 2017, 2015, 2014	=> Các năm phân biệt sau khi sắp xếp
** - Dùng vòng lặp lồng nhau
**for (int i = 0; i < length_arr1; i++)
**{
**	for (int i = 0; i < length_DanhSachLuanVan; i++)
**	{
**		if (DanhSachLuanVan[i].Year == arr1[i]) {
**			XuatLuanVan();
**		}
**	}
**}
*/
