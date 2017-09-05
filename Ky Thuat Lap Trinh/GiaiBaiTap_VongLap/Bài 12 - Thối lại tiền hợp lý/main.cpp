/*
Các mệnh giá tiền:
500, 1000, 2000, 5000, 10000, 20000, 50000, 100000, 200000, 500000,
Nhập vào giá tiền của sản phẩm
Nhập vào số tiền khách trả. Tính số tiền mà nhân viên phải trả lại sao cho số tờ tiền là ít nhất
VD: Mua hàng hết 3000, khách trả 20000 => Trả lại 17000
17000 = 1 * 10000 + 1 * 5000 + 1 * 2000
*/
#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
	unsigned long GiaSanPham, SoTienTra;
	do
	{
		printf("Nhap gia san pham: ");
		scanf("%d", &GiaSanPham);
		if (GiaSanPham <= 0)
			printf("Nhap lai gia tien cua san pham\n");
	} while (GiaSanPham <= 0);

	do
	{
		printf("Nhap so tien khach tra: ");
		scanf("%d", &SoTienTra);
		if (SoTienTra < GiaSanPham)
			printf("So tien tra khong duoc nho hon gia san pham\n");
	} while (SoTienTra < GiaSanPham);

	/*
	900k - 4k = 896k
	896k / 500k = 1 tờ
	896k % 500k = 396k

	396k / 200k = 1 tờ
	396k % 200k = 196k

	196k / 100k = 1 tờ
	196k % 100k = 96k

	96k / 50k = 1 tờ
	96k % 50k = 46k

	46k / 20k = 2 tờ
	46k % 20k = 6k

	6k / 5k = 1 tờ
	6k % 5k = 1k

	1k / 1k = 1 tờ
	1k % 1k = 0 => end
	*/

	unsigned long SoTienThoi = SoTienTra - GiaSanPham;
	printf("So tien tra lai khach: %d\n", SoTienThoi);
	printf("------------\n");
	while (SoTienThoi != 0)
	{
		// Số tiền trả lại hàng trăm nghìn
		if ((log10((float)SoTienThoi) + 1) >= 6) // 100k, 200k, 500k, ..
		{
			if (SoTienThoi >= 500000) // Trên 500k
			{
				int SoToNamTram = SoTienThoi / 500000;
				SoTienThoi %= 500000; // Cập nhật lại số tiền sau khi chia
				printf("So to 500k: %d\n", SoToNamTram);
			}

			if (SoTienThoi < 500000 && SoTienThoi >= 200000) // Từ 200k đến 499k
			{
				int SoToHaiTram = SoTienThoi / 200000;
				SoTienThoi %= 200000; // Cập nhật lại số tiền sau khi chia
				printf("So to 200k: %d\n", SoToHaiTram);
			}

			if (SoTienThoi < 200000 && SoTienThoi >= 100000)// từ 100k đến 199k
			{
				int SoToMotTram = SoTienThoi / 100000;
				SoTienThoi %= 100000; // Cập nhật lại số tiền sau khi chia
				printf("So to 100k: %d\n", SoToMotTram);
			}
		}

		// Số tiền trả lại hàng chục nghìn
		if ((log10((float)SoTienThoi) + 1) >= 5) // 10k, 20k, 50k, ..
		{
			if (SoTienThoi >= 50000) // Trên 50k
			{
				int SoToNamChuc = SoTienThoi / 50000;
				SoTienThoi %= 50000; // Cập nhật lại số tiền sau khi chia
				printf("So to 50k: %d\n", SoToNamChuc);
			}

			if (SoTienThoi < 50000 && SoTienThoi >= 20000) // Từ 20k đến 49k
			{
				int SoToHaiChuc = SoTienThoi / 20000;
				SoTienThoi %= 20000; // Cập nhật lại số tiền sau khi chia
				printf("So to 20k: %d\n", SoToHaiChuc);
			}

			if (SoTienThoi < 20000 && SoTienThoi >= 10000)// từ 10k đến 19k
			{
				int SoToMotChuc = SoTienThoi / 10000;
				SoTienThoi %= 10000; // Cập nhật lại số tiền sau khi chia
				printf("So to 10k: %d\n", SoToMotChuc);
			}
		}

		// Số tiền trả lại hàng nghìn
		if ((log10((float)SoTienThoi) + 1) >= 4) // 1k, 2k, 5k, ..
		{
			if (SoTienThoi >= 5000) // Trên 50k
			{
				int SoToNamNghin = SoTienThoi / 5000;
				SoTienThoi %= 5000; // Cập nhật lại số tiền sau khi chia
				printf("So to 5k: %d\n", SoToNamNghin);
			}

			if (SoTienThoi < 5000 && SoTienThoi >= 2000) // Từ 2k đến 4,9k
			{
				int SoToHaiNghin = SoTienThoi / 2000;
				SoTienThoi %= 2000; // Cập nhật lại số tiền sau khi chia
				printf("So to 2k: %d\n", SoToHaiNghin);
			}

			if (SoTienThoi < 2000 && SoTienThoi >= 1000)// từ 10k đến 19k
			{
				int SoToMotNghin = SoTienThoi / 1000;
				SoTienThoi %= 1000; // Cập nhật lại số tiền sau khi chia
				printf("So to 1k: %d\n", SoToMotNghin);
			}
		}

		// Số tiền trả lại hàng trăm
		if ((log10((float)SoTienThoi) + 1) >= 3) // 100, 200, 500, ..
		{
			if (SoTienThoi >= 500) // Trên 500
			{
				int SoToNamTram = SoTienThoi / 500;
				SoTienThoi %= 500; // Cập nhật lại số tiền sau khi chia
				printf("So to 500: %d\n", SoToNamTram);
			}
		}
	}
	printf("------------\n");
	getch();
	return 0;
}