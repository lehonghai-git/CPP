#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
** Input    : Hai số a, b
** Output   : Số ngẫu nhiên được sinh ra trong đoạn [a, b]
** IDE      : Visual Studio 2017
*/

int main()
{
#if 0 // Random số nguyên
	/*
	** Công thức: x = a + rand() % (b - a + 1)
	*/
	srand(time(0)); // Reset lại thời gian sau mỗi lần chạy
	for (int i = 0; i < 5; i++)
	{
		// Hàm rand() hỗ trợ sinh số ngẫu nhiên trong thời gian chạy
		int a = 1 + rand() % (10 - 1 + 1);
		printf("Random tu 1 -> 10: %d\n", a);

		int b = -123 + rand() % (456 + 123 + 1);
		printf("Random tu -123 -> 456: %d\n", b);

		int c = 1234 + rand() % (99999 - 1234 + 1);
		printf("Random tu 1234 -> 99999: %d\n", c);

		int Max = a > b ? a : b;
		Max = Max > c ? Max : c;
		int Min = a < b ? a : b;
		Min = Min < c ? Min : c;

		printf("Min = %d\nMax = %d\n", Min, Max);
	}
#endif // 1 // Random số nguyên


#if 1 // Random số thực
	/*
	** Random điểm (số thực) của sinh viên từ 0.0 -> 10.0
	** Random số nguyên trong đoạn từ 0 -> 100 rồi lấy kết quả / 10
	*/

	srand(time(0));
	printf("Random diem so hoc sinh: 0.0 - 10.0\n");
	for (int i = 0; i < 10; i++)
	{
		int a = (rand() % 101);
		float Point = (float)a / 10;

		printf("%.1f\n", Point);
	}
#endif // 1 // Random số thực

	getch();
	return 0;
}