#include <stdio.h>
#define n 7
/*
** - Các Kỹ thuật trên mảng một chiều
** 1. Kỹ thuật Nhập/Xuất cơ bản (duyệt mảng)
** 2. Kỹ thuật Thêm/Xóa/Sửa
** 3. Kỹ thuật Gộp/Tách mảng
** 4. Kỹ thuật Tìm kiếm/Sắp xếp mảng
*/

int main()
{
#if 0 // Các kiểu Khai báo mảng một chiều
	int a[5]; // Khai báo mảng a có 5 phần tử. Thời điểm khai báo các phần tử mang giá trị rác.
	int b[n] = { 2, 0, 7, 2, 0, 1, 7 }; // Khai báo mảng b có 7 phần tử đồng thời khởi tạo giá trị cho các phần tử
	int c[] = { 2, 0, 1, 7 }; // Khai báo mảng c với kích thước tùy vào số lượng phần tử khởi tạo bên trong cặp dấu {..}

	printf("Mang a[] chua khoi tao se co gia tri rac:\n");
	for (int i = 0; i < 5; i++)
		printf("a[%d] = %d \t Dia chi = %p\n", i, a[i], &a[i]);

	printf("\nDuyet mang b[]: \n");
	for (int i = 0; i < n; i++)
		printf("b[%d] = %d \t Dia chi = %p\n", i, b[i], &b[i]);

	printf("\nTruy xuat ra ngoai pham vi cua mang c[]: \n");
	for (int i = 0; i < 10; i++)
		printf("c[%d] = %d \t Dia chi = %p\n", i, c[i], &c[i]);
#endif // Các kiểu Khai báo mảng một chiều

#if 1
	int d[] = { 1, 4, 7, 8, 9, 3, 0, 2, 5, 6 };

	// Làm sao để tính được số lượng phẩn tử của mảng ?
	// Kích thước mảng = Số lượng * Kích thước kiểu dữ liệu
	// Kích thước mảng d = 10 * 4 = 40 byte
	printf("Sizeof d[] = %d\n", sizeof(d));
	int soluong = sizeof(d) / sizeof(int);

	printf("\nSo luong phan tu cua d[] = %d\n", soluong);
	printf("\nDuyet mang d[]:\n");
	for (int i = 0; i < soluong; i++)
		printf("d[%i] = %d\n", i, d[i]);
#endif // 0

	getch();
	return 0;
}

/*
- [] => Toán tử lấy chỉ số
- Lưu ý về cấp phát bộ nhớ trên Stack đối với mảng một chiều
Địa chỉ thấp
---------
|		|
|		| <= Vùng địa chỉ chưa dùng của Stack (đang chờ được dùng)
|		|
---------
|		| <= ESP: Đỉnh Stack
---------
|		|
|	c[]	| <= Vùng cấp phát cho mảng c
|		|
---------
|		|
|	b[]	| <= Vùng cấp phát cho mảng b
|		|
---------
|		|
|	a[]	| <= Vùng cấp phát cho mảng a
|		|
---------
Địa chỉ cao

+ Chương trình sẽ cấp phát vùng nhớ theo chiều từ địa chỉ cao -> địa chỉ thấp trên stack
+ Các mảng a, b, c được cấp phát vùng nhớ = số phần tử * kiểu dữ liệu của mảng (kiểu in là 4 byte)
+ Trường hợp truy xuất ra ngoài biên của mảng c => Truy xuất sang vùng của mảng b
+ Để cho tường minh thì nên in địa chỉ của các phần tử mảng và quan sát
*/