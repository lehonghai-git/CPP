/*
Bài toán: Cộng hai số mà số lượng chữ số của mỗi số đó lên đến hàng trăm, hàng nghìn chữ số
HD:
- 1 ký tự muốn đổi sang số: ký tự - 48
- 1 số muốn đổi sang ký tự: số + 48

B1: Chuẩn hóa hai chuỗi, cho hai chuỗi bằng nhau. Chuỗi nào ngắn hơn thì thêm số 0
vào đầu để cho hai chuỗi bằng nhau thì thôi
B2: Duyệt từ phải qua trái. Lần lượt lấy từng ký tự của hai chuỗi cộng với nhau (ký tự đã đổi sang số).
Trương hợp phép tổng > 9 thì sẽ có một biến tạm lưu chữ số hàng chục còn chữ số hàng đơn vị thì lưu vào
chuỗi kết quả.

*/
#include <stdio.h>
#include <conio.h>
#include <string.h>

void Xoa(char *, int);
void Them(char *, char, int);
void ChuanHoaCungDoDai(char *, char *);
char* TinhTong(char *, char *);

int main()
{
	char s1[30];
	char s2[30];
	char Tong[50];
	
	strcpy(s1, "957196721962761");
	strcpy(s2, "9751674196716472");
	strcpy(Tong, TinhTong(s1, s2));
	printf("%s\n+\n%s\n=\n%s\n", s1, s2, Tong);
	
	getch();
	return 0;
}

void Xoa(char *s, int vt)
{
	int n = strlen(s);
	for (int i = vt + 1; i < n; i++)
		s[i - 1] = s[i];
	s[n - 1] = '\0';
}
void Them(char *s, char kt, int vt)
{
	int n = strlen(s);
	for (int i = n - 1; i >= vt; i--)
		s[i + 1] = s[i];
	s[vt] = kt;
	s[n + 1] = '\0';
}
void ChuanHoaCungDoDai(char *s1, char *s2)
{
	int ns1 = strlen(s1);
	int ns2 = strlen(s2);

	if (ns1 < ns2)
		for (int i = 0; i < ns2 - ns1; i++)
			Them(s1, '0', 0);
	else if (ns1 > ns2)
		for (int i = 0; i < ns1 - ns2; i++)
			Them(s2, '0', 0);
}
char* TinhTong(char *s1, char *s2)
{
	ChuanHoaCungDoDai(s1, s2);
	int n = strlen(s1);
	int tmp = 0; // Biến nhớ khi kết quả phép tổng > 9
	char kq[200];
	int index = 0;

	for (int i = n - 1; i >= 0; i--)
	{
		int so1 = s1[i] - 48; // đổi ký tự sang số
		int so2 = s2[i] - 48;

		int Tong = so1 + so2 + tmp;
		tmp = Tong / 10;
		Tong %= 10; // Lấy phần dư
		kq[index++] = Tong + 48; // Lưu kết quả Tổng dạng ký tự vào chuỗi kết quả
	}
	
	if (tmp != 0)
		kq[index++] = tmp + 48; // Trường hợp hai số đầu tiên của chuỗi cộng lại > 9 thì nhớ sẽ vẫn đang lưu giữ một số
	kq[index] = '\0';

	strrev(kq); // Đảo ngược lại chuỗi

	return kq;
}