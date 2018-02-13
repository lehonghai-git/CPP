#include <stdio.h>

/*
** LÝ THUYẾT STRUCT
*/

// Khai báo một struct
struct Diem
{
	float HoanhDo;
	float TungDo;
};

// Định nghĩa cho nó một cái tên
typedef struct Diem DIEM;

// Khai báo kèm khởi tạo
struct ToaDo
{
	int HoanhDo;
	int TungDo;
} TD1 = { 1,2 }, TD2 = { 3,4 }, TD3;
typedef struct ToaDo TOADO;

int main()
{
	DIEM d1 = { 1, 2 };
	// Truy xuất biến bên trong bằng toán tử dấu chấm (.) hoặc bằng toán tử trỏ: ->
	printf("\nHoanh Do d1: %f", d1.HoanhDo);
	printf("\nTung Do d1: %f", d1.TungDo);

	// Gán qua lại các struct: Không khuyến khích dùng cách này.
	DIEM d2 = d1;
	printf("\nHoanh Do d2: %f", d2.HoanhDo);
	printf("\nTung Do d2: %f", d2.TungDo);

	// Gán từng biến bên trong struct
	DIEM d3;
	d3.HoanhDo = d2.HoanhDo;
	d3.TungDo = d2.TungDo;
	printf("\nHoanh Do d3: %f", d3.HoanhDo);
	printf("\nTung Do d3: %f", d3.TungDo);

	getch();
	return 0;
}
/*
- C Style: void NhapDiem(struct Diem d1)
- C++ Style: void NhapDiem(Diem d1)
Note: Nên viết theo C Style thì sẽ chạy được ở cả C và C++.
Hoặc có thể dùng typedef:

typedef struct Diem LeHongHai;
=> void NhapDiem(LeHongHai d1)
*/