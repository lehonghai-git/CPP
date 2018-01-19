#pragma once
#include "VeXemPhim.h"
#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct RCP
{
	int n; // số lượng
	VEXEMPHIM DanhSachVe[MAX];
}RAPCHIEUPHIM;

void NhapDanhSachVe(RAPCHIEUPHIM &);
void XuatDanhSachVe(RAPCHIEUPHIM);
float TinhTongTienBanVe(RAPCHIEUPHIM);