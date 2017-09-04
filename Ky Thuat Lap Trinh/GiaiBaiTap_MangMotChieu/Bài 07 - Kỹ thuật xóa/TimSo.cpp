#include "TimSo.h"

int TimMax(int a[], int n)
{
	int Max = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] > Max)
			Max = a[i];
	return Max;
}