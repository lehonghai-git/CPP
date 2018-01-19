#include "KiemTraMang.h"

int KiemTraMangDoiXung(int a[], int n)
{
	for (int i = 0; i < n / 2; i++)
		if (a[i] != a[n - 1 - i])
			return 0; // Không đối xứng
	return 1;
}
int KiemTraMangTangDan(int a[], int n)
{
	for (int i = 1; i < n; i++)
		if (a[i] < a[i - 1])
			return 0; // Không tăng dần
	return 1;
}
int KiemTraMangToanChan(int a[], int n)
{
	for (int i = 0; i < n; i++)
		if (a[i] % 2 != 0)
			return 0; // Không phải toàn chẵn
	return 1;
}
int KiemTraMangNgyenTo(int a[], int n)
{
	for (int i = 0; i < n; i++)
		if (!KiemTraNguyenTo(a[i]))
			return 0; // Không phải toàn nguyên tố
	return 1;
}