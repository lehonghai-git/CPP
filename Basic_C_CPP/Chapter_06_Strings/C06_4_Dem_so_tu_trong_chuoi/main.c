#include <stdio.h>
#include <string.h>

/*
** ĐẾM SỐ TỪ TRONG CHUỖI
*/

int DemSoTu(char *);

int main()
{
	/*
	* Viết hàm nhận vào một chuỗi s và đếm xem có bao nhiêu từ trong chuỗi đó.
	VD: Le Hong Hai => 3 từ
	* HD1:
	- Chuẩn hóa chuỗi: Xóa khoảng trắng thừa
	- Số từ = số khoảng trắng + 1

	* HD2
	- Một ký tự khoảng trắng + Một ký tự khác khoảng trắng = 1 từ
	*/
	char s[] = "Le Hong Hai";
	int sotu = DemSoTu(s);
	printf("Chuoi %s co %d tu\n", s, sotu);

	getch();
	return 0;
}

int DemSoTu(char *s)
{
	int n = strlen(s);
	int dem = 0;
	if (s[0] != ' ')
		dem = 1;
	for (int i = 0; i < n - 1; i++)
		if (s[i] == ' ' && s[i + 1] != ' ')
			dem++;
	return dem;
}