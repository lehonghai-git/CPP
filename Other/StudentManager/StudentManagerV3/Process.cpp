#include "Process.h"
#include "SinhVien.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

SinhVien sinhvien[300];
int index = 0;
Process process;
SinhVien sv;

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

bool Process::KiemTraSoBaoDanh(string sobaodanh) {
	bool KiemTra = false;
	for (int i = 0; i < index; i++) {
		KiemTra = false;
		/*cout << sobaodanh;
		cout << sinhvien[i].getSBD();*/
		if (sobaodanh == sinhvien[i].getSBD()) {
			KiemTra = true;
			break;
		}
	}
	return KiemTra;
}

bool Process::KiemTraTongDiem(double tongdiem) {
	bool KiemTra = false;
	for (int i = 0; i < index; i++)
	{
		if (tongdiem == sinhvien[i].TongDiem())
			KiemTra = true;
	}
	return KiemTra;
}

bool Process::KiemTraDiemToan(double diemtoan) {
	bool KiemTra = false;
	for (int i = 0; i < index; i++)
	{
		if (diemtoan == sinhvien[i].getToan())
			KiemTra = true;
	}
	return KiemTra;
}

bool Process::KiemTraDiemHoa(double diemhoa){
	bool KiemTra = false;
	for (int i = 0; i < index; i++)
	{
		if (diemhoa == sinhvien[i].getHoa())
			KiemTra = true;
	}
	return KiemTra;
}

bool Process::KiemTraDiemLy(double diemly){
	bool KiemTra = false;
	for (int i = 0; i < index; i++)
	{
		if (diemly == sinhvien[i].getLy())
			KiemTra = true;
	}
	return KiemTra;
}

bool Process::KiemTraHoTen(string hoten){
	bool KiemTra = false;
	for (int i = 0; i < index; i++)
	{
		if (hoten == sinhvien[i].getHoTen())
			KiemTra = true;
	}
	return KiemTra;
}

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

void Process::ThongKeTatCa() {
	cout << "\nTHONG KE SINH VIEN\n";
	int tsl = 0, nhohon15 = 0, _15den20 = 0, _20den25 = 0, lonhon25 = 0;
	cout << setw(20) << "HoTen" << setw(10) << "SBD" << setw(15) << "DiaChi" << setw(15) << "GioiTinh" << setw(10) << "Toan" << setw(10) << "Ly" << setw(10) << "Hoa" << setw(15) << "TongDiem" << endl;
	for (int i = 0; i < index; i++)
	{
		//sinhvien[index].XuatSinhVien();
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

void Process::XuatSinhVienRaFile(string fileName) {
	fstream f;
	fflush(stdin);
	f.open(fileName, ios::app); // append
	for (int i = 0; i < index; i++)
		f << sinhvien[i].getHoTen() << "\t" << sinhvien[i].getSBD() << "\t" << sinhvien[i].getDiaChi() << "\t" << sinhvien[i].getSex() << "\t" << sinhvien[i].getToan() << "\t" << sinhvien[i].getLy() << "\t" << sinhvien[i].getHoa() << "\t" << sinhvien[i].TongDiem() << endl;
	f.close();
}

void Process::NhapSinhVienTuFile(string input) {
	ifstream f;
	string line, ten, sbd, diachi;
	double sex, toan, ly, hoa;
	f.open(input);
	while (getline(f, line)) {
		istringstream iss(line);
		if (!(iss >> ten >> sbd >> diachi >> sex >> toan >> ly >> hoa)) { break; }
		cout << endl << ten << "\t" << sbd << "\t" << diachi << "\t" << sex << "\t" << toan << "\t" << ly << "\t" << hoa << endl;
		if (KiemTraSoBaoDanh(sbd)) {
			cout << "Sinh vien " << "'" << ten << "'" << "'" << " co so bao danh " << sbd << "'" << " da bi trung." << endl;
			//break;
			//goto jump;
		}
		else if (sex < 1 || sex > 3) {
			cout << "So bao danh " << "'" << sbd << "'" << " co gioi tinh khong hop le!" << endl;
			//break;
			//goto jump;
		}
		else if (toan < 0 || toan > 10 || ly < 0 || ly > 10 || hoa < 0 || hoa > 10) {
			cout << "So bao danh " << "'" << sbd << "'" << " co diem thi khong hop le!" << endl;
			//break;
			//goto jump;
		}
		else {
			sinhvien[index].setHoTen(ten);
			sinhvien[index].setSBD(sbd);
			sinhvien[index].setDiaChi(diachi);
			sinhvien[index].setSex(sex);
			sinhvien[index].setToan(toan);
			sinhvien[index].setLy(ly);
			sinhvien[index].setHoa(hoa);
			index++;
		}
	}
	f.close();
}

string Process::Convert(int i) {
	string result = "";
	stringstream convert;
	convert << i;
	result = convert.str();
	return result;
}

int Process::DemSoFile(string maTruong) {
	int soFile = 0;
	fstream fs;
	for (int i = 0; i < 10; i++) {
		string name = "diemthi/" + maTruong + "-" + Convert(i) + ".input";
		//cout << "ten file da xu ly: " << name << endl;
		fs.open(name, ios::in);
		if (fs.fail()) {
			break;
		}
		else {
			soFile++;
		}
		fs.close();
	}
	//cout << "BKA = " << soFile << endl;
	return soFile;
}

void Process::SuaSinhVienv2(string sobaodanh) {
	int vitri;
	bool KiemTra;
	KiemTra = KiemTraSinhVien(sobaodanh, vitri);
	if (KiemTra)
	{
		// Show thông tin sinh viên cần sửa
		TimKiemSoBaoDanh(sobaodanh);
		string hoten, diachi;
		double sex, toan, ly, hoa;

		fflush(stdin);
		cout << "\nNhap ho ten: ";
		getline(cin, hoten);
		sinhvien[vitri].setHoTen(hoten);

		cout << "\nNhap dia chi: ";
		getline(cin, diachi);
		sinhvien[vitri].setDiaChi(diachi);

		// Giới tính
		cout << "\nNhap Gioi Tinh";
		cout << "\n1. Nam";
		cout << "\n2. Nu";
		cout << "\n3. Khac";
		do {
			cout << "\nNhap Gioi tinh (1-3): ";
			cin >> sex;
			if (sex < 1 || sex > 4)
				cout << "\nNhap sai gioi tinh!";

		} while (sex < 1 || sex > 3);
		sinhvien[vitri].setSex(sex);

		// Toán
		do {
			cout << "\nNhap diem Toan (1-10): ";
			cin >> toan;
			if (toan < 0 || toan > 10)
				cout << "\nDiem Toan khong hop le!";
		} while (toan < 0 || toan > 10);
		sinhvien[vitri].setToan(toan);
		// Lý
		do {
			cout << "\nNhap diem Ly (1-10): ";
			cin >> ly;
			if (ly < 0 || ly > 10)
				cout << "\nDiem Ly khong hop le!";
		} while (ly < 0 || ly > 10);
		sinhvien[vitri].setLy(ly);
		// Hóa
		do {
			cout << "\nNhap diem Hoa (1-10): ";
			cin >> hoa;
			if (hoa < 0 || hoa > 10)
				cout << "\nDiem Hoa khong hop le!";
		} while (hoa < 0 || hoa > 10);
		sinhvien[vitri].setHoa(hoa);
		Sleep(500);
		cout << "\nSua Thanh Cong! Enter de quay lai!" << endl;
	}
	else
		cout << "So bao danh: " << sobaodanh << " khong ton tai" << endl;

}