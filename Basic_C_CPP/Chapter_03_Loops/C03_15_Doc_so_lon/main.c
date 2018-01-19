#include <stdio.h>
#include <math.h>

/*
** Input    : Số nguyên (<= 10 chữ số)
** Output   : Cách đọc
** IDE      : Visual Studio 2017
*/

int main()
{
	/*
	** 12 => Muoi Hai
	** 123 => Mot Tram Hai Muoi Ba
	** 1234 => Mot Ngan Hai Tram Ba Muoi Bon
	** 12345 => Muoi Hai Ngan Ba Tram Bon Muoi Nam
	*/

	int n;
	do
	{
		printf("Nhap vao so nguyen: ");
		scanf("%d", &n);
		if (n <= 0)
			printf("Kiem tra lai so vua nhap\n");
	} while (n <= 0);

	// Tìm Số đảo ngược
	int tmp = n, SoDaoNguoc = 0;
	while (tmp != 0)
	{
		SoDaoNguoc = SoDaoNguoc * 10 + tmp % 10;
		tmp /= 10;
	}

	// Đọc số
	int SoLuongChuSo = log10((float)SoDaoNguoc) + 1;
	while (SoDaoNguoc != 0)
	{
		/*
		1234 => 4321
		*/
		int ChuSo = SoDaoNguoc % 10;
		if (ChuSo == 0) printf(" Khong ");
		if (ChuSo == 1 && SoLuongChuSo >= 5)
			printf(" Muoi ");
		else if (ChuSo == 1)
			printf(" Mot ");
		if (ChuSo == 2) printf(" Hai ");
		if (ChuSo == 3) printf(" Ba ");
		if (ChuSo == 4) printf(" Bon ");
		if (ChuSo == 5) printf(" Nam ");
		if (ChuSo == 6) printf(" Sau ");
		if (ChuSo == 7) printf(" Bay ");
		if (ChuSo == 8) printf(" Tam ");
		if (ChuSo == 9) printf(" Chin ");


		if (SoLuongChuSo == 7) printf(" Trieu ");
		if (SoLuongChuSo == 6) printf(" Tram ");
		//if (SoLuongChuSo == 5) printf(" Ngan "); //12345
		if (SoLuongChuSo == 4) printf(" Ngan ");
		if (SoLuongChuSo == 3) printf(" Tram ");
		if (SoLuongChuSo == 2) printf(" Muoi ");
		SoLuongChuSo--;
		SoDaoNguoc /= 10;
	}

	getch();
	return 0;
}