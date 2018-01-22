#include <stdio.h>

/*
** CON TRỎ HÀM CƠ BẢN
*/

// Hàm hoán vị hai số nguyên
void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void Display(int a, int b)
{
	printf("%d   %d\n", a, b);
}
int TinhTongHaiSo(int a, int b)
{
	return a + b;
}
int TinhTichHaiSo(int a, int b)
{
	return a * b;
}
int TinhHieuHaiSo(int a, int b)
{
	return a - b;
}


int main()
{
#if 0 // Hoán vị hai số nguyên
	int a = 10;
	int b = 20;
	Display(a, b);
	Swap(&a, &b);
	Display(a, b);
#endif // 1 // Hoán vị hai số nguyên

#if 0 // Tính tổng hiệu tích hai số
	int a = 10;
	int b = 5;
	printf("Tong = %d\n", TinhTongHaiSo(a, b));
	printf("Hieu = %d\n", TinhHieuHaiSo(a, b));
	printf("Tich = %d\n", TinhTichHaiSo(a, b));

#endif // 1 // Tính tổng hiệu tích hai số

#if 0 // Con trỏ hàm hoán vị
	// Khai báo
	void(*ptr_FunSwap)(int*, int*);
	ptr_FunSwap = &Swap;

	// Sử dụng con trỏ như là sử dụng hàm
	int a = 1;
	int b = 2;
	Display(a, b);
	ptr_FunSwap(&a, &b);
	Display(a, b);
#endif // 1 // Con trỏ hàm hoán vị

#if 1 // Con trỏ hàm Tổng, hiệu, tích
	typedef int(*ptr_Calculator)(int, int);
	ptr_Calculator ptr_Tong = &TinhTongHaiSo;
	ptr_Calculator ptr_Hieu = &TinhHieuHaiSo;
	ptr_Calculator ptr_Tich = &TinhTichHaiSo;

	void(*ptr_Swap)(int*, int*) = &Swap;

	int x = 6;
	int y = 9;
	Display(x, y);
	ptr_Swap(&x, &y);
	Display(x, y);

	printf("Tong = %d\n", ptr_Tong(x, y));
	printf("Hieu = %d\n", ptr_Hieu(x, y));
	printf("Tich = %d\n", ptr_Tich(x, y));
#endif // 1 // Con trỏ hàm Tổng, hiệu, tích

	getch();
	return 0;
}