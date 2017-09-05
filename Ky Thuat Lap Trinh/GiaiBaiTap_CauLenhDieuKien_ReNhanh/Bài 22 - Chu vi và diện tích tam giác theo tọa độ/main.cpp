/*
Nhập vào tạo độ 3 đỉnh của tam giác
Tính chu vi và diện tích của tam giác đó
*/
#include <stdio.h>
#include <conio.h>
#include <math.h>


int main()
{
	float xA, yA, xB, yB, xC, yC;

	printf("Nhap toa do dinh A(x1, y1) = ");
	scanf("%f%f", &xA, &yA);
	printf("Nhap toa do dinh B(x2, y2) = ");
	scanf("%f%f", &xB, &yB);
	printf("Nhap toa do dinh C(x3, y3) = ");
	scanf("%f%f", &xC, &yC);

	printf("Toa do 3 diem:\n");
	printf("A (%.1f, %.1f)\n", xA, yA);
	printf("B (%.1f, %.1f)\n", xB, yB);
	printf("C (%.1f, %.1f)\n", xC, yC);

	float dAB, dAC, dBC;
	// Tính khoảng cách các đỉnh
	dAB = sqrt(pow((xA - xB), 2.0) + pow((yA - yB), 2.0));
	dAC = sqrt(pow((xA - xC), 2.0) + pow((yA - yC), 2.0));
	dBC = sqrt(pow((xB - xC), 2.0) + pow((yB - yC), 2.0));

	if (dAB < 0 || dAC < 0 || dBC < 0 || (dAB + dAC) <= dBC || (dAB + dBC) <= dAC || (dAC + dBC) <= dAB)
	{
		printf("Toa do ban nhap vao khong tao thanh tam giac\n");
		getch();
		return 0;
	}
	else
	{
		float C = dAB + dAC + dBC;
		float S = sqrt(C*(C / 2 - dAB)*(C / 2 - dAC)*(C / 2 - dBC) / 2);
		printf("Chu vi C = %.2f\n", C);
		printf("Dien tich S = %.2f\n", S);
	}

	getch();
	return 0;
}