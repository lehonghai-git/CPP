/*
Tìm và in lên màn hình các số nguyên trog phạm vi từ 10 đến 99 sao cho:
Tích của 2 chữ số bằng 2 lần tổng của 2 chữ số đó
VD: Số 44 <=> (4*4) = 2*(4+4)
*/
#include <stdio.h>
#include <conio.h>

int main()
{
#if 0
	// Cách 1:
	for (int i = 10; i < 100; i++)
	{
		int a = i % 10;
		int b = i / 10;
		if ((a * b) == 2 * (a + b))
			printf("%d\n", i);
	}
#endif // 0

#if 1
	// Cách 2:
	for (int i = 1; i < 10; i++)
		for (int j = 1; j < 10; j++)
			if ((i * j) == 2 * (i + j))
				printf("%d%d\n", i, j);
#endif // 1

	getch();
	return 0;
}