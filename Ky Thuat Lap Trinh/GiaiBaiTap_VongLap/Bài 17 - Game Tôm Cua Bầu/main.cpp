/*
Game Tôm Cua Bầu
1. Tôm
2. Cua
3. Bầu
4. Gà
5. Cá
6. Hươu
*/

#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>

#define TOM		1
#define CUA		2
#define BAU		3
#define GA		4
#define CA		5
#define HUOU	6

unsigned long SoTienHienTai = 100000;

int main()
{
	unsigned long DatTom, DatCua, DatBau, DatGa, DatCa, DatHuou;
	int CheckTom = 0, CheckCua = 0, CheckBau = 0, CheckGa = 0, CheckCa = 0, CheckHuou = 0;
	char key;

	do
	{
		system("cls");
		printf("So Tien hien tai: %d\n", SoTienHienTai);
		do
		{
			printf("Dat Tom: ");
			scanf("%d", &DatTom);
			if (DatTom > 0) CheckTom = 1;
			printf("Dat Cua: ");
			scanf("%d", &DatCua);
			if (DatCua > 0) CheckCua = 2;
			printf("Dat Bau: ");
			scanf("%d", &DatBau);
			if (DatBau > 0) CheckBau = 3;
			printf("Dat Ga: ");
			scanf("%d", &DatGa);
			if (DatGa > 0) CheckGa = 4;
			printf("Dat Ca: ");
			scanf("%d", &DatCa);
			if (DatCa > 0) CheckCa = 5;
			printf("Dat Huou: ");
			scanf("%d", &DatHuou);
			if (DatHuou > 0) CheckHuou = 6;

			if ((DatTom + DatCua + DatBau + DatGa + DatCa + DatHuou) > SoTienHienTai)
				printf("So tien hien tai khong du\n");
		} while ((DatTom + DatCua + DatBau + DatGa + DatCa + DatHuou) > SoTienHienTai);

		printf("Dang quay so ");
		Sleep(700); // 1s
		printf(" .");
		Sleep(700);
		printf(" .");
		Sleep(700);
		printf(" .\n");
		Sleep(700);

		// Quay số ngẫu nhiên từ [1, 6]
		srand(time(0));
		Sleep(1000);
		int KetQua1 = 1 + rand() % (6 - 1 + 1);
		if (KetQua1 == TOM) printf("TOM\t");
		if (KetQua1 == CUA) printf("CUA\t");
		if (KetQua1 == BAU) printf("BAU\t");
		if (KetQua1 == GA) printf("GA\t");
		if (KetQua1 == CA) printf("CA\t");
		if (KetQua1 == HUOU) printf("HUOU\t");

		srand(time(0));
		Sleep(1000);
		int KetQua2 = 1 + rand() % (6 - 1 + 1);
		if (KetQua2 == TOM) printf("TOM\t");
		if (KetQua2 == CUA) printf("CUA\t");
		if (KetQua2 == BAU) printf("BAU\t");
		if (KetQua2 == GA) printf("GA\t");
		if (KetQua2 == CA) printf("CA\t");
		if (KetQua2 == HUOU) printf("HUOU\t");

		srand(time(0));
		Sleep(1000);
		int KetQua3 = 1 + rand() % (6 - 1 + 1);
		if (KetQua3 == TOM) printf("TOM\n");
		if (KetQua3 == CUA) printf("CUA\n");
		if (KetQua3 == BAU) printf("BAU\n");
		if (KetQua3 == GA) printf("GA\n");
		if (KetQua3 == CA) printf("CA\n");
		if (KetQua3 == HUOU) printf("HUOU\n");

		printf("Dang tinh tien");
		Sleep(700); // 1s
		printf(" .");
		Sleep(700);
		printf(" .");
		Sleep(700);
		printf(" .\n");
		Sleep(700);

		// So sánh kết quả
		/*if (DatTom > 0 && KetQua1 == TOM || DatTom > 0 && KetQua2 == TOM || DatTom > 0 && KetQua3 == TOM)
		SoTienHienTai += DatTom;
		else
		SoTienHienTai -= DatTom;
		if (DatCua > 0 && KetQua1 == CUA || DatCua > 0 && KetQua2 == CUA || DatCua > 0 && KetQua3 == CUA)
		SoTienHienTai += DatCua;
		else
		SoTienHienTai -= DatCua;
		if (DatBau > 0 && KetQua1 == BAU || DatBau > 0 && KetQua2 == BAU || DatBau > 0 && KetQua3 == BAU)
		SoTienHienTai += DatBau;
		else
		SoTienHienTai -= DatBau;
		if (DatGa > 0 && KetQua1 == GA || DatGa > 0 && KetQua2 == GA || DatGa > 0 && KetQua3 == GA)
		SoTienHienTai += DatGa;
		else
		SoTienHienTai -= DatGa;
		if (DatCa > 0 && KetQua1 == CA || DatCa > 0 && KetQua2 == CA || DatCa > 0 && KetQua3 == CA)
		SoTienHienTai += DatCa;
		else
		SoTienHienTai -= DatCa;
		if (DatHuou > 0 && KetQua1 == HUOU || DatHuou > 0 && KetQua2 == HUOU || DatHuou > 0 && KetQua3 == HUOU)
		SoTienHienTai += DatHuou;
		else
		SoTienHienTai -= DatHuou;
		*/
		//if ((CheckTom || CheckCua || CheckBau || CheckGa || CheckCa || CheckHuou) == KetQua1)
		//{
		if (CheckTom == KetQua1) SoTienHienTai += DatTom;
		else SoTienHienTai -= DatTom;
		if (CheckCua == KetQua1) SoTienHienTai += DatCua;
		else SoTienHienTai -= DatCua;
		if (CheckBau == KetQua1) SoTienHienTai += DatBau;
		else SoTienHienTai -= DatBau;
		if (CheckGa == KetQua1) SoTienHienTai += DatGa;
		else SoTienHienTai -= DatGa;
		if (CheckCa == KetQua1) SoTienHienTai += DatCa;
		else SoTienHienTai -= DatCa;
		if (CheckHuou == KetQua1) SoTienHienTai += DatHuou;
		else SoTienHienTai -= DatHuou;
		//}
		if (CheckTom == KetQua2) SoTienHienTai += DatTom;
		else SoTienHienTai -= DatTom;
		if (CheckCua == KetQua2) SoTienHienTai += DatCua;
		else SoTienHienTai -= DatCua;
		if (CheckBau == KetQua2) SoTienHienTai += DatBau;
		else SoTienHienTai -= DatBau;
		if (CheckGa == KetQua2) SoTienHienTai += DatGa;
		else SoTienHienTai -= DatGa;
		if (CheckCa == KetQua2) SoTienHienTai += DatCa;
		else SoTienHienTai -= DatCa;
		if (CheckHuou == KetQua2) SoTienHienTai += DatHuou;
		else SoTienHienTai -= DatHuou;

		if (CheckTom == KetQua3) SoTienHienTai += DatTom;
		else SoTienHienTai -= DatTom;
		if (CheckCua == KetQua3) SoTienHienTai += DatCua;
		else SoTienHienTai -= DatCua;
		if (CheckBau == KetQua3) SoTienHienTai += DatBau;
		else SoTienHienTai -= DatBau;
		if (CheckGa == KetQua3) SoTienHienTai += DatGa;
		else SoTienHienTai -= DatGa;
		if (CheckCa == KetQua3) SoTienHienTai += DatCa;
		else SoTienHienTai -= DatCa;
		if (CheckHuou == KetQua3) SoTienHienTai += DatHuou;
		else SoTienHienTai -= DatHuou;

		// Kết quả tính tiền
		printf("So Tien hien tai: %d\n", SoTienHienTai);

		// Thông báo hết tiền
		if (SoTienHienTai <= 0)
		{
			char naptiep;
			rewind(stdin);
			printf("Ban da het tien. Ban co muon nap tien khong (y/n)? ");
			scanf("%c", &naptiep);
			if (naptiep == 'y')
			{
				unsigned long SoTienNap;
				printf("Nhap so tien muon nap: ");
				scanf("%d", &SoTienNap);
				SoTienHienTai += SoTienNap;
				printf("Da nap %ld\n", SoTienNap);
			}
			else
			{
				printf("Ban khong con tien de choi. Chuong trinh se ket thuc!");
				break;
			}
		}
		rewind(stdin);
		printf("Ban co muon choi tiep (y/n)? ");
		scanf("%c", &key);

	} while (key == 'y');

	getch();
	return 0;
}