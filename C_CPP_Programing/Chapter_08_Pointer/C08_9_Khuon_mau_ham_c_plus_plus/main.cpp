#include <iostream>
#include <string>
using namespace std;

template <typename Var>
void HoanVi(Var &a, Var &b)
{
	// Dùng được cho nhiều kiểu dữ liệu
	Var tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	int a = 6, b = 9; // HoanVi
	float x = 3.14, y = 5.16; // => Viết lại 1 hàm hoán vị số thực???? => Code lặp
							  // => Sử dụng khuôn mẫu hàm, là viết 1 hàm có thể truyền đc mọi kiểu dữ liệu

	cout << "a = " << a << ", b = " << b << endl;
	HoanVi<int>(a, b); //HoanVi(a, b); => Nhiều cách viết
	cout << "a = " << a << ", b = " << b << endl;

	cout << "x = " << x << ", y = " << y << endl;
	HoanVi(x, y); // HoanVi<float>(x, y);
	cout << "x = " << x << ", y = " << y << endl;

	string str1 = "Lap trinh C++";
	string str2 = "Khong he don gian";
	cout << "str1 = " << str1 << ", str2 = " << str2 << endl;
	HoanVi<string>(str1, str2); //HoanVi(str1, str2);
	cout << "str1 = " << str1 << ", str2 = " << str2 << endl;
	// => Nạp chồng (Overloading) trong OOP.

	system("pause");
	return 0;
}