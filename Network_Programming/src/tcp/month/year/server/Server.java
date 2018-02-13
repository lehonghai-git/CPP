package tcp.month.year.server;

import java.io.*;
import java.net.*;

/*
    Đề bài: Viết Chương trình TCP Client/Server trong đó Client gửi lên Server một chuỗi
    Gồm tháng và năm (VD: "6/2020"), Server nhận giá trị và trả về cho Client thông báo
    số ngày của tháng đó (VD: "Tháng 6 năm 2020 có 30 ngày").
 */
public class Server {

    public void SocketServer() {
        try {
            ServerSocket serverSocket = new ServerSocket(2016);
            System.out.println("Server is Running . . .");

            Socket socket = serverSocket.accept();
            System.out.println("Đã chấp nhận kết nối");

            DataInputStream dataInputStream = new DataInputStream(socket.getInputStream());
            DataOutputStream dataOutputStream = new DataOutputStream(socket.getOutputStream());

            String reciver = dataInputStream.readUTF();
            if (reciver != null) {
                try {
                    // Tách chuỗi sau đó lưu vào mảng
                    String Result[] = reciver.split("\\/");
                    // Ép kiểu
                    int month = Integer.parseInt(Result[0]);
                    int year = Integer.parseInt(Result[1]);
                    // Gửi trả kết quả
                    dataOutputStream.writeUTF("Tháng " + month + " năm" + " " + year + " " + Process.monthYear(month, year));
                } catch (Exception e) {
                    // Đoạn xử lý nếu người dùng nhập sai định dạng Tháng/Năm
                    dataOutputStream.writeUTF("Nhập sai định dạng " + e.toString());
                }
            } else {
                System.out.println("Chưa nhận được dữ liệu");
            }

            // Đóng luồng gửi/nhận và kết nối
            dataInputStream.close();
            dataOutputStream.close();
            serverSocket.close();
            System.out.println("Server is close!");

        } catch (IOException ex) {
            System.out.println(ex.toString());
        }

    }

    public static void main(String[] args) {
        Server server = new Server();
        server.SocketServer();
    }
}
