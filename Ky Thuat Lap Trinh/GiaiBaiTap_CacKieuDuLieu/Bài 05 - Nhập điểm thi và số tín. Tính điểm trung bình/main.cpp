/*
- Nhập điểm thi và số tín chỉ tương ứng của 3 môn học
- Tính trung bình cộng của sinh viên đó
*/
#include <stdio.h>
#include <conio.h>

int main()
{
	float Toan, Ly, Hoa;
	int HeSoToan, HeSoLy, HeSoHoa;

	printf("Nhap diem Toan: ");
	scanf("%f", &Toan);
	printf("Nhap diem Ly: ");
	scanf("%f", &Ly);
	printf("Nhap diem Hoa: ");
	scanf("%f", &Hoa);

	printf("-------------\n");
	printf("Nhap he so Toan: ");
	scanf("%d", &HeSoToan);
	printf("Nhap he so Ly: ");
	scanf("%d", &HeSoLy);
	printf("Nhap he so Hoa: ");
	scanf("%d", &HeSoHoa);

	printf("-------------\n");
	float TBC = (Toan * HeSoToan + Ly * HeSoLy + Hoa * HeSoHoa) / (HeSoHoa + HeSoLy + HeSoToan);
	printf("TBC: %.3f\n", TBC);

	getch();
	return 0;
}