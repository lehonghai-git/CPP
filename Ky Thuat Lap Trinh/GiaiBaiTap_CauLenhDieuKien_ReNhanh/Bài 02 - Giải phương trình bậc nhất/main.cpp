/*
- Nhập các hệ số của phương trình bậc nhất: ax + b = 0
- Tìm và in ra kết quả nghiệm của phương trình
*/
#include <stdio.h>
#include <conio.h>

int main()
{
	int a, b;
	printf("Nhap a = ");
	scanf("%d", &a);
	printf("Nhap b = ");
	scanf("%d", &b);

	if (a == 0)
	{
		if (b == 0) printf("Vo so nghiem\n");
		else printf("Vo nghiem\n");
	}
	else printf("x = %.3f\n", (float)-b / a);

	getch();
	return 0;
}