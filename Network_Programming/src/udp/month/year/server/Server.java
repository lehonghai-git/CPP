package udp.month.year.server;

import java.io.*;
import java.net.*;
import java.util.logging.*;

/*
    Đề bài: Viết Chương trình UDP Client/Server trong đó Client gửi lên Server một chuỗi
    Gồm tháng và năm (VD: "6/2020"), Server nhận giá trị và trả về cho Client thông báo
    số ngày của tháng đó (VD: "Tháng 6 năm 2020 có 30 ngày").
 */
public class Server {

    public void Server() {
        try {
            DatagramSocket socket = new DatagramSocket(2016);
            System.out.println("Server is running. . .");
            while (true) {
                // Tạo mảng lưu dữ liệu nhận
                byte[] receiveData = new byte[1024];
                // Đóng gói dữ liệu nhận
                DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
                // Nhận
                socket.receive(receivePacket);
                String msg = new String(receivePacket.getData()).trim();
                // Dùng hàm trim() để loại bỏ khoảng trắng ở đầu và cuối. Tránh bị lỗi trong quá trình tính toán
                System.out.println("From Client: " + msg);
                if (msg != null) {
                    try {
                        String str1[] = msg.split("\\/");
                        // Ép kiểu
                        int month = Integer.parseInt(str1[0]);
                        int year = Integer.parseInt(str1[1]);
                        String result = "Thang " + month + " nam" + " " + year + " " + Process.monthYear(month, year);
                        // Tạo mảng gửi trả kết quả cho Client
                        byte[] sendData = result.getBytes();
                        // Lấy Port và IP phía gửi
                        InetAddress address = receivePacket.getAddress();
                        int port = receivePacket.getPort();
                        // Đóng gói dữ liệu gửi gửi
                        DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, address, port);
                        // Gửi
                        socket.send(sendPacket);

                    } catch (Exception e) {
                        String str2 = "Ban phai nhap dung dinh dang Thang/Nam";
                        byte[] sendData2 = str2.getBytes();
                        InetAddress address2 = receivePacket.getAddress();
                        int port2 = receivePacket.getPort();
                        DatagramPacket sendPacket2 = new DatagramPacket(sendData2, sendData2.length, address2, port2);
                        socket.send(sendPacket2);
                    }
                } else {
                    System.out.println("Chưa nhận được dữ liệu.");
                }
            }

        } catch (SocketException ex) {
            Logger.getLogger(Server.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(Server.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    public static void main(String[] args) {
        Server server = new Server();
        server.Server();
    }
}
