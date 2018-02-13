package udp.multicast.server;

import java.net.*;
import java.util.Scanner;

public class Server {

    public void Sender() {

        try {
            DatagramSocket socket = new DatagramSocket();
            Scanner input = new Scanner(System.in);
            String msg = "";
            while (true) {
                // Nhận dữ liệu từ phía người gửi
                System.out.print("Nhập: ");
                msg = input.nextLine();

                // Lưu dữ liệu vào mảng
                byte[] Result = msg.getBytes();

                InetAddress IP = InetAddress.getByName("224.2.2.2");
                DatagramPacket datagramPacket = new DatagramPacket(Result, Result.length, IP, 2016);
                socket.send(datagramPacket);
            }
        } catch (Exception ex) {
            System.out.println(ex.toString());
        }
    }

    public static void main(String[] args) {
        Server server = new Server();
        server.Sender();
    }

}
