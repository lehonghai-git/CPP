#include <stdio.h>
#include <conio.h>
#include <string.h>

int DemSoTuTrongChuoi(char *);

int main()
{
	char s[50];
	printf("Nhap chuoi: ");
	gets_s(s);
	int sotu = DemSoTuTrongChuoi(s);
	printf("Chuoi vua nhap co %d tu\n", sotu);

	getch();
	return 0;
}

int DemSoTuTrongChuoi(char *s)
{
	int sotu = 1;
	int n = strlen(s);
	for (int i = 0; i < n; i++)
		if (s[i] == ' ' && s[i + 1] != ' ')
			sotu++;
	return sotu;
}