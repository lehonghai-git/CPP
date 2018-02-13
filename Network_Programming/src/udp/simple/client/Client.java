package udp.simple.client;

import java.io.*;
import java.net.*;
import java.util.Scanner;
import java.util.logging.*;

/*
    Đề bài: Viết chương trình UDP Client/Server trong đó Client gửi lên Server một chuỗi ký tự
    Server xử lý và trả về chuỗi ký tự viết hoa cho Client
 */
public class Client {

    public void Client() {
        try {
            DatagramSocket socket = new DatagramSocket();

            Scanner input = new Scanner(System.in);
            while (true) {
                System.out.print("Me: ");
                String msg = input.nextLine();

                // Chuyển Message vừa nhập sang byte, lưu vào mảng
                byte[] sendData = msg.getBytes();

                InetAddress address = InetAddress.getByName("localhost");
                // Đóng gói để gửi
                DatagramPacket packet = new DatagramPacket(sendData, sendData.length, address, 2016);
                // Gửi
                socket.send(packet);

                // Tạo mảng nhận dữ liệu
                byte[] receiveData = new byte[1024];
                // Đóng gói dữ liệu nhận
                DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
                // Nhận
                socket.receive(receivePacket);
                // Xử lý dữ liệu nhận
                String result = new String(receivePacket.getData());

                System.out.println("From Server: " + result);
            }

        } catch (SocketException ex) {
            Logger.getLogger(Client.class.getName()).log(Level.SEVERE, null, ex);
        } catch (UnknownHostException ex) {
            Logger.getLogger(Client.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(Client.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    public static void main(String[] args) {
        Client client = new Client();
        client.Client();
    }
}
/*
    Phía Client:
    B1: Khởi tạo Socket
    B2: Nhận dữ liệu từ người dùng
    B3: Gửi:
        - Tạo mảng Byte lưu dữ liệu gửi
        - Chuyển dữ liệu sang Byte
        - Đóng gói dữ liệu gửi
        - Gửi dữ liệu đã đc đóng gói

    B4: Nhận
        - Tạo mảng Byte lưu dữ liệu nhận
        - Đóng gói dữ liệu nhận
        - Nhận dữ liệu đã được đóng gói
        - Chuyển dữ liệu nhận được sang String
    B5: Hiển thị kết quả

*/
