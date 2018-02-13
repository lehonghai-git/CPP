#include <stdio.h>
#include <string.h>

/*
Tìm từ có chiều dài lớn nhất trong chuỗi. Xuất ra từ đó và độ dài tương ứng.
VD: Ky thuat lap trinh c/c++
=> "thuat" dài nhất
*/

int main()
{
	char s[] = "   Ky    thuat       lap   trinh aaaaaaaaaaa";
	int start, end;
	int length = strlen(s);
	int max = 1;
	int startMax, endMax;
	for (int i = 0; i < length; i++)
	{
		if (s[i] == ' ' && s[i + 1] != ' ')
		{
			start = i + 1;
			for (int j = start + 1; j <= length; j++)
			{
				if (s[j] == ' ' || s[j] == '\0')
				{
					end = j - 1;
					i = end;
					break;
				}
			}
			int dodai = end - start + 1;
			if (dodai > max)
			{
				max = dodai;
				startMax = start;
				endMax = end;
			}
		}
	}
	printf("Chuoi dai nhat: ");
	for (int i = startMax; i <= endMax; i++)
		printf("%c", s[i]);
	printf("\nDo dai = %d", max);
	getch();
	return 0;
}