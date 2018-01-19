#include <stdio.h>

/*
** Input    : Ký tự thường/hoa
** Output   : In ra ký tự hoa/thường
** IDE      : Visual Studio 2017
*/

int main()
{
	/*
	** - Nhập ký tự thường, in ký tự hoa và ngược lại
	** - Nếu không nằm trong đoạn sau thì báo lỗi, kết thúc
	** A -> Z và a -> z
	** - Xem lại bảng mã ASCII
	** A -> Z <=> 65 -> 90
	** a -> z <=> 97 -> 122
	*/

	char key;
	printf("Nhap ky tu: ");
	scanf("%c", &key);

	// Có thể dùng dạng thập phân hoặc dạng ký tự mã ascii để so sánh đều được
	if (key >= 65 && key <= 90) // Dùng dạng thập phân
	{
		key += 32;
		printf("Sau khi chuyen doi: %c\n", key);
	}
	else if (key >= 'a' && key <= 'z') // Dùng dạng ký tự ascii
	{
		key -= 32;
		printf("Sau khi chuyen doi: %c\n", key);
	}
	else printf("Nhap sai ky tu\n");

	getch();
	return 0;
}