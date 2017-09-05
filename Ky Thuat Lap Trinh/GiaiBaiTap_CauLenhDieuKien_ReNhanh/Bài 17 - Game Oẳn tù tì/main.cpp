/*
Game Oẳn tù tì
Người chơi đi trước và nhập vào ký tự:
'b' hoặc 'B' => Búa
'o' hoặc 'O' => Bao
'k' hoặc 'K' => Kéo
Sau đó máy tính sẽ Random ra một ký tự bất kỳ (Búa, kéo hoặc bao) và thông báo kết quả chung cuộc
HD: Random số trong khoảng nào đó và quy định mỗi số là búa, kéo, bao tùy ý
*/
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h> // Sleep

int main()
{
	printf("--------------\n");
	printf("Game Oan Tu Ti\n");
	printf("--------------\n");
	printf("1. Keo\n");
	printf("2. Bua\n");
	printf("3. Bao\n");
	printf("--------------\n");
	int Player;
	printf("Nguoi choi: ");
	scanf("%d", &Player);
	printf("--------------\n");

	if (Player == 1) printf("Nguoi choi chon: 'Keo'\n");
	else if (Player == 2) printf("Nguoi choi chon: 'Bua'\n");
	else if (Player == 3) printf("Nguoi choi chon: 'Bao'\n");
	else
	{
		printf("Nguoi choi chon sai");
		getch();
		return 0;
	}
	// Xử lý phía máy tính
	printf("Loading");
	Sleep(700); // 1s
	printf(" .");
	Sleep(700);
	printf(" .");
	Sleep(700);
	printf(" .\n");
	Sleep(700);

	srand(time(0)); // Reset time
	int Computer = 1 + rand() % 3; // Random từ 1 đến 3
	if (Computer == 1) printf("May tinh chon: 'Keo'\n");
	else if (Computer == 2) printf("May tinh chon: 'Bua'\n");
	else if (Computer == 3) printf("May tinh chon: 'Bao'\n");

	/*
	Quy định
	1 = Keo
	2 = Bua
	3 = Bao
	Trong đó:
	Kéo(1) thắng Bao(3)
	Bao(3) Thắng Búa(2)
	Búa(2) thắng Kéo(1)
	*/
	if (Player == 1 && Computer == 3 || Player == 3 && Computer == 2 || Player == 2 && Computer == 1)
		printf("Nguoi choi thang\n");
	else if (Player == Computer) printf("Hai ben hoa nhau\n");
	else
		printf("May tinh thang\n");

	getch();
	return 0;
}