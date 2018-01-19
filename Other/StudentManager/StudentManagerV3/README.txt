Hoạt động:
- Khi nhập sinh viên từ File thì chương trình sẽ yêu cầu nhập mã trường
- Chương trình sẽ kiểm tra xem mã trường nhập vào sẽ có bao nhiêu file bên trong thư mục diemthi/
- Sinh số Thread ứng với số File. Mỗi Thread đọc 1 file sau đó nạp vào chương trình
- Khi thêm sinh viên mới vào file hoặc khi có thêm một file mới chứa danh sách các sinh viên mới thì cần phải update thủ công bằng cách nhập mã trường
- Khi chạy lại các thread nhập file thì chỉ update những file/sinh viên mới. Còn những sinh viên đã nạp trước đó sẽ bị bỏ qua hoặc thông báo trùng
- Thông tin sinh viên trong file vẫn được kiểm tra. Nếu thông tin sinh viên trong file bị trùng số báo danh, điểm thi sai, giới tính sai .. . thì chương trình bỏ qua thông tin sinh viên bị sai đó