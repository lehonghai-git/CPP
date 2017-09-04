/*
Dân số hiện tại năm 2017 của một xã: 60k
Tỷ lệ tăng sau mỗi năm = 1.8%
Dân số của xã 5 năm nữa tức là năm 2022 = ?
*/
#include <stdio.h>
#include <conio.h>

#define DANSOHIENTAI 60000
#define TLT 1.8

int main()
{
	float Tong = DANSOHIENTAI;
	float TyLe = TLT / 100;
	printf("%f\n", TyLe);
	printf("Dan so nam 2017: %.2f\n", Tong);
	Tong += Tong * TyLe;
	printf("Dan so nam 2018: %.2f\n", Tong);
	Tong += Tong * TyLe;
	printf("Dan so nam 2019: %.2f\n", Tong);
	Tong += Tong * TyLe;
	printf("Dan so nam 2020: %.2f\n", Tong);
	Tong += Tong * TyLe;
	printf("Dan so nam 2021: %.2f\n", Tong);
	Tong += Tong * TyLe;
	printf("Dan so nam 2022: %.2f\n", Tong);

	getch();
	return 0;
}