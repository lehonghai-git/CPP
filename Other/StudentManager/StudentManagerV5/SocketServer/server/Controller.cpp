#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib,"ws2_32.lib")
#include <WinSock2.h>
#include "student.h"
#include "view.h"
#include "model.h"
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <fstream>

using namespace std;

const int soThread = 696;
//CRITICAL_SECTION cs;
int tmp = 0;
SOCKET Connections[100];
int ConnectionCounter = 0;

DWORD WINAPI threadNhap(LPVOID arg) {
	Model process;
	//EnterCriticalSection(&cs);
	string* param = (string*)(arg);
	string input = param->c_str();
	string fileName;
	fileName = "diemthi/" + input + ".input";
	cout << "\nFile Name Edited: " << fileName << endl;
	process.NhapSinhVienTuFile(fileName);
	//LeaveCriticalSection(&cs);
	return 0;
}

DWORD WINAPI threadMonitoring(LPVOID arg) {
	Model process;
	string* param = (string*)(arg);
	string input = param->c_str();
	while (true)
	{
		int dem;
		dem = process.DemSoFile(input);
		if (dem > tmp)
		{
			HANDLE hd[soThread];
			for (int i = tmp; i <= dem; i++) {
				string maTruong = input + "-" + process.Convert(i);
				hd[i] = CreateThread(NULL, 0, threadNhap, (LPVOID)&maTruong, 0, NULL);
				cout << "Da Update\n";
			}
			tmp = dem;
		}
		Sleep(3000);
	}
	return 0;
}

DWORD WINAPI threadRecv(int index) {
	while (true)
	{
		char input[256];
		recv(Connections[index], input, sizeof(input), NULL); //Receive Message of the Day buffer into MOTD array
		cout << "From client: " << input << endl;
	}
	return 0;
}

DWORD WINAPI threadSend(int index) {
	while (true) {
		char output[256];
		gets_s(output);
		send(Connections[index], output, sizeof(output), NULL);
	}
	return 0;
}

int main() {

	Model process;
	View menu;
	Student sinhvien;

	//WinSock Startup
	WSAData wsaData;
	WORD DllVersion = MAKEWORD(2, 2);
	if (WSAStartup(DllVersion, &wsaData) != 0) //If WSAStartup returns anything other than 0, then that means an error has occured in the WinSock Startup.
	{
		MessageBoxA(NULL, "WinSock startup failed", "Error", MB_OK | MB_ICONERROR);
		return 0;
	}

	SOCKADDR_IN addr; //Address that we will bind our listening socket to
	int addrlen = sizeof(addr); //length of the address (required for accept call)
	addr.sin_addr.s_addr = inet_addr("127.0.0.1"); //Broadcast locally
	addr.sin_port = htons(2016); //Port
	addr.sin_family = AF_INET; //IPv4 Socket

	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL); //Create socket to listen for new connections
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr)); //Bind the address to the socket
	listen(sListen, SOMAXCONN); //Places sListen socket in a state in which it is listening for an incoming connection. Note:SOMAXCONN = Socket Oustanding Max Connections
	cout << "Server is Ready!" << endl;
	for (int i = 0; i < 100; i++)
	{
		Connections[i] = accept(sListen, (SOCKADDR*)&addr, &addrlen); //Accept a new connection
		if (Connections[i] == 0) //If accepting the client connection failed
		{
			cout << "Failed to accept the client's connection." << endl;
		}
		else //If client connection properly accepted
		{
			//CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)threadRecv, (LPVOID)(i), NULL, NULL);
			//CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)threadSend, (LPVOID)(i), NULL, NULL);
			while (true)
			{
				char fromClient[256];
				recv(Connections[i], fromClient, sizeof(fromClient), NULL); //Receive Message of the Day buffer into MOTD array
				cout << "From client: " << fromClient << endl;

				// Thêm Sinh viên từ bàn phím
				if (strcmp(fromClient, "cn11") == 0) {
					system("cls");
					cout << "Nhap Sinh Vien Tu Ban Phim" << endl;
					char soluong[100], hoten[100], sbd[100], diaChi[100], gioiTinh[100], toan[100], ly[100], hoa[100];

					recv(Connections[i], soluong, sizeof(soluong), NULL);
					cout << soluong << endl;
					int n = atof(soluong);
					for (int j = 1; j <= n; j++)
					{
						recv(Connections[i], hoten, sizeof(hoten), NULL);
						cout << hoten << endl;
						string name = hoten;

						recv(Connections[i], sbd, sizeof(sbd), NULL);
						cout << sbd << endl;
						string id = sbd;

						recv(Connections[i], diaChi, sizeof(diaChi), NULL);
						cout << diaChi << endl;
						string addr = diaChi;

						recv(Connections[i], gioiTinh, sizeof(gioiTinh), NULL);
						cout << gioiTinh << endl;
						int sex = atof(gioiTinh);

						recv(Connections[i], toan, sizeof(toan), NULL);
						cout << toan << endl;
						double math = atof(toan);

						recv(Connections[i], ly, sizeof(ly), NULL);
						cout << ly << endl;
						double phys = atof(ly);

						recv(Connections[i], hoa, sizeof(hoa), NULL);
						cout << hoa << endl;
						double chemi = atof(hoa);

						process.ThemSinhvienv2(name, id, addr, sex, math, phys, chemi);
					}

				}

				// Nhập sinh viên từ file
				if (strcmp(fromClient, "cn12") == 0)  {
					// MultiThread Nhập File
					//--------------------------------------
					char input[256];
					recv(Connections[i], input, sizeof(input), NULL); //Receive Message of the Day buffer into MOTD array

					string matruong = input; // kiểu string gán trực tiếp cho mảng char :D :D
					int threadNumber = process.DemSoFile(matruong);
					cout << "Ma truong " << matruong << " co " << threadNumber << " File.";
					/*char* numberFile = (char*)threadNumber;
					send(Connections[i], numberFile, sizeof(numberFile), NULL);*/

					// --------------------------------------
					//InitializeCriticalSection(&cs);
					HANDLE hd[soThread];
					for (int i = 0; i < threadNumber; i++) {
						string maTruong = matruong + "-" + process.Convert(i);
						hd[i] = CreateThread(NULL, 0, threadNhap, (LPVOID)&maTruong, 0, NULL);
						tmp++;
						Sleep(300);
					}
					//WaitForMultipleObjects(threadNumber, hd, TRUE, INFINITE);
					//cout << "So file da doc: " << tmp;
					// Folder Monitoring
					HANDLE hThreadMoni = CreateThread(NULL, 0, threadMonitoring, (LPVOID)&matruong, 0, NULL);
					//DeleteCriticalSection(&cs);
					//--------------------------------------
					cout << "\nSucsess..!" << endl;
				}

				// Sửa sinh viên
				if (strcmp(fromClient, "cn13") == 0) {
					system("cls");
					cout << "Sua Sinh Vien" << endl;
					char sbd[100];
					recv(Connections[i], sbd, sizeof(sbd), NULL);
					cout << sbd;

					// dòng này sẽ gửi lại thông tin sinh viên ứng với số báo danh đã nhập từ client

					string xoasv = sbd;
					process.TimKiemSoBaoDanh(xoasv);
					process.XoaSinhVien(xoasv);

					char hoten[100], sobaodanh[100], diaChi[100], gioiTinh[100], toan[100], ly[100], hoa[100];
					recv(Connections[i], hoten, sizeof(hoten), NULL);
					cout << hoten << endl;
					string name = hoten;

					recv(Connections[i], sobaodanh, sizeof(sobaodanh), NULL);
					cout << sobaodanh << endl;
					string id = sobaodanh;

					recv(Connections[i], diaChi, sizeof(diaChi), NULL);
					cout << diaChi << endl;
					string addr = diaChi;

					recv(Connections[i], gioiTinh, sizeof(gioiTinh), NULL);
					cout << gioiTinh << endl;
					int sex = atof(gioiTinh);

					recv(Connections[i], toan, sizeof(toan), NULL);
					cout << toan << endl;
					double math = atof(toan);

					recv(Connections[i], ly, sizeof(ly), NULL);
					cout << ly << endl;
					double phys = atof(ly);

					recv(Connections[i], hoa, sizeof(hoa), NULL);
					cout << hoa << endl;
					double chemi = atof(hoa);

					process.ThemSinhvienv2(name, id, addr, sex, math, phys, chemi);
					cout << "Success!\n";
					process.TimKiemSoBaoDanh(id);
				}

				// Xóa sinh viên
				if (strcmp(fromClient, "cn14") == 0) {
					system("cls");
					cout << "Xoa Sinh Vien" << endl;
					char input[256];
					recv(Connections[i], input, sizeof(input), NULL);
					string sobd = input;
					process.XoaSinhVien(sobd);
					//process.ThongKeTatCa();
				}

				// Tìm SV theo điểm tổng
				if (strcmp(fromClient, "cn21") == 0) {
					system("cls");
					cout << "Tim Kiem Theo Diem Tong" << endl;
					char input[256];
					recv(Connections[i], input, sizeof(input), NULL);
					double tongDiem = atof(input); // Convert
					//cout << "Tong diem: " << input << endl;
					process.TimKiemTongDiem(tongDiem);

					fstream f;
					f.open("tmp/timkiemtongdiem.txt", ios::in);
					string data, line;
					while (!f.eof()) {
						getline(f, line);
						data += line + "\n";
					}
					f.close();
					cout << data;
					char sizeData[256];
					const char* tkTongDiem = data.c_str();
					send(Connections[i], tkTongDiem, sizeof(sizeData), NULL);
				}

				// Tìm SV theo số báo danh
				if (strcmp(fromClient, "cn22") == 0) {
					system("cls");
					cout << "Tim Kiem Theo SBD" << endl;
					char input[10];
					recv(Connections[i], input, sizeof(input), NULL);
					string soBaoDanh(input);
					process.TimKiemSoBaoDanh(soBaoDanh);

					fstream f;
					f.open("tmp/timkiemsbd.txt", ios::in);
					string data, line;
					while (!f.eof()) {
						getline(f, line);
						data += line + "\n";
					}
					f.close();
					cout << data;
					char sizeData[256];
					const char* tkSBD = data.c_str();
					send(Connections[i], tkSBD, sizeof(sizeData), NULL);
				}

				// Tìm SV theo họ tên
				if (strcmp(fromClient, "cn23") == 0) {
					system("cls");
					cout << "Tim Kiem Theo Ho Ten" << endl;
					char input[100];
					recv(Connections[i], input, sizeof(input), NULL);
					string hoTen(input);
					process.TimKiemHoTen(hoTen);

					fstream f;
					f.open("tmp/timkiemhoten.txt", ios::in);
					string data, line;
					while (!f.eof()) {
						getline(f, line);
						data += line + "\n";
					}
					f.close();
					cout << data;
					char sizeData[256];
					const char* tkHoTen = data.c_str();
					send(Connections[i], tkHoTen, sizeof(sizeData), NULL);
				}

				// Tìm SV theo điểm toán
				if (strcmp(fromClient, "cn24") == 0) {
					system("cls");
					cout << "Tim Kiem Theo Diem Toan" << endl;
					char input[100];
					recv(Connections[i], input, sizeof(input), NULL);
					double diemToan = atof(input); // Convert
					process.TimKiemDiemToan(diemToan);

					fstream f;
					f.open("tmp/timkiemdiemtoan.txt", ios::in);
					string data, line;
					while (!f.eof()) {
						getline(f, line);
						data += line + "\n";
					}
					f.close();
					cout << data;
					char sizeData[256];
					const char* tkDiemToan = data.c_str();
					send(Connections[i], tkDiemToan, sizeof(sizeData), NULL);
				}

				// Tìm SV theo điểm lý
				if (strcmp(fromClient, "cn25") == 0) {
					system("cls");
					cout << "Tim Kiem Theo Diem Ly" << endl;
					char input[100];
					recv(Connections[i], input, sizeof(input), NULL);
					double diemLy = atof(input); // Convert
					process.TimKiemDiemLy(diemLy);

					fstream f;
					f.open("tmp/timkiemdiemly.txt", ios::in);
					string data, line;
					while (!f.eof()) {
						getline(f, line);
						data += line + "\n";
					}
					f.close();
					cout << data;
					char sizeData[256];
					const char* tkDiemLy = data.c_str();
					send(Connections[i], tkDiemLy, sizeof(sizeData), NULL);
				}

				// Tìm SV theo điểm hóa
				if (strcmp(fromClient, "cn26") == 0) {
					system("cls");
					cout << "Tim Kiem Theo Diem Hoa" << endl;
					char input[100];
					recv(Connections[i], input, sizeof(input), NULL);
					double diemHoa = atof(input); // Convert
					process.TimKiemDiemHoa(diemHoa);
					
					fstream f;
					f.open("tmp/timkiemdiemhoa.txt", ios::in);
					string data, line;
					while (!f.eof()) {
						getline(f, line);
						data += line + "\n";
					}
					f.close();
					cout << data;
					char sizeData[256];
					const char* tkDiemHoa = data.c_str();
					send(Connections[i], tkDiemHoa, sizeof(sizeData), NULL);

				}

				// Sắp xếp SV theo SBD
				if (strcmp(fromClient, "cn31") == 0) {
					system("cls");
					cout << "Sap Xep Theo SBD" << endl;
					process.SapXepSoBaoDanh();
					process.XuatSinhVienRaFile("tmp/sapxepsbd.txt");
					fstream f;
					f.open("tmp/sapxepsbd.txt", ios::in);
					string data, line;
					while (!f.eof()) {
						getline(f, line);
						data += line + "\n";
					}
					f.close();
					cout << data;
					char sizeData[256];
					const char* sapxepsbd = data.c_str();
					send(Connections[i], sapxepsbd, sizeof(sizeData), NULL);
				}

				// Sắp xếp sinh viên theo Anphabe
				if (strcmp(fromClient, "cn32") == 0) {
					system("cls");
					cout << "Sap Xep Theo Anphabe" << endl;
					process.SapXepAnphabe();
					process.XuatSinhVienRaFile("tmp/sapxepanphabe.txt");
					fstream f;
					f.open("tmp/sapxepanphabe.txt", ios::in);
					string data, line;
					while (!f.eof()) {
						getline(f, line);
						data += line + "\n";
					}
					f.close();
					cout << data;
					char sizeData[256];
					const char* sapxepanphabe = data.c_str();
					send(Connections[i], sapxepanphabe, sizeof(sizeData), NULL);
				}

				// Sắp xếp theo điểm tổng
				if (strcmp(fromClient, "cn33") == 0) {
					system("cls");
					cout << "Sap Xep Theo Diem Tong" << endl;
					process.SapXepDiemTong();
					process.XuatSinhVienRaFile("tmp/sapxepdiemtong.txt");
					fstream f;
					f.open("tmp/sapxepdiemtong.txt", ios::in);
					string data, line;
					while (!f.eof()) {
						getline(f, line);
						data += line + "\n";
					}
					f.close();
					cout << data;
					char sizeData[256];
					const char* sapxepdiemtong = data.c_str();
					send(Connections[i], sapxepdiemtong, sizeof(sizeData), NULL);

				}

				// Xuất sinh viên ra file
				if (strcmp(fromClient, "cn41") == 0) {
					system("cls");
					cout << "Xuat Sinh Vien ra File" << endl;
					char input[100];
					recv(Connections[i], input, sizeof(input), NULL);
					string fileName(input);
					process.XuatSinhVienRaFile(fileName);
					cout << "Success!" << endl;
				}

				// Thống kê tất cả sinh viên
				if (strcmp(fromClient, "cn51") == 0) {
					system("cls");
					cout << "Thong Ke Sinh Vien" << endl;
					process.ThongKeTatCa();
					process.XuatSinhVienRaFile("tmp/sinhvien.txt");

					fstream f;
					f.open("tmp/sinhvien.txt", ios::in);
					string data, line;
					while (!f.eof()) {
						getline(f, line);
						data += line + "\n";
					}
					f.close();
					//cout << data << endl;
					
					/*fstream f1;
					f1.open("tmp/thongkenhanh.txt", ios::in);
					string data1;
					string line1;
					while (!f1.eof()) {
						getline(f1, line1);
						data1 += line1 + "\n";
					}
					f1.close();
					cout << data1 << endl;*/
					//string str2 = data;
					char sizeData[1024];
					const char* dataSend = data.c_str();
					send(Connections[i], dataSend, sizeof(sizeData), NULL);

					cout << "Success!" << endl;
				}

				// Thoát
				if (strcmp(fromClient, "cn61") == 0) {
					// cleanup
					closesocket(Connections[i]);
					WSACleanup();
					//break;
				}

			}
		}

	}

	system("pause");
	return 0;
}
