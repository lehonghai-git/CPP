/*
Nhập vào thông tin 1 ngày (ngày - tháng - năm). Kiểm tra tính hợp lệ của ngay đó
Nếu hợp lệ:
- Tìm ra ngày kế tiếp (ngày - tháng - năm)
- Tìm ra ngày trước đó (ngày - tháng - năm)

VD: 31/12/2017
- Ngày kế tiếp: 1/1/2018
- Ngày trước đó: 30/12/2017

Note: Xử lý các trường hợp đặc biệt trước
*/

#include <stdio.h>
#include <conio.h>

int main()
{
	int Nam, Thang, Ngay;

	printf("Nhap nam: ");
	scanf("%d", &Nam);
	if (Nam < 1945)
	{
		getch();
		return 0;
	}

	printf("Nhap thang: ");
	scanf("%d", &Thang);
	if (Thang < 1 || Thang > 12)
	{
		getch();
		return 0;
	}

	printf("Nhap ngay: ");
	scanf("%d", &Ngay);
	int CheckNgay = 1; // True

	if (Ngay < 1)
	{
		CheckNgay = 0;
	}
	else
	{
		if (Thang == 1 || Thang == 3 || Thang == 5 || Thang == 7 || Thang == 8 || Thang == 10 || Thang == 12)
		{
			if (Ngay > 31) CheckNgay = 0;
		}
		else if (Thang == 4 || Thang == 6 || Thang == 9 || Thang == 11)
		{
			if (Ngay > 30) CheckNgay = 0;
		}
		else // Tháng 2
		{
			if ((Nam % 4 == 0 && Nam % 100 != 0) || Nam % 400 == 0)
			{
				if (Ngay > 29) CheckNgay = 0;
			}
			else
			{
				if (Ngay > 28) CheckNgay = 0;
			}

		}
	}

	if (CheckNgay == 0)
	{
		printf("Ngay khong hop le\n");
		getch();
		return 0;
	}

	printf("Ban da nhap:\t %d/%d/%d\n", Ngay, Thang, Nam);
	printf("--------------------------\n");

	if (Ngay == 31) // Những tháng có 31 ngày: 1, 3, 5, 7, 8, 10, 12
	{
		if (Thang == 12) // Xử lý riêng tháng 12 vì là tháng cuối năm
		{
			printf("Ngay truoc do:\t %d/%d/%d\n", Ngay - 1, Thang, Nam);
			printf("Ngay ke tiep:\t %d/%d/%d\n", 1, 1, Nam + 1);
		}
		else // Xử lý các tháng còn lại: 1, 3, 5, 7, 8, 10
		{
			printf("Ngay truoc do:\t %d/%d/%d\n", Ngay - 1, Thang, Nam);
			printf("Ngay ke tiep:\t %d/%d/%d\n", 1, Thang + 1, Nam);
		}

	}
	else if (Ngay == 30)
	{
		if (Thang == 4 || Thang == 6 || Thang == 9 || Thang == 11) // Những tháng chỉ có 30 ngày: 4, 6, 9, 11
		{
			printf("Ngay truoc do:\t %d/%d/%d\n", Ngay - 1, Thang, Nam);
			printf("Ngay ke tiep:\t %d/%d/%d\n", 1, Thang + 1, Nam);
		}
		else // Những tháng còn lại: 1, 3, 5, 7, 8, 10, 12
		{
			printf("Ngay truoc do:\t %d/%d/%d\n", Ngay - 1, Thang, Nam);
			printf("Ngay ke tiep:\t %d/%d/%d\n", Ngay + 1, Thang, Nam);
		}
	}
	else if (Ngay == 1)
	{
		if (Thang == 1) // Xử lý riêng tháng 1 vì là tháng đầu năm
		{
			printf("Ngay truoc do:\t %d/%d/%d\n", 31, 12, Nam - 1);
			printf("Ngay ke tiep:\t %d/%d/%d\n", Ngay + 1, Thang, Nam);
		}
		else if (Thang == 5 || Thang == 7 || Thang == 10 || Thang == 12)
		{
			printf("Ngay truoc do:\t %d/%d/%d\n", 30, Thang - 1, Nam);
			printf("Ngay ke tiep:\t %d/%d/%d\n", Ngay + 1, Thang, Nam);
		}
		else if (Thang == 8)
		{
			printf("Ngay truoc do:\t %d/%d/%d\n", 31, Thang - 1, Nam);
			printf("Ngay ke tiep:\t %d/%d/%d\n", Ngay + 1, Thang, Nam);
		}
		else if (Thang == 3)
		{
			if ((Nam % 4 == 0 && Nam % 100 != 0) || Nam % 400 == 0)
			{
				printf("Ngay truoc do:\t %d/%d/%d\n", 29, Thang - 1, Nam);
				printf("Ngay ke tiep:\t %d/%d/%d\n", Ngay + 1, Thang, Nam);
			}
			else
			{
				printf("Ngay truoc do:\t %d/%d/%d\n", 28, Thang - 1, Nam);
				printf("Ngay ke tiep:\t %d/%d/%d\n", Ngay + 1, Thang, Nam);
			}
		}
		else
		{
			printf("Ngay truoc do:\t %d/%d/%d\n", 31, Thang - 1, Nam);
			printf("Ngay ke tiep:\t %d/%d/%d\n", Ngay + 1, Thang, Nam);
		}
	}
	else if (Ngay == 29 && Thang == 2) // Ngày 29 tháng 2 của năm nhuận
	{
		printf("Ngay truoc do:\t %d/%d/%d\n", 28, Thang, Nam);
		printf("Ngay ke tiep:\t %d/%d/%d\n", 1, Thang + 1, Nam);
	}
	else if (Ngay == 28 && Thang == 2)
	{
		if ((Nam % 4 == 0 && Nam % 100 != 0) || Nam % 400 == 0) // Ngày 28 tháng 2 của năm nhuận
		{
			printf("Ngay truoc do:\t %d/%d/%d\n", Ngay - 1, Thang, Nam);
			printf("Ngay ke tiep:\t %d/%d/%d\n", Ngay + 1, Thang, Nam);
		}
		else // Ngày 28 tháng 2 của các năm thường
		{
			printf("Ngay truoc do:\t %d/%d/%d\n", 27, Thang, Nam);
			printf("Ngay ke tiep:\t %d/%d/%d\n", 1, Thang + 1, Nam);
		}
	}
	else
	{
		printf("Ngay truoc do:\t %d/%d/%d\n", Ngay - 1, Thang, Nam);
		printf("Ngay ke tiep:\t %d/%d/%d\n", Ngay + 1, Thang, Nam);
	}

	getch();
	return 0;
}

/*
Test:
- Năm nhuận
29/2/2016
1/3/2016
28/2/2016

- Năm thường
8/7/2017
31/12/2017
30/12/2017
1/1/2017
28/2/2017
1/3/2017
1/8/2017
31/7/2017
*/