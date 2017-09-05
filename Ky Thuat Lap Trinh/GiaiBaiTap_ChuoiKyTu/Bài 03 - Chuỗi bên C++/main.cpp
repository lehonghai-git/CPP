/*
- Bên C++. Chuỗi không phải là kiểu dữ liệu, mảng ký tự như bên C mà Chuỗi bên C++ là một lớp (class)

- Chuỗi bên C
#include <string.h>
+ Chỉ khi cần dùng một số hàm strlen, strcmp, strstr... mới cần khai báo
+ Hỗ trợ ít hàm thao tác với chuỗi
+ Phải xây dựng lại nhiều hàm => Chạy chậm => Tốn ít bộ nhớ

- Chuỗi bên C++
#include <string>
+ Phải khai báo mới dùng được string
+ Lớp String của C++ hỗ trợ nhiều phương thức thao tác với chuỗi
+ Các hàm (phương thức) có sẵn => Chạy nhanh => Tốn nhiều bộ nhớ
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s; // Khai báo chuỗi
	cout << "Nhap chuoi: ";
	
	getline(cin, s);
	cout << "Chuoi vua nhap: " << s << endl;
	int dodaichuoi = s.length(); // strlen
	cout << "Chieu dai chuoi = " << dodaichuoi << endl;

	string a = s; // strcmp, strdup
	cout << "Chuoi vua copy: " << a << endl;

	// So sánh chuỗi bên C++ dùng các toán tử: >, <, ==
	// Nối chuỗi dùng phép: +
	// C++ không hỗ trợ hàm chuyển ký tự hoa - thường. Nhưng chỉ cần khai báo thư viện
	// của bên C thì vẫn có thể dùng đc các hàm đó.
	string str = "Le Hong Hai";
	cout << "str ban dau: " << str << endl;
	strlwr((char *)str.c_str()); // convert và ép kiểu
	cout << "str strlwr: " << str << endl;
	strupr((char *)str.c_str());
	cout << "str strupr: " << str << endl;
	strrev((char *)str.c_str());
	cout << "str strrev: " << str << endl;

	system("pause");
	return 0;
}