#include <stdio.h>
#include <math.h>

/*
** Input    : Số nguyên dương n
** Output   : Có là số nguyên tố hay không
** IDE      : Visual Studio 2017
*/

int main()
{
	int n;
	do
	{
		printf("Nhap n (n > 0): ");
		scanf("%d", &n);
		if (n <= 0)
			printf("Nhap lai n\n");
	} while (n <= 0);

#if 1
	/*
	Cách 1: Không khuyến cáo dùng cách này. Vì:
	- Số lần lặp bằng với n nhập vào => Mỗi lần lặp đều phải so sánh và gán
	=> Cách này độ phức tạp thuật toán cao => Không tối ưu nếu n là số lớn
	*/
	int dem1 = 0, SoLanLap1 = 0;
	for (int i = 1; i <= n; i++)
	{
		SoLanLap1++; // Đếm số lần lặp để tính độ phức tạp thuật toán
		if (n % i == 0)
			dem1++;
	}

	if (dem1 == 2)
		printf("So %d la so nguyen to\n", n);
	else
		printf("So %d khong la so nguyen to\n", n);

	printf("So lan lap cach 1: %d\n", SoLanLap1);
	printf("-----------\n");
#endif // 1

#if 1
	/*
	Cách 2: Dựa trên cách 1 nhưng có cải tiến
	Số nguyên tố là số chỉ chia hết cho 1 và chính nó
	=> Cho vòng lặp chạy trong đoạn [2, n - 1]
	=> Loại 2 đc 2 giá trị là 1 và chính nó vì số nào mà chả chia hết cho 1 và chính nó
	Trong quá trình lặp nếu n chỉ cần chia hết cho một số nào đó trong đoạn [2, n-1] thì
	thoát vòng lặp và kết luận ngay số này không là số nguyên tố => vì nó đã chia hết cho ít nhất 3 số rồi
	Còn nếu chạy hết vòng lặp mà vẫn không rơi vào trường hợp kia thì nó chính là số nguyên tố
	=> Cách này chỉ nhanh hơn khi mà số nhập vào không phải là số nguyên tố
	*/
	int check2 = 1, dem2 = 0;
	if (n < 2)
		check2 = 0;
	else
	{
		for (int i = 2; i < n; i++)
		{
			dem2++;
			if (n % i == 0)
			{
				check2 = 0;
				break;
			}
		}
	}

	if (check2)
		printf("So %d la so nguyen to\n", n);
	else
		printf("So %d khong la so nguyen to\n", n);

	printf("So lan lap cach 2: %d\n", dem2);
	printf("-----------\n");
#endif // 1

#if 1
	/*
	Cách 3: Dựa trên cách 2 nhưng có cải tiến
	Với ý tưởng 2 thì sẽ duyệt vòng lặp từ [2, n-1] thì cách này vẫn phải duyệt đến tận n-1 (vẫn lớn nếu n lớn)
	Ta có: Một số n không bao giờ chia hết cho một số nằm trong đoạn [n/2, n-1]
	VD: Số 10 sẽ không thể chia hết cho các số trong đoạn [5, 9]
	=> Nếu có chia hết thì chỉ chia hết cho những số trong đoạn [2, n/2]
	=> Chỉ cần lặp đến n/2 => giảm số lần lặp đáng kể
	*/
	int check3 = 1, dem3 = 0;
	if (n < 2)
		check3 = 0;
	else
	{
		for (int i = 2; i <= n / 2; i++)
		{
			dem3++;
			if (n % i == 0)
			{
				check3 = 0;
				break;
			}
		}
	}

	if (check3)
		printf("So %d la so nguyen to\n", n);
	else
		printf("So %d khong la so nguyen to\n", n);

	printf("So lan lap cach 3: %d\n", dem3);
	printf("-----------\n");

#endif // 1

#if 1
	/*
	Cách 4: Dựa trên cách 3 nhưng có cải tiến
	Trong vòng lặp thì chỉ cần duyệt đến căn bậc 2 của n nhập vào.
	Không cần phải duyệt đến n/2 như cách 3
	=> Số lần lặp giảm nhiều hơn cả cách 3
	==> Cách 4 này cho tốc độ nhanh nhất
	*/
	int check4 = 1, dem4 = 0;
	if (n < 2)
		check4 = 0;
	else
	{
		for (int i = 2; i <= (int)sqrt((double)n); i++)
		{
			dem4++;
			if (n % i == 0)
			{
				check4 = 0;
				break;
			}
		}
	}

	if (check4)
		printf("So %d la so nguyen to\n", n);
	else
		printf("So %d khong la so nguyen to\n", n);

	printf("So lan lap cach 4: %d\n", dem4);
	printf("-----------\n");
#endif // 1

#if 1
	/*
	Cách 5: Kế thừa từ cách 4 (Những cách 2,3,4 đều dùng cách phản chứng minh: tức là chỉ cần đi tìm trường hợp sai là kết luận)
	Ta có: Trong các số nguyên tố thì chỉ có duy nhất số 2 là số nguyên tố chẵn
	còn lại các số nguyên tố khác đều là số lẻ => Lợi dụng
	*/
	int check5 = 1, dem5 = 0;
	if (n < 2)
		check5 = 0;
	else if (n > 2) // Trường hợp n == 2 sẽ không nhảy vào đây
	{
		if (n % 2 == 0)
			check5 = 0;
		else
		{
			for (int i = 3; i <= (int)sqrt((double)n); i += 2) // Chỉ xét số lẻ
			{
				dem5++;
				if (n % i == 0)
				{
					check5 = 0;
					break;
				}
			}
		}
	}

	if (check5)
		printf("So %d la so nguyen to\n", n);
	else
		printf("So %d khong la so nguyen to\n", n);

	printf("So lan lap cach 5: %d\n", dem5);
	printf("-----------\n");
#endif // 1
	getch();
	return 0;
}