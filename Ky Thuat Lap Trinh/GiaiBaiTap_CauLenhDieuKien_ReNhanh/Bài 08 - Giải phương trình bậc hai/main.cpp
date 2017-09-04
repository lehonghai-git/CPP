/*
Giải phương trình bậc hai có dạng: ax^2 + bx + c = 0
*/
#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
	float a, b, c;

	printf("Nhap cac he so a, b, c: ");
	scanf("%f%f%f", &a, &b, &c);

	if (a == 0) // PT bậc nhất b.x + c = 0
	{
		if (b == 0)
		{
			if (c == 0) printf("PT VSN\n");
			else printf("PT VN\n");
		}
		else printf("X = %f\n", -c / b);
	}
	else
	{
		float Delta = b * b - 4 * a * c;
		if (Delta > 0)
		{
			float x1 = (-b - sqrt(Delta)) / (2 * a);
			float x2 = (-b + sqrt(Delta)) / (2 * a);
			printf("X1 = %f\n", x1);
			printf("X2 = %f\n", x2);
		}
		else if (Delta == 0)
		{
			printf("X1 = X2 = %f", -b / (2 * a));
		}
		else
		{
			printf("VN");
		}

	}

	getch();
	return 0;
}

/*
Mẹo tính căn bậc n của một số x
VD: Căn bậc 2 của 4 = 2
n	  x
Tương đương: x^(1/n) <=> 4^(1/2) = 2
=> Căn bậc n của x = pow(x, (1.0/n));
*/