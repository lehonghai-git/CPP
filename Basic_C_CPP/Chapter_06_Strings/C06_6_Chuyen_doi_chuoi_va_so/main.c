#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
** CHUYỂN ĐỔI QUA LẠI GIỮA CHUỖI VÀ SỐ
*/

int ATOI(char *);
double ATOF(char *);

int main()
{
#if 0
	// Hàm chuyển đổi chuỗi thành số.
	// Cần khai báo thư viện stdlib.h
	char s1[] = "123";
	char s2[] = "123456";
	char s3[] = "123.456";

	printf("s1 = %d\n", atoi(s1)); // int
	printf("s2 = %ld\n", atol(s2)); // long
	printf("s3 = %f\n", atof(s3)); // float
	/*
	Trường hợp tự xây dựng một hàm chuyển đổi:
	123 = 1*10^2 + 2*10^1 + 3*10^0
	Số lượng chữ số = log10(số)
	Số lượng ký tự = strlen(chuỗi)
	- Đổi 1 ký tự sang số => Ký tự - 48
	- Đổi 1 số sang ký tự => Số + 48
	VD: '1' có mã ascii là 49, '2' có mã ascii là 50
	*/

	char s4[] = "123abc123";
	printf("s4 = %d\n", ATOI(s4));

	char s5[] = "123.4567";
	printf("s5 = %f\n", ATOF(s5));
#endif // 1

#if 0 // Hàm chuyển đổi số thành chuỗi
	int x = 250;
	char kq[30];
	_itoa(x, kq, 16); // Chuyển 250 sang dạng nhị phân/bát phân/thập lục phân...
	printf("So %d chuyen sang he %d la %s\n", x, 16, kq);

	_itoa(x, kq, 2);
	printf("So %d chuyen sang he %d la %s\n", x, 2, kq);

	_itoa(x, kq, 8);
	printf("So %d chuyen sang he %d la %s\n", x, 8, kq);
#endif // Hàm chuyển đổi số thành chuỗi

	getch();
	return 0;
}

// Hàm chuyển đổi một chuỗi sang số
int ATOI(char *s)
{
	int length = strlen(s);
	int tmp = length;
	int So = 0;

	// Trường hợp chuỗi "123abc" => chỉ lấy số 123
	// Vòng lặp kiểm tra độ dài chỉ với những ký tự là số
	for (int i = 0; i < length; i++)
	{
		if (s[i] < '0' || s[i] > '9')
		{
			tmp = i;
			break;
		}
	}
	int somu = tmp;
	for (int i = 0; i < tmp; i++)
		So += (s[i] - 48) * pow((double)10, --somu);

	return So;
}
double ATOF(char *s)
{
	char PhanNguyen[30];
	char PhanThuc[30];
	int index = 0, Check = 1;
	int length = strlen(s);

	for (int i = 0; i < length; i++)
	{
		if (Check)
			PhanNguyen[index++] = s[i];
		else
			PhanThuc[index++] = s[i];
		if (s[i] == '.')
		{
			Check = 0;
			index = 0; // Reset lại index
		}
	}

	return ATOI(PhanNguyen) + ATOI(PhanThuc) / pow((double)10, index);
}