#include "SinhVien.h"
#include "Process.h"
#include <iostream>
using namespace std;

void SinhVien::NhapSinhVien() {
	fflush(stdin);
	cout << "\nNhap Ho Ten: ";
	getline(cin, HoTen);

	Process process;
	do {
		cout << "\nNhap So bao danh: ";
		fflush(stdin);
		getline(cin, SBD);
		if (process.KiemTraSoBaoDanh(SBD) == true)
			cout << "So bao danh " << "'" << SBD << "'" << "da ton tai!" << endl;
	} while (process.KiemTraSoBaoDanh(SBD) == true);

	cout << "\nNhap dia chi: ";
	getline(cin, DiaChi);

	cout << "\nNhap Gioi Tinh";
	cout << "\n1. Nam";
	cout << "\n2. Nu";
	cout << "\n3. Khac";

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
void SinhVien::XuatSinhVien() {
	if (Sex == 1)
		GioiTinh = "Nam";
	else if (Sex == 2)
		GioiTinh = "Nu";
	else
		GioiTinh = "Khac";
	cout << setw(20) << HoTen << setw(10) << SBD << setw(15) << DiaChi << setw(15) << GioiTinh << setw(10) << Toan << setw(10) << Ly << setw(10) << Hoa << setw(15) << TongDiem() << endl;
}
double SinhVien::TongDiem() {
	return (Toan + Ly + Hoa);
}
void SinhVien::setHoTen(string hoten) {
	HoTen = hoten;
}
string SinhVien::getHoTen() {
	return HoTen;
}
void SinhVien::setSBD(string sbd) {
	SBD = sbd;
}
string SinhVien::getSBD() {
	return SBD;
}
void SinhVien::setDiaChi(string diachi) {
	DiaChi = diachi;
}
string SinhVien::getDiaChi() {
	return DiaChi;
}
void SinhVien::setSex(double sex) {
	Sex = sex;
}
double SinhVien::getSex() {
	return Sex;
}
void SinhVien::setToan(double toan) {
	Toan = toan;
}
double SinhVien::getToan() {
	return Toan;
}
void SinhVien::setLy(double ly) {
	Ly = ly;
}
double SinhVien::getLy() {
	return Ly;
}
void SinhVien::setHoa(double hoa) {
	Hoa = hoa;
}
double SinhVien::getHoa() {
	return Hoa;
}
