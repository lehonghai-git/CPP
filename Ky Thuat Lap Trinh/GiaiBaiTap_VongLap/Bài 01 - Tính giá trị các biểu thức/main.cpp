/*
Nhập số nguyên dương n, tính:
a. S = 1+2+3+..+n
b. S = 1^2+2^2+..+n^2
c. S = 1+1/2+1/3+..+1/n
d. S = 1*2*3*..*n
e. S = 1!+2!+..+n!
*/
#include <stdio.h>
#include <conio.h>

int main()
{
#if 0
	// a. S = 1 + 2 + 3 + .. + n
	int n, S = 0;
	do
	{
		printf("Nhap n (n > 0) = ");
		scanf("%d", &n);
		if (n <= 0)
			printf("Kiem tra lai n\n");
	} while (n <= 0);

	for (int i = 1; i <= n; i++)
		S += i;
	printf("S = %d\n", S);
	// 5: 1+2+3+4+5 = 15
#endif // 1

#if 0
	// b. S = 1^2+2^2+..+n^2
	int n, S = 0;
	do
	{
		printf("Nhap n (n > 0) = ");
		scanf("%d", &n);
		if (n <= 0)
			printf("Kiem tra lai n\n");
	} while (n <= 0);

	for (int i = 1; i <= n; i++)
		S += i*i;
	printf("S = %d\n", S);
	// 5: 1^1 + 2^2 + 3^3 + 4^4 + 5^5 = 55
#endif // 1

#if 0
	// c. S = 1+1/2+1/3+..+1/n
	int n;
	float S = 0;
	do
	{
		printf("Nhap n (n > 0) = ");
		scanf("%d", &n);
		if (n <= 0)
			printf("Kiem tra lai n\n");
	} while (n <= 0);

	for (int i = 1; i <= n; i++)
		S += 1.0 / i;
	printf("S = %.3f\n", S);
	// 5: 1/1 + 1/2 + 1/3 + 1/4 + 1/5 = 2.283
#endif // 1

#if 0
	// d. S = 1*2*3*..*n
	int n, S = 1;
	do
	{
		printf("Nhap n (n > 0) = ");
		scanf("%d", &n);
		if (n <= 0)
			printf("Kiem tra lai n\n");
	} while (n <= 0);

	for (int i = 1; i <= n; i++)
		S *= i;
	printf("S = %d\n", S);
	// 5!: 1*2*3*4*5 = 120
#endif // 1

#if 1
	// e. S = 1!+2!+..+n!
	int n, S = 0;
	do
	{
		printf("Nhap n (n > 0) = ");
		scanf("%d", &n);
		if (n <= 0)
			printf("Kiem tra lai n\n");
	} while (n <= 0);

	// Cách 1:
	/*
	for (int i = 1; i <= n; i++)
	{
	int tmp = 1;
	for (int j = 1; j <= i; j++)
	tmp *= j;
	S += tmp;
	}
	printf("S = %d\n", S);
	*/

	// Cách 2: Nhanh hơn
	int tmp = 1;
	for (int i = 1; i <= n; i++)
	{
		tmp *= i;
		S += tmp;
	}
	printf("S = %d\n", S);
	// 5: 1! + 2! + 3! + 4! + 5! = 153
#endif // 1

	getch();
	return 0;
}
/*
Cho 3 vòng for
vòng for thứ 1: for(int i = 0; i <= n; i++)
vòng for thứ 2: for(int i = n; i >= 0; i--)
vòng for thứ 3: for(int i = n; i >= 0; --i)
Tốc độ thực thi của 3 vòng for này tăng dần từ vòng for 1 đến 3
Vì: Máy tính thực hiện việc so sánh một số a với 0 sẽ nhanh hơn việc so sánh một số a với một số b (b != 0)
*/