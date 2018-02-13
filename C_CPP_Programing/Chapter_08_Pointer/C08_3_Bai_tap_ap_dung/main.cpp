#include <stdio.h>
#include <conio.h>

void HoanVi(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void Menu()
{
	printf("Calculator\n");
	printf("  1. Add\n");
	printf("  2. Sub\n");
	printf("  3. Mul\n");
	printf("  4. Div\n");
	printf("  5. Mod\n");
	printf("Ban chon: ");
}


int main()
{
#if 1 Bài 1
	// Nhập 3 số nguyên, Tìm Max? Hàm nhập không sử dụng &
	int a, b, c;
	int *pa = &a, *pb = &b, *pc = &c;
	printf("Nhap 3 so: ");
	scanf_s("%d%d%d", pa, pb, pc);

	int Max = (*pa > *pb) ? *pa : *pb;
	Max = (Max > *pc) ? Max : *pc;
	printf("Max = %d", Max);
#endif // Bài 1

#if 0 // Bài 2
	// Nhập x và y, tính tổng x + y nhưng không dùng biến x và y
	int x, y;
	int *px = &x, *py = &y;
	printf("Nhap x va y: ");
	scanf_s("%d%d", px, py);
	printf("x + y = %d\n", *px + *py);
#endif // Bài 2

#if 0 //  Bài 3
	// Hoán vị hai số nguyên dùng con trỏ
	int x, y;
	printf("Nhap x va y: ");
	scanf_s("%d%d", &x, &y);
	printf("x = %d va y = %d \n", x, y);
	HoanVi(&x, &y);
	printf("x = %d va y = %d \n", x, y);
#endif // Bài 3

#if 0 // Bài 4
	// Máy tính bỏ túi đơn giản!
	Menu();
	int x, y, choice;
	int *px = &x, *py = &y, *pchoice = &choice;
	scanf_s("%d", pchoice);
	printf("Nhap x va y: ");
	scanf_s("%d%d", px, py);
	switch (*pchoice)
	{
	case 1: printf("x + y = %d", *px + *py); break;
	case 2: printf("x - y = %d", *px - *py); break;
	case 3: printf("x * y = %d", *px * *py); break;
	case 4: printf("x / y = %d", *px / *py); break;
	case 5: printf("x mod y = %d", *px % *py); break;
	default: break;
	}

#endif // Bài 4

#if 0 // Bài 5
	int x = 10;
	int a[] = { 1,2,3 };
	int *p = &a[0]; // int *p = a;

	printf("a[0] = %d \n", *p);
	printf("a = %d \n", a);
	printf("p = %d \n", p);
	printf("main = %d \n", main);
#endif // Bài 5

#if 0 // Bài 6
	// Ví dụ 1
	int x = 259;
	int *p = &x;
	// Do kiểu int độ lớn 4 byte.
	// Nên mỗi lần con trỏ tăng 1 thì tương đương +4 vào địa chỉ 
	printf("%d \n", &x);
	printf("%d \n", p);
	printf("%d \n", (p + 1));
	printf("%d \n", (p + 2));
	printf("%d \n", (p + 3));
	printf("----------\n");

	// Do kiểu char độ lớn 1 byte
	// Nên mỗi lần con trỏ tăng 1 thì tương đương +1 vào địa chỉ
	int v = 259;
	char *z = (char*)&v;
	printf("%d \n", z);
	printf("%d \n", (z + 1));
	printf("%d \n", (z + 2));
	printf("%d \n", (z + 3));
	printf("----------\n");

	// In giá trị
	// Các giá trị lần lượt ở 4 ô nhớ liên tiếp nhau
	int y = 259;
	char *q = (char*)&y;
	printf("%d \n", *q);
	printf("%d \n", *(q + 1));
	printf("%d \n", *(q + 2));
	printf("%d \n", *(q + 3));

#endif // Bài 6

	_getch();
	return 0;
}