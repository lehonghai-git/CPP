#pragma warning(disable:4996)
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int index = 0;

struct SinhVien
{
	string HoTen, ID;
	float Toan, Ly, Hoa;
	SinhVien *pNext;
};

SinhVien *pDau = NULL, *pChay = NULL, *p_Chay = NULL;

void NhapSinhVien() {
	int exit = 0;
	while (exit != 10)
	{
		SinhVien *sv = new SinhVien();
		fflush(stdin);
		printf("\nHo ten: ");
		getline(cin, sv->HoTen);

		printf("ID: ");
		getline(cin, sv->ID);

		printf("Toan: ");
		scanf("%f", &sv->Toan);

		printf("Ly: ");
		scanf("%f", &sv->Ly);

		printf("Hoa: ");
		scanf("%f", &sv->Hoa);
		index++;
		if (pDau == NULL) {
			pDau = sv;
			pChay = sv;
			p_Chay = sv; // new
			sv->pNext = NULL;
		}
		else {
			pChay = p_Chay; // new
			pChay->pNext = sv;
			pChay = sv;
			p_Chay = sv; // new
			sv->pNext = NULL;
		}
		string question;
		fflush(stdin);
		printf("\nBan co muon nhap tiep?(Y/N): ");
		getline(cin, question);
		if (question == "N" || question == "n" || question == "No" || question == "nO" || question == "no" || question == "NO")
		{
			exit = 10;
		}
	}
}
void XuatSinhVien() {
	SinhVien *pTmp;
	pTmp = pDau;
	printf("\nHoTen\tID\tToan\tLy\tHoa\tTong\n");
	while (pTmp != NULL)
	{
		float Tong = pTmp->Toan + pTmp->Ly + pTmp->Hoa;
		cout << pTmp->HoTen << "\t" << pTmp->ID << "\t" << pTmp->Toan << "\t" << pTmp->Ly << "\t" << pTmp->Hoa << "\t" << Tong << endl;
		pTmp = pTmp->pNext;
		//index++;
	}
}

void XuatSinhVienRaFile(string fileName)
{

	SinhVien *pTmp;
	pTmp = pDau;
	fstream f;
	fflush(stdin);
	f.open(fileName, ios::app); // append
	while (pTmp != NULL)
	{
		float Tong = pTmp->Toan + pTmp->Ly + pTmp->Hoa;
		f << pTmp->HoTen << "\t" << pTmp->ID << "\t" << pTmp->Toan << "\t" << pTmp->Ly << "\t" << pTmp->Hoa << "\t" << Tong << endl;
		pTmp = pTmp->pNext;
	}
	f.close();
	/*for (int i = 0; i < index; i++)
		f << sv[i].HoTen << "\t" << sv[i].SBD << "\t" << sv[i].DiaChi << "\t" << sv[i].GioiTinh << "\t" << sv[i].Toan << "\t" << sv[i].Ly << "\t" << sv[i].Hoa << "\t" << sv[i].Toan + sv[i].Ly + sv[i].Hoa << endl;
		f.close();*/
}
void DemSoSinhVien() {
	SinhVien *pTmp;
	pTmp = pDau;
	int x = 0, y = 0, z = 0, t = 0;
	printf("\nHoTen\tID\tToan\tLy\tHoa\tTong\n");
	while (pTmp != NULL)
	{
		float Tong = pTmp->Toan + pTmp->Ly + pTmp->Hoa;
		pTmp = pTmp->pNext;
		if (Tong < 15) x++;
		if (Tong >= 15 && Tong <= 20) y++;
		if (Tong >= 21 && Tong <= 25) z++;
		if (Tong > 25) t++;
	}

	cout << "Tong SV: " << index << endl;
	cout << "<15: " << x << endl;
	cout << "15 <= SV <= 20: " << y << endl;
	cout << "21 <= SV <= 25: " << z << endl;
	cout << "SV > 25: " << t << endl;

}
void TimKiemID(string _idSearch)
{
	SinhVien *pTmp;
	pTmp = pDau;
	printf("\nHoTen\tID\tToan\tLy\tHoa\tTong\n");
	while (pTmp != NULL)
	{
		if (pTmp->ID == _idSearch)
		{
			float Tong = pTmp->Toan + pTmp->Ly + pTmp->Hoa;
			cout << pTmp->HoTen << "\t" << pTmp->ID << "\t" << pTmp->Toan << "\t" << pTmp->Ly << "\t" << pTmp->Hoa << "\t" << Tong << endl;
		}
		pTmp = pTmp->pNext;
	}
}

void SuaSinhVien(string _id) {
	pChay = pDau;
	bool KiemTra = false;
	while (pChay != NULL) {
		if (pChay->ID == _id) {
			cout << pChay->HoTen << "\t" << pChay->ID << "\t" << pChay->Toan << "\t" << pChay->Ly << "\t" << pChay->Hoa << endl;
			printf("\nHo ten: ");
			getline(cin, pChay->HoTen);

			printf("\nID: ");
			getline(cin, pChay->ID);

			printf("\nToan: ");
			scanf("%f", &pChay->Toan);

			printf("\nLy: ");
			scanf("%f", &pChay->Ly);

			printf("\nHoa: ");
			scanf("%f", &pChay->Hoa);
			KiemTra = true;
			break;
		}
		pChay = pChay->pNext;
	}

	if (KiemTra == false) {
		printf("ID khong hop le!");
	}

}
void HoanVi(SinhVien *_p, SinhVien *_pChay) {
	SinhVien *ptr = new SinhVien;

	if (_p->Toan > _pChay->Toan)
	{
		/*_p->HoTen = "ngu nguoi";
		_pChay->Hoa = 111;

		/*_p->pNext = _pChay->pNext;
		_pChay->pNext = _p;*/

		/*ptr = _p;
		_p = _pChay;
		_pChay->pNext = ptr->pNext;*/

		ptr->HoTen = _p->HoTen;
		ptr->ID = _p->ID;
		ptr->Toan = _p->Toan;
		ptr->Ly = _p->Ly;
		ptr->Hoa = _p->Hoa;


		_p->HoTen = _pChay->HoTen;
		_p->ID = _pChay->ID;
		_p->Toan = _pChay->Toan;
		_p->Ly = _pChay->Ly;
		_p->Hoa = _pChay->Hoa;

		_pChay->HoTen = ptr->HoTen;
		_pChay->ID = ptr->ID;
		_pChay->Toan = ptr->Toan;
		_pChay->Ly = ptr->Ly;
		_pChay->Hoa = ptr->Hoa;
	}

}
void XoaSinhVien(string _id) {
	SinhVien *p, *tmp_Chay, *ptmp;
	p = pDau;
	pChay = pDau;

	/*tmp_Chay = pDau;
	ptmp = pDau;
	*/

	// TH node cần xóa là node đầu
	if (pChay->ID == _id) {
		pDau = pChay->pNext;
		delete pChay;
		index--;
	}
	else {
		while (pChay != NULL) {
			if (pChay->ID == _id) {
				//p = pDau->pNext;	//new
				//p = pChay->pNext;	//new

				p->pNext = pChay->pNext;
				delete pChay;
				index--;
			}
			else {
				p = pChay;
				pChay = pChay->pNext;
			}
		}
	}

	//if (pChay->ID == _id)
	//{
	//	pDau = pChay->pNext;
	//	delete pChay;
	//}
	//else
	//{
	//	while (pChay != NULL)
	//	{
	//		if (pChay->ID == _id)
	//		{
	//			p->pNext = pChay->pNext;
	//			delete pChay;
	//		}
	//		else
	//		{
	//			p = pChay;
	//			pChay = pChay->pNext;
	//			//HoanVi(p, pChay);
	//		}
	//	}
	//}

}
void SapXepToan(){
	pChay = pDau;
	//printf("\nHoTen\tID\tToan\tLy\tHoa\tTong\n");
	//error
	for (int i = 0; i < index - 1; i++)
	//for (int i = 0; i < index; i++)
	{
		HoanVi(pChay, pChay->pNext);
		pChay = pChay->pNext;
	}
	//XuatSinhVien();

	/*while (pChay != NULL)
	{
	HoanVi(pChay, pChay->pNext);
	pChay = pChay->pNext;
	}*/

}
void View() {
	system("cls");
	printf("______Quan Ly Sinh Vien______");
	printf("\n1. Them Sinh vien");
	printf("\n2. Sua Sinh vien");
	printf("\n3. Xoa Sinh vien");
	printf("\n4. Tim kiem SV theo ID");
	printf("\n5. Sap xep SV theo diem toan");
	printf("\n6. Thong ke Sinh vien");
	printf("\n7. Xuat Sinh vien ra File");
	printf("\n8. Thoat");
	printf("\nBan chon(1-7): ");
}

int main()
{
	do {
		View();
		char choice;
		cin >> choice;

		switch (choice)
		{
		case '1':
		{
			printf("\n1. Them Sinh vien");
			NhapSinhVien();
			system("pause>null");
			break;
		}

		case '2':
		{
			printf("\n2. Sua Sinh vien");
			string __id;
			printf("\nID: ");
			fflush(stdin);
			getline(cin, __id);
			SuaSinhVien(__id);
			system("pause>null");
			break;
		}

		case '3':
		{
			printf("\n3. Xoa Sinh vien");
			string _str;
			fflush(stdin);
			printf("\nNhap ID: ");
			getline(cin, _str);
			XoaSinhVien(_str);
			system("pause>null");
			break;
		}

		case '4':
		{
			printf("\n4. Tim kiem SV theo ID");
			string _idSearch;
			fflush(stdin);
			printf("\nID: ");
			getline(cin, _idSearch);
			TimKiemID(_idSearch);
			system("pause>null");
			break;
		}

		case '5':
		{
			printf("\n5. Sap xep SV theo diem toan");
			for (int i = 0; i < index; i++)
			{
				SapXepToan();
			}
			XuatSinhVien();
			system("pause>null");
			break;
		}

		case '6':
		{
			printf("\n6. Thong ke Sinh vien");
			XuatSinhVien();
			DemSoSinhVien();
			system("pause>null");
			break;
		}

		case '7':
		{
			printf("\n7. Xuat Sinh vien ra File");
			string filename;
			fflush(stdin);
			printf("\nTen File: ");
			getline(cin, filename);
			XuatSinhVienRaFile(filename);
			system("pause>null");
			break;
		}

		case '8':
		{
			exit(1);
		}
		default:
			printf("\nNhap sai!");
			system("pause>null");
			break;
		}

	} while (true);

	system("pause>null");
	return 0;
}

