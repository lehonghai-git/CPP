#include <stdio.h>
#include <string.h>

/*
* Chuẩn hóa chuỗi theo nguyên tắc sau
- Các từ các nhau 1 khoảng trắng
- Chữ cái đầu của mỗi từ phải là in hoa. Các chữ cái còn lại viết thường
VD: LE      hOng HAI
=> Le Hong Hai
* HD:
- Gặp hai khoảng trắng liền nhau => xóa 1 khoảng trắng
- Gặp một ký tự sau một khoảng trắng => In hoa
*/

void XoaMotKyTu(char[], int);
void ChuanHoaChuoi(char[]);

int main()
{
	char s[50];
	printf("Nhap chuoi can chuan hoa: ");
	gets(s);
	printf("Chuoi chua chuan hoa: %s\n", s);
	ChuanHoaChuoi(s);
	printf("Chuoi da chuan hoa: %s\n", s);

	getch();
	return 0;
}

void XoaMotKyTu(char s[], int vt)
{
	int n = strlen(s);
	for (int i = vt + 1; i < n; i++)
		s[i - 1] = s[i];
	s[n - 1] = '\0';
}
void ChuanHoaChuoi(char s[])
{
	_strlwr(s); // Chuyển chuỗi về toàn bộ là chữ thường
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] == ' ' && s[i + 1] == ' ')
		{
			XoaMotKyTu(s, i);
			i--;
		}
	}

	s[0] -= 32; // Chuyển ký tự đầu tiên thành ký tự hoa
	for (int i = 1; i < strlen(s) - 1; i++)
	{
		if (s[i] == ' ' && s[i + 1] != ' ')
			s[i + 1] -= 32; // Chuyển thành chữ hoa
	}
}