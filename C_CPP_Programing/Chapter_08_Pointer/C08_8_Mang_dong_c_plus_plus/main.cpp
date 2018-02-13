#include <iostream>
using namespace std;

void NhapMang(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap a[" << i << "] = ";
		//cin >> a[i];
		cin >> *(a + i);
		//cin >> *(a++);
	}
}
void XuatMang(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		//cout << a[i] << "   ";
		cout << *(a + i) << "   ";
		//cout << *(a++) << "   ";
	}
	cout << endl;
}

template <typename var> // => Function template
void *REALLOC(var *&a, int OldSize, int NewSize)
{
	/*
	*&a => Sẽ làm thay đổi địa chỉ của con trỏ khi kết thúc hàm
	NewSize > OldSize => Tăng thêm
	NewSize < OldSize => Giảm đi
	*/
	var *tmp = new var[OldSize];
	for (int i = 0; i < OldSize; i++)
		tmp[i] = a[i];
	delete[] a;
	a = NULL;

	a = new var[NewSize];
	int Min = OldSize < NewSize ? OldSize : NewSize;

	for (int i = 0; i < Min; i++)
		a[i] = tmp[i];

	delete[] tmp;
	tmp = NULL;

	return a;
}
void ThemPhanTu(int *&a, int &n, int vitri, int GiaTri)
{
	REALLOC(a, n, n + 1);
	for (int i = n - 1; i >= vitri; i--)
		a[i + 1] = a[i];
	a[vitri] = GiaTri;
	n++;
}
void XoaPhanTu(int *&a, int &n, int vitri)
{
	for (int i = vitri + 1; i < n; i++)
		a[i - 1] = a[i];
	REALLOC(a, n, n - 1);
	n--;
}

int main()
{
	int n;

	do
	{
		cout << "Nhap so luong phan tu: ";
		cin >> n;
	} while (n < 0);

	int *a = new int[n];
	NhapMang(a, n);
	XuatMang(a, n);

#if 0 // Tự tạo realloc
	// B1. Tạo mảng tạm
	int *tmp = new int[n];

	// B2. Chuyển dữ liệu từ a sang tmp
	for (int i = 0; i < n; i++)
		tmp[i] = a[i];

	// B3. Xóa a và cấp lại dư ra một ô
	delete[] a;
	a = NULL;
	a = new int[n + 1];

	// B4. Chuyển dữ liều từ tmp sang a
	for (int i = 0; i < n; i++)
		a[i] = tmp[i];

	// B5. Xóa tmp
	delete[] tmp;
	tmp = NULL;

	a[n] = 69;
	cout << "\na[" << n << "] = " << a[n] << endl;
#endif // 0 // Tự tạo realloc
	// Tăng thêm 1 ô
	/*a = (int*)REALLOC(a, n, n + 1);
	a[n] = 69;
	cout << "\na[" << n << "] = " << a[n] << endl;*/

	// Giảm đi 1 ô
	/*a = (int*)REALLOC(a, n, n - 1);
	cout << "\na[" << n - 1 << "] = " << a[n - 1] << endl;*/

#if 1 // Thêm phần tử
	int ViTri, GiaTriThem;
	do
	{
		cout << "Nhap vi tri them (0..n): ";
		cin >> ViTri;
		if (ViTri < 0 || ViTri > n)
		{
			cout << "Vi tri khong hop le!" << endl;
		}
	} while (ViTri < 0 || ViTri > n);

	cout << "Gia tri can them: ";
	cin >> GiaTriThem;
	ThemPhanTu(a, n, ViTri, GiaTriThem);
	XuatMang(a, n);
#endif // 1 // Thêm phần tử

#if 1 // Xóa phần tử
	int ViTriXoa;
	do
	{
		cout << "Nhap vi tri xoa (0..n-1): ";
		cin >> ViTriXoa;
		if (ViTriXoa < 0 || ViTriXoa > n - 1)
		{
			cout << "Vi tri khong hop le!" << endl;
		}
	} while (ViTriXoa < 0 || ViTriXoa > n - 1);

	XoaPhanTu(a, n, ViTriXoa);
	XuatMang(a, n);

#endif // 1 // Xóa phần tử


	// Giải phóng
	delete[] a;
	a = NULL;

	system("pause");
	return 0;
}