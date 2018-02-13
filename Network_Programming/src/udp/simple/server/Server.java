package udp.simple.server;

import java.io.*;
import java.net.*;
import java.util.logging.*;

/*
    Đề bài: Viết chương trình UDP Client/Server trong đó Client gửi lên Server một chuỗi ký tự
    Server xử lý và trả về chuỗi ký tự viết hoa cho Client
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
                String msg = new String(receivePacket.getData());
                // Xử lý chuỗi nhận được
                String msgUpper = msg.toUpperCase();
                System.out.println("From Client: " + msgUpper);

                // Tạo mảng gửi trả kết quả cho Client
                byte[] sendData = msgUpper.getBytes();

                // Lấy Port và IP phía gửi
                InetAddress address = receivePacket.getAddress();
                int port = receivePacket.getPort();
                // Đóng gói dữ liệu gửi gửi
                DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, address, port);
                socket.send(sendPacket);
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
/*
    Phía Server:
    B1:  Khởi tạo Socket, lắng nghe trên Port
    B2: Nhận
        - Tạo mảng Byte lưu dữ liệu nhận
        - Đóng gói dữ liệu nhận
        - Nhận dữ liệu đã được đóng gói
        
    B3: Gửi
        - Tạo mảng Byte lưu dữ liệu gửi
        - Lấy IP và Port của phía gửi từ Gói nhận được
        - Xử lý dữ liệu nhận được, lưu vào mảng Byte
        - Đóng gói dữ liệu gửi
        - Gửi dữ liệu đã đc đóng gói

 */
