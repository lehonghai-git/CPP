#pragma warning(disable:4996)
#include <stdio.h>
#include <iostream>
#include "view.h"
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

struct Student
{
	string HoTen, SBD, DiaChi, GioiTinh;
	float Toan, Ly, Hoa;
};


void NhapSinhVien(Student *sv, int n);
void XuatSinhVien(Student *sv, int n);
void XoaSinhVien(Student *sv, string sobd);
void SuaSinhVien(Student *sv, string sobd);
void ThongKeSinhVien(Student *sv);

void TimKiemSoBaoDanh(Student *sv, string sobd);
void TimKiemHoTen(Student *sv, string hoten);
void TimKiemTongDiem(Student *sv, float diemtong);
void TimKiemDiemToan(Student *sv, float diemtoan);
void TimKiemDiemLy(Student *sv, float diemly);
void TimKiemDiemHoa(Student *sv, float diemhoa);

void SapXepSoBaoDanh(Student *sv);
void SapXepAnphabe(Student *sv);
void SapXepDiemTong(Student *sv);

void XuatSinhVienRaFile(Student *sv, string fileName);
//void NhapSinhvienTuFile(Student *sv, string fileName);
void NhapSinhvienTuFile(string fileName);
int DemSoSinhVienTrongFile(string fileName);

bool KiemTraSinhVien(Student *sv, string sobaodanh, int &vitri);
bool KiemTraSoBaoDanh(Student *sv, string sobd);
bool KiemTraHoten(Student *sv, string hoten);
bool KiemTraTongDiem(Student *sv, float diemtong);
bool KiemTraDiemToan(Student *sv, float diemtoan);
bool KiemTraDiemLy(Student *sv, float diemly);
bool KiemTraDiemHoa(Student *sv, float diemhoa);

View view;
int index = 0;
Student *ptr;

int main()
{
	do {
		view.mainView();
		char choice;
		cin >> choice;

		// Lựa chọn Menu chính
		switch (choice)
		{
			// Case 1 Menu chính: Thêm sửa xóa sinh viên
		case '1':
		{
			// Menu con: Thêm, Sửa, Xóa Sinh viên
			view.updateView();
			char choice1;
			cin >> choice1;
			// Lựa chọn Menu con: Thêm sửa xóa
			switch (choice1)
			{
			case '1':
			{
				int soluong;
				Student svien;
				printf("NHAP SINH VIEN TU BAN PHIM\nNhap so luong: ");
				scanf("%d", &soluong);
				Student *sv = new Student[soluong];
				ptr = sv;
				NhapSinhVien(sv, soluong);
				sv = NULL;
				delete[]sv;
				break;
			}
			case '2':
			{
				string filename;
				printf("\nNHAP SINH VIEN TU FILE\nNhap ten file: ");
				fflush(stdin);
				getline(cin, filename);
				NhapSinhvienTuFile(filename);
				printf("\nNhap xong!");
				break;
			}
			case '3':
			{
				string msv;
				printf("\nSUA SINH VIEN\nNhap ma sv: ");
				fflush(stdin);
				getline(cin, msv);
				TimKiemSoBaoDanh(ptr, msv);
				SuaSinhVien(ptr, msv);
				printf("\nSua xong!");
				break;
			}
			case '4':
			{
				fflush(stdin);
				printf("\nXOA SINH VIEN\nNhap so bao danh: ");
				string sobd;
				getline(cin, sobd);
				XoaSinhVien(ptr, sobd);
				break;
			}
			case '5':
				printf("\nQuay lai Menu chinh!");
				system("pause>null");
				break;
			default:
				printf("Nhap sai! Moi nhap lai.");
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
			view.searchView();
			char choice2;
			cin >> choice2;
			// Lựa chọn Menu con Tìm kiếm sinh viên
			switch (choice2)
			{
			case '1':
			{
				float tongdiem;
				fflush(stdin);
				printf("TIM KIEM THEO DIEM TONG\nNhap Tong diem: ");
				scanf("%f", &tongdiem);
				TimKiemTongDiem(ptr, tongdiem);
				printf("\nEnter de quay lai");
				break;
			}
			case '2':
			{
				fflush(stdin);
				printf("\nTIM KIEM THEO SO BAO DANH\nNhap So bao danh: ");
				string sobd;
				getline(cin, sobd);
				TimKiemSoBaoDanh(ptr, sobd);
				printf("\nEnter de quay lai");
				break;
			}
			case '3':
			{
				fflush(stdin);
				printf("\nTIM KIEM THEO HO TEN\nNhap Ho ten: ");
				string hoten;
				getline(cin, hoten);
				TimKiemHoTen(ptr, hoten);
				printf("\nEnter de quay lai");
				break;
			}
			case '4':
			{
				fflush(stdin);
				printf("\nTIM KIEM THEO DIEM TOAN\nNhap diem Toan: ");
				float toan;
				scanf("%f", &toan);
				TimKiemDiemToan(ptr, toan);
				printf("\nEnter de quay lai");
				break;
			}
			case '5':
			{
				fflush(stdin);
				printf("\nTIM KIEM THEO DIEM LY\nNhap diem Ly: ");
				float ly;
				scanf("%f", &ly);
				TimKiemDiemLy(ptr, ly);
				printf("\nEnter de quay lai");
				break;
			}
			case '6':
			{
				fflush(stdin);
				printf("\nTIM KIEM THEO DIEM HOA\nNhap diem Hoa: ");
				float hoa;
				scanf("%f", &hoa);
				TimKiemDiemHoa(ptr, hoa);
				printf("\nEnter de quay lai");
				break;
			}
			case '7':
				printf("Ban chon Quay lai Menu chinh!");
				system("pause>null");
				break;
			default:
				printf("Nhap sai! Moi nhap lai.");
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
			view.sortView();
			char choice3;
			cin >> choice3;
			// Lựa chọn Menu con Sắp xếp sinh viên
			switch (choice3)
			{
			case '1':
			{
				cout << "Ban da chon: Sap xep theo So bao danh" << endl;
				SapXepSoBaoDanh(ptr);
				cout << "\nEnter de quay lai Menu" << endl;
				break;
			}
			case '2':
			{
				cout << "Ban da chon: Sap xep theo Anphabe" << endl;
				SapXepAnphabe(ptr);
				cout << "\nEnter de quay lai Menu" << endl;
				break;
			}
			case '3':
			{
				cout << "Ban da chon: Sap xep theo diem Tong" << endl;
				SapXepDiemTong(ptr);
				cout << "\nEnter de quay lai Menu" << endl;
				break;
			}
			case '4':
				printf("Ban chon Quay lai Menu chinh!");
				system("pause>null");
				break;
			default:
				printf("\nNhap sai! Moi nhap lai");
				system("pause>null");
				break;
			}
			system("pause>null");
			break;
		}
		// Case 4 Menu chính: Xuất Sinh viên ra File
		case '4':
		{
			string fileName;
			printf("\nXUAT SINH VIEN RA FILE\nTen file muon xuat (VD: sinhvien.output): ");
			fflush(stdin);
			getline(cin, fileName);
			XuatSinhVienRaFile(ptr, fileName);
			printf("\nDanh sach sinh vien da duoc xuat ra file");
			system("pause>null");
			break;
		}
		// Case 5 Menu chính: Thống kê sinh viên
		case '5':
		{
			printf("\nTHONG KE SINH VIEN\n");
			XuatSinhVien(ptr, index);
			ThongKeSinhVien(ptr);
			printf("\nEnter de quay lai");
			system("pause>null");
			break;
		}
		// Case 6 Menu chính
		case '6':
		{
			ptr = NULL;
			delete[] ptr;
			exit(0);
			break;
		}
		// default Menu chính
		default:
			printf("\nNhap sai! Moi ban nhap lai.");
			system("pause>null");
			break;
		}

	} while (true);

}

void NhapSinhVien(Student *sv, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap sinh vien thu " << i + 1 << endl;
		fflush(stdin);
		cout << "\nNhap ten: ";
		getline(cin, sv[i].HoTen);
		cout << "\nNhap sbd: ";
		getline(cin, sv[i].SBD);
		cout << "\nNhap dia chi: ";
		getline(cin, sv[i].DiaChi);
		cout << "\nNhap gioi tinh: ";
		getline(cin, sv[i].GioiTinh);
		cout << "\nNhap diem Toan: ";
		cin >> sv[i].Toan;
		cout << "\nNhap diem Ly: ";
		cin >> sv[i].Ly;
		cout << "\nNhap diem Hoa: ";
		cin >> sv[i].Hoa;
		cout << "\nNhap thanh cong" << endl;
		index++;
	}
}

void XuatSinhVien(Student *sv, int n)
{
	cout << setw(20) << "HoTen" << setw(10) << "SBD" << setw(15) << "DiaChi" << setw(15) << "GioiTinh" << setw(10) << "Toan" << setw(10) << "Ly" << setw(10) << "Hoa" << setw(15) << "TongDiem" << endl;
	for (int i = 0; i < n; i++)
	{
		float TongDiem = sv[i].Toan + sv[i].Hoa + sv[i].Ly;
		cout << setw(20) << sv[i].HoTen << setw(10) << sv[i].SBD << setw(15) << sv[i].DiaChi << setw(15) << sv[i].GioiTinh << setw(10) << sv[i].Toan << setw(10) << sv[i].Ly << setw(10) << sv[i].Hoa << setw(15) << TongDiem << endl;
	}
}

bool KiemTraSinhVien(Student *sv, string sobaodanh, int &vitri)
{
	bool KiemTra = false;
	for (int i = 0; i < index; i++) {
		if (sobaodanh == sv[i].SBD)
		{
			vitri = i;
			KiemTra = true;
			break;
		}
	}
	return KiemTra;
}

bool KiemTraSoBaoDanh(Student *sv, string sobd)
{
	bool KiemTra = false;
	for (int i = 0; i < index; i++) {
		KiemTra = false;
		if (sobd == sv[i].SBD) {
			KiemTra = true;
			break;
		}
	}
	return KiemTra;
}

bool KiemTraTongDiem(Student *sv, float diemtong)
{
	bool KiemTra = false;
	for (int i = 0; i < index; i++)
	{
		if (diemtong == sv[i].Toan + sv[i].Ly + sv[i].Hoa)
			KiemTra = true;
	}
	return KiemTra;
}

bool KiemTraHoten(Student *sv, string hoten)
{
	bool KiemTra = false;
	for (int i = 0; i < index; i++)
	{
		if (hoten == sv[i].HoTen)
			KiemTra = true;
	}
	return KiemTra;
}

bool KiemTraDiemToan(Student *sv, float diemtoan)
{
	bool KiemTra = false;
	for (int i = 0; i < index; i++)
	{
		if (diemtoan == sv[i].Toan)
			KiemTra = true;
	}
	return KiemTra;
}

bool KiemTraDiemLy(Student *sv, float diemly)
{
	bool KiemTra = false;
	for (int i = 0; i < index; i++)
	{
		if (diemly == sv[i].Ly)
			KiemTra = true;
	}
	return KiemTra;
}

bool KiemTraDiemHoa(Student *sv, float diemhoa)
{
	bool KiemTra = false;
	for (int i = 0; i < index; i++)
	{
		if (diemhoa == sv[i].Hoa)
			KiemTra = true;
	}
	return KiemTra;
}

void XoaSinhVien(Student *sv, string sobd)
{
	int vitri;
	bool KiemTra;
	KiemTra = KiemTraSinhVien(sv, sobd, vitri);
	if (KiemTra)
	{
		for (int i = vitri; i < index - 1; i++)
		{
			sv[i] = sv[i + 1];
		}
		index--;
	}
	else {
		cout << "So bao danh: " << sobd << " khong ton tai" << endl;
	}
}

void ThongKeSinhVien(Student *sv)
{
	int tsl = 0, nhohon15 = 0, _15den20 = 0, _20den25 = 0, lonhon25 = 0;
	for (int i = 0; i < index; i++)
	{
		tsl++;
		if (sv[i].Toan + sv[i].Ly + sv[i].Hoa < 15)
			nhohon15++;
		if (sv[i].Toan + sv[i].Ly + sv[i].Hoa >= 15 && sv[i].Toan + sv[i].Ly + sv[i].Hoa <= 20)
			_15den20++;
		if (sv[i].Toan + sv[i].Ly + sv[i].Hoa > 20 && sv[i].Toan + sv[i].Ly + sv[i].Hoa <= 25)
			_20den25++;
		if (sv[i].Toan + sv[i].Ly + sv[i].Hoa > 25)
			lonhon25++;
	}
	cout << "\nThong Ke Nhanh";
	cout << "\nTong Sinh Vien: " << tsl << " Sinh vien";
	cout << "\nDiem < 15:\t" << nhohon15 << " Sinh vien";
	cout << "\nDiem 15->20:\t" << _15den20 << " Sinh vien";
	cout << "\nDiem 21->25:\t" << _20den25 << " Sinh vien";
	cout << "\nDiem > 25:\t" << lonhon25 << " Sinh vien";
}

void SuaSinhVien(Student *sv, string sobd)
{
	XoaSinhVien(sv, sobd);
	NhapSinhVien(sv, 1);
}

void TimKiemSoBaoDanh(Student *sv, string sobd)
{
	bool KiemTra;
	KiemTra = KiemTraSoBaoDanh(sv, sobd);
	cout << setw(20) << "HoTen" << setw(10) << "SBD" << setw(15) << "DiaChi" << setw(15) << "GioiTinh" << setw(10) << "Toan" << setw(10) << "Ly" << setw(10) << "Hoa" << setw(15) << "TongDiem" << endl;
	if (KiemTra) {
		for (int i = 0; i < index; i++) {
			if (sobd == sv[i].SBD){
				float TongDiem = sv[i].Toan + sv[i].Hoa + sv[i].Ly;
				cout << setw(20) << sv[i].HoTen << setw(10) << sv[i].SBD << setw(15) << sv[i].DiaChi << setw(15) << sv[i].GioiTinh << setw(10) << sv[i].Toan << setw(10) << sv[i].Ly << setw(10) << sv[i].Hoa << setw(15) << TongDiem << endl;

			}
		}
	}
	else { cout << "\nSo bao danh: " << sobd << " khong ton tai"; }
}

void TimKiemTongDiem(Student *sv, float diemtong)
{
	bool kiemtra;
	kiemtra = KiemTraTongDiem(sv, diemtong);
	cout << setw(20) << "HoTen" << setw(10) << "SBD" << setw(15) << "DiaChi" << setw(15) << "GioiTinh" << setw(10) << "Toan" << setw(10) << "Ly" << setw(10) << "Hoa" << setw(15) << "TongDiem" << endl;
	if (kiemtra) {
		for (int i = 0; i < index; i++) {
			if (diemtong == sv[i].Toan + sv[i].Ly + sv[i].Hoa){
				float TongDiem = sv[i].Toan + sv[i].Hoa + sv[i].Ly;
				cout << setw(20) << sv[i].HoTen << setw(10) << sv[i].SBD << setw(15) << sv[i].DiaChi << setw(15) << sv[i].GioiTinh << setw(10) << sv[i].Toan << setw(10) << sv[i].Ly << setw(10) << sv[i].Hoa << setw(15) << TongDiem << endl;
			}
		}
	}
	else { cout << "\nDiem tong: " << diemtong << " khong ton tai"; }
}

void TimKiemHoTen(Student *sv, string hoten)
{
	bool kiemtra;
	kiemtra = KiemTraHoten(sv, hoten);
	cout << setw(20) << "HoTen" << setw(10) << "SBD" << setw(15) << "DiaChi" << setw(15) << "GioiTinh" << setw(10) << "Toan" << setw(10) << "Ly" << setw(10) << "Hoa" << setw(15) << "TongDiem" << endl;
	if (kiemtra) {
		for (int i = 0; i < index; i++) {
			if (hoten == sv[i].HoTen){
				float TongDiem = sv[i].Toan + sv[i].Hoa + sv[i].Ly;
				cout << setw(20) << sv[i].HoTen << setw(10) << sv[i].SBD << setw(15) << sv[i].DiaChi << setw(15) << sv[i].GioiTinh << setw(10) << sv[i].Toan << setw(10) << sv[i].Ly << setw(10) << sv[i].Hoa << setw(15) << TongDiem << endl;
			}
		}
	}
	else { cout << "\nSinh vien co ten: " << hoten << " khong ton tai"; }
}

void TimKiemDiemToan(Student *sv, float diemtoan)
{
	bool kiemtra;
	kiemtra = KiemTraDiemToan(sv, diemtoan);
	cout << setw(20) << "HoTen" << setw(10) << "SBD" << setw(15) << "DiaChi" << setw(15) << "GioiTinh" << setw(10) << "Toan" << setw(10) << "Ly" << setw(10) << "Hoa" << setw(15) << "TongDiem" << endl;
	if (kiemtra) {
		for (int i = 0; i < index; i++) {
			if (diemtoan == sv[i].Toan) {
				float TongDiem = sv[i].Toan + sv[i].Hoa + sv[i].Ly;
				cout << setw(20) << sv[i].HoTen << setw(10) << sv[i].SBD << setw(15) << sv[i].DiaChi << setw(15) << sv[i].GioiTinh << setw(10) << sv[i].Toan << setw(10) << sv[i].Ly << setw(10) << sv[i].Hoa << setw(15) << TongDiem << endl;
			}
		}
	}
	else { cout << "\nSV co diem Toan: " << diemtoan << " khong ton tai"; }
}

void TimKiemDiemLy(Student *sv, float diemly)
{
	bool kiemtra;
	kiemtra = KiemTraDiemLy(sv, diemly);
	cout << setw(20) << "HoTen" << setw(10) << "SBD" << setw(15) << "DiaChi" << setw(15) << "GioiTinh" << setw(10) << "Toan" << setw(10) << "Ly" << setw(10) << "Hoa" << setw(15) << "TongDiem" << endl;
	if (kiemtra) {
		for (int i = 0; i < index; i++) {
			if (diemly == sv[i].Ly){
				float TongDiem = sv[i].Toan + sv[i].Hoa + sv[i].Ly;
				cout << setw(20) << sv[i].HoTen << setw(10) << sv[i].SBD << setw(15) << sv[i].DiaChi << setw(15) << sv[i].GioiTinh << setw(10) << sv[i].Toan << setw(10) << sv[i].Ly << setw(10) << sv[i].Hoa << setw(15) << TongDiem << endl;
			}
		}
	}
	else { cout << "\nSV co diem Ly: " << diemly << " khong ton tai"; }
}

void TimKiemDiemHoa(Student *sv, float diemhoa)
{
	bool kiemtra;
	kiemtra = KiemTraDiemHoa(sv, diemhoa);
	cout << setw(20) << "HoTen" << setw(10) << "SBD" << setw(15) << "DiaChi" << setw(15) << "GioiTinh" << setw(10) << "Toan" << setw(10) << "Ly" << setw(10) << "Hoa" << setw(15) << "TongDiem" << endl;
	if (kiemtra) {
		for (int i = 0; i < index; i++) {
			if (diemhoa == sv[i].Hoa){
				float TongDiem = sv[i].Toan + sv[i].Hoa + sv[i].Ly;
				cout << setw(20) << sv[i].HoTen << setw(10) << sv[i].SBD << setw(15) << sv[i].DiaChi << setw(15) << sv[i].GioiTinh << setw(10) << sv[i].Toan << setw(10) << sv[i].Ly << setw(10) << sv[i].Hoa << setw(15) << TongDiem << endl;
			}
		}
	}
	else { cout << "\nSV co diem Hoa: " << diemhoa << " khong ton tai"; }
}

void SapXepSoBaoDanh(Student *sv)
{
	int i, j;
	for (i = 0; i < index; i++) {
		for (j = index - 1; j > i; j--) {
			if (sv[j].SBD < sv[j - 1].SBD) {
				Student temp = sv[j];
				sv[j] = sv[j - 1];
				sv[j - 1] = temp;
			}
		}
	}
	cout << setw(20) << "HoTen" << setw(10) << "SBD" << setw(15) << "DiaChi" << setw(15) << "GioiTinh" << setw(10) << "Toan" << setw(10) << "Ly" << setw(10) << "Hoa" << setw(15) << "TongDiem" << endl;
	for (int i = 0; i < index; i++) {
		float TongDiem = sv[i].Toan + sv[i].Hoa + sv[i].Ly;
		cout << setw(20) << sv[i].HoTen << setw(10) << sv[i].SBD << setw(15) << sv[i].DiaChi << setw(15) << sv[i].GioiTinh << setw(10) << sv[i].Toan << setw(10) << sv[i].Ly << setw(10) << sv[i].Hoa << setw(15) << TongDiem << endl;
	}
}

void SapXepAnphabe(Student *sv)
{
	int i, j;
	for (i = 0; i < index; i++) {
		for (j = index - 1; j > i; j--) {
			if (sv[j].HoTen < sv[j - 1].HoTen) {
				Student temp = sv[j];
				sv[j] = sv[j - 1];
				sv[j - 1] = temp;
			}
		}
	}
	cout << setw(20) << "HoTen" << setw(10) << "SBD" << setw(15) << "DiaChi" << setw(15) << "GioiTinh" << setw(10) << "Toan" << setw(10) << "Ly" << setw(10) << "Hoa" << setw(15) << "TongDiem" << endl;
	for (int i = 0; i < index; i++) {
		float TongDiem = sv[i].Toan + sv[i].Hoa + sv[i].Ly;
		cout << setw(20) << sv[i].HoTen << setw(10) << sv[i].SBD << setw(15) << sv[i].DiaChi << setw(15) << sv[i].GioiTinh << setw(10) << sv[i].Toan << setw(10) << sv[i].Ly << setw(10) << sv[i].Hoa << setw(15) << TongDiem << endl;
	}
}

void SapXepDiemTong(Student *sv)
{
	int i, j;
	for (i = 0; i < index; i++) {
		for (j = index - 1; j > i; j--) {
			if (sv[j].Toan + sv[j].Ly + sv[j].Hoa < sv[j - 1].Toan + sv[j - 1].Ly + sv[j - 1].Hoa) {
				Student temp = sv[j];
				sv[j] = sv[j - 1];
				sv[j - 1] = temp;
			}
		}
	}
	cout << setw(20) << "HoTen" << setw(10) << "SBD" << setw(15) << "DiaChi" << setw(15) << "GioiTinh" << setw(10) << "Toan" << setw(10) << "Ly" << setw(10) << "Hoa" << setw(15) << "TongDiem" << endl;
	for (int i = 0; i < index; i++) {
		float TongDiem = sv[i].Toan + sv[i].Hoa + sv[i].Ly;
		cout << setw(20) << sv[i].HoTen << setw(10) << sv[i].SBD << setw(15) << sv[i].DiaChi << setw(15) << sv[i].GioiTinh << setw(10) << sv[i].Toan << setw(10) << sv[i].Ly << setw(10) << sv[i].Hoa << setw(15) << TongDiem << endl;
	}
}

void XuatSinhVienRaFile(Student *sv, string fileName)
{
	fstream f;
	fflush(stdin);
	f.open(fileName, ios::app); // append
	for (int i = 0; i < index; i++)
		f << sv[i].HoTen << "\t" << sv[i].SBD << "\t" << sv[i].DiaChi << "\t" << sv[i].GioiTinh << "\t" << sv[i].Toan << "\t" << sv[i].Ly << "\t" << sv[i].Hoa << "\t" << sv[i].Toan + sv[i].Ly + sv[i].Hoa << endl;
	f.close();
}

//void NhapSinhvienTuFile(Student *sv, string fileName)
void NhapSinhvienTuFile(string fileName)
{
	Student *_ptr2 = new Student[DemSoSinhVienTrongFile(fileName)];
	ifstream f;
	string line, ten, sbd, diachi, gioitinh;
	float toan, ly, hoa;
	f.open(fileName);
	while (getline(f, line)) {
		istringstream iss(line);
		if (!(iss >> ten >> sbd >> diachi >> gioitinh >> toan >> ly >> hoa)) { break; }
		cout << endl << ten << "\t" << sbd << "\t" << diachi << "\t" << gioitinh << "\t" << toan << "\t" << ly << "\t" << hoa << endl;
		
		//ptr = _ptr2;
		_ptr2[index].HoTen = ten;
		_ptr2[index].SBD = sbd;
		_ptr2[index].DiaChi = diachi;
		_ptr2[index].GioiTinh = gioitinh;
		_ptr2[index].Toan = toan;
		_ptr2[index].Ly = ly;
		_ptr2[index].Hoa = hoa;
		index++;

		//if (KiemTraSoBaoDanh(sv, sbd)) {
		//	cout << "Sinh vien " << "'" << ten << "'" << "'" << " co so bao danh " << sbd << "'" << " da bi trung." << endl;
		//	//break;
		//	//goto jump;
		//}
		//else if (toan < 0 || toan > 10 || ly < 0 || ly > 10 || hoa < 0 || hoa > 10) {
		//	cout << "So bao danh " << "'" << sbd << "'" << " co diem thi khong hop le!" << endl;
		//	//break;
		//	//goto jump;
		//}
		//else {
		//	sv[index].HoTen = ten;
		//	sv[index].SBD = sbd;
		//	sv[index].DiaChi = diachi;
		//	sv[index].GioiTinh = gioitinh;
		//	sv[index].Toan = toan;
		//	sv[index].Ly = ly;
		//	sv[index].Hoa = hoa;
		//	index++;
		//}
	}
	ptr = _ptr2;
	f.close();
}

int DemSoSinhVienTrongFile(string fileName)
{
	ifstream f;
	int dem = 0;
	string line, ten, sbd, diachi, gioitinh;
	float toan, ly, hoa;
	f.open(fileName);
	while (getline(f, line)) {
		istringstream iss(line);
		if (!(iss >> ten >> sbd >> diachi >> gioitinh >> toan >> ly >> hoa)) { break; }
		//cout << endl << ten << "\t" << sbd << "\t" << diachi << "\t" << gioitinh << "\t" << toan << "\t" << ly << "\t" << hoa << endl;
		//cout << dem << endl;
		dem++;
	}
	f.close();

	return dem;
}