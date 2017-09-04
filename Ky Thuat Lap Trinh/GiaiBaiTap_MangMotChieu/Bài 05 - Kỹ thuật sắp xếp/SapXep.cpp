#include "SapXep.h"

void HoanVi(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
void SapXepTangDan(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
				HoanVi(a[i], a[j]);
}
void SapXepGiamDan(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] < a[j])
				HoanVi(a[i], a[j]);
}
void SapXepLeTang(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		if (a[i] % 2 != 0)
			for (int j = i + 1; j < n; j++)
				if (a[j] % 2 != 0)
					if (a[i] > a[j])
						HoanVi(a[i], a[j]);
}