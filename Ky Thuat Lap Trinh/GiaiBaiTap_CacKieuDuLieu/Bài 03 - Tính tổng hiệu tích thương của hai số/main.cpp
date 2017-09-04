/*
- Nhập hai số a và b
- Tính và in ra màn hình:
+ Tổng
+ Hiệu
+ Tích
+ Thương
*/
#include <stdio.h>
#include <conio.h>

int main()
{
	int a, b, Tong, Hieu, Tich;
	float Thuong;

	printf("Nhap a =  ");
	scanf("%d", &a);
	printf("Nhap b =  ");
	scanf("%d", &b);

	Tong = a + b;
	Hieu = a - b;
	Tich = a * b;
	Thuong = (float)a / b;

	printf("------------\n");
	printf("%d + %d = %d\n", a, b, Tong);
	printf("%d - %d = %d\n", a, b, Hieu);
	printf("%d * %d = %d\n", a, b, Tich);
	b == 0 ? printf("%d / %d = Thuong khong duoc bang 0\n", a, b) : printf("%d / %d = %.3f\n", a, b, Thuong);

	getch();
	return 0;
}