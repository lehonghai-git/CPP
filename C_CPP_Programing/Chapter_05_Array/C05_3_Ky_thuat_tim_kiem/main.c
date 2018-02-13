#include "NhapXuat.h"
#include "KiemTraSo.h"
#include "TinhToan.h"
#include "XuatKetQua.h"
#include "TimKiem.h"
#define MAX 100

/*
** TÌM KIẾM TRONG MẢNG MỘT CHIỀU
*/

int main()
{
#if 1
	int a[MAX], n;
	do
	{
		printf("Nhap so luong phan tu: ");
		scanf("%d", &n);
		if (n <= 0 || n > 100)
			printf("Nhap lai n\n");
	} while (n <= 0 || n > MAX);
	//NhapMang(a, n);
	NhapMangNgauNhien(a, n);
	printf("\nMang vua nhap:\n");
	XuatMang(a, n);
#endif // 1

#if 0 // Bài 1.1 Số đối xứng
	printf("\nCac so doi xung: ");
	XuatSoDoiXung(a, n);
	printf("\nTong so doi xung: %d", TongSoDoiXung(a, n));
#endif // Bài 1.1 Số đối xứng

#if 0 // Bài 1.2 Số Amstrong
	printf("\nCac so Amstrong: ");
	XuatSoAmstrong(a, n);
	printf("\nTong so amstrong: %d\n", TongSoAmstrong(a, n));
#endif // Bài 1.2 Số Amstrong

#if 0 // Bài 2. Số hoàn thiện, Kiểm tra mảng chẵn
	if (KiemTraMangChan(a, n) == 1)
		printf("Mang toan so chan\n");
	else
		printf("Mang khong phai toan chan\n");
	printf("Cac so hoan thien: \n");
	XuatSoHoanThien(a, n);
#endif // Bài 2. Số hoàn thiện, Kiểm tra mảng chẵn

#if 0 // Bài 3. Tìm kiếm một phần tử trong mảng
	int x, vt;
	printf("\nNhap phan tu muon tim kiem: ");
	scanf("%d", &x);
	vt = TimKiem(a, n, x);
	if (vt == -1)
		printf("Khong ton tai phan tu %d trong mang\n", x);
	else
		printf("Phan tu %d nam o vi tri: %d\n", x, vt);
#endif // Bài 3. Tìm kiếm một phần tử trong mảng

#if 0 // Bài 4. Tìm âm lớn nhất, dương bé nhất
	if (TimViTriAmDauTien(a, n) == -1)
		printf("Mang khong co so am\n");
	else
		printf("Max so am: %d\n", TimSoAmLonNhat(a, n));

	if (TimViTriDuongDauTien(a, n) == -1)
		printf("Mang khong co so duong\n");
	else
		printf("Min so duong: %d\n", TimSoDuongBeNhat(a, n));
#endif // Bài 4. Tìm âm lớn nhất, dương bé nhất

#if 0 // Bài 5.1 Tìm kiếm tuần tự vét cạn
	int x;
	printf("Nhap vao phan tu muon tim: ");
	scanf("%d", &x);
	int vt = TimKiemTuanTuVetCan(a, n, x);
	if (vt != -1)
		printf("Tim thay phan tu %d tai vi tri %d\n", x, vt);
	else
		printf("Khong tim thay phan tu %d\n", x);
#endif // Bài 5.1 Tìm kiếm tuần tự vét cạn

#if 0 // Bài 5.2 Tìm kiếm tuần tự lính canh
	int x;
	printf("Nhap vao phan tu muon tim: ");
	scanf("%d", &x);
	int vt = TimKiemTuanTuLinhCanh(a, n, x);
	if (vt != n)
		printf("Tim thay phan tu %d tai vi tri %d\n", x, vt);
	else
		printf("Khong tim thay phan tu %d\n", x);
#endif // Bài 5.2 Tìm kiếm tuần tự lính canh

#if 0 // Bài 5.3 Tìm kiếm nhị phân (VD mảng đã sắp xếp tăng dần)
	int x;
	printf("Nhap vao phan tu muon tim: ");
	scanf("%d", &x);
	int vt = TimKiemNhiPhan(a, n, x);
	if (vt != -1)
		printf("Tim thay phan tu %d tai vi tri %d\n", x, vt);
	else
		printf("Khong tim thay phan tu %d\n", x);
#endif // Bài 5.3 Tìm kiếm nhị phân (VD mảng đã sắp xếp tăng dần)

#if 0 // Bài 6. Max chẵn < Min lẻ trong mảng
	int batdau = TimViTriLeDauTien(a, n);
	if (batdau != -1)
	{
		int SoLeNhoNhat = TimSoLeNhoNhat(a, n, batdau);
		printf("So le be nhat: %d\n", SoLeNhoNhat);
		printf("So chan lon nhat ma be hon cac so le trong mang: %d\n", SoLeNhoNhat - 1);
	}
	else
		printf("Khong tim thay phan tu le\n");
#endif // Bài 6. Max chẵn < Min lẻ trong mảng

#if 0 // Bài 7. Số có dạng 2^k
	int coso;
	printf("Nhap co so: ");
	scanf("%d", &coso);
	printf("Cac so co dang %d^k la: \n", coso);
	XuatCacSoDangAMuK(a, n, coso);
#endif // Bài 7. Số có dạng 2^k

#if 0 // Bài 8. Tìm số lẻ max
	int batdau = TimViTriLeDauTien(a, n);
	if (batdau != -1)
		printf("So le lon nhat: %d\n", TimSoLeLonNhat(a, n, batdau));
	else
		printf("Khong tim thay phan tu le\n");

#endif // Bài 8. Tìm số lẻ max

#if 0 // Vị trí cuối cùng của phần tử x trong mảng
	int x;
	printf("Nhap phan tu muon tim: ");
	scanf("%d", &x);
	int ViTriCuoi = TimViTriCuoiCung(a, n, x);
	if (ViTriCuoi != -1)
		printf("Vi tri cuoi cua %d la %d\n", x, ViTriCuoi);
	else
		printf("Phan tu %d khong co trong mang\n", x);
#endif // Vị trí cuối cùng của phần tử x trong mảng

#if 0 // Vị trí số nguyên tố đầu tiên trong mảng
	int vitri = TimViTriSoNguyenToDauTien(a, n);
	if (vitri != -1)
		printf("Vi tri so nguyen to dau tien: %d\n", vitri);
	else
		printf("Mang khong co so nguyen to\n");
#endif // Vị trí số nguyên tố đầu tiên trong mảng

#if 0 // Số nhỏ nhất trong mảng
	int min = SoBeNhatTrongMang(a, n);
	printf("So be nhat trong mang = %d\n", min);
#endif // Số nhỏ nhất trong mảng

#if 0 // Số dương nhỏ nhất trong mảng
	int SoDuongMin = TimSoDuongBeNhat(a, n);
	if (SoDuongMin > 0)
		printf("So duong be nhat trong mang la %d\n", SoDuongMin);
	else
		printf("Mang khong co so duong\n");
#endif // Số dương nhỏ nhất trong mảng

#if 0 // Bài 9. Nhập mã số nhân viên
	int a[MAX], n;
	do
	{
		printf("Nhap so luong nhan vien: ");
		scanf("%d", &n);
		if (n <= 0 || n > 100)
			printf("Nhap lai n\n");
	} while (n <= 0 || n > MAX);

	NhapNhanVien(a, n);
	printf("\nDanh sach MSNV vua nhap:\n");
	XuatNhanVien(a, n);
#endif // Bài 9. Nhập mã số nhân viên

	getch();
	return 0;
}