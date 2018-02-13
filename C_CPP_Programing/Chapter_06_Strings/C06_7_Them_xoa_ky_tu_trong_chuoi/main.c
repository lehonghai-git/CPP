#include <stdio.h>
#include <string.h>

/*
** THÊM, XÓA KÝ TỰ
*/
void XoaKyTu(char *, int);
void ThemKyTu(char *, int, char);

int main()
{
#if 0 // Xóa ký tự
	char s[] = "abcdef";
	printf("Truoc khi xoa: %s\n", s);
	int vt;
	printf("Nhap vi tri muon xoa: ");
	scanf("%d", &vt);
	XoaKyTu(s, vt);
	printf("Sau khi xoa: %s\n", s);
#endif // Xóa ký tự

#if 0 // Thêm ký tự
	char s[] = "abcdef";
	printf("Truoc khi them: %s\n", s);
	ThemKyTu(s, 6, 'g');
	printf("Sau khi them: %s\n", s);
#endif // Thêm ký tự


	getch();
	return 0;
}

// Hàm xóa 1 ký tự trong chuỗi
void XoaKyTu(char *s, int vt)
{
	int n = strlen(s);
	for (int i = vt + 1; i < n; i++)
		s[i - 1] = s[i];
	s[n - 1] = '\0'; // Dịch ký tự kết thúc chuỗi sang trái 1 ký tự
}

// Hàm thêm một ký tự trong chỗi
void ThemKyTu(char *s, int vt, char gt)
{
	int n = strlen(s);
	for (int i = n - 1; i >= vt; i--)
		s[i + 1] = s[i];
	s[vt] = gt;
	s[n + 1] = '\0'; // Dịch ký tự kết thúc chuỗi sang phải 1 ký tự
}