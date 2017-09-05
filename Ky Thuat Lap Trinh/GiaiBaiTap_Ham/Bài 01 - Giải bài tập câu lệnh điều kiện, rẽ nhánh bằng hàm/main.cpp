#include "mylib.h"
#include <conio.h>

int main()
{
#if 1
	// 1a
	char key;
	printf("Nhap ky tu: ");
	scanf("%c", &key);
	printf("Truoc khi chuyen doi: %c\n", key);
	printf("Sau khi chuyen doi: %c\n", DoiKiTu(key));
#endif // 1

#if 0
	// 1b
	float a, b;
	printf("Nhap a =  ");
	scanf("%f", &a);
	printf("Nhap b =  ");
	scanf("%f", &b);
	GiaiPhuongTrinhBacNhat(a, b);

#endif // 1

#if 0
	// 1c
	float a, b, c;
	printf("Nhap he so =  ");
	scanf("%f%f%f", &a, &b, &c);
	GiaiPhuongTrinhBacHai(a, b, c);

#endif // 1

#if 0
	// 1d
	int a, b, c, d;
	printf("Nhap 4 so nguyen: ");
	scanf("%d%d%d%d", &a, &b, &c, &d);
	printf("Min 4 so: %d\n", MinHaiSo(d, MinHaiSo(c, MinHaiSo(a, b))));

#endif // 1

#if 0
	// 1e
	int a, b;
	printf("Nhap 2 so: ");
	scanf("%d%d", &a, &b);
	printf("Truoc khi hoan vi: %d  %d\n", a, b);
	HoanVi(a, b);
	printf("Sau khi hoan vi: %d  %d\n", a, b);
#endif // 1

#if 0
	// 1f
	int a, b, c, d;
	printf("Nhap 4 so nguyen: ");
	scanf("%d%d%d%d", &a, &b, &c, &d);
	printf("Trc khi sap xep: %d %d %d %d\n", a, b, c, d);
	SapXepBonSo(a, b, c, d);
	printf("Sau khi sap xep: %d %d %d %d\n", a, b, c, d);
#endif // 0

	getch();
	return 0;
}