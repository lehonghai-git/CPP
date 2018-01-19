#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

typedef struct Sach
{
	char MaSach[10];
	char TenSach[30];
	char NhaXuatBan[30];
	char TenTacGia[30];
	float GiaBan;
	int NamPhatHanh;
}SACH;

typedef struct ThuVien
{
	int n; // số lượng
	SACH DanhSachCuonSach[MAX];
}THUVIEN;

void NhapSach(SACH &s)
{
	rewind(stdin);
	/*printf("\nNhap ma sach: ");
	gets_s(s.MaSach);*/

	printf("Nhap ten sach: ");
	gets_s(s.TenSach);

	printf("Nhap ten NXB: ");
	gets_s(s.NhaXuatBan);

	printf("Nhap ten tac gia: ");
	gets_s(s.TenTacGia);

	printf("Nhap nam phat hanh: ");
	scanf_s("%d", &s.NamPhatHanh);
	do
	{
		printf("Nhap gia ban: ");
		scanf_s("%f", &s.GiaBan);
	} while (s.GiaBan < 0);
}
void XuatSach(SACH s)
{
	printf("\nMa sach: %s", s.MaSach);
	printf("\nTen sach: %s", s.TenSach);
	printf("\nNXH: %s", s.NhaXuatBan);
	printf("\nTen TG: %s", s.TenTacGia);
	printf("\nPhat hanh: %d", s.NamPhatHanh);
	printf("\nGia: %f", s.GiaBan);
}
void NhapThuVien(THUVIEN &tv)
{
	do
	{
		printf("Nhap so luong cuon sach: ");
		scanf_s("%d", &tv.n);
	} while (tv.n < 0 || tv.n > MAX);

	for (int i = 0; i < tv.n; i++)
	{
		printf("Nhap cuon sach thu %d", i + 1);
		char tmpMaSach[10];
		int flag;

		do
		{
			flag = 1;
			rewind(stdin);
			printf("\nNhap ma sach: ");
			gets_s(tmpMaSach);

			for (int j = i - 1; j >= 0; j--)
			{
				if (strcmp(tv.DanhSachCuonSach[j].MaSach, tmpMaSach) == 0)
				{
					flag = 0;
					break;
				}
			}
			if (flag == 0)
			{
				printf("Ma sach bi trung");
			}
		} while (flag == 0);

		strcpy_s(tv.DanhSachCuonSach[i].MaSach, tmpMaSach);
		NhapSach(tv.DanhSachCuonSach[i]);
	}

}
void XuatThuVien(THUVIEN tv)
{
	int n = tv.n;
	printf("\nTong so cuon: %d", n);
	for (int i = 0; i < n; i++)
	{
		printf("\nCuon thu %d", i + 1);
		XuatSach(tv.DanhSachCuonSach[i]);
	}
}
void NamXuatBanNhieuSachNhat(THUVIEN tv)
{
	/*
	** arr1 = 2010, 2011, 2015, 2016, 2012 => Chứa các năm phân biệt nhau
	** arr2 =  3	 2		1	 4	   2	=> Số lần xuất hiện
	*/
	// Đếm số Năm phân biệt
	int SoNam = 1, flag1;
	for (int i = 1; i < tv.n; i++)
	{
		flag1 = 1;
		int tmp = tv.DanhSachCuonSach[i].NamPhatHanh;
		for (int j = i - 1; j >= 0; j--)
		{
			if (tv.DanhSachCuonSach[j].NamPhatHanh == tmp)
			{
				flag1 = 0;
				break;
			}
		}
		if (flag1 == 1)
		{
			SoNam++;
		}
	}
	//printf("\nSo nam phan biet: %d", dem);


	int *arr1 = new int[SoNam];

	//memset(arr1, 0, tv.n); // set zero
	//for (int i = 0; i < tv.n; i++) arr1[i] = 0;
	arr1[0] = tv.DanhSachCuonSach[0].NamPhatHanh;
	/*for (int i = 1; i < tv.n; i++)
	{
	flag = 1;
	int tmp = tv.DanhSachCuonSach[i].NamPhatHanh;
	for (int j = 0; j < tv.n; j++)
	{
	if (arr1[j] == tmp)
	{
	flag = 0;
	break;
	}
	}
	if (flag == 1)
	{
	arr1[idx++] = tmp;
	}
	}*/
	int flag2, idx = 1;;
	for (int i = 1; i < tv.n; i++)
	{
		flag2 = 1;
		int tmp = tv.DanhSachCuonSach[i].NamPhatHanh;
		for (int j = i - 1; j >= 0; j--)
		{
			if (tv.DanhSachCuonSach[j].NamPhatHanh == tmp)
			{
				flag2 = 0;
				break;
			}
		}

		if (flag2 == 1)
		{
			arr1[idx++] = tmp;
		}
	}
	// show arr1
	printf("\nThong ke:");
	for (int i = 0; i < SoNam; i++)
		printf("\t%d", arr1[i]);

	/*int idx_arr2;
	for (int i = 0; i < tv.n; i++)
	{
	if (arr1[i] == 0)
	{
	idx_arr2 = i - 1;
	}
	}*/

	int *arr2 = new int[SoNam];
	// Set Zero
	for (int i = 0; i < SoNam; i++) arr2[i] = 0;

	// Đếm tần suất xuất hiện
	for (int i = 0; i < tv.n; i++)
	{
		int tmp = tv.DanhSachCuonSach[i].NamPhatHanh;
		for (int j = 0; j < SoNam; j++)
			if (arr1[j] == tmp)
				arr2[j]++;
	}

	printf("\n\t");
	for (int i = 0; i < SoNam; i++)
		printf("\t%d", arr2[i]);
}

int main()
{
	THUVIEN tv;
	NhapThuVien(tv);
	XuatThuVien(tv);
	NamXuatBanNhieuSachNhat(tv);
	_getch();
	return 0;
}