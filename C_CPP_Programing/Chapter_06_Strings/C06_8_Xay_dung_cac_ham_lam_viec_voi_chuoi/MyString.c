#include "MyString.h"

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
void SWAP(char *a, char *b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

// Hàm đảo ngược chuỗi (giống strrev)
void STRREV(char *s)
{
	int n = STRLEN(s);
	for (int i = 0; i < n / 2; i++)
		SWAP(&s[i], &s[n - 1 - i]);
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