#include <stdio.h>
#include <math.h>

/*
** Input    : Số có hai chữ số
** Output   : In ra cách đọc
** IDE      : Visual Studio 2017
*/

int main()
{
	int So, SoAm = 0;
	printf("Nhap So co 2 chu so: ");
	scanf("%d", &So);

	// Đặt cờ hiệu để biết số âm
	if (So < 0)
	{
		SoAm = 1;
		So *= -1;
	}

	int SoChuSo = log10((double)So) + 1;

	if (SoChuSo != 2) printf("So khong hop le!\n");
	else
	{
		int Donvi = So % 10;
		int Chuc = So / 10;

		if (SoAm == 1) printf("Am ");

		if (Chuc == 2) printf("Hai ");
		if (Chuc == 3) printf("Ba ");
		if (Chuc == 4) printf("Bon ");
		if (Chuc == 5) printf("Nam ");
		if (Chuc == 6) printf("Sau ");
		if (Chuc == 7) printf("Bay ");
		if (Chuc == 8) printf("Tam ");
		if (Chuc == 9) printf("Chin ");

		printf("Muoi ");

		if (Donvi == 1) printf("Mot");
		if (Donvi == 2) printf("Hai");
		if (Donvi == 3) printf("Ba");
		if (Donvi == 4) printf("Bon");
		if (Donvi == 5) printf("Nam");
		if (Donvi == 6) printf("Sau");
		if (Donvi == 7) printf("Bay");
		if (Donvi == 8) printf("Tam");
		if (Donvi == 9) printf("Chin");
	}

	getch();
	return 0;
}