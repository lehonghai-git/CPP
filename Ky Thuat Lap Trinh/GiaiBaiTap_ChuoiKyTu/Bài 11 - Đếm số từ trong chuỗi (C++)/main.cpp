#include <iostream>
#include <string>
using namespace std;

int DemSoTu(string);

int main()
{
	string s = "Le Hong Hai Hai Le Hong";
	int sotu = DemSoTu(s);
	cout << "Chuoi " << s << " co " << sotu << " tu" << endl;

	system("pause");
	return 0;
}

int DemSoTu(string s)
{
	int n = s.length();
	int dem = 0;
	if (s[0] != ' ')
		dem = 1;
	for (int i = 0; i < n - 1; i++)
		if (s[i] == ' ' && s[i + 1] != ' ')
			dem++;
	return dem;
}