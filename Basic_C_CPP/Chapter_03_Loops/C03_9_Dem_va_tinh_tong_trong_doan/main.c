#include <stdio.h>
#include <math.h>

/*
** Input    : Hai số nguyên dương a và b
** Output   : Đếm các loại số có trong đoạn a, b và tính tổng chúng
** IDE      : Visual Studio 2017
*/

int main()
{
	int a, b;
	do
	{
		printf("Nhap a (a > 0): ");
		scanf("%d", &a);
		if (a <= 0)
			printf("Nhap lai a\n");
	} while (a <= 0);

	do
	{
		printf("Nhap b (b > a): ");
		scanf("%d", &b);
		if (b <= 0)
			printf("Nhap lai b\n");
	} while (b <= a);

	int DemSoDoiXung = 0, DemSoChinhPhuong = 0, DemSoNguyenTo = 0;
	int TongSoDoiXung = 0, TongSoChinhPhuong = 0, TongSoNguyenTo = 0;
	for (int i = a; i <= b; i++)
	{
		// Đếm và tính tổng số đối xứng
		int SoNghichDao = 0, TmpDoiXung = i;
		while (TmpDoiXung != 0)
		{
			SoNghichDao = SoNghichDao * 10 + TmpDoiXung % 10;
			TmpDoiXung /= 10;
		}
		if (SoNghichDao == i)
		{
			DemSoDoiXung++;
			TongSoDoiXung += i;
		}

		// Đếm và tính tổng số chính phương
		int TmpChinhPhuong = i;
		if (sqrt((float)TmpChinhPhuong) == (int)sqrt((float)TmpChinhPhuong))
		{
			DemSoChinhPhuong++;
			TongSoChinhPhuong += i;
		}

		// Đếm và tính tổng số nguyên tố
		int KiemTraNguyenTo = 1, TmpNguyenTo = i;
		if (TmpNguyenTo < 2)
			KiemTraNguyenTo = 0;
		else if (TmpNguyenTo > 2) // Trường hợp n == 2 sẽ không nhảy vào đây
		{
			if (TmpNguyenTo % 2 == 0)
				KiemTraNguyenTo = 0;
			else
			{
				for (int j = 3; j <= (int)sqrt((double)TmpNguyenTo); j += 2) // Chỉ xét số lẻ
				{
					if (TmpNguyenTo % j == 0)
					{
						KiemTraNguyenTo = 0;
						break;
					}
				}
			}
		}

		if (KiemTraNguyenTo)
		{
			DemSoNguyenTo++;
			TongSoNguyenTo += i;
		}
	}
	printf("Co %d so doi xung\n", DemSoDoiXung);
	printf("Tong cac so doi xung la: %d\n", TongSoDoiXung);

	printf("Co %d so chinh phuong\n", DemSoChinhPhuong);
	printf("Tong cac so chinh phuong la: %d\n", TongSoChinhPhuong);

	printf("Co %d so nguyen to\n", DemSoNguyenTo);
	printf("Tong cac so nguyen to la: %d\n", TongSoNguyenTo);

	getch();
	return 0;
}