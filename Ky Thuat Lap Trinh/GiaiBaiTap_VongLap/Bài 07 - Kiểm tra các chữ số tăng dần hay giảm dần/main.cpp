/*
Nhập vào số nguyên dương n. và kiểm tra:
- Kiểm tra các chữ số tăng dần?
VD: 123456, 11223344

- Kiểm tra các chữ số giảm dần?
VD: 654321, 66554433
- Kiểm tra các chữ số không tăng, không giảm?
VD: 11072017

*/
#include <stdio.h>
#include <conio.h>

int main()
{
	int n;
	do
	{
		printf("Nhap n (n > 0): ");
		scanf("%d", &n);
		if (n <= 0)
			printf("Nhap lai n\n");
	} while (n <= 0);


	/*
	VD có một số abcd. Cần tách từng chữ số ra để so sánh
	d = abcd % 10
	abcd /= 10 = abc
	c = abc % 10
	=> So sánh c với d. Chỉ cần c > d => Kết luận là không tăng dần
	=> Dùng cờ hiệu
	*/
#if 0
	// Kiểm tra có tăng dần hay không
	int CoTangDanKhong = 1, tmp1 = n;
	int donvi1 = tmp1 % 10;
	tmp1 /= 10;
	while (tmp1 != 0)
	{
		int chuc1 = tmp1 % 10;
		if (chuc1 > donvi1)
		{
			CoTangDanKhong = 0;
			break;
		}
		donvi1 = chuc1; // Cập nhập số để so sánh lần lặp kế tiếp
		tmp1 /= 10;
	}

#endif // 1

#if 0
	// Kiểm tra có giảm dần hay không
	int CoGiamDanKhong = 1, tmp2 = n;
	int donvi2 = tmp2 % 10;
	tmp2 /= 10;
	while (tmp2 != 0)
	{
		int chuc2 = tmp2 % 10;
		if (chuc2 < donvi2)
		{
			CoGiamDanKhong = 0;
			break;
		}
		donvi2 = chuc2; // Cập nhập số để so sánh lần lặp kế tiếp
		tmp2 /= 10;
	}

#endif // 1

#if 1
	// Kiểm tra có tăng dần và giảm đần trong một vòng lặp
	int CoTangDanKhong = 1, CoGiamDanKhong = 1, tmp = n;
	int donvi = tmp % 10;
	tmp /= 10;
	while (tmp != 0)
	{
		int chuc = tmp % 10;
		// Check tăng
		if (chuc > donvi)
			CoTangDanKhong = 0;
		// Check giảm
		if (chuc < donvi)
			CoGiamDanKhong = 0;
		donvi = chuc; // Cập nhập số để so sánh lần lặp kế tiếp
		tmp /= 10;
	}
#endif // 1

	if (CoTangDanKhong)
		printf("So %d la so tang dan\n", n);
	else if (CoGiamDanKhong)
		printf("So %d la so giam dan\n", n);
	else
		printf("So %d khong tang khong giam\n", n);

	getch();
	return 0;
}