#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/*
** LÝ THUYẾT CHUỖI KÝ TỰ
*/

int main()
{
#if 0 // Khai báo chuỗi ký tự
	char s[15] = { 'L','e','H','o','n','g','H','a','i','\0' }; // Khai báo tường minh đầy đủ cả ký tự kết thúc chuỗi
	char name[] = "Le Hong Hai"; // Tự động thêm '\0' và tự xác định độ dài

								 // Xuất chuỗi
	printf("%s\n", s);
	puts(s); // Tự động xuống dòng
	printf("Size of s[]: %d\n", sizeof(s));
	printf("So phan tu cua s = %d\n", strlen(s));

	printf("%s\n", name);
	puts(name); // Tự động xuống dòng
	printf("Size of name[]: %d\n", sizeof(name));
#endif // Khai báo chuỗi ký tự

#if 0 // Nhập chuỗi
	char ten[20];
	int tuoi;

	printf("Nhap tuoi: ");
	scanf("%d", &tuoi);

	//fflush(stdin); not working vs 2017
	//rewind(stdin);
	while (getchar() != '\n') {}
	printf("Nhap ten: ");
	gets(ten);

	// Xuất chuỗi
	printf("\nBan ten: %s\n", ten);
	printf("Ban %d tuoi\n", tuoi);
#endif // Nhập chuỗi

#if 0 // Hàm tính độ dài chuỗi
	
	char s[] = "Visual Studio 2017";
	int dodaichuoi = strlen(s);
	printf("Do dai chuoi = %d\n", dodaichuoi);
#endif // Hàm tính độ dài chuỗi

#if 0 // Hàm sao chép chuỗi
	char s[50], say[] = "Hello Friend";
	strcpy(s, say); // Sao chép nội dung chuỗi say[] sang cho chuỗi s[]
					// Lưu ý: s >= say thì mới sao chép chuỗi đc.
	printf("Chuoi s: %s\n", s);
#endif // Hàm sao chép chuỗi

#if 0 // Hàm tạo một bản sao của chuỗi
	char *s; // Khai báo một con trỏ s kiểu char
	char z[] = "Lap trinh C co ban";

	s = strdup(z); // Không phải là một standard C++ function
	printf("Ban goc z = %s\n", z);
	printf("Do dai ban goc z = %d\n", strlen(z));

	printf("Ban sao s = %s\n", s);
	printf("Do dai ban sao s = %d\n", strlen(s));

	delete(s); // Hủy
	printf("Sau khi huy z = %s\n", z);
	printf("Sau khi huy s = %s\n", s);
#endif // Hàm tạo một bản sao của chuỗi

#if 0 // Hàm chuyển các chữ cái hoa về chữ thường
	char name[] = "Le Hong Hai";
	printf("Chuoi trc khi chuyen: %s\n", name);
	_strlwr(name);
	printf("Chuoi sau khi chuyen: %s\n", name);
#endif // Hàm chuyển các chữ cái hoa về chữ thường

#if 0 // Hàm chuyển ký tự thường lên ký tự hoa
	char name[] = "Le Hong Hai";
	printf("Chuoi trc khi chuyen: %s\n", name);
	_strupr(name);
	printf("Chuoi sau khi chuyen: %s\n", name);
#endif // Hàm chuyển ký tự thường lên ký tự hoa

#if 0 // Hàm đảo ngược chuỗi
	char name[] = "Le Hong Hai";
	printf("Chuoi trc khi dao: %s\n", name);
	_strrev(name);
	printf("Chuoi sau khi dao: %s\n", name);
#endif // 1

#if 0 // Hàm so sánh hai chuỗi. Có phân biệt hoa thường
	char s1[] = "Le Van A";
	char s2[] = "Nguyen Van B";
	int kq = strcmp(s1, s2);
	printf("Ket qua: %d\n", kq);
	/*
	// So sánh từng cặp ký tự (byte) lần lượt dựa vào việc đối chiếu lên bảng mã ascii.
	// Không phải là so sánh độ dài chuỗi
	// Gặp ký tự nào mà khác nhau thì nó so sánh và trả về kết quả. Nếu cặp ký tự == nhau thì
	// mới xét cặp ký tự tiếp theo.
	-1 => s1 < s2
	0 => s1 == s2
	1 => s1 > s2
	*/
#endif // Hàm so sánh hai chuỗi. Có phân biệt hoa thường

#if 0 // Hàm so sánh hai chuỗi. Không phân biệt hoa thường
	// Giống với strcmp nhưng không phân biệt hoa hay thường
	char s1[] = "Le Van A";
	char s2[] = "Le Van A";
	int kq = _stricmp(s1, s2);
	printf("Ket qua: %d\n", kq);
#endif // Hàm so sánh hai chuỗi. Không phân biệt hoa thường

#if 0 // Hàm nối hai chuỗi với nhau
	char s1[50] = "Lap trinh C";
	char s2[] = "co ban";
	strcat(s1, " ");
	strcat(s1, s2);
	printf("Chuoi sau khi noi: %s\n", s1);
#endif // Hàm nối hai chuỗi với nhau

#if 0 // Hàm tìm chuỗi trong chuỗi (Tìm chuỗi con)
	char s1[] = "Lap trinh C co ban";
	char s2[] = "co ban";
	char s3[] = "nang cao";
	// Trả về con trỏ đến vị trí xuất hiện đầu tiên của chuỗi con trong chuỗi lớn
	// Trả về null nếu không tìm thấy
	if (strstr(s1, s2) != NULL)
		printf("Tim thay '%s' trong '%s'\n", s2, s1);
	if (strstr(s1, s3) == NULL)
		printf("Khong tim thay '%s' trong '%s'\n", s3, s1);
#endif /// Hàm tìm chuỗi trong chuỗi (Tìm chuỗi con)

#if 0 // Hàm tách chuỗi
	char s1[50];
	printf("Nhap chuoi muon tach: ");
	gets(s1);

	char *ptr1 = strtok(s1, " ");
	printf("%s\n", ptr1);

	while (ptr1 != '\0')
	{
		ptr1 = strtok(NULL, " ");
		if (ptr1 != '\0')
			printf("%s\n", ptr1);
	}

	//char *ptr2 = strtok(NULL, " "); // NULL: Xét từ vị trí vừa cắt trước đó
	//printf("ptr1 = %s\n", ptr2);

	//char *ptr3 = strtok(NULL, " ");
	//printf("ptr1 = %s\n", ptr3);
#endif // Hàm tách chuỗi

	getch();
	return 0;
}
/*
- Chuỗi ký tự = mảng các ký tự
- Chuỗi ký tự luôn có một ký tự kết thúc chuỗi là '\0' (null)
- Độ dài chuỗi = kích thước mảng - 1 (Không tính ký tự '\0')
- Trường hợp chuỗi được nhập sau khi đã nhập một số trươc đó chẳng hạn thì dẫn tới việc ký tự enter
sau khi nhập số được coi là ký tự kết thúc chuỗi lên vùng đệm của chuỗi nhận ký tự đó
và không cho nhập chuỗi nữa => cần phải xóa bộ đệm (buffer) trước khi nhập chuỗi
*/

/*
Phân biệt hàm strcpy() và hàm strdup()
- Với hàm strcpy, bản gốc và bản sao chép đều nằm trên Stack. Tự động được clear khi kết thúc hàm.
- Còn với hàm strdup, bản gốc nằm trên Stack còn bản sao thì nằm trên Heap và được quản lý bởi 1 con trỏ.
Không tự động clear mà lập trình viên phải chủ động clear vùng nhớ này khi không dùng.
- Với hàm strcpy thì vùng dữ liệu của bản sao phải được khai báo trước với một kích thước nào đó => dễ gây dư thừa.
(lớn hơn hoặc bằng với vùng dữ liệu chứa bản gốc)
- Còn với strdup thì linh động hơn do hàm này sẽ cấp phát động và chỉ cần khai báo một con trỏ để trỏ tới vùng
nhớ chứa bản sao.
*/