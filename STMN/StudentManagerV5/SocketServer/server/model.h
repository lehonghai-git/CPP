#pragma once
#include <string>
#include "student.h"
#include <windows.h>
using namespace std;

class Model
{
public:
	bool KiemTraSinhVien(string sobaodanh, int &vitri);
	bool KiemTraSoBaoDanh(string sobaodanh);
	bool KiemTraTongDiem(double tongdiem);
	bool KiemTraDiemToan(double diemtoan);
	bool KiemTraDiemHoa(double diemhoa);
	bool KiemTraDiemLy(double diemly);
	bool KiemTraHoTen(string hoten);
	void TimKiemSoBaoDanh(string sobaodanh);
	void TimKiemTongDiem(double tongdiem);
	void TimKiemHoTen(string hoten);
	void TimKiemDiemToan(double diemtoan);
	void TimKiemDiemLy(double diemly);
	void TimKiemDiemHoa(double diemhoa);
	void SapXepDiemTong();
	void SapXepSoBaoDanh();
	void SapXepAnphabe();
	void ThemSinhvien(int n);
	void ThemSinhvienv2(string hoten, string sbd, string diachi, int gioitinh, double toan, double ly, double hoa);
	void SuaSinhVien(string sobaodanh);
	void XoaSinhVien(string sobaodanh);
	void ThongKeTatCa();
	void XuatSinhVienRaFile(string fileName);
	void NhapSinhVienTuFile(string fileName);

	DWORD WINAPI threadNhap(LPVOID arg);
	string Convert(int i);
	string double_to_string(double num);
	string int_to_string(int num);
	int DemSoFile(string maTruong);
	void SuaSinhVienv2(string sobaodanh);
};