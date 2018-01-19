#include <stdio.h>
#include <conio.h>

int main()
{
#if 1 // Giá trị của biến
	int x = 2, y = 5;
	int Tong = x + y;
	printf("Tong = %d", Tong);
	/*
	- Mọi thao tác trên là đang thao tác với giá trị của biến
	- Chưa hề thao tác tới địa chỉ của biến
	*/
#endif // 1 // Giá trị của biến

#if 0 // Địa chỉ của biến
	int x = 0;
	scanf_s("%d", &x);
	printf("x = %d", x);
	/*
	- Toán tử & sẽ lấy địa chỉ của biến
	- Hàm scanf() nhận vào địa chỉ của biến và lưu giá trị nhập vào vùng nhớ có địa chỉ đó
	- Mỗi ô nhớ trên bộ nhớ (RAM) sẽ có một địa chỉ
	*/
#endif // 1 // Địa chỉ của biến

#if 0 // Giá trị và địa chỉ
	int x = 0;
	printf("Gia tri cua x la %d \n", x);
	printf("Dia chi cua x la %d \n", &x);
	printf("Dia chi (hex) cua x la %p \n", &x);

#endif // 1 // Giá trị và địa chỉ

#if 0 // Giới thiệu về con trỏ
	int x = 0;
	int *p; // Hoặc khởi tạo và gán luôn: int *p = &x;
	p = &x;

	printf("Gia tri cua x la %d \n", x);
	printf("Dia chi cua x la %d \n", &x);
	printf("Gia tri cua p la %d \n", p);
	/*
	- Tại sao khi chạy đoạn mã trên địa chỉ của x lại bằng với giá trị của p?
	- biến p có kiểu dữ liệu là int * và thao tác *p = &x; là ta đã gán địa chỉ của x vào p
	- Ta nói p chính là biến con trỏ và nó đang trỏ tới x.
	=> Con trỏ là biến lưu địa chỉ của biến khác
	*/
#endif // 1 // Giới thiệu về con trỏ

#if 0 // Dùng con trỏ để thay đổi giá trị biến khác
	int x = 0;
	printf("x = %d \n", x);

	int *p = &x; // Hoàn toàn tương tự lệnh x = 69;
	*p = 69;
	printf("x = %d \n", x);
	/*
	- Thông qua con trỏ có thể gián tiếp thay đổi giá trị của x
	- Có được con trỏ p thì có thể gián tiếp điều khiển biến x
	*/
#endif // 1 // Dùng con trỏ để thay đổi giá trị biến khác

#if 0 // Ghi chú
	/*
	- Con trỏ được nhắc đến trong C/C++, ở ngôn ngữ khác khái niệm này không dùng nữa mà thay vào đó khái niệm Tham chiếu (99% giống con trỏ)
	- Các ngôn ngữ như Java. C# ngăn chặn việc sử dụng con trỏ vì có thể gây nguy hiểm thay vào đó nó sử dụng Tham chiếu (Giảm bớt quyền lực của con trỏ đi)
	*/
#endif // 1 // Ghi chú

	_getch();
	return 0;
}