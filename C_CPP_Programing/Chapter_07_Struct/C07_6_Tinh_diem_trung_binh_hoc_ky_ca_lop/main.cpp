#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX 100

struct MonHoc
{
	int SoTinChiMonHoc;
	float DiemTrungBinhMonHoc;
};
typedef struct MonHoc MONHOC;
typedef struct SinhVien
{
	char MaSo[10], HoTen[30];
	int SoLuongMon;
	MONHOC DanhSachMonHoc[MAX];
}SINHVIEN;
//typedef struct SinhVien SINHVIEN;
typedef struct LopHoc
{
	int SiSo; // Sĩ số lớp học
	SINHVIEN DanhSachSinhVien[MAX];
}LOPHOC;
//typedef struct LopHoc LOPHOC;

void NhapThongTinLopHoc(LOPHOC &);
void XuatThongTinLopHoc(LOPHOC);
void NhapThongTinSinhVien(SINHVIEN &);
void XuatThongTinSinhVien(SINHVIEN);
void NhapThongTinMonHoc(MONHOC &);
void XuatThongTinMonHoc(MONHOC);
float TinhDTBHocKyMotSV(SINHVIEN);
const char* XepLoaiSinhVien(SINHVIEN);

int main()
{
	LOPHOC lh;

	NhapThongTinLopHoc(lh);
	XuatThongTinLopHoc(lh);

	_getch();
	return 0;
}
/*
** Bài tập Áp dụng kiến thức đã học vể Struct, viết chương trình với các yêu cầu sau:
- Mỗi học kỳ các sinh viên học xong một số môn. Gọi số môn là n
- Mỗi môn có các thông tin: Số tín chỉ, điểm trung bình đạt được
- Xếp loại sinh viên theo DTBHK
- Công thức tính điểm TB của cả học kỳ:
DTBHK = (Số chỉ môn 1 * Điểm TB môn 1 + Số chỉ môn 2 * Điểm TB môn 2 + Số chỉ môn n * Điểm TB môn n) / (Số chỉ môn 1 + Số chỉ môn 2 + Số chỉ môn n)

- Nhập thông tin sinh viên: Mã số, Họ tên, Số lượng môn, số tín chỉ + điểm TB từng môn
=> Tính điểm TB học kỳ và xếp loại sinh viên
=> Phát triển thành Lớp học (Nhiều sinh viên)
*/

void NhapThongTinLopHoc(LOPHOC &lh)
{
	do
	{
		printf("Nhap si so: ");
		scanf_s("%d", &lh.SiSo);
		if (lh.SiSo < 1 || lh.SiSo > MAX)
			printf("Nhap lai si so!\n");
	} while (lh.SiSo < 1 || lh.SiSo > MAX);

	for (int i = 0; i < lh.SiSo; i++)
	{
		printf("\nNhap Thong Tin Sinh Vien Thu %d", i + 1);
		int flag; // Cờ kiểm tra mã số sinh viên có bị nhập trùng
		char tmpMaSo[10]; // Dùng làm một biến tạm để kiểm tra Mã số

		do
		{
			flag = 1;

			// Nhập mã số
			rewind(stdin);
			printf("\nNhap Ma So: ");
			gets_s(tmpMaSo);

			// Duyệt ngược lại danh sách để kiểm tra
			for (int j = i - 1; j >= 0; j--)
			{
				if (strcmp(lh.DanhSachSinhVien[j].MaSo, tmpMaSo) == 0)
				{
					flag = 0; // Phát hiện trùng sau khi so sánh.
					break;
				}
			}

			if (flag == 0) // Thông báo
				printf("Ma so sinh vien bi trung!\n");
		} while (flag == 0);

		// Mã số không bị trùng.
		strcpy_s(lh.DanhSachSinhVien[i].MaSo, tmpMaSo);

		NhapThongTinSinhVien(lh.DanhSachSinhVien[i]);
	}
}
void XuatThongTinLopHoc(LOPHOC lh)
{
	printf("\nSo luong sinh vien: %d", lh.SiSo);
	for (int i = 0; i < lh.SiSo; i++)
	{
		printf("\n\nThong tin sinh vien thu %d", i + 1);
		XuatThongTinSinhVien(lh.DanhSachSinhVien[i]);
	}
}
void NhapThongTinSinhVien(SINHVIEN &sv)
{
	rewind(stdin);
	printf("Nhap Ho Ten: ");
	gets_s(sv.HoTen);

	do
	{
		printf("Nhap so luong mon hoc: ");
		scanf_s("%d", &sv.SoLuongMon);
		if (sv.SoLuongMon < 0)
		{
			printf("Nhap lai so luong mon!\n");
		}
	} while (sv.SoLuongMon < 0);

	for (int i = 0; i < sv.SoLuongMon; i++)
	{
		printf("\nMon hoc thu %d", i + 1);
		NhapThongTinMonHoc(sv.DanhSachMonHoc[i]);
	}

}
void XuatThongTinSinhVien(SINHVIEN sv)
{
	printf("\nMa so: %s", sv.MaSo);
	printf("\nHo ten: %s", sv.HoTen);
	printf("\nSo luong mon da hoc: %d", sv.SoLuongMon);
	printf("\nThong Tin Cac Mon Da Hoc");
	for (int i = 0; i < sv.SoLuongMon; i++)
	{
		printf("\nMon thu %d", i + 1);
		XuatThongTinMonHoc(sv.DanhSachMonHoc[i]);
	}
	printf("\nDiem trung binh hoc ky: %.2f", TinhDTBHocKyMotSV(sv));
	printf("\nXep loai: %s", XepLoaiSinhVien(sv));
}
void NhapThongTinMonHoc(MONHOC &mh)
{
	do
	{
		printf("\nNhap DTB cua mon hoc: ");
		scanf_s("%f", &mh.DiemTrungBinhMonHoc);
		if (mh.DiemTrungBinhMonHoc < 0 || mh.DiemTrungBinhMonHoc > 10)
		{
			printf("Nhap lai DTB mon hoc!\n");
		}
	} while (mh.DiemTrungBinhMonHoc < 0 || mh.DiemTrungBinhMonHoc > 10);

	do
	{
		printf("\nNhap so tin chi cua mon hoc: ");
		scanf_s("%d", &mh.SoTinChiMonHoc);
		if (mh.SoTinChiMonHoc < 0)
		{
			printf("Nhap lai so tin chi cua mon hoc!\n");
		}
	} while (mh.SoTinChiMonHoc < 0);
}
void XuatThongTinMonHoc(MONHOC mh)
{
	printf("\nSo tin chi mon hoc: %d", mh.SoTinChiMonHoc);
	printf("\nDiem trung binh mon hoc: %.2f", mh.DiemTrungBinhMonHoc);
}
float TinhDTBHocKyMotSV(SINHVIEN sv)
{
	int TongSoTinChiCaHocKy = 0;
	float TongDiemTBCacMon = 0;
	for (int i = 0; i < sv.SoLuongMon; i++)
	{
		TongSoTinChiCaHocKy += sv.DanhSachMonHoc[i].SoTinChiMonHoc;
		TongDiemTBCacMon += (sv.DanhSachMonHoc[i].SoTinChiMonHoc * sv.DanhSachMonHoc[i].DiemTrungBinhMonHoc);
	}

	return TongDiemTBCacMon / TongSoTinChiCaHocKy;
}
const char* XepLoaiSinhVien(SINHVIEN sv)
{
	float DTB = TinhDTBHocKyMotSV(sv);
	if (DTB < 2) return "Yeu";
	if (DTB < 5) return "Kem";
	if (DTB < 6) return "Trung Binh";
	if (DTB < 7) return "TB Kha";
	if (DTB < 8) return "Kha";
	if (DTB < 9) return "Gioi";
	return "Xuat Sac";
}