package udp.month.year.client;

import java.io.*;
import java.net.*;
import java.util.Scanner;
import java.util.logging.*;

/*
    Đề bài: Viết Chương trình UDP Client/Server trong đó Client gửi lên Server một chuỗi
    Gồm tháng và năm (VD: "6/2020"), Server nhận giá trị và trả về cho Client thông báo
    số ngày của tháng đó (VD: "Tháng 6 năm 2020 có 30 ngày").
 */
public class Client {

    public void Client() {
        try {
            DatagramSocket socket = new DatagramSocket();

            Scanner input = new Scanner(System.in);
            while (true) {
                System.out.print("Nhập Tháng/Năm: ");
                String msg = input.nextLine();

                // Chuyển Message vừa nhập sang byte, lưu vào mảng
                byte[] sendData = msg.getBytes();

                InetAddress address = InetAddress.getByName("localhost");
                // Đóng gói để gửi
                DatagramPacket packet = new DatagramPacket(sendData, sendData.length, address, 2016);
                // Gửi
                socket.send(packet);
                
                // Tạo mảng nhận dữ liệu
                byte[] receiveData = new byte[1024*3];
                // Đóng gói dữ liệu nhận
                DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
                // Nhận
                socket.receive(receivePacket);
                // Xử lý gói nhận được
                String result = new String(receivePacket.getData());

                System.out.println("From Server: \n" + result);
                 
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
