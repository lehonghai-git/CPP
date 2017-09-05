/*
- Nhập vào năm sinh của một người.
- Tính và in ra kết quả tuổi của người đó
- Viết bằng C
*/
#include <stdio.h>
#include <conio.h>
#include <time.h>

int main()
{
	int namSinh, namHienTai;

	printf("Nhap nam sinh: ");
	scanf("%d", &namSinh);

	// Get time system
	time_t t = time(0);
	struct tm *Now = localtime(&t);
	namHienTai = Now->tm_year + 1900;

	printf("Ban sinh nam %d => Ban %d tuoi\n", namSinh, namHienTai - namSinh);

	getch();
	return 0;
}