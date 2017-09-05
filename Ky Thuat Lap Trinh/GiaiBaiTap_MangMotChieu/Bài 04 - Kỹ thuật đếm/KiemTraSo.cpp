#include "KiemTraSo.h"

int KiemTraBiTrung(int a[], int n, int vtht)
{
	// Đếm từ vị trí hiện tại (vtht) trở về trước đó xem có phần từ nào trùng không
	for (int i = vtht - 1; i >= 0; i--)
		if (a[i] == a[vtht])
			return 1; // Bị trùng
	return 0;
}