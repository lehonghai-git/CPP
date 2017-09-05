#include "ThemSo.h"

void ThemPhanTu(int a[], int &n, int vt, int giatri)
{
	for (int i = n; i > vt; i--)
		a[i] = a[i - 1];
	a[vt] = giatri;
	n++;
}
void ThemSauPhanTuChan(int a[], int &n, int giatri)
{
	for (int i = 0; i < n; i++)
		if (a[i] % 2 == 0) // Chẵn
		{
			ThemPhanTu(a, n, i + 1, giatri);
			i++; // (*)
		}
	/*
	(*): Sau khi thêm số 0 vào sau số chẵn thì đến lượt tiếp theo sẽ là số 0 => Chương trình
	hiểu đây là số chẵn nên sẽ tiếp tục thêm => Cứ như thế các p.tử ở sau p.tử chẵn đầu tiền đều là số 0
	=> Giải pháp: Sau khi thêm số 0 thì tăng i lên 1 để lần lặp kế tiếp sẽ bỏ qua p.tử 0
	vừa thêm mà chỉ xét phần tử sau p.tử 0 (mới thêm)
	*/
}
void ThemSauPhanTuChinhPhuong(int a[], int &n, int giatri)
{
	for (int i = 0; i < n; i++)
	{
		if (sqrt((float)a[i]) == (int)sqrt((float)a[i]))
		{
			ThemPhanTu(a, n, i + 1, giatri);
			i++;
		}
	}
}
void ThemSauSoTanCung(int a[], int &n, int giatri)
{
	for (int i = 0; i < n; i++)
		if (a[i] % 10 == 9) // Số tận cùng là 9
		{
			ThemPhanTu(a, n, i + 1, giatri);
			i++;
		}
}