#include "SinhVien.h"
#include "Menu.h"
#include "Process.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>

using namespace std;

const int soThread = 696;
//CRITICAL_SECTION cs;
int tmp = 0;

DWORD WINAPI threadNhap(LPVOID arg) {
	Process process;
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
	Process process;
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

int main() {
	Menu menu;
	Process process;
	SinhVien sinhvien;

	do {
		menu.MenuChinh();
		char choice;
		cin >> choice;
		// Lựa chọn Menu chính
		switch (choice)
		{
			// Case 1 Menu chính: Thêm sửa xóa sinh viên
		case '1':
		{
			// Menu con: Thêm, Sửa, Xóa Sinh viên
			menu.MenuThemSuaXoa();
			char choice1;
			cin >> choice1;
			// Lựa chọn Menu con: Thêm sửa xóa
			switch (choice1)
			{
			case '1':
			{
				cout << "Ban da chon: Nhap sinh vien tu ban phim" << endl;
				cout << "Nhap so luong sinh vien: ";
				int soluong;
				cin >> soluong;
				process.ThemSinhvien(soluong);
				cout << "\nNhap thanh cong!" << endl;
				break;
			}
			case '2':
			{
				cout << "Ban da chon: Nhap sinh vien tu File" << endl;
				// MultiThread Nhập File
				//--------------------------------------
				string matruong;
				cin.ignore();
				cout << "Nhap Ma Truong (VD: BKA): ";
				getline(cin, matruong);
				int threadNumber = process.DemSoFile(matruong);
				cout << "Ma truong " << matruong << " co " << threadNumber << " File.";
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
				break;
			}
			case '3':
			{
				cout << "Ban da chon: Sua sinh vien" << endl;
				fflush(stdin);
				cout << "Nhap so bao danh: ";
				string sobd;
				getline(cin, sobd);
				//process.SuaSinhVien(sobd);
				process.SuaSinhVienv2(sobd);
				break;
			}
			case '4':
			{
				cout << "Ban da chon: Xoa sinh vien" << endl;
				fflush(stdin);
				cout << "Nhap so bao danh: ";
				string sobd;
				getline(cin, sobd);
				process.XoaSinhVien(sobd);
				break;
			}
			case '5':
				cout << "Ban da chon: Quay lai Menu chinh!";
				system("pause>null");
				break;
			default:
				cout << "Nhap sai! Moi ban nhap lai." << endl;
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
			menu.MenuTimKiemSinhVien();
			char choice2;
			cin >> choice2;
			// Lựa chọn Menu con Tìm kiếm sinh viên
			switch (choice2)
			{
			case '1':
			{
				cout << "Ban da chon: Tim kiem theo Diem Tong" << endl;
				fflush(stdin);
				cout << "Nhap Tong diem: ";
				double tongdiem;
				cin >> tongdiem;
				process.TimKiemTongDiem(tongdiem);
				cout << "\nEnter de quay lai Menu" << endl;
				break;
			}
			case '2':
			{
				cout << "Ban da chon: Tim kiem theo So bao danh" << endl;
				fflush(stdin);
				cout << "Nhap So bao danh: ";
				string sobd;
				getline(cin, sobd);
				process.TimKiemSoBaoDanh(sobd);
				cout << "\nEnter de quay lai Menu" << endl;
				break;
			}
			case '3':
			{
				cout << "Ban da chon: Tim kiem theo Ho ten" << endl;
				fflush(stdin);
				cout << "Nhap Ho ten: ";
				string hoten;
				getline(cin, hoten);
				process.TimKiemHoTen(hoten);
				cout << "\nEnter de quay lai Menu" << endl;
				break;
			}
			case '4':
			{
				cout << "Ban da chon: Tim kiem theo diem Toan" << endl;
				fflush(stdin);
				cout << "Nhap diem Toan: ";
				double toan;
				cin >> toan;
				process.TimKiemDiemToan(toan);
				cout << "\nEnter de quay lai Menu" << endl;
				break;
			}
			case '5':
			{
				cout << "Ban da chon: Tim kiem theo diem Ly" << endl;
				fflush(stdin);
				cout << "Nhap diem Ly: ";
				double ly;
				cin >> ly;
				process.TimKiemDiemLy(ly);
				cout << "\nEnter de quay lai Menu" << endl;
				break;
			}
			case '6':
			{
				cout << "Ban da chon: Tim kiem theo diem Hoa" << endl;
				fflush(stdin);
				cout << "Nhap diem Hoa: ";
				double hoa;
				cin >> hoa;
				process.TimKiemDiemHoa(hoa);
				cout << "\nEnter de quay lai Menu" << endl;
				break;
			}
			case '7':
				cout << "Ban chon Quay lai Menu chinh!";
				system("pause>null");
				break;
			default:
				cout << "Nhap sai! Moi ban nhap lai." << endl;
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
			menu.MenuSapXepSinhVien();
			char choice3;
			cin >> choice3;
			// Lựa chọn Menu con Sắp xếp sinh viên
			switch (choice3)
			{
			case '1':
			{
				cout << "Ban da chon: Sap xep theo So bao danh" << endl;
				process.SapXepSoBaoDanh();
				cout << "\nEnter de quay lai Menu" << endl;
				break;
			}
			case '2':
			{
				cout << "Ban da chon: Sap xep theo Anphabe" << endl;
				process.SapXepAnphabe();
				cout << "\nEnter de quay lai Menu" << endl;
				break;
			}
			case '3':
			{
				cout << "Ban da chon: Sap xep theo diem Tong" << endl;
				process.SapXepDiemTong();
				cout << "\nEnter de quay lai Menu" << endl;
				break;
			}
			case '4':
				cout << "Ban chon Quay lai Menu chinh!";
				system("pause>null");
				break;
			default:
				cout << "Nhap sai! Moi ban nhap lai." << endl;
				system("pause>null");
				break;
			}
			system("pause>null");
			break;
		}
		// Case 4 Menu chính: Xuất Sinh viên ra File
		case '4':
		{
			cout << "Ban chon: Xuat sinh vien ra file" << endl;
			string fileName;
			fflush(stdin);
			cout << "Xuat ra File (VD: sinhvien.output): ";
			getline(cin, fileName);
			process.XuatSinhVienRaFile(fileName);
			cout << "\nDanh sach sinh vien da duoc xuat ra file" << endl;
			system("pause>null");
			break;
		}
		// Case 5 Menu chính: Thống kê sinh viên
		case '5':
		{
			process.ThongKeTatCa();
			cout << "\nEnter de quay lai Menu" << endl;
			system("pause>null");
			break;
		}
		// Case 6 Menu chính
		case '6':
		{
			exit(0);
			break;
		}
		// default Menu chính
		default:
			cout << "Nhap sai! Moi ban nhap lai." << endl;
			system("pause>null");
			break;
		}

	} while (true);

	system("pause");
	return 0;
}