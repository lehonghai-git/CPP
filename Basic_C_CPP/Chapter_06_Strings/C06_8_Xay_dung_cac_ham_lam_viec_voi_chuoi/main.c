#include "MyString.h"

/*
** XÂY DỰNG CÁC HÀM TƯƠNG TỰ NHƯ: STRCPY, STRCMP, STRREV,...
*/

int main()
{
	char s[] = " Ky    thuat   lap trinh      C/C++         ";
	printf("Chuoi ban dau: %s\n", s);

#if 0 // Tính chiều dài chuỗi
	int dai = STRLEN(s);
	printf("%d\n", dai);
#endif // Tính chiều dài chuỗi

#if 0 // Hàm copy chuỗi này sang chuỗi khác
	char buff[50];
	STRCPY(buff, s);
	printf("Ban sao cua s: %s", buff);
#endif // Hàm copy chuỗi này sang chuỗi khác

#if 0 // Biến đổi chuỗi về hoa và thường
	char *p1 = STRLWR(s);
	printf("Chuoi thuong: %s\n", p1);

	char *p2 = STRUPR(s);
	printf("Chuoi hoa: %s\n", p2);
#endif // Biến đổi chuỗi về hoa và thường

#if 0 // Đảo ngược chuỗi
	char name[] = "Le Hong Hai";
	printf("Truoc khi dao chuoi: %s\n", name);
	STRREV(name);
	printf("Sau  khi  dao chuoi: %s\n", name);
#endif // Đảo ngược chuỗi

#if 0 // So sánh hai chuỗi có phân biệt hoa thường
	char s1[] = "abc";
	char s2[] = "ABC";

	int kq = STRCMP(s1, s2);
	printf("%d", kq);
#endif // So sánh hai chuỗi có phân biệt hoa thường

#if 0 // So sánh hai chuỗi không phân biệt hoa thường
	char s1[] = "abcd";
	char s2[] = "Abed";

	int kq = STRICMP(s1, s2);
	printf("%d", kq);
#endif // So sánh hai chuỗi không phân biệt hoa thường

#if 0 // Nối hai chuỗi lại với nhau
	char s1[50] = "abc";
	char s2[8] = "defghi";
	STRCAT(s1, s2);
	printf("%s", s1);
#endif // Nối hai chuỗi lại với nhau

#if 0 // Hàm tìm một chuỗi trong chuỗi khác
	char s1[] = "Ky thuat lap trinh c/c++";
	char s2[] = "c/c++";
	printf("s1 = %s\n", s1);
	printf("s2 = %s\n", s2);
	int kq = STRSTR(s1, s2);
	printf("kq = %d", kq);
#endif // Hàm tìm một chuỗi trong chuỗi khác

#if 0 // Hàm cắt chuỗi theo vị trí từ x đến y
	char s1[50] = "Ky thuat lap trinh c/c++";
	char buff[60];
	strcpy(buff, SUBSTR(s1, 9, 17));
	printf("buff = %s\n", buff);
#endif // Hàm cắt chuỗi theo vị trí từ x đến y

#if 0 // Hàm nhân bản một chuỗi sang vùng nhớ  có độ lớn vừa đủ
	char s3[] = "Nhan ban mot chuoi";
	printf("s3 = %s\n", s3);

	char *s2 = STRDUP(s3);
	printf("s2 = %s\n", s2);

	free(s2); // Giải phóng khi không dùng
#endif // Hàm nhân bản một chuỗi sang vùng nhớ  có độ lớn vừa đủ

#if 0 // Viết hoa ký tự đầu mỗi từ	  
	VietHoaKyTuDau(s);
	printf("Viet hoa ky tu dau: %s\n", s);
#endif // Viết hoa ký tự đầu mỗi từ

#if 0 // Xóa khoảng trắng
	XoaKhoangTrangThua(s);
	printf("Sau khi xoa khoang trang thua: %s", s);
#endif // Xóa khoảng trắng

#if 0
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
	char s11[] = "  Le   Hong   Hai      ";
	XuatCacTu(s11);
#endif // 1 // T

	getch();
	return 0;
}