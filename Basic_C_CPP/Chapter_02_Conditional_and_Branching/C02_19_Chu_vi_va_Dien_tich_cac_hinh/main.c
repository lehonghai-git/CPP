#include <stdio.h>
#include <math.h>
#define PI 3.14

/*
** Input    : Tùy chọn các loại hình để tính
** Output   : Chu vi, diện tích hình đã chọn
** IDE      : Visual Studio 2017
*/

int main()
{
	printf("CHU VI & DIEN TICH CAC HINH\n");
	printf("---------------------------\n");
	printf("1. Hinh vuong\n");
	printf("2. Hinh chu nhat\n");
	printf("3. Hinh tron\n");
	printf("4. Hinh tam giac\n");
	printf("Ban chon: ");
	int choice;
	scanf("%d", &choice);

	if (choice == 1)
	{
		float a;
		printf("Nhap 1 canh hinh vuong: ");
		scanf("%f", &a);

		printf("C hinh vuong = %.2f\n", a * 4);
		printf("S hinh vuong = %.2f\n", a * a);
	}
	else if (choice == 2)
	{
		float a, b;
		printf("Nhap 2 canh hinh chu nhat: ");
		scanf("%f%f", &a, &b);
		if (a == b)
		{
			printf("Khong phai hinh chu nhat\n");
			getch();
			return 0;
		}
		else
		{
			printf("C hinh chu nhat = %.2f\n", (a + b) * 2);
			printf("S hinh chu nhat = %.2f\n", a * b);
		}
	}
	else if (choice == 3)
	{
		float r;
		printf("Nhap ban kinh hinh tron: ");
		scanf("%f", &r);
		printf("C hinh tron = %.2f\n", 2 * PI * r);
		printf("S hinh tron = %.2f\n", PI * r * r);
	}
	else if (choice == 4)
	{
		float a, b, c;
		printf("Nhap 3 canh tam giac: ");
		scanf("%f%f%f", &a, &b, &c);
		if (a < 0 || b < 0 || c < 0 || (a + b) <= c || (a + c) <= b || (b + c) <= a)
			printf("Nhap lai 3 canh tam giac.\n");
		else
		{
			float C = a + b + c;
			float S = sqrt(C*(C / 2 - a)*(C / 2 - b)*(C / 2 - c) / 2);
			printf("C hinh tam giac = %.2f\n", C);
			printf("S hinh tam giac = %.2f\n", S);
		}
	}
	else
	{
		printf("Nhap lai lua chon\n");
	}

	getch();
	return 0;
}