#include "TachMang.h"

void TachMang(int a[], int n, int chan[], int &nchan, int le[], int &nle)
{
	nchan = nle = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0) // Chẵn
		{
			chan[nchan++] = a[i];
			//nchan++;
		}
		else
		{
			le[nle++] = a[i];
			//nle++;
		}
	}
}