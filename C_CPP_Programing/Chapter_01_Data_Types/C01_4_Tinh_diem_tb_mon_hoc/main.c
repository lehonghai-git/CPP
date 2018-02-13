#include <stdio.h>

/*
** Input    : Điểm thi giữa kỳ, cuối kỳ
** Output   : Điểm trung bình môn học
** IDE      : Visual Studio 2017
*/

int main()
{
	float DiemGiuaKy, DiemCuoiKy;
	printf("Nhap diem giua ky: ");
	scanf("%f", &DiemGiuaKy);
	printf("Nhap diem cuoi ky: ");
	scanf("%f", &DiemCuoiKy);

	float DiemTB = DiemGiuaKy * 0.3 + DiemCuoiKy * 0.7;
	printf("\nDiem TB mon: %.2f", DiemTB);

	getch();
	return 0;
}