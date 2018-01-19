#include <stdio.h>
#define PI 3.14

/*
** Input    : Bán kính
** Output   : Chu vi, diện tích hình tròn
** IDE      : Visual Studio 2017
*/

int main()
{
	float BanKinh;
	printf("Nhap vao ban kinh: ");
	scanf("%f", &BanKinh);

	float Chuvi = 2 * BanKinh * PI;
	float Dientich = BanKinh * BanKinh * PI;
	
	printf("\nChu vi: %.2f", Chuvi);
	printf("\nDien tich: %.2f", Dientich);

	getch();
	return 0;
}