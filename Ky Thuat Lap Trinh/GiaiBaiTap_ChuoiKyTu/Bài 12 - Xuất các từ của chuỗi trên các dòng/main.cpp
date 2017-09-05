/*
* Viết hàm nhận vào một chuỗi s và xuất các từ trên các dòng liên tiếp.
VD: Le Hong     Hai
Output:
Le
Hong
Hai
* HD:
- Xây dựng một hàm cắt ra chuỗi con trong đoạn từ x đến y
- x ký tự khác khoảng trắng đầu tiên
- y ký tự khoảng trắng lùi về trước đó 1 chỉ số
*/
#include <stdio.h>
#include <conio.h>
#include <string.h>

char* SUBSTR(char *, int, int);
void XuatCacTu(char *);

int main()
{
	char s[] = "  Le   Hong   Hai      ";
	XuatCacTu(s);

	getch();
	return 0;
}

// Hàm tách các chuỗi con
char* SUBSTR(char *s, int start, int end)
{
	char p[100];
	int index = 0;
	for (int i = start; i <= end; i++)
		p[index++] = s[i];
	p[index] = '\0';
	return p;
}

// Hàm liệt kê các từ
void XuatCacTu(char *s)
{
	int start, end;
	int n = strlen(s);
	for (int i = 0; i < n; i++)
	{
		if (s[i] != ' ')
		{
			start = i;
			// Chạy tiếp từ start
			for (int j = start + 1; j <= n; j++)
			{
				if (s[j] == ' ' || s[j] == '\0')
				{
					end = j - 1;
					char p[100];
					strcpy(p, SUBSTR(s, start, end));
					printf("\n%s", p);
					i = j; // Cập nhập lại vị trí chạy của i. Bỏ qua từ đã đi qua
					break;
				}
			}
		}
	}

} 