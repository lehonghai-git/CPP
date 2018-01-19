#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib,"ws2_32.lib")
#include <WinSock2.h>
#include "student.h"
#include "model.h"
#include <iostream>
#include <string>

using namespace std;

void Student::NhapSinhVienv2(string hoten, string sbd, string diachi, int gioitinh, double toan, double ly, double hoa) {
	HoTen = hoten;
	SBD = sbd;
	DiaChi = diachi;
	Sex = gioitinh;
	Toan = toan;
	Ly = ly;
	Hoa = hoa;
}

void Student::NhapSinhVien() {
	fflush(stdin);
	cout << "\nNhap Ho Ten: ";
	getline(cin, HoTen);

	Model process;
	do {
		cout << "\nNhap So bao danh: ";
		fflush(stdin);
		getline(cin, SBD);
		if (process.KiemTraSoBaoDanh(SBD) == true)
			cout << "So bao danh " << "'" << SBD << "'" << "da ton tai!" << endl;
	} while (process.KiemTraSoBaoDanh(SBD) == true);

	cout << "\nNhap dia chi: ";
	getline(cin, DiaChi);

	cout << "\nNhap Gioi Tinh\n1. Nam\n2. Nu\n3. Khac";

	do {
		cout << "\nNhap Gioi tinh (1-3): ";
		cin >> Sex;
		if (Sex < 1 || Sex > 4)
			cout << "\nNhap sai gioi tinh!";

	} while (Sex < 1 || Sex > 3);

	do {
		cout << "\nNhap diem Toan (1-10): ";
		cin >> Toan;
		if (Toan < 0 || Toan > 10)
			cout << "\nDiem Toan khong hop le!";
	} while (Toan < 0 || Toan > 10);

	do {
		cout << "\nNhap diem Ly (1-10): ";
		cin >> Ly;
		if (Ly < 0 || Ly > 10)
			cout << "\nDiem Ly khong hop le!";
	} while (Ly < 0 || Ly > 10);

	do {
		cout << "\nNhap diem Hoa (1-10): ";
		cin >> Hoa;
		if (Hoa < 0 || Hoa > 10)
			cout << "\nDiem Hoa khong hop le!";
	} while (Hoa < 0 || Hoa > 10);
}
void Student::XuatSinhVien() {
	if (Sex == 1)
		GioiTinh = "Nam";
	else if (Sex == 2)
		GioiTinh = "Nu";
	else
		GioiTinh = "Khac";
	cout << setw(20) << HoTen << setw(10) << SBD << setw(15) << DiaChi << setw(15) << GioiTinh << setw(10) << Toan << setw(10) << Ly << setw(10) << Hoa << setw(15) << TongDiem() << endl;
}
double Student::TongDiem() {
	return (Toan + Ly + Hoa);
}
void Student::setHoTen(string hoten) {
	HoTen = hoten;
}
string Student::getHoTen() {
	return HoTen;
}
void Student::setSBD(string sbd) {
	SBD = sbd;
}
string Student::getSBD() {
	return SBD;
}
void Student::setDiaChi(string diachi) {
	DiaChi = diachi;
}
string Student::getDiaChi() {
	return DiaChi;
}
void Student::setSex(double sex) {
	Sex = sex;
}
double Student::getSex() {
	return Sex;
}
void Student::setToan(double toan) {
	Toan = toan;
}
double Student::getToan() {
	return Toan;
}
void Student::setLy(double ly) {
	Ly = ly;
}
double Student::getLy() {
	return Ly;
}
void Student::setHoa(double hoa) {
	Hoa = hoa;
}
double Student::getHoa() {
	return Hoa;
}