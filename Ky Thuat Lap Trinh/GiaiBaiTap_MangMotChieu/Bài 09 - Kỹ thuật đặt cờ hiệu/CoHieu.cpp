#include "CoHieu.h"

int KiemTraLienTiep(int a[], int n, int x)
{
	for (int i = 0; i < n - 1; i++)
		if (a[i] == x && a[i + 1] == x)
			return 1; // Có tồn tại
	return 0;
}