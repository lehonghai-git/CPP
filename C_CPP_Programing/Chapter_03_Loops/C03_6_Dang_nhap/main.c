#include <stdio.h>
#define PSW 12345

/*
** Input    : Nhập vào mật khẩu là số nguyên
** Output   : Thông báo đăng nhập thành công hay thất bại
** IDE      : Visual Studio 2017
*/

int main()
{
	int input;
	char key;
	do
	{
		printf("Enter Password: ");
		scanf("%d", &input);

		input == PSW ? printf("Dang nhap thanh cong!\n") : printf("Dang nhap that bai!\n");
		rewind(stdin); //fflush(stdin); // not working in vs2015, vs2017
		printf("Co muon tiep tuc? (y/n): ");
		scanf("%c", &key);
	} while (key == 'y');
	getch();
	return 0;
}