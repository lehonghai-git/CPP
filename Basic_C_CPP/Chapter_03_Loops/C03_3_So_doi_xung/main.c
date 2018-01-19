#include <stdio.h>
#include <math.h>

/*
** Input    : Số nguyên dương n
** Output   : Có là số đối xứng hay không
** IDE      : Visual Studio 2017
*/

int main()
{
	/*
	** Số đối xứng (“palindrome”)?
	** VD: 121, 12321, 14741
	** => Số đối xứng là số trước và sau khi đảo vẫn bằng nhau
	*/

	int n;
	do
	{
		printf("Nhap n (n > 0): ");
		scanf("%d", &n);
		if (n <= 0)
			printf("Nhap lai n\n");
	} while (n <= 0);
	/*
	** Xét một số: n = 12345 => Có 5 chữ số
	** Số đảo ngược của n: 54321
	** Để tách được từng chữ số từ 5,4,3,2,1
	** =>	n % 10;
	** n /= 10;
	** Mà 54321 = 5*10^4 + 4*10^3 + 3*10^2 + 2*10^1 + 1*10^0
	** => Giải thuật là sau mỗi lần tách được chữ số của n thì lấy số tách được đó
	** đem nhân cho 10^(Số chữ số - 1), với mỗi lần thì số chữ số giảm đi 1 và sau
	** mỗi lần kết quả đem cộng dồn vào là được số đảo ngược
	** So sánh số đảo ngược với số ban đầu, nếu bằng nhau thì là số đối xứng
	*/

	int SoNghichDao = 0, tmp = n;
#if 0 // Cách 1
	
	int SoChuSo = log10((float)n) + 1;
	while (n != 0)
	{
		int ChuSo = n % 10;
		n /= 10;
		SoNghichDao += ChuSo * pow(10.0, --SoChuSo);
	}
#endif // Cách 1

#if 1 // Cách 2
	
	while (n != 0)
	{
		SoNghichDao = SoNghichDao * 10 + n % 10;
		n /= 10;
	}
#endif // Cách 2

	printf("So nghich dao: %d\n", SoNghichDao);
	if (SoNghichDao == tmp)
		printf("So %d la so doi xung!\n", tmp);
	else
		printf("So %d khong phai so doi xung!\n", tmp);
	getch();
	return 0;
}