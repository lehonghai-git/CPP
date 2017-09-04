/*
Nhập vào 3 cạnh của một tam giác. Kiểm tra xem 3 cạnh đó có tạo thành một tham giác không?
- Tổng 2 cạnh bất kỳ > cạnh còn lại => Tạo thành tam giác.
Nếu tạo thành tam giác gì tam giác đó là tam giác gì?
- Tam giác thường
- Tam giác cân
- Tam giác đều
- Tam giác vuông
- Tam giác vuông cân
*/
#include <stdio.h>
#include <conio.h>

int main()
{
	float a, b, c;
	printf("Nhap vao 3 canh tam giac: ");
	scanf("%f%f%f", &a, &b, &c);

	if (a < 0 || b < 0 || c < 0 || a + b <= c || a + c <= b || b + c <= a)
	{
		printf("Khong tao thanh tam giac\n");
		getch();
		return 0;
	}
	/*
	Ưu tiên các trường hợp đặc biệt lên trước
	1. Đều
	2. Vuông cân
	3. Vuông
	4. Cân
	5. Thuờng
	*/

	// Trường hợp tam giác đều là th đặc biệt của tam giác cân
	if (a == b && b == c)
	{
		printf("Tam giac deu\n");
		getch();
		return 0;
	}

	if (a*a + b*b == c*c || c*c + a*a == b*b || b*b + c*c == a*a)
	{
		// Vuông cân là th đặc biệt của vuông
		if (a == b || a == c || b == c)
		{
			printf("Tam giac vuong can\n");
			getch();
			return 0;
		}

		printf("Tam giac vuong\n");
		getch();
		return 0;
	}

	if (a == b || a == c || b == c)
	{
		printf("Tam giac can\n");
		getch();
		return 0;
	}

	printf("Tam giac thuong\n");

	getch();
	return 0;
}