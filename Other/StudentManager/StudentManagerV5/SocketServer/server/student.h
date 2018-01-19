#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Student {
private:
	string HoTen;
	string SBD;
	string DiaChi;
	string GioiTinh;
	double Sex;
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
	void setSex(double sex);
	double getSex();
	void setToan(double toan);
	double getToan();
	void setLy(double ly);
	double getLy();
	void setHoa(double hoa);
	double getHoa();
	void NhapSinhVien();
	void NhapSinhVienv2(string hoten, string sbd, string diachi, int gioitinh, double toan, double ly, double hoa);
	double TongDiem();
	void XuatSinhVien();
};