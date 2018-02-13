#include <stdio.h>
#include <conio.h>
#define MAX 100

void NhapMangCach1(int *, int);
void XuatMangCach1(int *, int);
void NhapMangCach2(int *, int);
void XuatMangCach2(int *, int);

int main()
{
#if 1 // Con trỏ trỏ đến từng phần tử trong mảng
	int a[3] = { 9,8,7 };
	int *p = &a[0]; // Hoặc *p = a
	int *q = &a[2];

	for (int i = 0; i < 3; i++)
	{
		printf("%4d", *p);
		p++; // Sau mỗi vòng lặp địa chỉ sẽ +4
	}
	printf("\n");
	for (int i = 0; i < 3; i++)
	{
		printf("%4d", *q);
		q--; // Sau mỗi vòng lặp địa chỉ sẽ +4
	}
#endif // Con trỏ trỏ đến từng phần tử trong mảng

#if 0 // Mảng một chiều là hằng con trỏ
	int a[3] = { 1,2,3 };
	int *p = NULL;

	p = a;			// ok
	p = a + 1;		// ok // a[1]
					//a++;			// sai
					//a = a + 2;	// sai
					/*
					- a như là một con trỏ, a cũng chính là địa chỉ của phần tử đầu tiên trong mảng
					- Không thể thay đổi địa chỉ của a
					- Có thể thay đổi giá trị của a (Giá trị phần tử đầu tiên trong mảng)
					=> Hằng con trỏ
					*/
#endif // Mảng một chiều là hằng con trỏ

#if 0 // Nhập xuất mảng sử dụng con trỏ
	int a[MAX], n;
	int *p = NULL;

	do
	{
		printf("Nhap so phan tu: ");
		scanf_s("%d", &n);
	} while (n < 0 || n > MAX);
	NhapMangCach1(a, n);
	XuatMangCach1(a, n);
#endif // Nhập xuất mảng sử dụng con trỏ

#if 0 // Con trỏ là mảng, mảng là con trỏ
	int a[MAX], n;
	do
	{
		printf("Nhap so phan tu: ");
		scanf_s("%d", &n);
	} while (n < 0 || n > MAX);
	NhapMangCach2(a, n);
	XuatMangCach2(a, n);
#endif // 1 // Con trỏ là mảng, mảng là con trỏ

#if 0 // Truy xuất chỉ số âm?
	int a[] = { 2,0,1,8 };
	int *p = &a[2];

	printf("%d\n", p[0]);
	printf("%d\n", p[1]);
	printf("%d\n", p[-1]);
	printf("%d\n", p[-2]);

#endif // Truy xuất chỉ số âm?

	_getch();

	return 0;
}
void NhapMangCach2(int *a, int n)
{
	int *p = a; // *p = &a[0];
	for (int i = 0; i < n; i++)
	{
		printf("Nhap a[%d] = ", i);
		scanf_s("%d", &p[i]);
	}
}
void XuatMangCach2(int *a, int n)
{
	int *p = a;
	for (int i = 0; i < n; i++)
	{
		printf("%4d", p[i]);
	}
}
void NhapMangCach1(int *a, int n)
{
	int *p = NULL;
	for (p = a; p < a + n; p++)
	{
		printf("Nhap a[%d] = ", p - a);
		scanf_s("%d", p);
	}
}
void XuatMangCach1(int *a, int n)
{
	int *p = NULL;

	for (p = a; p < a + n; p++)
	{
		printf("%4d", *p);
	}
}