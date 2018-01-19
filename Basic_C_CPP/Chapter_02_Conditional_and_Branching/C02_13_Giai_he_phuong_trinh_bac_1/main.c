#include <stdio.h>

/*
** Input    : Các hệ số của Hệ phương trình
** Output   : Nghiệm của phương trình
** IDE      : Visual Studio 2017
*/

int main()
{
	/*
	** Giải hệ phương trình sau:
	** ax + by = c
	** dx + ey = f
	*/

	float a, b, c, d, e, f;
	printf("Nhap he so a, b, c: ");
	scanf("%f%f%f", &a, &b, &c);

	printf("Nhap he so d, e, f: ");
	scanf("%f%f%f", &d, &e, &f);

	float D, Dx, Dy;
	D = a * e - b * d;
	Dx = c * e - b * f;
	Dy = a * f - c * d;

	if (D == 0 && Dx == 0) printf("HPT co vo so nghiem\n");
	if (D == 0 && Dx != 0) printf("HPT vo nghiem\n");
	if (D != 0)
	{
		printf("x = %.2f\n", Dx / D);
		printf("y = %.2f\n", Dy / D);
	}

	getch();
	return 0;
}