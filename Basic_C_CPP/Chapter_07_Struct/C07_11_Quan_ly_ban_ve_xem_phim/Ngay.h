#pragma once
#include <stdio.h>

typedef struct Ngay
{
	int Day, Month, Year;
}NGAY;

void NhapNgay(NGAY &);
void XuatNgay(NGAY);