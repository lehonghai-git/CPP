#include "view.h"
#include <iostream>

void View::mainMenu() {
	system("cls");
	cout << "===|| STUDENT MANAGE CLIENT ||===";
	cout << "\n1. Update";
	cout << "\n2. Search";
	cout << "\n3. Sort";
	cout << "\n4. Export";
	cout << "\n5. Statistical";
	cout << "\n6. Exit";
	cout << "\nSelect(1-6): ";
}

void View::updateMenu() {
	system("cls");
	cout << "===|| STUDENTT UPDATE ||===";
	cout << "\n1. Nhap Sinh Vien Tu Ban Phim";
	cout << "\n2. Nhap Sinh Vien Tu File";
	cout << "\n3. Sua Sinh Vien";
	cout << "\n4. Xoa Sinh Vien";
	cout << "\n5. Exit";
	cout << "\nSelect(1-5): ";
}

void View::searchMenu() {
	system("cls");
	cout << "===|| STUDENT SEARCH ||===" << endl;
	cout << "\n1. Tim Kiem Theo Diem Tong";
	cout << "\n2. Tim Kiem Theo So Bao Danh";
	cout << "\n3. Tim Kiem Theo Ho Ten";
	cout << "\n4. Tim Kiem Theo Diem Toan";
	cout << "\n5. Tim Kiem Theo Diem Ly";
	cout << "\n6. Tim Kiem Theo Diem Hoa";
	cout << "\n7. Exit";
	cout << "\nSelect(1-7): ";
}

void View::sortMenu() {
	system("cls");
	cout << "===|| STUDENT SORT ||===" << endl;
	cout << "\n1. Sap Xep Theo So Bao Danh";
	cout << "\n2. Sap Xep Theo Anphabe";
	cout << "\n3. Sap Xep Theo Diem Tong";
	cout << "\n4. Exit";
	cout << "\nSelect(1-4): ";
}