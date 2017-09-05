/*
Viết hàm nhận vào một chuỗi và trả về chuỗi tương ứng (giữ nguyên chuỗi đầu vào):
- Các ký tự thành ký tự thường (giống strlwr).
	+ 'a' = 97
	+ 'A' = 65
- Các ký tự thành ký tự hoa (giống strupr).
- Các ký tự đầu tiên mỗi từ thành ký tự hoa.
- Chuẩn hóa chuỗi (xóa khoảng trắng thừa)
	+ Đầu chuỗi và cuối chuỗi không có khoảng trắng
	+ Giữa 2 từ chỉ cách nhau 1 khoảng trắng
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h> // malloc()
#include <string.h>

int STRLEN(char *);
void STRCPY(char *, char *);
char* STRDUP(char *);
char* STRLWR(char *);
char* STRUPR(char *);
void SWAP(char &, char &);
void STRREV(char *);
int STRCMP(char *, char *);
int STRICMP(char *, char *);
void STRCAT(char *, char *);
int STRSTR(char *, char *);
char* SUBSTR(char *, int, int);
void VietHoaKyTuDau(char *);
void XoaKyTu(char *, int);
void XoaKhoangTrangThua(char *);

int main()
{
	char s[] = " Ky    thuat   lap trinh         C/C++         ";
	printf("Chuoi ban dau: %s\n", s);

#if 0
	// Tính chiều dài chuỗi
	int dai = STRLEN(s);
	printf("%d\n", dai);
#endif // 0

#if 0
	// Hàm copy chuỗi này sang chuỗi khác
	char buff[50];
	STRCPY(buff, s);
	printf("Ban sao cua s: %s", buff);
#endif // 0

#if 0
	// Biển đuỗi chuỗi về hoa và thường
	char *p1 = STRLWR(s);
	printf("Chuoi thuong: %s\n", p1);

	char *p2 = STRUPR(s);
	printf("Chuoi hoa: %s\n", p2);
#endif // 1

#if 0
	// Đảo ngược chuỗi
	char name[] = "Le Hong Hai";
	printf("Truoc khi dao chuoi: %s\n", name);
	STRREV(name);
	printf("Sau  khi  dao chuoi: %s\n", name);
#endif // 1

#if 0
	// So sánh hai chuỗi có phân biệt hoa thường
	char s1[] = "abc";
	char s2[] = "ABC";

	int kq = STRCMP(s1, s2);
	printf("%d", kq);
#endif // 1

#if 0
	// So sánh hai chuỗi không phân biệt hoa thường
	char s1[] = "abcd";
	char s2[] = "Abed";

	int kq = STRICMP(s1, s2);
	printf("%d", kq);
#endif // 1

#if 0
	// Nối hai chuỗi lại với nhau
	char s1[50] = "abc";
	char s2[8] = "defghi";
	STRCAT(s1, s2);
	printf("%s", s1);

#endif // 1

#if 0
	// Hàm tìm một chuỗi trong chuỗi khác
	char s1[] = "Ky thuat lap trinh c/c++";
	char s2[] = "c/c++";
	printf("s1 = %s\n", s1);
	printf("s2 = %s\n", s2);
	int kq = STRSTR(s1, s2);
	printf("kq = %d", kq);

#endif // 1

#if 0
	// Hàm cắt chuỗi theo vị trí từ x đến y
	char s1[50] = "Ky thuat lap trinh c/c++";
	char buff[60];
	strcpy(buff, SUBSTR(s1, 9, 17));
	printf("buff = %s\n", buff);

#endif // 1

#if 0
	// Hàm nhân bản một chuỗi sang vùng nhớ  có độ lớn vừa đủ
	char s1[] = "Nhan ban mot chuoi";
	printf("s1 = %s\n", s1);

	char *s2 = STRDUP(s1);
	printf("s2 = %s\n", s2);

	free(s2); // Giải phóng khi không dùng
#endif // 1

#if 0
	// Viết hoa ký tự đầu mỗi từ
	VietHoaKyTuDau(s);
	printf("Viet hoa ky tu dau: %s\n", s);
#endif // 1

#if 0
	// Xóa khoảng trắng
	XoaKhoangTrangThua(s);
	printf("Sau khi xoa khoang trang thua: %s", s);
#endif // 1

	getch();
	return 0;
}

// Hàm trả về độ dài của một chuỗi (giống strlen)
int STRLEN(char *s)
{
	int len = 0;
	while (s[len] != '\0') { len++; }
	return len;
}

// Hàm copy một chuỗi (s) sang chuỗi mới (buff) (giống strcpy)
void STRCPY(char *buff, char *s)
{
	int n = STRLEN(s);
	for (int i = 0; i < n; i++)
		buff[i] = s[i];
	buff[n] = '\0'; // Kết thúc chuỗi
}

// Hàm nhân bản một chuỗi (giống strdup)
// Vùng nhớ mới có độ lớn vừa đủ để lưu chuỗi, tránh đc tình trạng lãng phí bộ nhớ của strcpy
// Độ lớn sao chép = length + 1
char* STRDUP(char *s)
{
	int len = STRLEN(s);
	char *p = (char *)malloc((len + 1) * sizeof(char));

	for (int i = 0; i < len; i++)
		p[i] = s[i];
	p[len] = '\0';

	return p;
}

// Hàm chuyển ký tự hoa sang thường (giống strlwr)
// char* => Tức là hàm sẽ trả về một chuỗi/mảng ký tự
char* STRLWR(char *s)
{
	char *p = STRDUP(s);
	int n = STRLEN(p);
	for (int i = 0; i < n; i++)
		if (p[i] >= 'A' && p[i] <= 'Z')
			p[i] += 32; // Chuyển từ hoa sang thường
	return p;
}

// Hàm chuyển ký tự thường sang hoa (giống strupr)
char* STRUPR(char *s)
{
	char *p = STRDUP(s);
	int n = STRLEN(p);
	for (int i = 0; i < n; i++)
		if (p[i] >= 'a' && p[i] <= 'z')
			p[i] -= 32; // Chuyển từ thường sang hoa
	return p;
}

// Hàm hoán vị hai ký tự
void SWAP(char &a, char &b)
{
	char tmp = a;
	a = b;
	b = tmp;
}

// Hàm đảo ngược chuỗi (giống strrev)
void STRREV(char *s)
{
	int n = STRLEN(s);
	for (int i = 0; i < n / 2; i++)
		SWAP(s[i], s[n - 1 - i]);
}

// Hàm so sánh hai chuỗi (Giống strcmp)
int STRCMP(char *s1, char *s2)
{
	int ns1 = STRLEN(s1);
	int ns2 = STRLEN(s2);
	// Sẽ duyệt theo chuỗi mà có độ dài nhỏ hơn
	int n = ns1 < ns2 ? ns1 : ns2; // n là chiều dài chuỗi nhỏ hơn
	for (int i = 0; i < n; i++)
	{
		if (s1[i] < s2[i])
			return -1;
		else if (s1[i] > s2[i])
			return 1;
	}
	/*
	* Xử lý trường hợp đặc biệt
	VD: s1 = "abc", s2 = "a";
	=> chuỗi nào có độ dài lớn hơn thì chuỗi đó lơn hơn
	*/
	if (ns1 > ns2)
		return 1;
	if (ns1 < ns2)
		return -1;

	return 0; // Hai chuỗi bằng nhau
}

// Hàm so sánh hai chuỗi không phân biệt hoa, thường (giống stricmp)
int STRICMP(char *s1, char *s2)
{
#if 0
	// Cách 1: Sử dụng lại những hàm đã xây dựng
	// Chuyển hai chuỗi về cùng một dạng chuỗi thường
	s1 = STRLWR(s1);
	s2 = STRLWR(s2);

	return STRCMP(s1, s2);
#endif // 1
#if 1
	// Cách 2: Tương tự STRCMP nhưng khác ở xử lý ở bước so sánh ký tự
	int ns1 = STRLEN(s1);
	int ns2 = STRLEN(s2);

	int n = ns1 < ns2 ? ns1 : ns2; // n là chiều dài chuỗi nhỏ hơn
	for (int i = 0; i < n; i++)
	{
		// Chuyển về cùng một dạng ký tự (thường)
		char tmp1 = s1[i];
		char tmp2 = s2[i];
		if (tmp1 >= 'A' && tmp1 <= 'Z')
			tmp1 += 32;
		if (tmp2 >= 'A' && tmp2 <= 'Z')
			tmp2 += 32;
		// Bắt đầu so sánh
		if (tmp1 < tmp2)
			return -1;
		else if (tmp1 > tmp2)
			return 1;
	}

	if (ns1 > ns2)
		return 1;
	if (ns1 < ns2)
		return -1;

	return 0;

#endif // 1

}

// Hàm nối chuỗi s2 vào sau chuỗi s1 (giống strcat)
// Trường hợp những vùng thừa của s1 không đủ cho s2 thì chỉ nối sao cho đầy s1 thôi.
void STRCAT(char *s1, char *s2)
{
	int ns1 = STRLEN(s1);
	int sizes1 = sizeof(s1);
	int ns2 = STRLEN(s2);

	for (int i = 0; i < ns2; i++)
	{
		s1[ns1++] = s2[i];
		if (ns1 == sizes1 - 1) // Đã chạm đến kích thước tối đa của chuỗi s1
			break;
	}
	/*
	Note:
	- size của chuỗi khác length của chuỗi
	- VD: s[20] = "Hai";
	=> Size = 20, length = 3
	- Vị trí bắt đầu của chuỗi s[0]
	- Chuỗi có size = 20 nhưng chỉ chứa được 19 ký tự vì ký tự cuối là '\0'
	*/

}

// Hàm tìm vị trí xuất hiện đầu tiên của một chuỗi trong một chuỗi khác (giống strstr)
// Nếu không tìm ra thì trả về -1
int STRSTR(char *s1, char *s2)
{
	int ns1 = STRLEN(s1);
	int ns2 = STRLEN(s2);
	int start;
	int check;
	for (int i = 0; i < ns1; i++)
	{
		if (s1[i] == s2[0]) // Bắt đầu gặp ký tự trùng
		{
			start = i;
			check = 1;
			int tmp = start;
			for (int j = 1; j < ns2; j++)
			{
				if (s1[++tmp] != s2[j])
				{
					check = 0;
					break;
				}
			}
			if (check == 1)
				return start;
		}
	}

	return -1;
}

// Hàm cắt ra chuỗi chuỗi con từ vị trí x đến y trong chuỗi lớn
char* SUBSTR(char *s, int x, int y)
{
	char kq[50];
	int index = 0;
	for (int i = x; i <= y; i++)
		kq[index++] = s[i];
	kq[index] = '\0';
	return kq;
}

// Hàm chuyển ký tự đầu tiên thành ký tự hoa của mỗi từ trong chuỗi
void VietHoaKyTuDau(char *s)
{
	int n = STRLEN(s);
	if (s[0] != ' ') // Xử lý ký tự đầu tiên của cả chuỗi
		if (s[0] >= 'a' && s[0] <= 'z')
			s[0] -= 32;

	// Xử lý các ký tự tiếp theo
	for (int i = 0; i < n; i++)
		if (s[i] == ' ' && s[i + 1] != ' ')
			if (s[i + 1] >= 'a' && s[i + 1] <= 'z')
				s[i + 1] -= 32;


}

// Hàm xóa một ký tự bất kỳ
void XoaKyTu(char *s, int vt)
{
	int n = STRLEN(s);
	for (int i = vt + 1; i < n; i++)
		s[i - 1] = s[i];
	s[n - 1] = '\0';
}

// Hàm chuẩn hóa
void XoaKhoangTrangThua(char *s)
{
	int n = STRLEN(s);
	for (int i = 0; i < n; i++)
	{
		if (s[i] == ' ' && s[i + 1] == ' ')
		{
			XoaKyTu(s, i + 1);
			i--;
			n--;
		}
	}

	// Xóa khoảng trắng ở đầu
	if (s[0] == ' ')
	{
		XoaKyTu(s, 0);
		n--;
	}

	// Xóa khoảng trắng ở cuối
	if (s[n - 1] == ' ')
	{
		XoaKyTu(s, n - 1);
		n--;
	}
}