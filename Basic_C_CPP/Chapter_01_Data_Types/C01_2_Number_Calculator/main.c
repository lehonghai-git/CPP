#include <stdio.h>

/*
** Input    : Nhập hai số
** Output   : Tính tổng, hiệu, tích, thương
** IDE      : Visual Studio 2017
*/

int main()
{
	// Input
	float num1, num2;
	printf("Nhap num 1 = ");
	scanf("%f", &num1);
	printf("Nhap num 2 = ");
	scanf("%f", &num2);

	// Calculator
	float Add = num1 + num2;
	float Sub = num1 - num2;
	float Div = num1 / num2;
	float Mul = num1 * num2;

	printf("\nAdd: %.1f", Add);
	printf("\nSub: %.2f", Sub);
	printf("\nMul: %.3f", Mul);
	printf("\nDiv: %.4f", Div);

	getch();
	return 0;
}