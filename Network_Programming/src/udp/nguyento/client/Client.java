package udp.nguyento.client;

import java.io.*;
import java.net.*;
import java.util.Scanner;
import java.util.logging.*;

/*
    Đề bài: Viết chương trình UDP Client/Server trong đó Client gửi lên Server một số nguyên
    Server nhận giá trị và trả về cho Client thông báo số đó có là số nguyên tố hay không.
    Nếu là số nguyên tố thì trả về danh sách các số nguyên tố <= n và tổng các số nguyên tố đó.
 */
public class Client {

    public void Client() {
        try {
            DatagramSocket socket = new DatagramSocket();

            Scanner input = new Scanner(System.in);
            while (true) {
                System.out.print("Nhập số nguyên n: ");
                String msg = input.nextLine();

                // Chuyển Message vừa nhập sang byte, lưu vào mảng
                byte[] sendData = msg.getBytes();

                InetAddress address = InetAddress.getByName("localhost");
                // Đóng gói để gửi
                DatagramPacket packet = new DatagramPacket(sendData, sendData.length, address, 2016);
                // Gửi
                socket.send(packet);

                // Tạo mảng nhận dữ liệu
                byte[] receiveData = new byte[1024*4];
                // Đóng gói dữ liệu nhận
                DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
                // Nhận
                socket.receive(receivePacket);
                // Xử lý dữ liệu nhận
                String result = new String(receivePacket.getData()).trim();

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
