#include <stdio.h>

/*
** Input    :
** Output   :
** IDE      : Visual Studio 2017
*/

int main()
{
#if 1 // C�ch 1:
	for (int i = 10; i < 100; i++)
	{
		int a = i % 10;
		int b = i / 10;
		if ((a * b) == 2 * (a + b))
			printf("%d\n", i);
	}
#endif // C�ch 1:

#if 1 // C�ch 2:
	for (int i = 1; i < 10; i++)
		for (int j = 1; j < 10; j++)
			if ((i * j) == 2 * (i + j))
				printf("%d%d\n", i, j);
#endif // C�ch 2:

	getch();
	return 0;
}