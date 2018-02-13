#pragma once
#include <stdio.h>

typedef struct Gio
{
	int Hour, Minute, Second;
}GIO;

void NhapGio(GIO &);
void XuatGio(GIO);