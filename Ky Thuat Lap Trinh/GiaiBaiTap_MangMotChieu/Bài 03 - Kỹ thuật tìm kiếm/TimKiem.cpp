#include "TimKiem.h"

int TimKiem(int a[], int n, int x)
{
	for (int i = 0; i < n; i++)
		if (a[i] == x)
			return i;
	return -1;
}
int TimViTriAmDauTien(int a[], int n)
{
	for (int i = 0; i < n; i++)
		if (a[i] < 0)
			return i;
	return -1;
}
int TimSoAmLonNhat(int a[], int n)
{
	int index = TimViTriAmDauTien(a, n);
	int MaxAm = a[index];

	for (int i = index + 1; i < n; i++)
		if (a[i] < 0 && a[i] > MaxAm) // thỏa mãn phải là số âm và lớn hơn giá trị âm max hiện tại
			MaxAm = a[i];
	return MaxAm;
}
int TimViTriDuongDauTien(int a[], int n)
{
	for (int i = 0; i < n; i++)
		if (a[i] > 0)
			return i;
	return -1;
}
int TimSoDuongBeNhat(int a[], int n)
{
	int index = TimViTriDuongDauTien(a, n);
	int MinDuong = a[index];

	for (int i = index + 1; i < n; i++)
		if (a[i] > 0 && a[i] < MinDuong)
			MinDuong = a[i];
	return MinDuong;
}
int TimKiemTuanTuVetCan(int a[], int n, int x)
{
	for (int i = 0; i < n; i++)
		if (a[i] == x)
			return i;
	return -1;
	// Thuật toán này dễ cài đặt nhưng chưa tối ưu
}
int TimKiemTuanTuLinhCanh(int a[], int n, int x)
{
	/*
	Giải thuật này sẽ thêm x (x là phần tử cần tìm) vào cuối cùng của mảng
	Trong quá trình duyệt, bỏ qua điều kiện dừng vòng lặp (i < n) vì chắc chắn duyệt đến cuối mảng là có x
	Khi duyệt mảng:
	Nếu gặp phần tử == x mà không phải vị trí cuối cùng (n) thì trả về vị trí đó
	Còn nếu gặp phần tử == x mà là vị trí cuối cùng n (trường hợp tệ nhất) thì là không tìm thấy
	*/
	a[n] = x; // Thêm x vào cuối mảng
	for (int i = 0; ; i++)
		if (a[i] == x)
			return i;
}
int TimKiemNhiPhan(int a[], int n, int x)
{
	/*
	Giải thuật tìm kiếm nhị phân
	* Ý tưởng:
	- Mảng phải được sắp xếp trước đó (VD: Tăng dần)
	- Chia mảng thành 2 miền và có một vị trí mốc ở giữa
	- So sánh giá trị cần tìm với mốc
	+ Nếu giá trị cần tìm = p.tử mốc => trả về vị trí mốc
	+ Nếu giá trị cần tìm > p.tử mốc => Chuyển sang tìm kiếm ở miền bên phải của mốc
	+ Nếu giá trị cần tìm < p.tử mốc => chuyển sang tìm kiếm ở miền bên trái của mốc

	* Giải thuật cụ thể:
	- Khởi tạo Left = 0, Right = n -1
	Trong khi Left <= Right thì:
	- Mid = (Left + Right) / 2
	+ Nếu x > a[Mid] thì cập nhập Left = Mid + 1
	+ Nếu x < a[Mid] thì cập nhập Right = Mid - 1
	+ Nếu x == a[Mid] thì có tồn tại
	Nếu Left > Right thì không tồn tại
	*/
	int Left = 0, Right = n - 1;
	while (Left <= Right)
	{
		int Mid = (Left + Right) / 2;
		if (x > a[Mid])
			Left = Mid + 1; // Cập nhật mốc bên trái
		else if (x < a[Mid])
			Right = Mid - 1; // Cập nhật mốc bên phải
		else
			return Mid; // Nếu tìm thấy
	}
	return -1; // Nếu Không tìm thấy
}
int TimViTriLeDauTien(int a[], int n)
{
	for (int i = 0; i < n; i++)
		if (a[i] % 2 != 0)
			return i;
	return -1;
}
int TimSoLeNhoNhat(int a[], int n, int batdau)
{
	int SoLeNhoNhat = a[batdau];
	for (int i = batdau + 1; i < n; i++)
		if (a[i] < SoLeNhoNhat && a[i] % 2 != 0) // Số lẻ và nhỏ hơn cả Min
			SoLeNhoNhat = a[i]; // Thì cập nhập lại Min số lẻ
	return SoLeNhoNhat;
}
int TimSoLeLonNhat(int a[], int n, int batdau)
{
	int SoLeLonNhat = a[batdau];
	for (int i = batdau + 1; i < n; i++)
		if (a[i] > SoLeLonNhat && a[i] % 2 != 0) // Số lẻ và lớn hơn cả Max
			SoLeLonNhat = a[i]; // Thì cập nhập lại Max số lẻ
	return SoLeLonNhat;
}
int TimViTriCuoiCung(int a[], int n, int x)
{
	for (int i = n - 1; i >= 0; i--)
		if (a[i] == x)
			return i;
	return -1;
}
int SoBeNhatTrongMang(int a[], int n)
{
	int min = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] < min)
			min = a[i];
	return min;
}
int TimViTriSoNguyenToDauTien(int a[], int n)
{
	for (int i = 0; i < n; i++)
		if (KiemTraNguyenTo(a[i]))
			return i;
	return -1;
}