/*
- Nhập vào tháng và năm
- In ra kết quả tháng đó có bao nhiêu ngày
*/
#include <stdio.h>
#include <conio.h>
int main()
{
	int Thang, Nam;

	printf("Nhap vao thang va nam: ");
	scanf("%d%d", &Thang, &Nam);
	if (Thang < 1 || Thang > 12)
	{
		printf("Thang khong hop le.\n");
		getch();
		return 0;
	}
	if (Nam < 1940)
	{
		printf("Nam khong hop le.\n");
		getch();
		return 0;
	}

	if (Thang == 1 || Thang == 3 || Thang == 5 || Thang == 7 || Thang == 8 || Thang == 10 || Thang == 12)
		printf("Thang %d nam %d co 31 ngay\n", Thang, Nam);
	else if (Thang == 4 || Thang == 6 || Thang == 9 || Thang == 11)
		printf("Thang %d nam %d co 30 ngay\n", Thang, Nam);
	else
	{
		/*
		Năm nhuận là năm thỏa mãn:
		- Chia hết cho 4 và không chia hết cho 100: Nam % 4 == 0 && Nam % 100 != 0
		- Chia hết cho 400: Nam % 400 == 0
		*/
		if ((Nam % 4 == 0 && Nam % 100 != 0) || Nam % 400 == 0)
			printf("Thang %d nam %d co 29 ngay (Nam nhuan)\n", Thang, Nam);
		else
			printf("Thang %d nam %d co 28 ngay\n", Thang, Nam);
	}

	getch();
	return 0;
}