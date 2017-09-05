/*
** KỸ THUẬT NHẬP XUẤT CƠ BẢN TRÊN MẢNG MỘT CHIỀU
- Hàm Nhập mảng
- Hàm Xuất mảng
- Hàm tự động nhập ngẫu nhiên các phần tử của mảng
*/
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 100

void NhapMang(int[], int);
void XuatMang(int[], int);
void NhapMangNgauNhien(int[], int);

int main()
{
	// Khai báo mảng a[] có kích thước cố định và biến n làm số phần tử sẽ nhập vào mảng
	int a[MAX], n;
	do
	{
		printf("Nhap so phan tu: ");
		scanf("%d", &n);
		if (n <= 0 || n > 100)
			printf("Nhap lai n\n");
	} while (n <= 0 || n > MAX);

	NhapMang(a, n);
	//NhapMangNgauNhien(a, n);
	XuatMang(a, n);

	getch();
	return 0;
}

void NhapMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Nhap a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}
void XuatMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d   ", a[i]);
	printf("\n");
}
void NhapMangNgauNhien(int a[], int n)
{
	srand(time(0));
	for (int i = 0; i < n; i++)
		a[i] = 10 + rand() % (99 - 10 + 1); // [10..99]
	printf("Nhap xong mang ngau nhien.\n");
}

/*
Lưu ý:
- Mảng một chiều mặc định đã là tham chiếu (C++), bên C là con trỏ => Tham số truyền vào không cần có dấu '&'
*/