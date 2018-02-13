#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void NhapMang(int *, int);
void XuatMang(int *, int);
int TinhTongMang(int *, int);
void HoanVi(int *, int *);
void DaoNguocMang(int *, int);
void testBinhThuong();
void testCapPhatDong();

int main()
{
#if 0 // Bài 1+2+3
	// Nhập, xuất, tính tổng
	int n;
	do
	{
		printf("Nhap so phan tu: ");
		scanf_s("%d", &n);
	} while (n < 0);
	int *a = (int*)malloc(n * sizeof(int));

	// Bài 1
	NhapMang(a, n);
	XuatMang(a, n);

	// Bài 2
	printf("Tong mang = %d\n", TinhTongMang(a, n));

	// Bài 3
	DaoNguocMang(a, n);
	XuatMang(a, n);

	// Giải phóng vùng nhớ
	free(a);
	a = NULL;
#endif // 1 // Bài 1+2+3

#if 0 // Bài 4
	// Bài 4
	int na, nb;
	int *a = NULL, *b = NULL, *c = NULL;

	do
	{
		printf("Nhap so phan tu mang a: ");
		scanf_s("%d", &na);
	} while (na < 0);
	a = (int*)malloc(na * sizeof(int));
	NhapMang(a, na);
	XuatMang(a, na);
	do
	{
		printf("Nhap so phan tu mang b: ");
		scanf_s("%d", &nb);
	} while (nb < 0);
	b = (int*)malloc(nb * sizeof(int));
	NhapMang(b, nb);
	XuatMang(b, nb);

	c = (int*)malloc((na + nb) * sizeof(int));
	int idx = 0;
	for (int i = 0; i < na; i++)
		c[idx++] = a[i];
	for (int i = 0; i < nb; i++)
		c[idx++] = b[i];
	printf("\nMang C la: ");
	XuatMang(c, na + nb);

	free(a);
	free(b);
	free(c);
	a = b = c = NULL;
#endif // 1 // Bài 4

#if 0 // Bài 5
	testBinhThuong();
	testCapPhatDong();
	/*
	- Con trỏ quản lý mảng đều nằm trên Stack
	- Vùng nhớ do con trỏ (testBinhThuong) cấp phát tĩnh quản lý => nằm trên stack
	- Vùng nhớ do con trỏ (testCapPhatDong) cấp phát động quản lý => nằm trên heap
	- Địa chỉ của vùng nhớ heap nằm ở vùng nhớ cao hơn vùng stack.
	*/
#endif // 1 // Bài 5

#if 0 // malloc, calloc và realloc
	int *a = NULL, n;
	do
	{
		printf("Nhap so luong phan tu: ");
		scanf_s("%d", &n);
	} while (n < 0);
	a = (int*)malloc(n * sizeof(int));
	//a = (int*)calloc(n, sizeof(int)); // 
	//a = (int*)realloc(0, n * sizeof(int)); // Cấp mới
	NhapMang(a, n);
	XuatMang(a, n);

	// Cấp lại, tăng thêm 4 byte
	a = (int*)realloc(a, (n + 1) * sizeof(int));
	a[n] = 69;
	printf("\na[%d] = %d", n, a[n]);

	// Giải phóng
	free(a);
	a = NULL;
#endif // malloc, calloc và realloc

	_getch();
	return 0;
}

void testBinhThuong()
{
	int a[3];
	int i;
	printf("\nTEST BINH THUONG \n\n");
	printf("&a = %d \n", &a);
	for (i = 0; i < 3; i++)
		printf("&a[%d] = %d \n", i, &a[i]);

}
void testCapPhatDong()
{
	int *a = NULL;
	int i;
	a = (int*)malloc(3 * sizeof(int));
	printf("\nTEST CAP PHAT DONG \n\n");
	printf("&a = %d \n", &a);
	for (i = 0; i < 3; i++)
		printf("&a[%d] = %d \n", i, &a[i]);
	free(a);
	a = NULL;
}
void DaoNguocMang(int *a, int n)
{
	for (int i = 0; i < n / 2; i++)
		HoanVi(&a[i], &a[n - i - 1]);
}
void HoanVi(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int TinhTongMang(int *a, int n)
{
	int Tong = 0;
	for (int i = 0; i < n; i++)
		Tong += *(a + i);
	return Tong;
}
void NhapMang(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("a[%d] = ", i);
		scanf_s("%d", (a + i));
	}
}
void XuatMang(int *a, int n)
{
	for (int i = 0; i < n; i++)
		printf("%4d", *(a + i));
	printf("\n");
}