#pragma once
#include "LuanVan.h"
#include <string.h>
#include <time.h>
#define MAX 100

typedef struct DanhSachLuanvan
{
	int n; // Số lượng luận văn
	LUANVAN DanhSachLuanVan[MAX];
}DANHSACHLUANVAN;

void NhapDanhSachLuanVan(DANHSACHLUANVAN &);
void XuatDanhSachLuanVan(DANHSACHLUANVAN);
int DemTanSoXuatHienMax(DANHSACHLUANVAN);
void TimNamCoNhieuLuanVan(DANHSACHLUANVAN, int);
int TimNamGanNhat(DANHSACHLUANVAN);
void LietKeCacLuanVanGanNhat(DANHSACHLUANVAN);