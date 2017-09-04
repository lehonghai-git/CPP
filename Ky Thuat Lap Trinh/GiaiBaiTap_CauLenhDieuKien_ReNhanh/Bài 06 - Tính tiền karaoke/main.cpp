/*
Tính tiền Karaoke
- Nếu thời gia thuê <= 3h tính 30000 đồng/giờ (Giảm 0%)
- Nếu thời gian thuê > 3h tính 21000 đồng/giờ (Giảm 30%)
- Trong khung giờ vàng: 8h-17h: Giảm thêm 10% tổng số tiền
Quán Karaoke mở cửa từ: 8h00 - 24h00
Viết chương trình nhập vào giờ bắt đầu và giờ kết thúc sau đó in ra số tiền khách phải trả.
*/
#include <stdio.h>
#include <conio.h>

#define GioMoCua 8
#define GioDongCua 24
#define GiaPhong 30000

int main()
{
	float GioVao, GioRa;
	printf("Gio vao: ");
	scanf("%f", &GioVao);

	if (GioVao < GioMoCua || GioVao > GioDongCua)
	{
		printf("Gio vao khong hop le\n");
		getch();
		return 0;
	}

	printf("Gio ra: ");
	scanf("%f", &GioRa);
	if (GioRa <= GioVao || GioRa > GioDongCua)
	{
		printf("Gio ra khong hop le\n");
		getch();
		return 0;
	}

	float ThoiGianThue = GioRa - GioVao;

	if (GioVao >= GioMoCua && GioRa <= 17) // Khung giờ vàng từ 8h - 17h
	{
		if (ThoiGianThue <= 3) // 3 giờ đầu
		{
			// Giảm 10% tổng tiền vì nằm trong khung giờ vàng
			float TienPhaiTra = ThoiGianThue * GiaPhong;
			float KhuyenMai = TienPhaiTra * 0.1;
			printf("So tien phai tra: %.2f\n", TienPhaiTra - KhuyenMai);
		}
		else // Thời gian thuê > 3
		{
			// KM1: Giảm 30% mỗi giờ do thời gian > 3h
			// KM2: Giảm 10% tổng tiền do khung giờ vàng
			float TienPhaiTra = ThoiGianThue * GiaPhong;
			float KhuyenMai1 = ThoiGianThue * (0.3*GiaPhong);
			float KhuyenMai2 = (TienPhaiTra - KhuyenMai1)*0.1;
			printf("So tien phai tra: %.2f\n", TienPhaiTra - KhuyenMai1 - KhuyenMai2);
		}

	}
	else if (GioVao > 17 && GioRa <= GioDongCua) // Khung giờ thường từ 18h - 24h
	{
		if (ThoiGianThue <= 3) // 3 giờ đầu
		{
			// Khung giờ thường + <= 3h => Không có khuyến mại
			float TienPhaiTra = ThoiGianThue * GiaPhong;
			printf("So tien phai tra: %.2f\n", TienPhaiTra);
		}
		else // Thời gian thuê > 3
		{
			// KM1: Giảm 30% cho mỗi giờ vì thời gian thuê >3h
			float TienPhaiTra = ThoiGianThue * GiaPhong;
			float KhuyenMai = ThoiGianThue * (0.3*GiaPhong);
			printf("So tien phai tra: %.2f\n", TienPhaiTra - KhuyenMai);
		}
	}
	else // Khung giờ giữa khung vàng và khung thường
	{
		// Khung giờ này sẽ có đoạn thuộc giờ vàng và đoạn thuộc giờ thường
		float GioVang = 17 - GioVao;
		float GioThuong = GioRa - 17;
		float TongTien = (GioVang + GioThuong) * GiaPhong;
		float KM1, KM2;

		if (GioVang <= 3)
			KM1 = (GiaPhong * GioVang) * 0.1; // Khuyên mại 10%
		else
		{
			float KM1_1 = GiaPhong * GioVang * 0.3; // Khuyến mại > 3h
			float KM1_2 = ((GioVang * GiaPhong) - KM1_1) * 0.1; // Khuyến mại Giờ vàng giảm 10%
			KM1 = KM1_1 + KM1_2;
		}

		if (GioThuong <= 3)
			KM2 = 0;
		else
			KM2 = GioThuong * GiaPhong * 0.3;

		printf("So tien phai tra: %.2f\n", TongTien - KM1 - KM2);
	}

	getch();
	return 0;
}