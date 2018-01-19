#include <stdio.h>
#define DANSOHIENTAI 60000
#define TLT 1.8

/*
** Input    : Dân số hiện tại
** Output   : Dân số sau 5 năm nữa
** IDE      : Visual Studio 2017
*/

int main()
{
	/*
	** Tỷ lệ tăng sau mỗi năm = 1.8%
	*/
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