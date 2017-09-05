#include <stdio.h>
#include <conio.h>
#include <math.h>

int TinhDoDaiChuoi(char *);

int main()
{
	char s[50];
	printf("Nhap chuoi: ");
	gets_s(s);
	int len = TinhDoDaiChuoi(s);
	printf("Do dai chuoi s = %d\n", len);

	getch();
	return 0;
}

// Hàm strlen()
int TinhDoDaiChuoi(char *s)
{
	int i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return i;
}
// Hàm strcpy()
void SaoChepChuoi(char *s, char *z)
{

}