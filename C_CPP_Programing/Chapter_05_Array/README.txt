** TÌM KIẾM
Bài 1:
Nhập vào mảng một chiều các số nguyên. In ra màn hình các số đối xứng, số amstrong và tính tổng các số đối xứng, số amstrong?
- Số Amstrong là số mà Tổng mỗi chữ số mũ lên theo số lượng chữ số bằng chính nó.
VD: 153
Có 3 chữ số
1^3 + 5^3 + 3^3 = 153
------------------------------
Bài 2
- Nhập mảng một chiều các số nguyên. Kiểm tra mảng có toàn là các số chẵn hay không? Liệt kê các số hoàn thiện
có trong mảng? Nếu mảng không có số hoàn thiện thì xuất ra thông báo "Khong co so hoan thien".
- Số hoàn thiện là số mà tổng các ước số nhỏ hơn nó cộng lại bằng chính nó
VD: 6, 28, 496, 8128
+ Các ước số nhỏ hơn 6: 1, 2, 3 => 1 + 2 + 3 = 6
------------------------------
Bài 3
- Tìm kiếm phần tử x xem có nằm trong mảng hay không? Nếu có trả về vị trí
của phần tử x, nếu không trả về -1
------------------------------
Bài 4
Tìm giá trị âm lớn nhất, dương bé nhất trong mảng các số nguyên
VD: 2 -2 4 6 9 -10 7 9
=> Âm lớn nhất: -2
=> Dương bé nhất: 2
------------------------------
Bài 5
* Thao tác tìm kiếm một phần tử trong mảng
- Tìm kiếm tuần tự (Tuyến tính)
	+ Vét Cạn (cách cùi bắp nhất nhưng dễ hiểu)
	+ Lính Canh
- Tìm kiếm nhị phân
------------------------------
Bài 6
Tìm số chẵn lớn nhất nhỏ hơn mọi giá trị lẻ có trong mảng một chiều các số nguyên
------------------------------
Bài 7
Tìm số có dạng 2^k trong mảng
Công thức: Loga(b) / Loga(c) = Logc(b)
Log2(2^k) = k là số nguyên thì x có dạng 2^k
VD: Log2(8) = Log2(2^3) = 3
Log10(8) / Log10(2) = Log2(8)
<=>
Log2(x) = Log10(x) / Log10(2)
------------------------------
Bài 8
Tìm số lẻ lớn nhất trong mảng. Nếu mảng không có số lẻ thì thông báo là không có.
------------------------------
Bài 9
Nhập vào mã số của nhân viên. Nếu mã số nhân viên nhập sau mà trùng với mã số
nhân viên nhập trước đó thì sẽ phải nhập lại cho tới khi nhập đúng.
------------------------------
Bài 10
Tìm vị trí cuối cùng của phần tử x trong mảng
------------------------------
Bài 11
Tìm vị trí số nguyên tố đầu tiên trong mảng nếu có
------------------------------
Bài 12
Tìm số min trong mảng
------------------------------
Bài 13
Tìm số dương min trong mảng
------------------------------

** ĐẾM
Bài 1
Đếm số lượng các giá trị phân biệt có trong mảng. In ra màn hình các giá trị phân biệt đó
VD: 1 1 2 3 3 3 1 2
=> 3 phần tử phân biệt: 1 2 3
--------------------
Bài 2
a. Đếm số lần xuất hiện của các phần tử có trong mảng.
VD: 1 2 3 4 5 6 5 5 1 1 1 2 4 3 3 3 3
Số 1: 4 lần
Số 2: 2 lần
Số 3: 5 lần
Số 4: 2 lần
Số 5: 3 lần
Số 6: 1 lần

* Ý tưởng:
Đứng từ vị trí hiện tại ta đi xét về các phần tử đứng trước
đó xem có bị trùng giá trị hay không? Nếu bị trùng thì bỏ qua
Nếu không thì chạy từ vị trí đó về sau và đếm xem có bao nhiêu
phần tử trùng với nó, in ra số lượng

b. Tìm ra các số nguyên có tần suất xuất hiện nhiều nhất và
xuất ra số nguyên đó kèm theo số lần xuất hiện.
VD1: 1 2 3 4 5 6 6 6 7 8
=> Phần tử 6 xuất hiện 3 lần
VD2: 1 2 2 2 5 6 6 6 7 8 8 8
=> Phần tử 2, 6, 8 xuất hiện 3 lần
--------------------
Bài 3
Đếm các số  chẵn trong mảng 1 chiều các số nguyên
--------------------
** SẮP XẾP
Bài 1
Sắp xếp mảng số nguyên theo chiều:
- Tăng dần
- Giảm dần
- Chỉ sắp xếp các số lẻ tăng dần. VD: 7 4 1 4 1 3 6 => 1 4 1 4 3 7 6
--------------------
** THÊM
Bài 1
- Thao tác thêm một phần tử mới vào trong mảng.
- Thêm số 0 (hoặc số nào đó tùy đề bài) vào sau tất cả các phần tử chẵn trong mảng.
VD: Mảng: 1 2 3 4 5 6
=> 1 2 0 3 4 0 5 6 0
- Thêm giá trị 69 vào đằng sau các số có chữ số tận cùng là 9
VD: 1 13 69 2 23 69 33 69 3 69 43 69 9
--------------------
** XÓA
- Thao tác xóa một phần tử trong mảng.
- Xóa tất cả các sỗ chẵn có trong mảng
- Xóa tất cả các phần tử max trong mảng. VD: 1 2 3 9 6 9 6 9 6 2 => 1 2 3 6 6 6 2
- Xóa tất cả các phần tử có chữ số đầu là 5. VD: 5, 51, 500, 5000...
--------------------
** TÍNH TỔNG
1. Nhập vào mảng số nguyên, hãy tính tổng các phần tử mà có chữ số hàng chục = 5.
2. Tổng các số nguyên tố cho mảng
3. Có bao nhiêu số chia hết cho 4 nhưng không chia hết cho 5
--------------------
** KỸ THUẬT ĐẶT CỜ HIỆU
1. Kiểm tra mảng số nguyên có tồn tại 2 giá trị 0 liên tiếp hay không?
--------------------
** TÁCH MẢNG
1. Nhập vào mảng 1 chiều các số nguyên.
- Tách các số chẵn ra 1 mảng
- Tách các số lẻ ra một mảng
- Tách các số nguyên tố ra một mảng
- Tách các số chính phương ra một mảng
--------------------
** GỘP MẢNG
1. Gộp mảng đã tách theo thứ tự lẻ trước sau đó đến chẵn
lẻ: 1 3 4 5 7
chẵn: 2 4 6 8
=> Gộp thành: 1 3 4 5 7 2 4 6 8
--------------------
** TẠO MẢNG PHỤ
1. Nhập vào mảng số nguyên, hãy đếm tần suất xuất hiện của từng
"chữ số" trong mảng. Các chữ số xuất ra không trùng nhau (phân biệt)
VD: 111 222 333 123 696 969
Số 1: 4 lần
Số 2: 4 lần
Số 3: 4 lần
Số 6: 3 lần
Số 9: 3 lần

* Ý tưởng 1: Với mỗi phần tử trong mảng, sau khi tách được từng chữ số của
phần tử đó thì đưa chữ số đó vào mảng phụ. Cuối cùng mảng phụ sẽ chứa tất
cả các chữ số của các phần tử. Bài toán trở thành đếm tần suất xuất hiện
như bài đã làm trước kia.
=> Cách làm này tốn bộ nhớ khi mảng chính có số phần tử lớn và số chữ số lớn

* Ý tưởng 2: Do các chữ số chỉ chạy từ 0-9
Khởi tạo một mảng phụ với 10 phần tử. Ta quy ước các chỉ số từ 0..9 cũng chính
là các chữ số bóc tách ra được từ các phần tử của mảng chính. Cứ mỗi lần bóc đc
chữ số con của một phần tử ở mảng chính thì ta tăng giá trị của phần tử ở mảng
phụ tương ứng lên 1 đơn vị. Kết quả là được 1 mảng phụ chứa số lần xuất hiện của
các số từ 0..9.
VD:
Mảng chính			 : 111 222 333 123 696 969
Khởi tạo Mảng phụ	 : 0 0 0 0 0 0 0 0 0 0
Chỉ số mảng phụ		 : 0 1 2 3 4 5 6 7 8 9
Mảng phụ sau khi đếm : 0 4 4 4 0 0 3 0 0 3

2. Tìm các giá trị trong mảng một chiều các số nguyên xa giá trị x nhất
VD: 15 50 23 21 10 9 5
x = 10
Khoảng cách từ x = 15 đến các phẩn tử trong mảng:
	5 40 13 11 0 1 5
=> Giá trị trong mảng xa x nhất là: 50
--------------------
** KIỂM TRA TÍNH CHẤT CỦA MẢNG
Bài 1
Kiểm tra một mảng xem có phải mảng đối xứng hay không?
VD:
- Mảng đối xứng: 1 2 3 2 1; 1 2 2 1; 1
- Mảng không đối xứng: 1 2 4 5; 1 2 3; 1 2
VD: 1 2 3 4 5 4 3 2 1 (n = 9, n/2 = 4 => vị trí 4 là vị trí ở giữa)
So sánh các cặp:
	a[0] vs a[8]
	a[1] vs a[7]
	a[2] vs a[6]
	a[3] vs a[5]
	------------
	a[x] vs a[y]
X chạy từ 0 đến n/2 -1
	0 <= x < n/2
Ta có: x + y = n-1 => y = n-1-x
=> Công thức chung là so sánh: a[x] vs a[y] <=> a[x] vs a[n-1-x]
--------------------
Bài 2
- Kiểm tra xem mảng có là tăng dần hay không
- VD mảng tăng dần: 1 2 3 4 5 6 hoặc 1 1 2 3 4 4 5 6 6
--------------------
Bài 3
Kiểm tra xem mảng có phải toàn là nguyên tố hay không
--------------------