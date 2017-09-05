/*
- Nhập số lượng và đơn giá của một sản phẩm
- Tính tiền và thuế giá trị gia tăng (GTGT)
- Biết:
	Tiền = số lượng * đơn giá
	Thuế GTGT = 10% tiền
*/
#include <stdio.h>
#include <conio.h>

int main()
{
	unsigned int SoLuong, DonGia;

	printf("Nhap so luong: ");
	scanf("%u", &SoLuong);
	printf("Nhap don gia: ");
	scanf("%u", &DonGia);

	unsigned int Tien = SoLuong * DonGia;
	float Thue = Tien *0.1;

	printf("-------------\n");
	printf("Tien = %.2u $\n", Tien);
	printf("Thue = %.2f $\n", Thue);

	getch();
	return 0;
}