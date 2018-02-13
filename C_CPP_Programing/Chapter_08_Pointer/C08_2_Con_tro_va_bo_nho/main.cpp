#include <stdio.h>
#include <conio.h>

int main()
{
#if 1 // Độ lớn kiểu dữ liệu
	printf("int co do lon %d bytes \n", sizeof(int));
	printf("char co do lon %d bytes \n", sizeof(char));
	printf("double co do lon %d bytes \n", sizeof(double));
	/*
	- byte là một đơn vị đo lường độ lớn của bộ nhớ
	*/
#endif // 1 // Độ lớn kiểu dữ liệu

#if 0 // Độ lớn của con trỏ
	void *ptr1 = NULL; // NULL  = không trỏ vào đâu
	char *ptr2 = NULL;
	int *ptr3 = NULL;
	double *ptr4 = NULL;

	printf("%d %d %d %d", sizeof(ptr1), sizeof(ptr2), sizeof(ptr3), sizeof(ptr4));
	/*
	- Độ lớn của con trỏ luôn là 4 byte (HĐH 32 bits/IDE 32 bits)
	- Độ lớn của con trỏ luôn là 8 byte (HĐH 64 bits/IDE 64 bits)
	- Tại sao HĐH 32 bit chỉ hỗ trợ tối đa 4GB RAM
	- RAM như mảng một chiều gồm các ô nhớ liên tiếp nhau, mỗi ô là 1 bytes và đều được đánh địa chỉ.
	=> Con trỏ có độ lớn 4 bytes (32 bits) => Chỉ đánh được từ 0..2^32 địa chỉ ô nhớ => MAX chỉ được 4GB RAM
	*/
#endif // 1 // Độ lớn của con trỏ

#if 0 // Phân biệt * khai báo và * lấy giá trị
	int x = 10;

	// Khai báo
	int *p = &x;

	// Lấy giá trị
	printf("%d", *p);

	// Dấu * được gọi là toán tử
#endif // 1 // Phân biệt * khai báo và * lấy giá trị

#if 0 // Tăng giảm con trỏ
	int x = 10;
	int *p = &x;

	printf("%p \n", &x);
	printf("%p \n", p);
	p++; // Đoán xem
	printf("%p \n", p);
	// Địa chỉ tăng thêm 4
	// => Trỏ sang ô nhớ bên cạnh
#endif // 1 // Tăng giảm con trỏ

#if 0 // Nhiều con trỏ cùng trỏ 1 vùng nhớ

	int x = 10;
	int *p1 = &x;
	int *p2 = &x;
	int *p3 = p2;

	x++;
	printf("x = %d \n", x);
	*p1 += 10;
	printf("x = %d \n", x);
	*p2 -= 10;
	printf("x = %d \n", x);
	*p3 -= 11;
	printf("x = %d \n", x);
#endif // 1 // Nhiều con trỏ cùng trỏ 1 vùng nhớ

#if 0 // Gán địa chỉ bất kỳ cho con trỏ
	int *p = (int*)2018;
	printf("%d\n", p);
	p += 2;
	printf("%d\n", p);
#endif // Gán địa chỉ bất kỳ cho con trỏ

#if 0 // Con trỏ NULL
	int x = 10;
	int *p = NULL;
	p = &x;

	printf("x = %d\n", x);
	*p = 21;
	printf("x = %d\n", x);

	// Con trỏ NULL sẽ trỏ đến địa chỉ 0x000000
	// Trong C++11 trở đi có thể sử dụng nullptr thay cho NULL
	// Trong Visual Studio, không thể lấy được giá trị mà con trỏ đó đang trỏ NULL (Báo lỗi)
#endif // 1 // Con trỏ NULL

#if 0 // Con trỏ void
	int x = 10;
	void *p = NULL;
	p = &x;
	printf("x = %d\n", *(int*)p);
	*(int*)p += 90; // Ép kiểu
	printf("x = %d\n", *(int*)p);
#endif // 1 // Con trỏ void

#if 0 // Con trỏ trỏ đến con trỏ
	int x = 10;
	int *p1 = &x; // Pointer cấp 1
	int **p2 = &p1; // Pointer cấp 2
	int ***p3 = &p2; // Pointer cấp 3

	printf("x = %d\n", *p1);
	**p2 += 40;
	printf("x = %d\n", **p2);
	***p3 += 50;
	printf("x = %d\n", ***p3);
	printf("-----\n");

	printf("&x = %d \n", &x);
	printf("p1 = %d \n", p1);
	printf("&p1 = %d \n", &p1);
	printf("p2 = %d \n", p2);
	printf("&p2 = %d \n", &p2);
	printf("p3 = %d \n", p3);
	printf("&p3 = %d \n", &p3);
	printf("-----\n");
#endif // 1 // Con trỏ trỏ đến con trỏ

#if 0 // Ghi chú
	/*
	- Nên khởi tạo NULL cho con trỏ khi nó chưa trỏ tới đâu cả
	*/
#endif // 1 // Ghi chú

	_getch();
	return 0;
}

/*
** Giải thích tại sao kích thước con trỏ luôn chỉ là 4 byte (Kể cả con trỏ kiểu: char, int, short, long long, float, double,...)
* Các hệ điều hành 32 bits thì chỉ đánh được từ : 0..2^32 địa chỉ ô nhớ (Mỗi ô nhớ là 1 địa chỉ) tương đương hỗ trợ <= 4GB RAM
* 32 bits = 4 bytes => Chỉ cần một con trỏ kích thước 4 byte là có thể trỏ đến bất kỳ đâu trên bộ nhớ RAM
*
* Còn các hệ điều hành 64 bits thì đánh được từ 0..2^64 địa chỉ ô nhớ => Hỗ trợ <= 16777216 TB
* 64 bits = 8 bytes => Cần 1 con trỏ kích thước 8 byte là có thể trỏ đến bất kỳ đâu trên bộ nhớ của HĐH 64 bits
*
* Ở các HĐH 64 bit còn có thể tùy chọn biên dịch ở chế độ 32 bit hoặc 64bit tùy theo IDE có hỗ trợ hay không
*/