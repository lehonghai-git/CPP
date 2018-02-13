#include <stdio.h>
#include <conio.h>
#include <math.h>
#define MAX 100

void NhapMang(int *, int);
void XuatMang(int *, int);
void XuatMangCach1(int *, int);
void XuatMangCach2(int *, int);
void XuatMangCach3(int *, int);
void NhapMangBai3(int *, int);
void XuatMangBai3(int *, int);
int TongChanBai3(int *, int);
void HoanVi(int *, int *);
void DaoMangCach1(int *, int);
void DaoMangCach2(int *, int);
int* TimKiemBai5(int *, int, int);
int KiemTraSNT(int);
int* TimKiemSNTBai6(int *, int);
void ResetSNT(int *, int);
void NhapMangBai8(int *, int);
void PhanTuXuatHienNhieuNhat(int *, int);
void PhanTuXuatHienItNhat(int *, int);

int main()
{
#if 1 // Bài 1
	// Nhập mảng 1 chiều, tính tổng các phần tử của mảng
	// Sử dụng con trỏ
	int a[MAX], n;
	int *p = NULL;

	// Số phần tử
	do
	{
		printf("Nhap so phan tu: ");
		scanf_s("%d", &n);
	} while (n < 0 || n > MAX);

	// Nhập mảng
	for (p = a; p < a + n; p++)
	{
		printf("Nhap a[%d] = ", p - a);
		scanf_s("%d", p);
	}

	// Xuất mảng
	for (p = a; p < a + n; p++)
		printf("%4d", *p);

	int Sum1 = 0, Sum2 = 0;
	// Tính tổng cách 1
	for (p = a; p < a + n; p++)
		Sum1 += (*p);
	printf("\nSum1 = %d", Sum1);

	// Tính tổng cách 2
	for (int i = 0; i < n; i++)
		Sum2 += *(a + i);
	printf("\nSum2 = %d", Sum2);

#endif // Bài 1

#if 0 // Bài 2
	// In ra mảng đảo ngược theo 3 cách
	int a[MAX], n;
	do
	{
		printf("So phan tu = ");
		scanf_s("%d", &n);
	} while (n <0 || n > MAX);
	NhapMang(a, n);
	XuatMangCach1(a, n);
	printf("\n");
	XuatMangCach2(a, n);
	printf("\n");
	XuatMangCach3(a, n);
#endif // Bài 2

#if 0 // Bài 3
	// Tính tổng các số chẵn
	int a[MAX], n;
	do
	{
		printf("So phan tu = ");
		scanf_s("%d", &n);
	} while (n <0 || n > MAX);
	NhapMangBai3(a, n);
	XuatMangBai3(a, n);
	int TongChan = TongChanBai3(a, n);
	printf("\nTong chan = %d", TongChan);
#endif // Bài 3

#if 0 // Bài 4
	// Đảo ngược mảng
	int a[MAX], n;
	do
	{
		printf("So phan tu = ");
		scanf_s("%d", &n);
	} while (n <0 || n > MAX);
	NhapMang(a, n);
	XuatMang(a, n);
	DaoMangCach1(a, n);
	printf("\n");
	XuatMang(a, n);
	DaoMangCach2(a, n);
	printf("\n");
	XuatMang(a, n);
#endif // Bài 4

#if 0 // Bài 5
	// Viết hàm tìm kiếm phần tử trong mảng: int* TimKiem(int *a, int n, int GiaTri)
	// Trả về địa chỉ của phần tử tìm thấy đầu tiên trong mảng
	// Không tìm thấy trả về NULL
	int a[MAX], n;
	int GiaTri;
	do
	{
		printf("So phan tu = ");
		scanf_s("%d", &n);
	} while (n <0 || n > MAX);
	NhapMang(a, n);
	XuatMang(a, n);
	printf("\nNhap gia tri can tim: ");
	scanf_s("%d", &GiaTri);

	int *p = TimKiemBai5(a, n, GiaTri);
	if (p != NULL)
		printf("\nTim thay o vi tri: %d", p - a);
	else
		printf("\nKhong tim thay!");

#endif // 1 // Bài 5

#if 0 // Bài 6
	// Viết hàm tìm số nguyên tố trong mảng: int* TimKiemSNT(int *a, int n)
	// Trả về địa chỉ của số nguyên tố đầu tiên trong mảng nếu có
	// Trả về NULL nếu không tìm thấy số nguyên tố nào
	int a[MAX], n;
	int GiaTri;
	do
	{
		printf("So phan tu = ");
		scanf_s("%d", &n);
	} while (n <0 || n > MAX);
	NhapMang(a, n);
	XuatMang(a, n);
	int *p = TimKiemSNTBai6(a, n);
	if (p != NULL)
		printf("\nTim thay SNT tai vi tri %d", p - a);
	else
		printf("\nKhong tim thay SNT trong mang!");
#endif // Bài 6

#if 0 // Bài 7
	// Viết hàm gán tất cả các số nguyên tố có trong mảng về 0
	// Sử dụng lại hàm TimKiemSNT bài trước
	int a[MAX], n;
	int GiaTri;
	do
	{
		printf("So phan tu = ");
		scanf_s("%d", &n);
	} while (n <0 || n > MAX);
	NhapMang(a, n);
	XuatMang(a, n);
	ResetSNT(a, n);
	printf("\n");
	XuatMang(a, n);

#endif // Bài 7

#if 0 // Bài 8
	// Cho biết phần tử nào xuất hiện nhiều nhất, bao nhiêu lần
	// Cho biết phần tử nào xuất hiện ít nhất, bao nhiêu lần
	int a[MAX], n;
	int GiaTri;
	do
	{
		printf("So phan tu = ");
		scanf_s("%d", &n);
	} while (n <0 || n > MAX);
	NhapMangBai8(a, n);
	XuatMang(a, n);
	PhanTuXuatHienNhieuNhat(a, n);
	PhanTuXuatHienItNhat(a, n);
#endif // Bài 8

	_getch();
	return 0;
}


void PhanTuXuatHienNhieuNhat(int *a, int n)
{
	int PhanTuXuatHienNhieuNhat;
	int SoLan = 0;

	for (int i = 0; i < n; i++)
	{
		int dem = 0;
		for (int j = 0; j < n; j++)
			if (a[i] == a[j])
				dem++;

		if (dem > SoLan)
		{
			SoLan = dem;
			PhanTuXuatHienNhieuNhat = a[i];
		}
	}

	printf("\nPhan tu %d xuat hien nhieu nhat! (%d lan)", PhanTuXuatHienNhieuNhat, SoLan);
}
void PhanTuXuatHienItNhat(int *a, int n)
{
	int PhanTuXuatHienItNhat;
	int SoLan = n; // Giả sử mảng có n số giống nhau

	for (int i = 0; i < n; i++)
	{
		int dem = 0;
		for (int j = 0; j < n; j++)
			if (a[i] == a[j])
				dem++;

		if (dem < SoLan)
		{
			SoLan = dem;
			PhanTuXuatHienItNhat = a[i];
		}
	}

	printf("\nPhan tu %d xuat hien it nhat! (%d lan)", PhanTuXuatHienItNhat, SoLan);
}
void NhapMangBai8(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		do
		{
			printf("a[%d] = ", i);
			scanf_s("%d", &a[i]);
		} while (a[i] < -500 || a[i] > 500);
	}
}
void ResetSNT(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		int *p = TimKiemSNTBai6(a, n);
		if (p != NULL)
		{
			*p = 0;
		}
	}
}
int* TimKiemSNTBai6(int *a, int n)
{
	for (int i = 0; i < n; i++)
		if (KiemTraSNT(*(a + i))) // true
			return (a + i);
	return NULL;
}
int KiemTraSNT(int n)
{
	if (n < 2)
		return 0;
	else if (n > 2)
	{
		if (n % 2 == 0) return 0; // số chẵn

		for (int i = 3; i <= (int)sqrt((double)n); i += 2)
			if (n % i == 0)
				return 0;
	}
	// 2 là số nguyên tố
	return 1;
}
int* TimKiemBai5(int *a, int n, int GiaTri)
{
	for (int i = 0; i < n; i++)
		if (*(a + i) == GiaTri)
			return (a + i);
	return NULL;
}
void DaoMangCach1(int *a, int n)
{
	for (int i = 0; i < n / 2; i++)
		HoanVi(&a[i], &a[n - i - 1]);
}
void DaoMangCach2(int *a, int n)
{
	int *pLeft = a, *pRight = a + n - 1;
	/*while (pLeft < pRight)
	{
	HoanVi(pLeft, pRight);
	pLeft++;
	pRight--;
	}*/
	// Hoặc dùng for
	for (; pLeft < pRight; pLeft++, pRight--)
		HoanVi(pLeft, pRight);
}
void HoanVi(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void NhapMangBai3(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Nhap a[%d] = ", i);
		scanf_s("%d", a + i);
	}
}
void XuatMangBai3(int *a, int n)
{
	for (int i = 0; i < n; i++)
		printf("%4d", *(a + i));
}
int TongChanBai3(int *a, int n)
{
	int Tong = 0;
	for (int i = 0; i < n; i++)
		if (*(a + i) % 2 == 0)
			Tong += *(a + i);
	return Tong;
}
void NhapMang(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("a[%d] = ", i);
		scanf_s("%d", &a[i]);
	}
}
void XuatMang(int *a, int n)
{
	for (int i = 0; i < n; i++)
		printf("%4d", *(a + i));
}
void XuatMangCach1(int *a, int n)
{
	for (int i = n - 1; i >= 0; i--)
		printf("%4d", a[i]);
}
void XuatMangCach2(int *a, int n)
{
	for (int i = n - 1; i >= 0; i--)
		printf("%4d", *(a + i));
}
void XuatMangCach3(int *a, int n)
{
	int *p = NULL;
	for (p = a + n - 1; p >= a; p--)
		printf("%4d", *p);
}