﻿#include "NhapXuat.h"
#include "KiemTraSo.h"
#include "TachMang.h"
#define MAX 100

/*
** TÁCH MẢNG
*/

int main()
{
	int n, a[MAX];
	do
	{
		printf("Nhap so luong phan tu: ");
		scanf("%d", &n);
		if (n < 0 || n > MAX)
			printf("So luong phan tu khong hop le.\n");
	} while (n < 0 || n > MAX);
	//NhapMang(a, n);
	NhapMangNgauNhien(a, n);
	printf("Mang vua nhap: \n");
	XuatMang(a, n);

#if 0 // Tách mảng chẵn, mảng lẻ
	int chan[MAX], le[MAX], nchan, nle;
	TachMang(a, n, chan, &nchan, le, &nle);

	printf("\nMang chan:\n");
	XuatMang(chan, nchan);

	printf("\nMang le:\n");
	XuatMang(le, nle);
#endif // Tách mảng chẵn, mảng lẻ

#if 0 // Tách mảng các số nguyên tố, chính phương
	int b[MAX], nb, c[MAX], nc;
	TachMangNguyenTo(a, n, b, &nb);
	printf("\nMang nguyen to:\n");
	XuatMang(b, nb);

	TachMangChinhPhuong(a, n, c, &nc);
	printf("\nMang chinh phuong:\n");
	XuatMang(c, nc);
#endif // Tách mảng các số nguyên tố, chính phương

	getch();
	return 0;
}