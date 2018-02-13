package udp.ucbc.client;

import java.io.*;
import java.net.*;
import java.util.Scanner;
import java.util.logging.*;

/*
    Đề bài: Viết chương trình UDP Client/Server trong đó Client gửi lên Server 2 số nguyên
    Server xử lý và trả về Bội chung nhỏ nhất của 2 số
 */
public class Client {

    public void Client() {
        try {
            DatagramSocket socket = new DatagramSocket();

            Scanner input = new Scanner(System.in);
            while (true) {
                System.out.print("a = ");
                String a = input.nextLine();
                System.out.print("b = ");
                String b = input.nextLine();

                // Chuyển Message vừa nhập sang byte, lưu vào mảng
                byte[] senda = a.getBytes();
                byte[] sendb = b.getBytes();

                InetAddress address = InetAddress.getByName("localhost");
                // Đóng gói để gửi
                DatagramPacket packet1 = new DatagramPacket(senda, senda.length, address, 2016);
                socket.send(packet1);
                DatagramPacket packet2 = new DatagramPacket(sendb, sendb.length, address, 2016);
                socket.send(packet2);

                // Tạo mảng nhận dữ liệu
                byte[] receiveData = new byte[1024*2];
                // Đóng gói dữ liệu nhận
                DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
                // Nhận
                socket.receive(receivePacket);
                // Xử lý dữ liệu nhận
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
