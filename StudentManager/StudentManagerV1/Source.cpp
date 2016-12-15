#include <iostream>
#include <string>
#include <iomanip>
#include <fstream> 

using namespace std;

class SinhVien
{
private:
	string HoTen;
	string SBD;
	string DiaChi;
	string GioiTinh;
	double Toan;
	double Ly;
	double Hoa;
public:
	void setHoTen(string hoten);
	string getHoTen();
	void setSBD(string sbd);
	string getSBD();
	void setDiaChi(string diachi);
	string getDiaChi();
	void setGioiTinh(string gioitinh);
	string getGioiTinh();
	void setToan(double toan);
	double getToan();
	void setLy(double ly);
	double getLy();
	void setHoa(double hoa);
	double getHoa();
	SinhVien();
	SinhVien(string hoten, string sbd, string diachi, string gioitinh, double toan, double ly, double hoa);
	void Nhap();
	void Xuat();
	double TongDiem();

};

SinhVien MangSV[100];
int chiso = 0;
bool CheckSV(string sbd, int &vitri);
bool CheckSbd(string sobaodanh);
bool CheckTongDiem(double tong);
bool CheckDiemHoa(double hoa);
bool CheckDiemToan(double toan);
bool CheckDiemLy(double ly);
bool CheckHoTen(string hoten);
void Them(int n);
void Sua(string sbd);
void Xoa(string sbd);
void ThongKeAll();
void TimKiemTheoSbd(string sbd);
void TimKiemTheoTongDiem(double tong);
void TimKiemTheoTen(string hoten);
void TimKiemTheoToan(double diemToan);
void TimKiemTheoLy(double diemLy);
void TimKiemTheoHoa(double diemHoa);
void SapXepTheoTongDiem(SinhVien mangsv[], int n);
void SapXepTheoSbd(SinhVien mangsv[], int n);
void SapXepTheoAnphabe(SinhVien mangsv[], int n);
void GhiFile();
void DocFile(string _strName);

int main()
{
	int select;
	while (true)
	{
		do
		{
			system("cls");
			cout << "__Student Manager 2016__" << endl;
			cout << "1: Cap nhat Sinh vien" << endl;
			cout << "2: Tim Kiem Sinh vien" << endl;
			cout << "3: Sap Xep Sinh vien" << endl;
			cout << "4: Xuat Sinh vien ra File" << endl;
			cout << "5: Thong Ke Sinh vien" << endl;
			cout << "6: Thoat" << endl;
			cout << "Ban chon: ";
			cin >> select;
		} while (select < 1 || select > 8);

		switch (select)
		{
		case 1:
		{
			int select;
			do
			{
				system("cls");
				cout << "Cap nhat Sinh vien" << endl;
				cout << "1: Them tu ban phim" << endl;
				cout << "2: Them tu file" << endl;
				cout << "3: Sua Sinh vien" << endl;
				cout << "4: Xoa Sinh vien" << endl;
				cout << "5: Thoat" << endl;
				cout << "Ban chon: ";
				cin >> select;
			} while (select < 1 || select > 4);
			// Menu con 1
			switch (select)
			{
			case 1:
			{
				cout << "Them SV tu ban phim";
				int soluong;
				cout << "\nSo luong: ";
				cin >> soluong;
				Them(soluong);
				cout << "Enter de quay lai Menu";
				system("pause>null");
				break;
			}
			case 2:
			{
				cout << "Them SV tu file";
				string tenfile;
				cout << "\nNhap ten file: ";
				cin.ignore();
				getline(cin, tenfile);
				DocFile(tenfile);
				cout << "Doc xong!" << endl;
				system("pause>null");
				break;
			}
			case 3:
			{
				string sbd;
				cin.ignore();
				cout << "Sua Sinh Vien" << endl;
				cout << "Nhap SBD: ";
				getline(cin, sbd);
				Sua(sbd);
				cout << "Enter de quay lai Menu";
				system("pause>null");
				break;
			}
			case 4:
			{
				string sbd;
				cin.ignore();
				cout << "Xoa Sinh Vien" << endl;
				cout << "Nhap SBD: ";
				getline(cin, sbd);
				Xoa(sbd);
				cout << "Enter de quay lai Menu";
				system("pause>null");
				break;
			}
			case 5:
				break;
			}
		}
		break;

		case 2:
		{
			int select;
			do
			{
				system("cls");
				cout << "Tim kiem Sinh vien" << endl;
				cout << "1: Theo Tong Diem" << endl;
				cout << "2: Theo SBD" << endl;
				cout << "3: Theo Ten" << endl;
				cout << "4: Theo Diem 1 Trong 3 Mon" << endl;
				cout << "5: Thoat" << endl;
				cout << "Ban chon: ";
				cin >> select;
			} while (select < 1 || select > 5);
			// Menu con 2
			switch (select)
			{
			case 1:
			{
				double tong;
				cin.ignore();
				cout << "Tim Kiem Theo Tong Diem" << endl;
				cout << "Nhap Tong Diem: ";
				cin >> tong;
				TimKiemTheoTongDiem(tong);
				cout << "Enter de quay lai Menu";
				system("pause>null");
				break;
			}
			case 2:
			{
				string sbd;
				cin.ignore();
				cout << "Tim Kiem Theo SBD" << endl;
				cout << "Nhap SBD: ";
				getline(cin, sbd);
				TimKiemTheoSbd(sbd);
				cout << "Enter de quay lai Menu";
				system("pause>null");
				break;
			}
			case 3:
			{
				string ten;
				cin.ignore();
				cout << "Tim Kiem Theo Ho Ten" << endl;
				cout << "Nhap Ho Ten: ";
				getline(cin, ten);
				TimKiemTheoTen(ten);
				cout << "Enter de quay lai Menu";
				system("pause>null");
				break;
			}
			case 4:
			{
				int select;
				do
				{
					system("cls");
					cout << "Tim Kiem Theo Diem 1 Trong 3 Mon" << endl;
					cout << "1: Theo Diem Toan" << endl;
					cout << "2: Theo Diem Ly" << endl;
					cout << "3: Theo Diem Hoa" << endl;
					cout << "4: Thoat" << endl;
					cout << "Ban chon: ";
					cin >> select;
				} while (select < 1 || select > 4);
				// Menu 2.1
				switch (select)
				{
				case 1:
					double toan;
					cin.ignore();
					cout << "Tim Kiem Theo Diem Toan" << endl;
					cout << "Nhap Diem Toan: ";
					cin >> toan;
					TimKiemTheoToan(toan);
					break;
				case 2:
					double ly;
					cin.ignore();
					cout << "Tim Kiem Theo Diem Ly" << endl;
					cout << "Nhap Diem Ly: ";
					cin >> ly;
					TimKiemTheoLy(ly);
					break;
				case 3:
					double hoa;
					cin.ignore();
					cout << "Tim Kiem Theo Diem Hoa" << endl;
					cout << "Nhap Diem Hoa: ";
					cin >> hoa;
					TimKiemTheoHoa(hoa);
					break;
				case 4:
					break;
				}
				cout << "Enter de quay lai Menu";
				system("pause>null");
				break;
			}
			case 5:
				break;
			}
		}
		break;
		case 3:
		{
			int select;
			do
			{
				system("cls");
				cout << "Sap xep Sinh vien" << endl;
				cout << "1: Theo SBD" << endl;
				cout << "2: Theo Anphabe" << endl;
				cout << "3: Theo Tong Diem" << endl;
				cout << "4: Thoat" << endl;
				cout << "Ban chon: ";
				cin >> select;
			} while (select < 1 || select > 4);
			// Menu con 3
			switch (select)
			{
			case 1:
			{
				cout << "Sap Xep Theo SBD" << endl;
				cin.ignore();
				SapXepTheoSbd(MangSV, chiso);
				cout << "Enter de quay lai Menu";
				system("pause>null");
				break;
			}
			case 2:
			{
				cout << "Sap Xep Theo Anphabe" << endl;
				cin.ignore();
				SapXepTheoAnphabe(MangSV, chiso);
				cout << "Enter de quay lai Menu";
				system("pause>null");
				break;
			}
			case 3:
			{
				cout << "Sap Xep Theo Tong Diem" << endl;
				cin.ignore();
				SapXepTheoTongDiem(MangSV, chiso);
				//bubbleSort(MangSV, chiso);
				cout << "Enter de quay lai Menu";
				system("pause>null");
				break;
			}
			case 4:
				break;
			}
		}
		break;
		case 4:
		{
			GhiFile();
			cout << "Xuat file thanh cong";
			cout << "Enter de quay lai Menu";
			system("pause>null");
			break;
		}
		case 5:
			// Thong Ke
			ThongKeAll();
			cout << "Enter de quay lai Menu";
			system("pause>null");
			break;
		case 6:
			exit(1);
			break;
		}
	}

	system("pause>null");
	return 0;
}

// constructor
SinhVien::SinhVien()
{
	HoTen = "";
	SBD = "";
	DiaChi = "";
	GioiTinh = "";
	Toan = 0;
	Ly = 0;
	Hoa = 0;
}

SinhVien::SinhVien(string hoten, string sbd, string diachi, string gioitinh, double toan, double ly, double hoa)
{
	HoTen = hoten;
	SBD = sbd;
	DiaChi = diachi;
	GioiTinh = gioitinh;
	Toan = toan;
	Ly = ly;
	Hoa = hoa;
}




void DocFile(string _strName)
{
	fstream f;
	f.open(_strName, ios::in);
	string _hoten, _sbd, _diachi, _gioitinh;
	double _toan, _ly, _hoa;
	int i = 0;
	while (!f.eof()) {
		f >> _hoten >> _sbd >> _diachi >> _gioitinh >> _toan >> _ly >> _hoa;
		MangSV[chiso].setHoTen(_hoten);
		MangSV[chiso].setSBD(_sbd);
		MangSV[chiso].setDiaChi(_diachi);
		MangSV[chiso].setGioiTinh(_gioitinh);
		MangSV[chiso].setToan(_toan);
		MangSV[chiso].setLy(_ly);
		MangSV[chiso].setHoa(_hoa);
		chiso++;
	}
	f.close();
}

void GhiFile()
{
	fstream f;
	f.open("output.txt", ios::out);
	for (int i = 0; i < chiso; i++)
	{
		string hoten = MangSV[i].getHoTen();
		string sbd = MangSV[i].getSBD();
		string diachi = MangSV[i].getDiaChi();
		string gioitinh = MangSV[i].getGioiTinh();
		double toan = MangSV[i].getToan();
		double ly = MangSV[i].getLy();
		double hoa = MangSV[i].getHoa();
		double tong = MangSV[i].TongDiem();

		f << hoten << "\t" << sbd << "\t" << diachi << "\t" << gioitinh << "\t" << toan << "\t" << ly << "\t" << hoa << "\t" << tong << endl;
	}
	f.close();
}

void SapXepTheoSbd(SinhVien mangsv[], int n)
{
	int i, j;
	cout << setw(20) << "Ho Ten" << setw(10) << "SBD" << setw(15) << "Dia Chi" << setw(15) << "Gioi Tinh" << setw(10) << "Toan" << setw(10) << "Ly" << setw(10) << "Hoa" << setw(10) << "Tong" << endl;
	for (i = 0; i < n; i++)
	{
		for (j = n - 1; j > i; j--)
		{
			if (mangsv[j].getSBD() < mangsv[j - 1].getSBD())
			{
				SinhVien temp = mangsv[j];
				mangsv[j] = mangsv[j - 1];
				mangsv[j - 1] = temp;
			}
		}
	}
	for (int i = 0; i < chiso; i++)
	{
		MangSV[i].Xuat();
	}

}

void SapXepTheoAnphabe(SinhVien mangsv[], int n)
{
	int i, j;
	cout << setw(20) << "Ho Ten" << setw(10) << "SBD" << setw(15) << "Dia Chi" << setw(15) << "Gioi Tinh" << setw(10) << "Toan" << setw(10) << "Ly" << setw(10) << "Hoa" << setw(10) << "Tong" << endl;
	for (i = 0; i < n; i++)
	{
		for (j = n - 1; j > i; j--)
		{
			if (mangsv[j].getHoTen() < mangsv[j - 1].getHoTen())
			{
				SinhVien temp = mangsv[j];
				mangsv[j] = mangsv[j - 1];
				mangsv[j - 1] = temp;
			}
		}

	}
	for (int i = 0; i < chiso; i++)
	{
		MangSV[i].Xuat();
	}
}

void SapXepTheoTongDiem(SinhVien mangsv[], int n)
{
	int i, j;
	cout << setw(20) << "Ho Ten" << setw(10) << "SBD" << setw(15) << "Dia Chi" << setw(15) << "Gioi Tinh" << setw(10) << "Toan" << setw(10) << "Ly" << setw(10) << "Hoa" << setw(10) << "Tong" << endl;
	for (i = 0; i < n; i++)
	{
		for (j = n - 1; j > i; j--)
		{
			if (mangsv[j].TongDiem() < mangsv[j - 1].TongDiem())
			{
				SinhVien temp = mangsv[j];
				mangsv[j] = mangsv[j - 1];
				mangsv[j - 1] = temp;
			}

		}

	}
	for (int i = 0; i < chiso; i++)
	{
		MangSV[i].Xuat();
	}

}

void TimKiemTheoToan(double diemToan)
{
	bool kiemtra;
	kiemtra = CheckDiemToan(diemToan);
	if (kiemtra)
	{
		cout << setw(20) << "Ho Ten" << setw(10) << "SBD" << setw(15) << "Dia Chi" << setw(15) << "Gioi Tinh" << setw(10) << "Toan" << setw(10) << "Ly" << setw(10) << "Hoa" << setw(10) << "Tong" << endl;
		for (int i = 0; i < chiso; i++)
		{
			if (diemToan == MangSV[i].getToan())
				MangSV[i].Xuat();
		}
	}
	else
	{
		cout << "SV co diem Toan " << diemToan << " khong ton tai" << endl;
	}
}

void TimKiemTheoLy(double diemLy)
{
	bool kiemtra;
	kiemtra = CheckDiemLy(diemLy);
	if (kiemtra)
	{
		cout << setw(20) << "Ho Ten" << setw(10) << "SBD" << setw(15) << "Dia Chi" << setw(15) << "Gioi Tinh" << setw(10) << "Toan" << setw(10) << "Ly" << setw(10) << "Hoa" << setw(10) << "Tong" << endl;
		for (int i = 0; i < chiso; i++)
		{
			if (diemLy == MangSV[i].getLy())
				MangSV[i].Xuat();
		}
	}
	else
	{
		cout << "SV co diem Ly " << diemLy << " khong ton tai" << endl;
	}
}

void TimKiemTheoHoa(double diemHoa)
{
	bool kiemtra;
	kiemtra = CheckDiemHoa(diemHoa);
	if (kiemtra)
	{
		cout << setw(20) << "Ho Ten" << setw(10) << "SBD" << setw(15) << "Dia Chi" << setw(15) << "Gioi Tinh" << setw(10) << "Toan" << setw(10) << "Ly" << setw(10) << "Hoa" << setw(10) << "Tong" << endl;
		for (int i = 0; i < chiso; i++)
		{
			if (diemHoa == MangSV[i].getHoa())
				MangSV[i].Xuat();
		}
	}
	else
	{
		cout << "SV co diem Hoa " << diemHoa << " khong ton tai" << endl;
	}
}

void TimKiemTheoTen(string hoten)
{
	bool kiemtra;
	kiemtra = CheckHoTen(hoten);
	if (kiemtra)
	{
		cout << setw(20) << "Ho Ten" << setw(10) << "SBD" << setw(15) << "Dia Chi" << setw(15) << "Gioi Tinh" << setw(10) << "Toan" << setw(10) << "Ly" << setw(10) << "Hoa" << setw(10) << "Tong" << endl;
		for (int i = 0; i < chiso; i++)
		{
			if (hoten == MangSV[i].getHoTen())
				MangSV[i].Xuat();
		}
	}
	else
	{
		cout << "SV co Ho Ten " << hoten << " khong ton tai" << endl;
	}
}

void TimKiemTheoTongDiem(double tong)
{
	bool kiemtra;
	kiemtra = CheckTongDiem(tong);
	if (kiemtra)
	{
		cout << setw(20) << "Ho Ten" << setw(10) << "SBD" << setw(15) << "Dia Chi" << setw(15) << "Gioi Tinh" << setw(10) << "Toan" << setw(10) << "Ly" << setw(10) << "Hoa" << setw(10) << "Tong" << endl;
		for (int i = 0; i < chiso; i++)
		{
			if (tong == MangSV[i].TongDiem())
				MangSV[i].Xuat();
		}
	}
	else
	{
		cout << "SV co tong " << tong << " diem khong ton tai" << endl;
	}
}

void TimKiemTheoSbd(string sbd)
{
	bool kiemtra;
	kiemtra = CheckSbd(sbd);
	if (kiemtra)
	{
		cout << setw(20) << "Ho Ten" << setw(10) << "SBD" << setw(15) << "Dia Chi" << setw(15) << "Gioi Tinh" << setw(10) << "Toan" << setw(10) << "Ly" << setw(10) << "Hoa" << setw(10) << "Tong" << endl;
		for (int i = 0; i < chiso; i++)
		{
			if (sbd == MangSV[i].getSBD())
				MangSV[i].Xuat();
		}
	}
	else
	{
		cout << "SV co sbd " << sbd << " khong ton tai" << endl;
	}
}

void ThongKeAll()
{
	cout << "\nThong Ke Sinh Vien" << endl;
	int dem = 0, diem1 = 0, diem2 = 0, diem3 = 0, diem4 = 0;
	cout << setw(20) << "Ho Ten" << setw(10) << "SBD" << setw(15) << "Dia Chi" << setw(15) << "Gioi Tinh" << setw(10) << "Toan" << setw(10) << "Ly" << setw(10) << "Hoa" << setw(10) << "Tong" << endl;
	for (int i = 0; i < chiso; i++)
	{
		MangSV[i].Xuat();
		dem++;
		if (MangSV[i].TongDiem() < 15)
		{
			diem1++;
		}
		if (MangSV[i].TongDiem() >= 15 && MangSV[i].TongDiem() <= 20)
		{
			diem2++;
		}
		if (MangSV[i].TongDiem() > 20 && MangSV[i].TongDiem() <= 25)
		{
			diem3++;
		}
		if (MangSV[i].TongDiem() > 25)
		{
			diem4++;
		}
	}
	cout << "Tong:\t\t" << dem << " Sinh vien" << endl;
	cout << "Diem < 15:\t" << diem1 << " Sinh vien" << endl;
	cout << "Diem 15->20:\t" << diem2 << " Sinh vien" << endl;
	cout << "Diem 21->25:\t" << diem3 << " Sinh vien" << endl;
	cout << "Diem > 25:\t" << diem4 << " Sinh vien" << endl;

}

void Xoa(string sbd)
{
	int vitri;
	bool kiemtra;
	kiemtra = CheckSV(sbd, vitri);
	if (kiemtra)
	{
		for (int i = vitri; i < chiso - 1; i++)
		{
			MangSV[i] = MangSV[i + 1];
		}
		chiso--;
		cout << "Da xoa!" << endl;
	}
	else
	{
		cout << "SV co sbd " << sbd << " khong ton tai" << endl;
	}
}

void Sua(string sbd)
{
	int vitri;
	bool kiemtra;
	kiemtra = CheckSV(sbd, vitri);
	if (kiemtra)
	{
		cout << "Nhan Enter de bat dau sua!";
		MangSV[vitri].Nhap();
		cout << "Sua thanh cong!" << endl;
	}
	else
	{
		cout << "SV co sbd " << sbd << " khong ton tai" << endl;
	}
}

void Them(int n)
{
	for (int i = 0; i < n; i++)
	{
		SinhVien sv;
		sv.Nhap();

		MangSV[chiso] = sv;
		chiso++;
	}
}

bool CheckHoTen(string hoten)
{
	bool check = false;
	for (int i = 0; i < chiso; i++)
	{
		if (hoten == MangSV[i].getHoTen())
			check = true;
	}
	return check;
}

bool CheckDiemHoa(double hoa)
{
	bool check = false;
	for (int i = 0; i < chiso; i++)
	{
		if (hoa == MangSV[i].getHoa())
			check = true;
	}
	return check;
}

bool CheckDiemToan(double toan)
{
	bool check = false;
	for (int i = 0; i < chiso; i++)
	{
		if (toan == MangSV[i].getToan())
			check = true;
	}
	return check;
}

bool CheckDiemLy(double ly)
{
	bool check = false;
	for (int i = 0; i < chiso; i++)
	{
		if (ly == MangSV[i].getLy())
			check = true;
	}
	return check;
}

bool CheckTongDiem(double tong)
{
	bool check = false;
	for (int i = 0; i < chiso; i++)
	{
		if (tong == MangSV[i].TongDiem())
			check = true;
	}
	return check;
}

bool CheckSbd(string sobaodanh)
{
	bool check = false;
	for (int i = 0; i < chiso; i++)
	{
		if (sobaodanh == MangSV[i].getSBD())
			check = true;
	}
	return check;
}

bool CheckSV(string sbd, int &vitri)
{
	bool check = false;
	for (int i = 0; i < chiso; i++)
	{
		if (sbd == MangSV[i].getSBD())
		{
			vitri = i;
			check = true;
			break;
		}
	}
	return check;
}

void SinhVien::Nhap()
{
	cin.ignore();
lbsbd:
	cout << "So bao danh: ";
	getline(cin, SBD);
	if (SBD == "")
	{
		cout << "SBD khong hop le!" << endl; goto lbsbd;
	}
	//if (CheckSbd(SBD))
	//{
	//	cout << "Trung SBD!" << endl;
	//	goto lbsbd;
	//}
lbshoten:
	cout << "Ho ten: ";
	getline(cin, HoTen);
	if (HoTen == "")
	{
		cout << "Ho Ten khong hop le!" << endl; goto lbshoten;
	}
lbsdiachi:
	cout << "Dia chi: ";
	getline(cin, DiaChi);
	if (DiaChi == "")
	{
		cout << "Dia Chi khong hop le!" << endl; goto lbsdiachi;
	}
lbgioitinh:
	cout << "Gioi tinh: ";
	getline(cin, GioiTinh);
	if (GioiTinh == "")
	{
		cout << "Gioi Tinh khong hop le!" << endl; goto lbgioitinh;
	}
lbtoan:
	cout << "Diem toan: ";
	cin >> Toan;
	if (Toan < 0 || Toan > 10)
	{
		cout << "Diem khong hop le" << endl; goto lbtoan;
	}
lbly:
	cout << "Diem ly: ";
	cin >> Ly;
	if (Ly < 0 || Ly > 10)
	{
		cout << "Diem khong hop le" << endl; goto lbly;
	}
lbhoa:
	cout << "Diem hoa: ";
	cin >> Hoa;
	if (Hoa < 0 || Hoa > 10)
	{
		cout << "Diem khong hop le" << endl; goto lbhoa;
	}

}
void SinhVien::Xuat()
{
	cout << setw(20) << HoTen << setw(10) << SBD << setw(15) << DiaChi << setw(15) << GioiTinh << setw(10) << Toan << setw(10) << Ly << setw(10) << Hoa << setw(10) << TongDiem() << endl;
}

double SinhVien::TongDiem()
{
	return Toan + Ly + Hoa;
}
void SinhVien::setHoTen(string hoten)
{
	HoTen = hoten;
}
string SinhVien::getHoTen()
{
	return HoTen;
}
void SinhVien::setSBD(string sbd)
{
	SBD = sbd;
}
string SinhVien::getSBD()
{
	return SBD;
}
void SinhVien::setDiaChi(string diachi)
{
	DiaChi = diachi;
}
string  SinhVien::getDiaChi()
{
	return DiaChi;
}
void SinhVien::setGioiTinh(string gioitinh)
{
	GioiTinh = gioitinh;
}
string SinhVien::getGioiTinh()
{
	return GioiTinh;
}
void SinhVien::setToan(double toan)
{
	Toan = toan;
}
double SinhVien::getToan()
{
	return Toan;
}
void SinhVien::setLy(double ly)
{
	Ly = ly;
}
double SinhVien::getLy()
{
	return Ly;
}
void SinhVien::setHoa(double hoa)
{
	Hoa = hoa;
}
double SinhVien::getHoa()
{
	return Hoa;
}
