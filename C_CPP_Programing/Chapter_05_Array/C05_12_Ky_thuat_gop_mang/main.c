#include "NhapXuat.h"
#include "TachMang.h"
#include "GopMang.h"
#define MAX 100

/*
** GỘP MẢNG
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

	int chan[MAX], le[MAX], nchan, nle;
	TachMang(a, n, chan, &nchan, le, &nle);

	printf("\nMang chan:\n");
	XuatMang(chan, nchan);

	printf("\nMang le:\n");
	XuatMang(le, nle);

	int b[MAX], nb;
	GopMang(chan, nchan, le, nle, b, &nb);
	printf("\nMang sau khi gop:\n");
	XuatMang(b, nb);

	getch();
	return 0;
}