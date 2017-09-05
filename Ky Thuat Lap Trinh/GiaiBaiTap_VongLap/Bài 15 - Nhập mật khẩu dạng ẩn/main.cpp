/*
Nhập mật khẩu từ bàn phím. Mậu khẩu nhập vào phải hiển thị dạng dấu *
- Hàm kbhit() sẽ bắt phím người dùng nhấn.
Trả về True nếu người dùng có nhấn phím
*/
#include <stdio.h>
#include <conio.h>

int main()
{
#if 1
	char c = 'h', password[20]; // Khởi tạo cho c là một ký tự bất kỳ
	int i = 0;

	printf("Password: ");
	while (c != 13) {
		if (kbhit()) // trả về True nếu phím được ấn
		{
			c = getch(); // Đợi nhập 1 ký tự
			if (c != 8) // Không phải phím xóa
			{
				printf("*");
				password[i] = c; // Lưu từng ký tự nhập vào mảng
				i++;
			}
			else
			{
				printf("\b \b");
				i--;
				password[i] = '\0';
			}
		}
	}
	password[i] = '\0'; // Thêm kí tự kết thúc chuỗi
	printf("\nPassword is: %s\n", password);

#endif // 0

	getch();
	return 0;
}