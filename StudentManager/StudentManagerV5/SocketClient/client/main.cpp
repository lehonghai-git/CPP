#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib,"ws2_32.lib")
#include <WinSock2.h>
#include <iostream>
#include <string>
#include <windows.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include "view.h"

using namespace std;

View view;
SOCKET Connections;

DWORD WINAPI threadRecv(LPVOID arg) {
	while (true)
	{
		char input[256];
		recv(Connections, input, sizeof(input), NULL);
		cout << "From server: " << input << endl;
	}
	return 0;
}

DWORD WINAPI threadSend(LPVOID arg) {
	while (true)
	{
		char output[256];
		gets_s(output);
		send(Connections, output, sizeof(output), NULL);
	}
	return 0;
}

int main()
{
	//---------------------------------
	WSAData wsaData;
	WORD DllVersion = MAKEWORD(2, 2);

	//If WSAStartup returns anything other than 0, then that means an error has occured in the WinSock Startup.
	if (WSAStartup(DllVersion, &wsaData) != 0) {
		MessageBoxA(NULL, "Winsock startup failed", "Error", MB_OK | MB_ICONERROR);
		exit(1);
	}

	//Address to be binded to our Connection socket
	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr); //Need sizeofaddr for the connect function
	addr.sin_addr.s_addr = inet_addr("127.0.0.1"); //Address = localhost (this pc)
	addr.sin_port = htons(2016); //Port = 1111
	addr.sin_family = AF_INET; //IPv4 Socket

	Connections = socket(AF_INET, SOCK_STREAM, NULL); //Set Connection socket
	cout << "Connect to Server!" << endl;
	//If we are unable to connect...
	if (connect(Connections, (SOCKADDR*)&addr, sizeofaddr) != 0) {
		MessageBoxA(NULL, "Failed to Connect", "Error", MB_OK | MB_ICONERROR);
		return 0; //Failed to Connect
	}
	else
	{
		cout << "Connect Success!" << endl;
		//CreateThread(NULL, 0, threadRecv, NULL, 0, NULL);
		//while (true)
		//{
		//	//cout << "Message: ";
		//	char output[256];
		//	gets_s(output);
		//	send(Connections, output, sizeof(output), NULL);
		//}

		//---------------------------------
		do {
			view.mainMenu();
			char choice;
			cin >> choice;
			// Lựa chọn Menu chính
			switch (choice)
			{
				// Case 1 Menu chính: Thêm sửa xóa sinh viên
			case '1':
			{
				// Menu con: Thêm, Sửa, Xóa Sinh viên
				view.updateMenu();
				char choice1;
				cin >> choice1;
				// Lựa chọn Menu con: Thêm sửa xóa
				switch (choice1)
				{
				case '1':
				{
					cout << "Nhap Sinh Vien Tu Ban Phim" << endl;
					// send id = cn11					
					send(Connections, "cn11", sizeof("cn11"), NULL);
					char soluong[100], hoten[100], sbd[100], diachi[100], gioitinh[100], toan[100], ly[100], hoa[100];
					fflush(stdin);
					cout << "So luong: ";
					gets_s(soluong);
					send(Connections, soluong, sizeof(soluong), NULL);
					
					int n = atof(soluong); // Convert
					for (int j = 1; j <= n; j++)
					{
						fflush(stdin);
						cout << "Ho ten: ";
						gets_s(hoten);
						send(Connections, hoten, sizeof(hoten), NULL);

						cout << "SBD: ";
						gets_s(sbd);
						send(Connections, sbd, sizeof(sbd), NULL);

						cout << "Dia Chi: ";
						gets_s(diachi);
						send(Connections, diachi, sizeof(diachi), NULL);

						cout << "Gioi Tinh:\n1. Nam\n2. Nu\n3. Khac\n";
						gets_s(gioitinh);
						send(Connections, gioitinh, sizeof(gioitinh), NULL);

						cout << "Diem Toan: ";
						gets_s(toan);
						send(Connections, toan, sizeof(toan), NULL);

						cout << "Diem Ly: ";
						gets_s(ly);
						send(Connections, ly, sizeof(ly), NULL);

						cout << "Diem Hoa: ";
						gets_s(hoa);
						send(Connections, hoa, sizeof(hoa), NULL);
					}
					cout << "\nSuccess!" << endl;
					break;
				}
				case '2':
				{
					cout << "Nhap Sinh Vien Tu File" << endl;
					// MultiThread Nhập File
					//--------------------------------------
					// send id = cn12
					send(Connections, "cn12", sizeof("cn12"), NULL);
					cin.ignore();
					cout << "Nhap Ma Truong (VD: BKA): ";
					char output[256];
					gets_s(output);
					send(Connections, output, sizeof(output), NULL);
					Sleep(1500);
					cout << "\nSucsess!" << endl;
					break;
				}
				case '3':
				{
					cout << "Sua Sinh Vien" << endl;
					// send id = cn13
					send(Connections, "cn13", sizeof("cn13"), NULL);
					fflush(stdin);
					cout << "Nhap SBD: ";
					char sbd[100];
					gets_s(sbd);
					send(Connections, sbd, sizeof(sbd), NULL);

					// Dòng này nhận chuỗi thông tin sinh viên ứng với số báo danh vừa nhập

					char hoten[100], sobaodanh[100], diachi[100], gioitinh[100], toan[100], ly[100], hoa[100];
					fflush(stdin);
					cout << "Ho ten: ";
					gets_s(hoten);
					send(Connections, hoten, sizeof(hoten), NULL);

					cout << "SBD: ";
					gets_s(sobaodanh);
					send(Connections, sobaodanh, sizeof(sobaodanh), NULL);

					cout << "Dia Chi: ";
					gets_s(diachi);
					send(Connections, diachi, sizeof(diachi), NULL);

					cout << "Gioi Tinh:\n1. Nam\n2. Nu\n3. Khac\n";
					gets_s(gioitinh);
					send(Connections, gioitinh, sizeof(gioitinh), NULL);

					cout << "Diem Toan: ";
					gets_s(toan);
					send(Connections, toan, sizeof(toan), NULL);

					cout << "Diem Ly: ";
					gets_s(ly);
					send(Connections, ly, sizeof(ly), NULL);

					cout << "Diem Hoa: ";
					gets_s(hoa);
					send(Connections, hoa, sizeof(hoa), NULL);

					cout << "\nSuccess!" << endl;
					break;
				}
				case '4':
				{
					cout << "Xoa Sinh Vien" << endl;
					// send id = cn14
					send(Connections, "cn14", sizeof("cn14"), NULL);
					fflush(stdin);
					cout << "Nhap SBD: ";
					char xoasinhvien[256];
					gets_s(xoasinhvien);
					send(Connections, xoasinhvien, sizeof(xoasinhvien), NULL);
					cout << "Send to Server!" << endl;
					break;
				}
				case '5':
					cout << "Exit!";
					system("pause>null");
					break;
				default:
					cout << "Nhap lai!" << endl;
					system("pause>null");
					break;
				}

				system("pause>null");
				break;
			}
			// Case 2 Menu chính: tìm kiếm sinh viên
			case '2':
			{
				// Menu con Tìm kiếm sinh viên
				view.searchMenu();
				char choice2;
				cin >> choice2;
				// Lựa chọn Menu con Tìm kiếm sinh viên
				switch (choice2)
				{
				case '1':
				{
					cout << "Tim Kiem Theo Diem Tong" << endl;
					send(Connections, "cn21", sizeof("cn21"), NULL);
					fflush(stdin);
					// send id = cn21
					cout << "Nhap Tong diem: ";
					char diemTong[256];
					gets_s(diemTong);
					send(Connections, diemTong, sizeof(diemTong), NULL);
					char tkTD[500];
					recv(Connections, tkTD, sizeof(tkTD), NULL);
					cout << tkTD;
					cout << "\nSuccess!" << endl;
					break;
				}
				case '2':
				{
					cout << "Tim Kiem Theo SBD" << endl;
					// send id = cn22
					char output[5] = "cn22";
					send(Connections, output, sizeof(output), NULL);
					fflush(stdin);
					cout << "Nhap SBD: ";
					char soBaoDanh[10];
					gets_s(soBaoDanh);
					send(Connections, soBaoDanh, sizeof(soBaoDanh), NULL);
					char tkSBD[500];
					recv(Connections, tkSBD, sizeof(tkSBD), NULL);
					cout << tkSBD;
					cout << "\nSuccess!" << endl;
					break;
				}
				case '3':
				{
					cout << "Tim Kiem Theo Ho Ten" << endl;
					// send id = cn23
					char output[5] = "cn23";
					send(Connections, output, sizeof(output), NULL);
					fflush(stdin);
					cout << "Nhap Ten: ";
					char hoTen[100];
					gets_s(hoTen);
					send(Connections, hoTen, sizeof(hoTen), NULL);
					char tkHoTen[500];
					recv(Connections, tkHoTen, sizeof(tkHoTen), NULL);
					cout << tkHoTen;
					cout << "\nSuccess!" << endl;
					break;
				}
				case '4':
				{
					cout << "Tim Kiem Theo Diem Toan" << endl;
					// send id = cn24
					char output[5] = "cn24";
					send(Connections, output, sizeof(output), NULL);
					fflush(stdin);
					char diemToan[100];
					cout << "Nhap diem Toan: ";
					gets_s(diemToan);
					send(Connections, diemToan, sizeof(diemToan), NULL);
					char tkDiemToan[500];
					recv(Connections, tkDiemToan, sizeof(tkDiemToan), NULL);
					cout << tkDiemToan;
					cout << "\nSuccess!" << endl;
					break;
				}
				case '5':
				{
					cout << "Tim Kiem Theo Diem Ly" << endl;
					// send id = cn25
					char output[5] = "cn25";
					send(Connections, output, sizeof(output), NULL);
					fflush(stdin);
					char diemLy[100];
					cout << "Nhap diem Ly: ";
					gets_s(diemLy);
					send(Connections, diemLy, sizeof(diemLy), NULL);
					char tkDiemLy[500];
					recv(Connections, tkDiemLy, sizeof(tkDiemLy), NULL);
					cout << tkDiemLy;
					cout << "\nSuccess!" << endl;
					break;
				}
				case '6':
				{
					cout << "Tim Kiem Theo Diem Hoa" << endl;
					// send id = cn26
					char output[5] = "cn26";
					send(Connections, output, sizeof(output), NULL);
					fflush(stdin);
					cout << "Nhap diem Hoa: ";
					char diemHoa[100];
					gets_s(diemHoa);
					send(Connections, diemHoa, sizeof(diemHoa), NULL);

					char tkDiemHoa[500];
					recv(Connections, tkDiemHoa, sizeof(tkDiemHoa), NULL);
					cout << tkDiemHoa;
					cout << "\nSuccess!" << endl;
					break;
				}
				case '7':
					cout << "Ban chon Exit!";
					system("pause>null");
					break;
				default:
					cout << "Nhap lai!" << endl;
					system("pause>null");
					break;
				}
				system("pause>null");
				break;
			}
			// Case 3 Menu chính: Sắp xếp sinh viên
			case '3':
			{
				// Menu con Sắp xếp sinh viên
				view.sortMenu();
				char choice3;
				cin >> choice3;
				// Lựa chọn Menu con Sắp xếp sinh viên
				switch (choice3)
				{
				case '1':
				{
					cout << "Sap Xep Theo SBD" << endl;
					// send id = cn31
					char output[5] = "cn31";
					send(Connections, "cn31", sizeof("cn31"), NULL);
					char sxsbd[500];
					recv(Connections, sxsbd, sizeof(sxsbd), NULL);
					cout << sxsbd;
					cout << "\nSuccess!" << endl;
					break;
				}
				case '2':
				{
					cout << "Sap Xep Theo Anphabe" << endl;
					// send id = cn32
					char output[5] = "cn32";
					send(Connections, output, sizeof(output), NULL);
					char sxanphabe[500];
					recv(Connections, sxanphabe, sizeof(sxanphabe), NULL);
					cout << sxanphabe;
					cout << "\nSuccess!" << endl;
					break;
				}
				case '3':
				{
					cout << "Sap Xep Theo Diem Tong" << endl;
					// send id = cn33
					char output[5] = "cn33";
					send(Connections, output, sizeof(output), NULL);
					char sxdiemtong[500];
					recv(Connections, sxdiemtong, sizeof(sxdiemtong), NULL);
					cout << sxdiemtong;
					cout << "\nSuccess!" << endl;
					break;
				}
				case '4':
					cout << "Ban chon Exit!";
					system("pause>null");
					break;
				default:
					cout << "Nhap sai!" << endl;
					system("pause>null");
					break;
				}
				system("pause>null");
				break;
			}
			// Case 4 Menu chính: Xuất Sinh viên ra File
			case '4':
			{
				cout << "Xuat Sinh Vien Ra File" << endl;
				// send id = cn41
				char output[5] = "cn41";
				send(Connections, output, sizeof(output), NULL);
				fflush(stdin);
				cout << "Xuat ra File (VD: sinhvien.output): ";
				char fileName[100];
				gets_s(fileName);
				send(Connections, fileName, sizeof(fileName), NULL);
				cout << "\nSuccess!" << endl;
				system("pause>null");
				break;
			}
			// Case 5 Menu chính: Thống kê sinh viên
			case '5':
			{
				// send id = cn51
				char output[5] = "cn51";
				send(Connections, output, sizeof(output), NULL);

				char _input[1024];
				recv(Connections, _input, sizeof(_input), NULL);
				cout << _input << endl;

				cout << "\nSuccess!" << endl;
				system("pause>null");
				break;
			}
			// Case 6 Menu chính
			case '6':
			{
				// send id = cn61
				char output[5] = "cn61";
				send(Connections, output, sizeof(output), NULL);
				exit(0);
				break;
			}
			// default Menu chính
			default:
				cout << "Nhap sai!" << endl;
				system("pause>null");
				break;
			}

		} while (true);
		//---------------------------------
	}

	system("pause");
	return 0;
}
