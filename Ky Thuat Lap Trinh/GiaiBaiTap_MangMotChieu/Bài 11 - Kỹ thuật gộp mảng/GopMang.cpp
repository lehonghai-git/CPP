#include "GopMang.h"

void GopMang(int chan[], int nchan, int le[], int nle, int Result[], int &nResult)
{
	nResult = 0;
	for (int i = 0; i < nle; i++)
		Result[nResult++] = le[i];

	for (int i = 0; i < nchan; i++)
		Result[nResult++] = chan[i];
}