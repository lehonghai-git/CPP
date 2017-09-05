/*
Đảo từng ký tự của một từ bên trong một chuỗi.
VD: Le Hong Hai
=> eL gnoH iaH
*/
#include <stdio.h>
#include <conio.h>
#include <string.h>

void DaoKyTuTrongTu(char *);

int main()
{
	char s[50];
	printf("Nhap chuoi: ");
	gets_s(s);
	printf("Chuoi sau khi dao: ");
	DaoKyTuTrongTu(s);

	getch();
	return 0;
}

void DaoKyTuTrongTu(char *s)
{
	char *ptr = strtok(s, " ");
	printf("%s ", strrev(ptr));
	while (ptr != '\0')
	{
		ptr = strtok(NULL, " ");
		if (ptr != '\0')
			printf("%s ", strrev(ptr));
	}
}