#include <stdio.h>

/*
** Input    : Nhập số lượng sản phẩm và đơn giá 
** Output   : Tính tiền và thuế GTGT
** IDE      : Visual Studio 2017
*/

int main()
{
	// Input
	unsigned int SoLuong;
	float DonGia;
	printf("Nhap so luong: ");
	scanf("%d", &SoLuong);
	printf("Nhap don gia: ");
	scanf("%f", &DonGia);

	// Calculator
	float TongTien = (float)SoLuong * DonGia;
	float GTGT = TongTien * 0.1;

	printf("\nTong tien: %.2f", TongTien);
	printf("\nGTGT: %.2f", GTGT);

	getch();
	return 0;
}