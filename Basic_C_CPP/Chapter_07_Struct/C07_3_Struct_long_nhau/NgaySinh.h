#pragma once
#include <stdio.h>

typedef struct Ngaysinh
{
	int NgaySinh;
	int ThangSinh;
	int NamSinh;
} NGAYSINH;

void NhapNgaySinh(NGAYSINH &);
void XuatNgaySinh(NGAYSINH);

/*
** Giải thích: #pragma once
** Ví dụ tại các File *.h đều có khai báo: #include <stdio.h>
** => Khai báo trùng lặp thư viện
** => #pragma once sẽ giúp tránh tình trạng này bằng cách dù có khai báo trùng lặp
** đi nữa thì nó cũng chỉ biên dịch #include <stdio.h> 1 lần mà thôi => Tránh đụng độ thư viện
*/