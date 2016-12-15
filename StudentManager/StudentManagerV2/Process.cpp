#include "Process.h"
#include "SinhVien.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

SinhVien sinhvien[100];
int index = 0;
Process process;
SinhVien sv;

// Phương thức kiểm tra một Sinh Viên đã tồn tại hay chưa
bool Process::KiemTraSinhVien(string sobaodanh, int &vitri) {
	bool KiemTra = false;
	for (int i = 0; i < index; i++) {
		if (sobaodanh == sinhvien[i].getSBD())
		{
			vitri = i;
			KiemTra = true;
			break;
		}
	}
	return KiemTra;
}
// Phương thức kiểm tra Số báo danh đã tồn tại hay chưa
bool Process::KiemTraSoBaoDanh(string sobaodanh) {
	bool KiemTra = false;
	for (int i = 0; i < index; i++) {
		KiemTra = false;
		//cout << sobaodanh;
		cout << sinhvien[i].getSBD();
		if (sobaodanh == sinhvien[i].getSBD()) {
			KiemTra = true;
			break;
		}
	}
	return KiemTra;
}
// Phương thức kiểm tra Điểm tổng đã tồn tại hay chưa
bool Process::KiemTraTongDiem(double tongdiem) {
	bool KiemTra = false;
	for (int i = 0; i < index; i++)
	{
		if (tongdiem == sinhvien[i].TongDiem())
			KiemTra = true;
	}
	return KiemTra;
}
// Phương thức kiểm tra điểm toán đã tồn tại hay chưa
bool Process::KiemTraDiemToan(double diemtoan) {
	bool KiemTra = false;
	for (int i = 0; i < index; i++)
	{
		if (diemtoan == sinhvien[i].getToan())
			KiemTra = true;
	}
	return KiemTra;
}
// Phương thức kiểm tra điểm hóa đã tồn tại hay chưa
bool Process::KiemTraDiemHoa(double diemhoa){
	bool KiemTra = false;
	for (int i = 0; i < index; i++)
	{
		if (diemhoa == sinhvien[i].getHoa())
			KiemTra = true;
	}
	return KiemTra;
}
// Phương thức kiểm tra điểm lý đã tồn tại hay chưa
bool Process::KiemTraDiemLy(double diemly){
	bool KiemTra = false;
	for (int i = 0; i < index; i++)
	{
		if (diemly == sinhvien[i].getLy())
			KiemTra = true;
	}
	return KiemTra;
}
// Phương thức kiểm tra Họ tên đã tồn tại hay chưa
bool Process::KiemTraHoTen(string hoten){
	bool KiemTra = false;
	for (int i = 0; i < index; i++)
	{
		if (hoten == sinhvien[i].getHoTen())
			KiemTra = true;
	}
	return KiemTra;
}
// Phương thức tìm kiếm theo Số báo danh
void Process::TimKiemSoBaoDanh(string sobaodanh) {
	bool KiemTra;
	KiemTra = KiemTraSoBaoDanh(sobaodanh);
	cout << setw(20) << "HoTen" << setw(10) << "SBD" << setw(15) << "DiaChi" << setw(15) << "GioiTinh" << setw(10) << "Toan" << setw(10) << "Ly" << setw(10) << "Hoa" << setw(15) << "TongDiem" << endl;
	if (KiemTra) {
		for (int i = 0; i < index; i++) {
			if (sobaodanh == sinhvien[i].getSBD())
				sinhvien[i].XuatSinhVien();
		}
	}
	else { cout << "\nSo bao danh: " << sobaodanh << " khong ton tai"; }
}
// Phương thức tìm kiếm theo điểm tổng
void Process::TimKiemTongDiem(double tongdiem) {
	bool kiemtra;
	kiemtra = KiemTraTongDiem(tongdiem);
	cout << setw(20) << "HoTen" << setw(10) << "SBD" << setw(15) << "DiaChi" << setw(15) << "GioiTinh" << setw(10) << "Toan" << setw(10) << "Ly" << setw(10) << "Hoa" << setw(15) << "TongDiem" << endl;
	if (kiemtra) {
		for (int i = 0; i < index; i++) {
			if (tongdiem == sinhvien[i].TongDiem())
				sinhvien[i].XuatSinhVien();
		}
	}
	else { cout << "\nDiem tong: " << tongdiem << " khong ton tai"; }
}
// Phương thức tìm kiếm theo Họ tên
void Process::TimKiemHoTen(string hoten) {
	bool kiemtra;
	kiemtra = KiemTraHoTen(hoten);
	cout << setw(20) << "HoTen" << setw(10) << "SBD" << setw(15) << "DiaChi" << setw(15) << "GioiTinh" << setw(10) << "Toan" << setw(10) << "Ly" << setw(10) << "Hoa" << setw(15) << "TongDiem" << endl;
	if (kiemtra) {
		for (int i = 0; i < index; i++) {
			if (hoten == sinhvien[i].getHoTen())
				sinhvien[i].XuatSinhVien();
		}
	}
	else { cout << "Sinh vien: " << hoten << " khong ton tai" << endl; }
}
// Phương thức tìm kiếm theo Điểm toán
void Process::TimKiemDiemToan(double diemtoan) {
	bool kiemtra;
	kiemtra = KiemTraDiemToan(diemtoan);
	cout << setw(20) << "HoTen" << setw(10) << "SBD" << setw(15) << "DiaChi" << setw(15) << "GioiTinh" << setw(10) << "Toan" << setw(10) << "Ly" << setw(10) << "Hoa" << setw(15) << "TongDiem" << endl;
	if (kiemtra) {
		for (int i = 0; i < index; i++) {
			if (diemtoan == sinhvien[i].getToan())
				sinhvien[i].XuatSinhVien();
		}
	}
	else { cout << "\nSV co diem Toan: " << diemtoan << " khong ton tai"; }
}
// Phương thức tìm kiếm theo Điểm lý
void Process::TimKiemDiemLy(double diemly) {
	bool kiemtra;
	kiemtra = KiemTraDiemToan(diemly);
	cout << setw(20) << "HoTen" << setw(10) << "SBD" << setw(15) << "DiaChi" << setw(15) << "GioiTinh" << setw(10) << "Toan" << setw(10) << "Ly" << setw(10) << "Hoa" << setw(15) << "TongDiem" << endl;
	if (kiemtra) {
		for (int i = 0; i < index; i++) {
			if (diemly == sinhvien[i].getLy())
				sinhvien[i].XuatSinhVien();
		}
	}
	else { cout << "\nSV co diem Ly: " << diemly << " khong ton tai"; }
}
// Phương thức tìm kiếm theo Điểm hóa
void Process::TimKiemDiemHoa(double diemhoa) {
	bool kiemtra;
	kiemtra = KiemTraDiemToan(diemhoa);
	cout << setw(20) << "HoTen" << setw(10) << "SBD" << setw(15) << "DiaChi" << setw(15) << "GioiTinh" << setw(10) << "Toan" << setw(10) << "Ly" << setw(10) << "Hoa" << setw(15) << "TongDiem" << endl;
	if (kiemtra) {
		for (int i = 0; i < index; i++) {
			if (diemhoa == sinhvien[i].getHoa())
				sinhvien[i].XuatSinhVien();
		}
	}
	else { cout << "\nSV co diem Hoa: " << diemhoa << " khong ton tai"; }
}
// Phương thức sắp xếp theo Số báo danh
void Process::SapXepSoBaoDanh() {
	int i, j;
	for (i = 0; i < index; i++) {
		for (j = index - 1; j > i; j--) {
			if (sinhvien[j].getSBD() < sinhvien[j - 1].getSBD()) {
				SinhVien temp = sinhvien[j];
				sinhvien[j] = sinhvien[j - 1];
				sinhvien[j - 1] = temp;
			}
		}
	}
	cout << setw(20) << "HoTen" << setw(10) << "SBD" << setw(15) << "DiaChi" << setw(15) << "GioiTinh" << setw(10) << "Toan" << setw(10) << "Ly" << setw(10) << "Hoa" << setw(15) << "TongDiem" << endl;
	for (int i = 0; i < index; i++) {
		sinhvien[i].XuatSinhVien();
	}
}
// Phương thức sắp xếp theo Anphabe
void Process::SapXepAnphabe() {
	int i, j;
	for (i = 0; i < index; i++) {
		for (j = index - 1; j > i; j--) {
			if (sinhvien[j].getHoTen() < sinhvien[j - 1].getHoTen()) {
				SinhVien temp = sinhvien[j];
				sinhvien[j] = sinhvien[j - 1];
				sinhvien[j - 1] = temp;
			}
		}
	}
	cout << setw(20) << "HoTen" << setw(10) << "SBD" << setw(15) << "DiaChi" << setw(15) << "GioiTinh" << setw(10) << "Toan" << setw(10) << "Ly" << setw(10) << "Hoa" << setw(15) << "TongDiem" << endl;
	for (int i = 0; i < index; i++) {
		sinhvien[i].XuatSinhVien();
	}
}
// Phương thức sắp xếp theo Điểm tổng
void Process::SapXepDiemTong() {
	int i, j;
	for (i = 0; i < index; i++) {
		for (j = index - 1; j > i; j--) {
			if (sinhvien[j].TongDiem() < sinhvien[j - 1].TongDiem()) {
				SinhVien temp = sinhvien[j];
				sinhvien[j] = sinhvien[j - 1];
				sinhvien[j - 1] = temp;
			}
		}
	}
	cout << setw(20) << "HoTen" << setw(10) << "SBD" << setw(15) << "DiaChi" << setw(15) << "GioiTinh" << setw(10) << "Toan" << setw(10) << "Ly" << setw(10) << "Hoa" << setw(15) << "TongDiem" << endl;
	for (int i = 0; i < index; i++) {
		sinhvien[i].XuatSinhVien();
	}
}
// Các Phương thức khác
void Process::ThemSinhvien(int n) {
	for (int i = 0; i < n; i++)
	{
		SinhVien sv;
		sv.NhapSinhVien();
		sinhvien[index] = sv;
		index++;
	}
}
void Process::SuaSinhVien(string sobaodanh) {
	int vitri;
	bool KiemTra;
	KiemTra = KiemTraSinhVien(sobaodanh, vitri);
	if (KiemTra)
	{
		TimKiemSoBaoDanh(sobaodanh);
		sinhvien[vitri].NhapSinhVien();
		cout << "\nSua Thanh Cong!";
	}
	else
		cout << "So bao danh: " << sobaodanh << " khong ton tai" << endl;

}

void Process::XoaSinhVien(string sobaodanh) {
	int vitri;
	bool KiemTra;
	KiemTra = KiemTraSinhVien(sobaodanh, vitri);
	if (KiemTra)
	{
		for (int i = vitri; i < index - 1; i++)
		{
			sinhvien[i] = sinhvien[i + 1];
		}
		index--;
		cout << "\nXoa Thanh Cong!";
	}
	else {
		cout << "So bao danh: " << sobaodanh << " khong ton tai" << endl;
	}
}
// Phương thức Thống kế, Nhập, Xuất file
void Process::ThongKeTatCa() {
	cout << "\nTHONG KE SINH VIEN\n";
	int tsl = 0, nhohon15 = 0, _15den20 = 0, _20den25 = 0, lonhon25 = 0;
	cout << setw(20) << "HoTen" << setw(10) << "SBD" << setw(15) << "DiaChi" << setw(15) << "GioiTinh" << setw(10) << "Toan" << setw(10) << "Ly" << setw(10) << "Hoa" << setw(15) << "TongDiem" << endl;
	for (int i = 0; i < index; i++)
	{
		tsl++;
		if (sinhvien[i].TongDiem() < 15)
		{
			nhohon15++;
		}
		if (sinhvien[i].TongDiem() >= 15 && sinhvien[i].TongDiem() <= 20)
		{
			_15den20++;
		}
		if (sinhvien[i].TongDiem() > 20 && sinhvien[i].TongDiem() <= 25)
		{
			_20den25++;
		}
		if (sinhvien[i].TongDiem() > 25)
		{
			lonhon25++;
		}
		sinhvien[i].XuatSinhVien();
	}
	cout << "\nThong Ke Nhanh";
	cout << "\nTong Sinh Vien: " << tsl << " Sinh vien";
	cout << "\nDiem < 15:\t" << nhohon15 << " Sinh vien";
	cout << "\nDiem 15->20:\t" << _15den20 << " Sinh vien";
	cout << "\nDiem 21->25:\t" << _20den25 << " Sinh vien";
	cout << "\nDiem > 25:\t" << lonhon25 << " Sinh vien";
}
void Process::XuatSinhVienRaFile() {
	fstream f;
	string fileName;
	fflush(stdin);
	cout << "Xuat Sinh vien ra File: ";
	getline(cin, fileName);
	f.open(fileName, ios::app); // ios::app
	for (int i = 0; i < index; i++)
		f << sinhvien[i].getHoTen() << "\t" << sinhvien[i].getSBD() << "\t" << sinhvien[i].getDiaChi() << "\t" << sinhvien[i].getSex() << "\t" << sinhvien[i].getToan() << "\t" << sinhvien[i].getLy() << "\t" << sinhvien[i].getHoa() << "\t" << sinhvien[i].TongDiem() << endl;
	f.close();
}
void Process::NhapSinhVienTuFile() {
	ifstream f;
	string fileName;
	fflush(stdin);
	cout << "Nhap sinh vien tu File: ";
	getline(cin, fileName);
	string line, ten, sbd, diachi;
	double sex, toan, ly, hoa;
	f.open(fileName);
	while (getline(f, line)) {
		istringstream iss(line);
		if (!(iss >> ten >> sbd >> diachi >> sex >> toan >> ly >> hoa)) { break; }
		cout << endl << ten << "\t" << sbd << "\t" << diachi << "\t" << sex << "\t" << toan << "\t" << ly << "\t" << hoa << endl;
		sinhvien[index].setHoTen(ten);
		sinhvien[index].setSBD(sbd);
		sinhvien[index].setDiaChi(diachi);
		sinhvien[index].setSex(sex);
		sinhvien[index].setToan(toan);
		sinhvien[index].setLy(ly);
		sinhvien[index].setHoa(hoa);
		index++;
	}
	f.close();
}