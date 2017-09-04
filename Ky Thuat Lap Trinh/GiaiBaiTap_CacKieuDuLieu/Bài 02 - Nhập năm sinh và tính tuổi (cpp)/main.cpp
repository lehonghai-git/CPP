/*
- Nhập vào năm sinh của một người
- Tính và in ra kết quả tuổi của người đó
- Viết bằng C++
*/
#include <iostream>
#include <ctime>

int main()
{
	int namSinh, namHienTai;

	std::cout << "Nhap nam sinh: ";
	std::cin >> namSinh;

	// Get time system
	time_t t = time(0);
	struct tm *Now = localtime(&t);
	namHienTai = Now->tm_year + 1900;

	std::cout << "Ban sinh nam " << namSinh << " => Ban " << namHienTai - namSinh << " tuoi." << std::endl;

	system("pause");
	return 0;
}

/*
* Chú ý:
- C:
float x;
printf("%.2f", x);

- C++:
#include<iomanip>
float x;
cout << setprecision(3) << x;

- C:
int x;
printf("%5d", x);

- C++:
#include<iomanip>
int x;
cout << setw(5) << x;

*/