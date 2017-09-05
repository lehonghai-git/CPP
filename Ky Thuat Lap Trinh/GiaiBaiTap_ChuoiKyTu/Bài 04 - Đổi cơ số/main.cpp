#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void DoiCoSo(int, int);
void ITOA(int, char *, int);
int DoiSangHe10(char *, int);

int main()
{
#if 0
	int x;
	printf("Nhap so nguyen he 10: ");
	scanf("%d", &x);

	printf("\nDEC to BIN: ");
	DoiCoSo(x, 2);
	printf("\nDEC to OCT: ");
	DoiCoSo(x, 8);
	printf("\nDEC to HEX: ");
	DoiCoSo(x, 16);
#endif // 0

#if 0
	int x = 250;
	char kq[50];
	ITOA(x, kq, 16);
	printf("%s\n", kq);
#endif // 1

#if 0
	// Đổi các số hệ 2, 8, 16 sang hệ 10
	char s1[] = "11111001011";
	int x = DoiSangHe10(s1, 2);
	printf("(%s)Bin to Dec = %d\n", s1, x);

	char s2[] = "372";
	int y = DoiSangHe10(s2, 8);
	printf("(%s)Oct to Dec = %d\n", s2, y);

	char s3[] = "12Abc34";
	int z = DoiSangHe10(s3, 16);
	printf("(%s)Hex to Dec = %d\n", s3, z);

#endif // 1


	getch();
	return 0;
}

// Hàm chuyển đổi cơ số hệ 10 sang các hệ cơ số: 2, 8, 16
void DoiCoSo(int x, int radix)
{
	char s[30];
	int i = 0;
	while (x != 0)
	{
		int tmp = x % radix;
		if (tmp == 10)
			s[i] = 'A';
		else if (tmp == 11)
			s[i] = 'B';
		else if (tmp == 12)
			s[i] = 'C';
		else if (tmp == 13)
			s[i] = 'D';
		else if (tmp == 14)
			s[i] = 'E';
		else if (tmp == 15)
			s[i] = 'F';
		else
		{
			tmp += 48;
			s[i] = tmp;
		}

		x /= radix;
		i++;
	}

	for (int j = i - 1; j >= 0; j--)
		printf("%c", s[j]);
}
void ITOA(int value, char *kq, int radix)
{
	int index = 0;
	while (value != 0)
	{
		int so = value % radix;
		if (so < 9)
			kq[index++] = so + 48;
		else if (so == 10)
			kq[index++] = 'A';
		else if (so == 11)
			kq[index++] = 'B';
		else if (so == 12)
			kq[index++] = 'C';
		else if (so == 13)
			kq[index++] = 'D';
		else if (so == 14)
			kq[index++] = 'E';
		else if (so == 15)
			kq[index++] = 'F';

		value /= radix;
	}
	kq[index] = '\0';

	strrev(kq);
}
// Hàm chuyển đổi cơ số hệ 2, 8, 16 sang hệ 10
int DoiSangHe10(char *s, int coso)
{
	int n = 0;
	int length = strlen(s);
	int somu = length - 1;

	if (coso == 2)
		for (int i = 0; i < length; i++)
			n += (s[i] - 48) * pow((double)coso, somu--);
	else if (coso == 8)
		for (int i = 0; i < length; i++)
			n += (s[i] - 48) * pow((double)coso, somu--);
	else if (coso == 16)
	{
		for (int i = 0; i < length; i++)
		{
			int so;
			if (s[i] == 'A' || s[i] == 'a')
				so = 10;
			else if (s[i] == 'B' || s[i] == 'b')
				so = 11;
			else if (s[i] == 'C' || s[i] == 'c')
				so = 12;
			else if (s[i] == 'D' || s[i] == 'd')
				so = 13;
			else if (s[i] == 'E' || s[i] == 'e')
				so = 14;
			else if (s[i] == 'F' || s[i] == 'f')
				so = 15;
			else if (s[i] > '0' && s[i] < '9')
				so = s[i] - 48;
			n += so * pow((double)coso, somu--);
		}
	}
	else
		return 0;

	return n;
}