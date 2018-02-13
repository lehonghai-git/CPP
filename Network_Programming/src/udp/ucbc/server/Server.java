package udp.ucbc.server;

import java.io.*;
import java.net.*;
import java.util.logging.*;

/*
    Đề bài: Viết chương trình UDP Client/Server trong đó Client gửi lên Server 2 số nguyên
    Server xử lý và trả về Bội chung nhỏ nhất của 2 số
 */
public class Server {

    public void Server() {
        try {
            DatagramSocket socket = new DatagramSocket(2016);
            System.out.println("Server is running. . .");
            while (true) {
                // Tạo mảng lưu dữ liệu nhận
                byte[] receivea = new byte[1024];
                byte[] receiveb = new byte[1024];

                // Đóng gói dữ liệu nhận
                DatagramPacket Packeta = new DatagramPacket(receivea, receivea.length);
                socket.receive(Packeta);
                DatagramPacket Packetb = new DatagramPacket(receiveb, receiveb.length);
                socket.receive(Packetb);

                // Xử lý dữ liệu nhận từ client
                int a = Integer.parseInt(new String(Packeta.getData()).trim());
                int b = Integer.parseInt(new String(Packetb.getData()).trim());

                System.out.println("Form Client: a = " + a + " | b = " + b);
                int ucln = Process.UCLN(a, b);
                int bcnn = Process.BCNN(a, b);
                String result = "UCLN: " + ucln + "\nBCNN: " + bcnn;
                System.out.println(result);

                // Tạo mảng gửi trả kết quả cho Client
                byte[] sendData = result.getBytes();
                // Lấy Port và IP phía gửi
                InetAddress address = Packeta.getAddress();
                int port = Packeta.getPort();
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
