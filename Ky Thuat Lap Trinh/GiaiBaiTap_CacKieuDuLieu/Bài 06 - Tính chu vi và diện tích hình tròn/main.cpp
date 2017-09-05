/*
- Nhập vào bán kính của hình tròn
- Tính và in ra chu vi, diện tích của hình tròn
*/
#include <stdio.h>
#include <conio.h>

#define PI 3.14159

int main()
{
	float BanhKinh, ChuVi, DienTich;
	printf("Nhap ban kinh = ");
	scanf("%f", &BanhKinh);

	ChuVi = 2 * BanhKinh * PI;
	DienTich = BanhKinh * BanhKinh * PI;

	printf("Chu vi: %.3f\n", ChuVi);
	printf("Dien tich: %.3f\n", DienTich);

	getch();
	return 0;
}