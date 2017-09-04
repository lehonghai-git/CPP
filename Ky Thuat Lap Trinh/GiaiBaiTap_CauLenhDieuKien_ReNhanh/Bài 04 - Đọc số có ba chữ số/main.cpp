/*
- Nhập vào số có ba chữ số
- In ra cách đọc số đó
*/
#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
	int So, SoAm = 0;
	printf("Nhap So co 3 chu so: ");
	scanf("%d", &So);

	// Đặt cờ hiệu để biết số âm
	if (So < 0)
	{
		SoAm = 1;
		So *= -1;
	}

	int SoChuSo = log10((double)So) + 1;

	if (SoChuSo != 3) printf("So khong hop le!\n");
	else
	{
		// 123 / 10 = 12 % 10 = 2
		int Donvi = So % 10;
		int Chuc = (So / 10) % 10;
		int Tram = So / 100;

		if (SoAm == 1) printf("Am ");

		if (Tram == 1) printf("Mot ");
		if (Tram == 2) printf("Hai ");
		if (Tram == 3) printf("Ba ");
		if (Tram == 4) printf("Bon ");
		if (Tram == 5) printf("Nam ");
		if (Tram == 6) printf("Sau ");
		if (Tram == 7) printf("Bay ");
		if (Tram == 8) printf("Tam ");
		if (Tram == 9) printf("Chin ");

		printf("Tram ");

		if (Chuc == 0 && Donvi != 0) printf("Le ");

		//if (Chuc == 1) printf("Muoi ");
		if (Chuc == 2) printf("Hai ");
		if (Chuc == 3) printf("Ba ");
		if (Chuc == 4) printf("Bon ");
		if (Chuc == 5) printf("Nam ");
		if (Chuc == 6) printf("Sau ");
		if (Chuc == 7) printf("Bay ");
		if (Chuc == 8) printf("Tam ");
		if (Chuc == 9) printf("Chin ");

		if (Chuc != 0) printf("Muoi ");

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