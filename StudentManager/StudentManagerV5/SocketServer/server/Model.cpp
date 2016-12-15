#include "model.h"
#include "student.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

Student sinhvien[300];
int index = 0;
Model process;
Student sv;

bool Model::KiemTraSinhVien(string sobaodanh, int &vitri) {
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

bool Model::KiemTraSoBaoDanh(string sobaodanh) {
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

bool Model::KiemTraTongDiem(double tongdiem) {
	bool KiemTra = false;
	for (int i = 0; i < index; i++)
	{
		if (tongdiem == sinhvien[i].TongDiem())
			KiemTra = true;
	}
	return KiemTra;
}

bool Model::KiemTraDiemToan(double diemtoan) {
	bool KiemTra = false;
	for (int i = 0; i < index; i++)
	{
		if (diemtoan == sinhvien[i].getToan())
			KiemTra = true;
	}
	return KiemTra;
}

bool Model::KiemTraDiemHoa(double diemhoa){
	bool KiemTra = false;
	for (int i = 0; i < index; i++)
	{
		if (diemhoa == sinhvien[i].getHoa())
			KiemTra = true;
	}
	return KiemTra;
}

bool Model::KiemTraDiemLy(double diemly){
	bool KiemTra = false;
	for (int i = 0; i < index; i++)
	{
		if (diemly == sinhvien[i].getLy())
			KiemTra = true;
	}
	return KiemTra;
}

bool Model::KiemTraHoTen(string hoten){
	bool KiemTra = false;
	for (int i = 0; i < index; i++)
	{
		if (hoten == sinhvien[i].getHoTen())
			KiemTra = true;
	}
	return KiemTra;
}

void Model::TimKiemSoBaoDanh(string sobaodanh) {
	bool KiemTra;
	KiemTra = KiemTraSoBaoDanh(sobaodanh);
	cout << setw(20) << "HoTen" << setw(10) << "SBD" << setw(15) << "DiaChi" << setw(15) << "GioiTinh" << setw(10) << "Toan" << setw(10) << "Ly" << setw(10) << "Hoa" << setw(15) << "TongDiem" << endl;
	if (KiemTra) {
		fstream f;
		f.open("tmp/timkiemsbd.txt", ios::out);
		for (int i = 0; i < index; i++) {
			if (sobaodanh == sinhvien[i].getSBD()) {
				//sinhvien[i].XuatSinhVien();
				f << sinhvien[i].getHoTen() << "\t" << sinhvien[i].getSBD() << "\t" << sinhvien[i].getDiaChi() << "\t" << sinhvien[i].getSex() << "\t" << sinhvien[i].getToan() << "\t" << sinhvien[i].getLy() << "\t" << sinhvien[i].getHoa() << "\t" << sinhvien[i].TongDiem() << endl;
			}
		}
		f.close();
	}
	else { cout << "\nSo bao danh: " << sobaodanh << " khong ton tai"; }
}

void Model::TimKiemTongDiem(double tongdiem) {
	bool kiemtra;
	kiemtra = KiemTraTongDiem(tongdiem);
	cout << setw(20) << "HoTen" << setw(10) << "SBD" << setw(15) << "DiaChi" << setw(15) << "GioiTinh" << setw(10) << "Toan" << setw(10) << "Ly" << setw(10) << "Hoa" << setw(15) << "TongDiem" << endl;
	if (kiemtra) {
		fstream f;
		f.open("tmp/timkiemtongdiem.txt", ios::out);
		for (int i = 0; i < index; i++) {
			if (tongdiem == sinhvien[i].TongDiem()) {
				//sinhvien[i].XuatSinhVien();
				f << sinhvien[i].getHoTen() << "\t" << sinhvien[i].getSBD() << "\t" << sinhvien[i].getDiaChi() << "\t" << sinhvien[i].getSex() << "\t" << sinhvien[i].getToan() << "\t" << sinhvien[i].getLy() << "\t" << sinhvien[i].getHoa() << "\t" << sinhvien[i].TongDiem() << endl;
			}
		}
		f.close();
	}
	else { cout << "\nDiem tong: " << tongdiem << " khong ton tai"; }
}

void Model::TimKiemHoTen(string hoten) {
	bool kiemtra;
	kiemtra = KiemTraHoTen(hoten);
	cout << setw(20) << "HoTen" << setw(10) << "SBD" << setw(15) << "DiaChi" << setw(15) << "GioiTinh" << setw(10) << "Toan" << setw(10) << "Ly" << setw(10) << "Hoa" << setw(15) << "TongDiem" << endl;
	if (kiemtra) {
		fstream f;
		f.open("tmp/timkiemhoten.txt", ios::out);
		for (int i = 0; i < index; i++) {
			if (hoten == sinhvien[i].getHoTen()) {
				//sinhvien[i].XuatSinhVien();
				f << sinhvien[i].getHoTen() << "\t" << sinhvien[i].getSBD() << "\t" << sinhvien[i].getDiaChi() << "\t" << sinhvien[i].getSex() << "\t" << sinhvien[i].getToan() << "\t" << sinhvien[i].getLy() << "\t" << sinhvien[i].getHoa() << "\t" << sinhvien[i].TongDiem() << endl;
			}
		}
		f.close();
	}
	else { cout << "Sinh vien: " << hoten << " khong ton tai" << endl; }
}

void Model::TimKiemDiemToan(double diemtoan) {
	bool kiemtra;
	kiemtra = KiemTraDiemToan(diemtoan);
	cout << setw(20) << "HoTen" << setw(10) << "SBD" << setw(15) << "DiaChi" << setw(15) << "GioiTinh" << setw(10) << "Toan" << setw(10) << "Ly" << setw(10) << "Hoa" << setw(15) << "TongDiem" << endl;
	if (kiemtra) {
		fstream f;
		f.open("tmp/timkiemdiemtoan.txt", ios::out);
		for (int i = 0; i < index; i++) {
			if (diemtoan == sinhvien[i].getToan()){
				//sinhvien[i].XuatSinhVien();
				f << sinhvien[i].getHoTen() << "\t" << sinhvien[i].getSBD() << "\t" << sinhvien[i].getDiaChi() << "\t" << sinhvien[i].getSex() << "\t" << sinhvien[i].getToan() << "\t" << sinhvien[i].getLy() << "\t" << sinhvien[i].getHoa() << "\t" << sinhvien[i].TongDiem() << endl;
			}
		}
		f.close();
	}
	else { cout << "\nSV co diem Toan: " << diemtoan << " khong ton tai"; }
}

void Model::TimKiemDiemLy(double diemly) {
	bool kiemtra;
	kiemtra = KiemTraDiemLy(diemly);
	cout << setw(20) << "HoTen" << setw(10) << "SBD" << setw(15) << "DiaChi" << setw(15) << "GioiTinh" << setw(10) << "Toan" << setw(10) << "Ly" << setw(10) << "Hoa" << setw(15) << "TongDiem" << endl;

	if (kiemtra) {
		fstream f;
		f.open("tmp/timkiemdiemly.txt", ios::out);
		for (int i = 0; i < index; i++) {
			if (diemly == sinhvien[i].getLy()) {
				//sinhvien[i].XuatSinhVien();
				cout << sinhvien[i].getLy();
				f << sinhvien[i].getHoTen() << "\t" << sinhvien[i].getSBD() << "\t" << sinhvien[i].getDiaChi() << "\t" << sinhvien[i].getSex() << "\t" << sinhvien[i].getToan() << "\t" << sinhvien[i].getLy() << "\t" << sinhvien[i].getHoa() << "\t" << sinhvien[i].TongDiem() << endl;
			}
		}
		f.close();
	}
	else { cout << "\nSV co diem Ly: " << diemly << " khong ton tai"; }
}

void Model::TimKiemDiemHoa(double diemhoa) {
	bool kiemtra;
	kiemtra = KiemTraDiemToan(diemhoa);
	cout << setw(20) << "HoTen" << setw(10) << "SBD" << setw(15) << "DiaChi" << setw(15) << "GioiTinh" << setw(10) << "Toan" << setw(10) << "Ly" << setw(10) << "Hoa" << setw(15) << "TongDiem" << endl;
	if (kiemtra) {
		fstream f;
		f.open("tmp/timkiemdiemhoa.txt", ios::out);
		for (int i = 0; i < index; i++) {
			if (diemhoa == sinhvien[i].getHoa()) {
				/*sinhvien[i].XuatSinhVien();*/
				f << sinhvien[i].getHoTen() << "\t" << sinhvien[i].getSBD() << "\t" << sinhvien[i].getDiaChi() << "\t" << sinhvien[i].getSex() << "\t" << sinhvien[i].getToan() << "\t" << sinhvien[i].getLy() << "\t" << sinhvien[i].getHoa() << "\t" << sinhvien[i].TongDiem() << endl;
			}
		}
		f.close();
	}
	else { cout << "\nSV co diem Hoa: " << diemhoa << " khong ton tai"; }
}

void Model::SapXepSoBaoDanh() {
	int i, j;
	for (i = 0; i < index; i++) {
		for (j = index - 1; j > i; j--) {
			if (sinhvien[j].getSBD() < sinhvien[j - 1].getSBD()) {
				Student temp = sinhvien[j];
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

void Model::SapXepAnphabe() {
	int i, j;
	for (i = 0; i < index; i++) {
		for (j = index - 1; j > i; j--) {
			if (sinhvien[j].getHoTen() < sinhvien[j - 1].getHoTen()) {
				Student temp = sinhvien[j];
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

void Model::SapXepDiemTong() {
	int i, j;
	for (i = 0; i < index; i++) {
		for (j = index - 1; j > i; j--) {
			if (sinhvien[j].TongDiem() < sinhvien[j - 1].TongDiem()) {
				Student temp = sinhvien[j];
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

void Model::ThemSinhvienv2(string hoten, string sbd, string diachi, int gioitinh, double toan, double ly, double hoa) {
	Student sv;
	sv.NhapSinhVienv2(hoten, sbd, diachi, gioitinh, toan, ly, hoa);
	sinhvien[index] = sv;
	index++;
}

void Model::ThemSinhvien(int n) {
	for (int i = 0; i < n; i++)
	{
		Student sv;
		sv.NhapSinhVien();
		sinhvien[index] = sv;
		index++;
	}
}

void Model::SuaSinhVien(string sobaodanh) {
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

void Model::XoaSinhVien(string sobaodanh) {
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
		cout << "\nSuccess!\n";
	}
	else {
		cout << "So bao danh: " << sobaodanh << " khong ton tai" << endl;
	}
}

void Model::ThongKeTatCa() {
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

	stringstream ss1;
	ss1 << tsl;
	string str1 = ss1.str();
	stringstream ss2;
	ss2 << nhohon15;
	string str2 = ss2.str();
	stringstream ss3;
	ss3 << _15den20;
	string str3 = ss3.str();
	stringstream ss4;
	ss4 << _20den25;
	string str4 = ss4.str();
	stringstream ss5;
	ss5 << lonhon25;
	string str5 = ss5.str();

	fstream f;
	f.open("tmp/thongkenhanh.txt", ios::app);
	string data = "Thong Ke Nhanh\nTong Sinh Vien: " + str1 + "\nDiem < 15:\t" + str2 + "\nDiem 15->20:\t" + str3 + "\nDiem 21->25:\t" + str4 + "\nDiem > 25:\t" + str5;
	f << data;
	f.close();

}

void Model::XuatSinhVienRaFile(string fileName) {
	fstream f;
	fflush(stdin);
	f.open(fileName, ios::out); // append
	for (int i = 0; i < index; i++)
		f << sinhvien[i].getHoTen() << "\t" << sinhvien[i].getSBD() << "\t" << sinhvien[i].getDiaChi() << "\t" << sinhvien[i].getSex() << "\t" << sinhvien[i].getToan() << "\t" << sinhvien[i].getLy() << "\t" << sinhvien[i].getHoa() << "\t" << sinhvien[i].TongDiem() << endl;
	f.close();
}

void Model::NhapSinhVienTuFile(string input) {
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

string Model::Convert(int i) {
	string result = "";
	stringstream convert;
	convert << i;
	result = convert.str();
	return result;
}

string Model::double_to_string(double num){
	ostringstream result;
	result << num;
	return result.str();
}

string Model::int_to_string(int num) {
	ostringstream result;
	result << num;
	return result.str();
}

int Model::DemSoFile(string maTruong) {
	int soFile = 0;
	fstream fs;
	for (int i = 0; i < 69; i++) {
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

void Model::SuaSinhVienv2(string sobaodanh) {
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
		cout << "\nNhap Gioi Tinh\n1. Nam\n2. Nu\n3. Khac";
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