#include "XoaSo.h"
#include "TimSo.h"

void XoaPhanTu(int a[], int &n, int vt)
{
	for (int i = vt; i < n; i++)
		a[i] = a[i + 1];
	n--;
}
void XoaPhanTuChan(int a[], int &n)
{
	for (int i = 0; i < n; i++)
		if (a[i] % 2 == 0)
		{
			XoaPhanTu(a, n, i);
			i--; // (*) Tương tự như bài thêm sau phần tử chẵn
		}
	/*
	(*): Nếu ko có i--: trường hợp các số chẵn không liên tiếp nhau thì có thể chạy đúng, nhưng còn trường
	hợp các số chẵn không liên tiếp nhau sẽ dẫn đến trường hợp số chẵn thứ i bị xóa nhưng thứ i + 1 ko đc xóa
	Vì sau khi xóa xong số chẵn thứ i => Cập nhập lại vị trí số chẵn thứ i + 1 trước đó giờ thành thứ i. Mà vòng
	lặp thì sẽ tiếp tục vòng lặp mới tại i + 1, i + 1 lúc này ko chưa chắc đã là số chẵn => Dẫn đến xóa thiếu
	Nên cần phải có i-- để chương trình tiếp tục xét tiếp vòng lặp tại vị trí nó vừa xóa
	*/
}
void XoaTatCaPhanTuMax(int a[], int &n)
{
	int Max = TimMax(a, n);
	for (int i = 0; i < n; i++)
		if (a[i] == Max)
		{
			XoaPhanTu(a, n, i);
			i--;
		}
}
void XoaPhanTuCoChuSoDau(int a[], int &n, int giatri)
{
	for (int i = 0; i < n; i++)
	{
		int SoChuSo = log10((double)a[i]) + 1;
		int ChuSoDauTien = (int)(a[i] / pow(10, (SoChuSo - 1)));
		if (ChuSoDauTien == giatri)
		{
			XoaPhanTu(a, n, i);
			i--;
		}
	}
}