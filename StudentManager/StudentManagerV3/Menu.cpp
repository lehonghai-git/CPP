#include "Menu.h"
#include <iostream>

void Menu::MenuChinh() {
	system("cls");
	cout << "___STUDENT MANAGER 2016___";
	cout << "\n1. Them, Sua, Xoa Sinh Vien";
	cout << "\n2. Tim Kiem Sinh Vien";
	cout << "\n3. Sap Xep Sinh Vien";
	cout << "\n4. Xuat Sinh Vien Ra File";
	cout << "\n5. Thong Ke Sinh Vien";
	cout << "\n6. Thoat Chuong Trinh";
	cout << "\nBan chon (1-6): ";
}

void Menu::MenuThemSuaXoa() {
	system("cls");
	cout << "=====THEM - SUA - XOA SINH VIEN=====";
	cout << "\n1. Nhap Sinh Vien Tu Ban Phim";
	cout << "\n2. Nhap Sinh Vien Tu File";
	cout << "\n3. Sua Sinh Vien";
	cout << "\n4. Xoa Sinh Vien";
	cout << "\n5. Quay Lai Menu Chinh";
	cout << "\nBan chon (1-5): ";
}

void Menu::MenuTimKiemSinhVien() {
	system("cls");
	cout << "=====TIM KIEM SINH VIEN=====" << endl;
	cout << "\n1. Tim Kiem Theo Diem Tong";
	cout << "\n2. Tim Kiem Theo So Bao Danh";
	cout << "\n3. Tim Kiem Theo Ho Ten";
	cout << "\n4. Tim Kiem Theo Diem Toan";
	cout << "\n5. Tim Kiem Theo Diem Ly";
	cout << "\n6. Tim Kiem Theo Diem Hoa";
	cout << "\n7. Quay Lai Menu Chinh";
	cout << "\nBan chon (1-7): ";
}

void Menu::MenuSapXepSinhVien() {
	system("cls");
	cout << "=====SAP XEP SINH VIEN=====" << endl;
	cout << "\n1. Sap Xep Theo So Bao Danh";
	cout << "\n2. Sap Xep Theo Anphabe";
	cout << "\n3. Sap Xep Theo Diem Tong";
	cout << "\n4. Quay Lai Menu Chinh";
	cout << "\nBan chon (1-4): ";
}