#include <stdio.h>
#include <conio.h>

#define PSW 972017

int main()
{
	int input;
	char key;
	do
	{
		printf("Enter Password: ");
		scanf("%d", &input);

		input == 972017 ? printf("Dang nhap thanh cong!\n") : printf("Dang nhap that bai!\n");

		//fflush(stdin); // not working in vs2015, vs2017
		rewind(stdin);
		printf("Co muon tiep tuc? (y/n): ");
		scanf("%c", &key);
	} while (key == 'y');

	getch();
	return 0;
}
/*
for(;;)
{
printf("abc");
}
=> Vòng lặp vô tận
*/