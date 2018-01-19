#include <stdio.h>

struct SinhVien
{
	char MaSo[10], HoTen[30];
	float DiemToan, DiemLy, DiemHoa;
};
typedef struct SinhVien SINHVIEN;

void NhapSinhVien(SINHVIEN *);
void XuatSinhVien(SINHVIEN);
float TinhDiemTrungBinh(SINHVIEN);
const char* XepLoai(SINHVIEN);

int main()
{
	SINHVIEN sv;

	// Nhập xuất
	NhapSinhVien(&sv);
	XuatSinhVien(sv);

	getch();
	return 0;
}

void NhapSinhVien(SINHVIEN *sv)
{
	rewind(stdin); // Clear buffer
	printf("Nhap Ma So: ");
	gets(sv->MaSo);

	printf("Nhap Ho Ten: ");
	gets(sv->HoTen);

	do
	{
		printf("Nhap Diem Toan: ");
		scanf("%f", &sv->DiemToan);

	} while (sv->DiemToan < 0 || sv->DiemToan > 10);
	do
	{
		printf("Nhap Diem Ly: ");
		scanf("%f", &sv->DiemLy);

	} while (sv->DiemLy < 0 || sv->DiemLy > 10);
	do
	{
		printf("Nhap Diem Hoa: ");
		scanf("%f", &sv->DiemHoa);
	} while (sv->DiemHoa < 0 || sv->DiemHoa > 10);
}
void XuatSinhVien(SINHVIEN sv)
{
	printf("\nMa so: %s", sv.MaSo);
	printf("\nHo ten: %s", sv.HoTen);
	printf("\nDiem toan: %.2f", sv.DiemToan);
	printf("\nDiem ly: %.2f", sv.DiemLy);
	printf("\nDiem hoa: %.2f", sv.DiemHoa);
	printf("\nDiem TB: %.2f", TinhDiemTrungBinh(sv));
	printf("\nXep loai: %s", XepLoai(sv));
}
float TinhDiemTrungBinh(SINHVIEN sv)
{
	return (sv.DiemHoa + sv.DiemLy + sv.DiemToan) / 3;
}
const char* XepLoai(SINHVIEN sv)
{
	float DTB = TinhDiemTrungBinh(sv);
	if (DTB < 2) return "Yeu";
	if (DTB < 5) return "Kem";
	if (DTB < 6) return "Trung Binh";
	if (DTB < 7) return "TB Kha";
	if (DTB < 8) return "Kha";
	if (DTB < 9) return "Gioi";
	return "Xuat Sac";
}