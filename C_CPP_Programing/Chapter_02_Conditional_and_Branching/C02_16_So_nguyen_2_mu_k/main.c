#include <stdio.h>
#include <math.h>

/*
** Input    : Số nguyên
** Output   : Có phải dạng 2^k không
** IDE      : Visual Studio 2017
*/

int main()
{
	/*
	** VD:
	** 4 => Có dạng 2^2
	** 5 => Không th
	*/

	int x;
	printf("Nhap vao so nguyen: ");
	scanf("%d", &x);

	if (x < 1)
	{
		printf("So %d khong hop le\n", x);
		getch();
		return 0;
	}

	/*
	** Công thức: Loga(b) / Loga(c) = Logc(b)
	** Log2(2^k) = k là số nguyên thì x có dạng 2^k
	** VD: Log2(8) = Log2(2^3) = 3
	** Log10(8) / Log10(2) = Log2(8)
	*/
	double kq = log10((double)x) / log10(2.0);
	if (kq == (int)kq)
		printf("%d = 2^%d\n", x, (int)kq);
	else
		printf("Khong co dang 2^k\n");
	getch();
	return 0;
}