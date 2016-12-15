#pragma warning(disable:4996)
#include "view.h"
#include <iostream>
#include <stdio.h>

void View::mainView() {
	system("cls");
	printf("===|| STUDENT MANAGE ||===");
	printf("\n1. Cap nhap Sinh vien");
	printf("\n2. Tim kiem Sinh vien");
	printf("\n3. Sap xep Sinh vien");
	printf("\n4. Xuat Sinh vien");
	printf("\n5. Thong ke Sinh vien");
	printf("\n6. Thoat");
	printf("\nBan chon(1-6): ");
}

void View::updateView() {
	system("cls");
	printf("===|| STUDENTT UPDATE ||===");
	printf("\n1. Nhap Sinh Vien Tu Ban Phim");
	printf("\n2. Nhap Sinh Vien Tu File");
	printf("\n3. Sua Sinh Vien");
	printf("\n4. Xoa Sinh Vien");
	printf("\n5. Exit");
	printf("\nSelect(1-5): ");
}

void View::searchView() {
	system("cls");
	printf("===|| STUDENT SEARCH ||===");
	printf("\n1. Tim Kiem Theo Diem Tong");
	printf("\n2. Tim Kiem Theo So Bao Danh");
	printf("\n3. Tim Kiem Theo Ho Ten");
	printf("\n4. Tim Kiem Theo Diem Toan");
	printf("\n5. Tim Kiem Theo Diem Ly");
	printf("\n6. Tim Kiem Theo Diem Hoa");
	printf("\n7. Exit");
	printf("\nSelect(1-7): ");
}

void View::sortView() {
	system("cls");
	printf("===|| STUDENT SORT ||===");
	printf("\n1. Sap Xep Theo So Bao Danh");
	printf("\n2. Sap Xep Theo Anphabe");
	printf("\n3. Sap Xep Theo Diem Tong");
	printf("\n4. Exit");
	printf("\nSelect(1-4): ");
}