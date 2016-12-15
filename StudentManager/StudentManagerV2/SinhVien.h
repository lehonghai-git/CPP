#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class SinhVien
{
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
	// Các phương thức Get - Set
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

	// Các phương thức Nhập, Xuất, Tính tổng
	void NhapSinhVien();
	double TongDiem();
	void XuatSinhVien();
};