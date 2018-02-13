package udp.nguyento.server;

import java.io.*;
import java.net.*;
import java.util.logging.*;

/*
    Đề bài: Viết chương trình UDP Client/Server trong đó Client gửi lên Server một số nguyên
    Server nhận giá trị và trả về cho Client thông báo số đó có là số nguyên tố hay không.
    Nếu là số nguyên tố thì trả về danh sách các số nguyên tố <= n và tổng các số nguyên tố đó.
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
                // Tạo chuỗi lưu dữ liệu nhận được
                // Hàm trim() cắt khoảng trống 2 đầu của msg
                String msg = new String(receivePacket.getData()).trim();
                // Ép kiểu msg sang int
                int number = Integer.parseInt(msg);
                System.out.println("Form Client: " + number + "\n Waitting Process..!");
                // Xử lý và gửi trả kết quả
                if (Process.KiemTraNT(number)) {
                    String laNT = "La Nguyen To" + "\nDanh sach: " + Process.showNguyenTo(number);
                    byte[] sendData1 = laNT.getBytes();
                    InetAddress address1 = receivePacket.getAddress();
                    int port1 = receivePacket.getPort();
                    DatagramPacket sendPacket = new DatagramPacket(sendData1, sendData1.length, address1, port1);
                    socket.send(sendPacket);
                } else {
                    String khongLaNT = "Khong La Nguyen To";
                    byte[] sendData2 = khongLaNT.getBytes();
                    InetAddress address2 = receivePacket.getAddress();
                    int port2 = receivePacket.getPort();
                    DatagramPacket sendPacket = new DatagramPacket(sendData2, sendData2.length, address2, port2);
                    socket.send(sendPacket);
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
