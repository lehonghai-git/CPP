/*
- Tính lương của nhân viên dựa vào hệ số và năm kinh nghiệm
- Công thức: Luong = HeSo * LuongCoBan.
Trong đó:
	LuongCoBan = 1300000 VNĐ
	Nếu: KN < 12 tháng => HeSo = 1.92
	Nếu: 12 <= KN < 36 tháng => HeSo = 2.34
	Nếu: 36 <= KN < 60 tháng => HeSo = 3
	Nếu: KN >= 60 tháng => HeSo = 4.5
*/
#include <stdio.h>
#include <conio.h>

#define LuongCoBan 1300000

int main()
{
	float HeSo;
	unsigned long ThamNien, Luong;

	printf("Nhap tham nien cong tac (thang): ");
	scanf("%d", &ThamNien);
	if (ThamNien < 12) HeSo = 1.92;
	else if (ThamNien >= 12 && ThamNien < 36) HeSo = 2.34;
	else if (ThamNien >= 36 && ThamNien < 60) HeSo = 3.0;
	else HeSo = 4.5;

	Luong = HeSo * LuongCoBan;
	printf("Luong = %ld VND\n", Luong);

	getch();
	return 0;
}