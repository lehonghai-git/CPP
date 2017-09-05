/*
Kiểm tra 1 số nguyên có phải số chính phương hay không?
Số chính phương là số mà đem khai căn b2 thì được kết quả là một số nguyên.
VD: 1, 4, 9, 16, 25
*/

#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
	int n;
	printf("Nhap vao so can kiem tra: ");
	scanf("%d", &n);
#if 0
	// Cách 1
	if (sqrt((float)n) == (int)sqrt((float)n))
		printf("La so chinh phuong\n");
	else
		printf("Khong la so chinh phuong\n");
#endif // 0

#if 1
	// Cách 2:
	if (sqrt((float)n) * sqrt((float)n) == n)
		printf("La so chinh phuong\n");
	else
		printf("Khong la so chinh phuong\n");
#endif // 1

	getch();
	return 0;
}
/*
- Với cách 1
VD: n = 5
sqrt((float)5) = 2.2360
(int)sqrt((float)5) = 2
=> 2.2360 != 2

VD: n = 4
sqrt((float)4) = 2.0000
(int)sqrt((float)4) = 2
=> 2.0000 == 2
*/