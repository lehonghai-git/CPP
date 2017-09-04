#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>

#define TITLE Show()
#define CLEAR system("cls")
#define PAUSE system("pause")
#define GREEN system("color A")

void Show()
{
	printf("\n      HUONG DAN\n");
	printf("Nhan 'ENTER' de bat dau\n");
	printf("Nhan 'SPACE' de tam dung\n");
	printf("Nhan 'SPACE' de tiep tuc\n");
	printf("------------------------\n");
}

inline bool NhanNut(int presskey)
{
	return GetAsyncKeyState(presskey);
}

int main()
{
	char key;
	int check = 0;
	GREEN;
	TITLE;
	printf("      00:00:00\n");
	scanf("%c", &key);
	if (key == '\n')
	{
		CLEAR;
		TITLE;
		for (int gio = 0; gio <= 24; gio++)
		{
			for (int phut = 0; phut <= 59; phut++)
			{
				for (int giay = 0; giay <= 59; giay++)
				{
					if (NhanNut(VK_ESCAPE))
						break;
					if (NhanNut(VK_SPACE))
						check++;
					if (check % 2 != 0)
						PAUSE;
					printf("      %02d:%02d:%02d\n", gio, phut, giay);
					Sleep(1000); // Delay milisecond
					CLEAR;
					TITLE;
				}
			}
		}
	}

	getch();
	return 0;
}