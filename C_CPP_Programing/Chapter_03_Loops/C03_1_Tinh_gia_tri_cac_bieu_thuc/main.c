#include <stdio.h>

/*
** Input    : Nhập số nguyên dương n
** Output   : Tính giá trị các biểu thức
** IDE      : Visual Studio 2017
*/

int main()
{
	int n;
	do
	{
		printf("Nhap n (n > 0) = ");
		scanf("%d", &n);
		if (n <= 0)
			printf("Kiem tra lai n\n");
	} while (n <= 0);

#if 0 // // a. S = 1 + 2 + 3 + .. + n
	int Sa = 0;
	for (int i = 1; i <= n; i++)
		Sa += i;
	printf("S = %d\n", Sa);
#endif // 1 // // a. S = 1 + 2 + 3 + .. + n

#if 0 // b. S = 1^2+2^2+..+n^2
	int Sb = 0;
	for (int i = 1; i <= n; i++)
		Sb += i * i;
	printf("S = %d\n", Sb);
#endif // 1 // b. S = 1^2+2^2+..+n^2

#if 0 // c. S = 1+1/2+1/3+..+1/n
	float Sc = 0;
	for (int i = 1; i <= n; i++)
		Sc += 1.0 / i;
	printf("S = %.3f\n", Sc);
#endif // 1 // c. S = 1+1/2+1/3+..+1/n

#if 0 // d. S = 1*2*3*..*n
	int Sd = 1;
	for (int i = 1; i <= n; i++)
		Sd *= i;
	printf("S = %d\n", Sd);
#endif // 1 // d. S = 1*2*3*..*n

#if 1 // e. S = 1!+2!+..+n!
	int Se = 0;
	// Cách 1:
	/*for (int i = 1; i <= n; i++)
	{
		int tmp = 1;
		for (int j = 1; j <= i; j++)
			tmp *= j;
		Se += tmp;
	}
	printf("S = %d\n", Se);
	*/

	// Cách 2: Nhanh hơn
	int tmp = 1;
	for (int i = 1; i <= n; i++)
	{
		tmp *= i;
		Se += tmp;
	}
	printf("S = %d\n", Se);
#endif // 1 // e. S = 1!+2!+..+n!

#if 1 // Ghi chú
	/*
	** Cho 3 vòng for
	** vòng for thứ 1: for(int i = 0; i <= n; i++)
	** vòng for thứ 2: for(int i = n; i >= 0; i--)
	** vòng for thứ 3: for(int i = n; i >= 0; --i)
	** Tốc độ thực thi của 3 vòng for này tăng dần từ vòng for 1 đến 3
	** Vì: Máy tính thực hiện việc so sánh một số a với 0 sẽ nhanh hơn
	** việc so sánh một số a với một số b (b != 0)
	*/
#endif // 1 // Ghi chú

	getch();
	return 0;
}