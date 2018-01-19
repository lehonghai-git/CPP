#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX 100

struct SinhVien
{
	char MaSo[10], HoTen[30];
	float DiemToan, DiemLy, DiemHoa;
};
typedef struct SinhVien SINHVIEN;
struct LopHoc
{
	int SiSo; // Sĩ số lớp học
	SINHVIEN DanhSachSinhVien[MAX];
};
typedef struct LopHoc LOPHOC;

void NhapSinhVien(SINHVIEN &);
void XuatSinhVien(SINHVIEN);
float TinhDiemTrungBinh(SINHVIEN);
const char* XepLoai(SINHVIEN);
void NhapThongTinLopHoc(LOPHOC &);
void XuatThongTinLopHoc(LOPHOC);

int main()
{
	LOPHOC lh;
	// Nhập xuất
	NhapThongTinLopHoc(lh);
	XuatThongTinLopHoc(lh);

	_getch();
	return 0;
}
/*
** Bài tập này nâng cấp lên của bài nhập xuất thông tin 1 sinh viên
- Khi nhập một danh sách sinh viên
thì trước đó cần phải xây dựng được hàm Nhập một sinh viên
- Không nên dùng một hàm mà trong đó nhập tất cả sinh viên
thay vào đó nên gọi hàm nhập một sinh viên bên trong hàm nhập một danh sách.
- Chia nhỏ thành các hàm để dễ quản lý và tái sử dụng
- Các sinh viên không được trùng mã số
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

		NhapSinhVien(lh.DanhSachSinhVien[i]);
	}
}
void XuatThongTinLopHoc(LOPHOC lh)
{
	printf("\nSo luong sinh vien: %d", lh.SiSo);
	for (int i = 0; i < lh.SiSo; i++)
	{
		printf("\n\nThong tin sinh vien thu %d", i + 1);
		XuatSinhVien(lh.DanhSachSinhVien[i]);
	}
}
void NhapSinhVien(SINHVIEN &sv)
{
	/*rewind(stdin);
	printf("\nNhap Ma So: ");
	gets_s(sv.MaSo);*/

	rewind(stdin);
	printf("Nhap Ho Ten: ");
	gets_s(sv.HoTen);

	do
	{
		printf("Nhap Diem Toan: ");
		scanf_s("%f", &sv.DiemToan);

	} while (sv.DiemToan < 0 || sv.DiemToan > 10);
	do
	{
		printf("Nhap Diem Ly: ");
		scanf_s("%f", &sv.DiemLy);

	} while (sv.DiemLy < 0 || sv.DiemLy > 10);
	do
	{
		printf("Nhap Diem Hoa: ");
		scanf_s("%f", &sv.DiemHoa);
	} while (sv.DiemHoa < 0 || sv.DiemHoa > 10);
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