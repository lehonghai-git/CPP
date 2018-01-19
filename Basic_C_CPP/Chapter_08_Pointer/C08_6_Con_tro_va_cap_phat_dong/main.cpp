#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void NhapMang(int *, int);
void XuatMang(int *, int);

int main()
{
#if 1 // Cấp phát động một mảng: malloc
	// malloc(số byte cần cấp);
	// hàm malloc kiểu void nên cần phải ép kiểu
	// Trả về địa chỉ của byte đầu vùng nhớ nếu cấp phát thành công
	// Trả về NULL nếu cấp phát không thành công
	int *a = NULL;
	int n = 0;

	printf("Nhap so phan tu: ");
	scanf_s("%d", &n);

	// Cấp phát bộ nhớ
	a = (int*)malloc(n * sizeof(int));

	// Nhập mảng
	NhapMang(a, n);
	// Xuất mảng
	XuatMang(a, n);
	// Giải phóng vùng nhớ
	free(a);
	a = NULL;
#endif // Cấp phát động một mảng: malloc()

#if 0 // Cấp phát động một mảng: calloc (tương tự malloc)
	// calloc(Số phần tử, Độ lớn một phần tử tính theo byte);
	int *a = NULL;
	int n = 0;

	printf("Nhap so phan tu: ");
	scanf_s("%d", &n);

	// Cấp phát bộ nhớ
	a = (int*)calloc(n, sizeof(int));

	// Nhập mảng
	NhapMang(a, n);
	// Xuất mảng
	XuatMang(a, n);
	// Giải phóng vùng nhớ
	free(a);
	a = NULL;

#endif // Cấp phát động một mảng: calloc() (tương tự malloc)

#if 0 // Cấp phát lại một mảng: realloc
	/*
	- Dạng 1: realloc(0, Số byte): Giống như malloc
	- Dạng 2: realloc(Vùng nhớ, NewSize)
	+ Vùng nhớ: con trỏ trỏ tới vùng nhớ đã được cấp phát trước đó
	+ NewSize: Kích thước mới của vùng nhớ
	# NewSize > Kích thước vùng nhớ trước đó => Vùng nhớ mới sẽ tăng kích thước so với ban đầu
	# NewSize < Kích thước vùng nhớ trước đó => Vùng nhớ mới sẽ giảm kích thước so với ban đầu
	=> Hàm realloc thực chất là cấp phát một vùng mới như malloc/calloc sau đó gán từng giá trị của
	vùng nhớ cũ sang cho vùng nhớ mới
	*/

	int *a = NULL;
	int n = 0;

	printf("Nhap so phan tu: ");
	scanf_s("%d", &n);

	// Cấp phát bộ nhớ
	a = (int*)malloc(n * sizeof(int));

	// Nhập mảng
	NhapMang(a, n);
	// Xuất mảng
	XuatMang(a, n);
	// Cấp lại
	int nThem;
	printf("So phan tu muon them: ");
	scanf_s("%d", &nThem);
	a = (int*)realloc(a, (n + nThem) * sizeof(int));
	// Nhập thêm
	for (int i = n; i < n + nThem; i++)
	{
		printf("a[%d] = ", i);
		scanf_s("%d", &a[i]);
	}
	XuatMang(a, n + nThem);
	// Giải phóng vùng nhớ
	free(a);
	a = NULL;
#endif // 1 Cấp phát lại một mảng: realloc()

#if 1 // Ghi chú
	/*
	- Khi dùng hàm malloc(), calloc(), realloc() hay toán tử new (c++) để cấp phát động thì:
	+ Phải dùng con trỏ để quản lý vùng nhớ đó
	+ Con trỏ này có địa chỉ nằm trên vùng nhớ Stack
	+ Vùng nhớ động mà nó quản lý nằm trên Heap

	- Khi giải phóng vùng nhớ cấp phát động: free(), delete,...
	+ Thì chỉ có thể hủy một con trỏ mà con trỏ đó đang quản lý vùng nhớ ở Heap. VD: int *p = (int*)malloc(5*sizeof(int)); free(p); => Đúng
	+ Không thể hủy một con trỏ mà nó đang trỏ vào một biến ở vùng nhớ Stack. VD: int a = 10; int *p = &a; free(p); => Sai
	*/
#endif // 1 // Ghi chú

	_getch();
	return 0;
}

void NhapMang(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Nhap a[%d] = ", i);
		scanf_s("%d", &a[i]);
	}
}
void XuatMang(int *a, int n)
{
	for (int i = 0; i < n; i++)
		printf("%4d", a[i]);
	printf("\n");
}