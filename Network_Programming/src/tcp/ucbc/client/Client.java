package tcp.ucbc.client;

import java.io.*;
import java.net.Socket;
import java.util.Scanner;
import java.util.logging.*;

/*
    Đề bài: Viết Chương trình TCP Client/Server trong đó Client gửi lên Server hai số
    nguyên a và b, Server nhận giá trị và trả về cho Client giá trị Bội chung nhỏ nhất
    của 2 số đó
 */
public class Client {

    public void SocketClient() {

        try {
            Socket socket = new Socket("127.0.0.1", 2016);
            System.out.println("Connect to Server . . .");

            Scanner input = new Scanner(System.in);
            System.out.print("Nhập a = ");
            int a = input.nextInt();
            System.out.print("Nhập b = ");
            int b = input.nextInt();

            DataOutputStream dataOutputStream = new DataOutputStream(socket.getOutputStream());
            DataInputStream dataInputStream = new DataInputStream(socket.getInputStream());

            try {
                // Gửi dữ liệu
                dataOutputStream.writeInt(a);
                dataOutputStream.writeInt(b);
                // Nhận kết quả
                int BCNN = dataInputStream.readInt();
                int UCLN = dataInputStream.readInt();
                System.out.println("BCNN: " + BCNN);
                System.out.println("UCLN: " + UCLN);
            } catch (Exception e) {
                System.out.println(e.toString());
            }

            // Đóng luồng gửi/nhận và kết nối
            dataInputStream.close();
            dataOutputStream.close();
            socket.close();
            System.out.println("Client is close!");

        } catch (IOException ex) {
            System.out.println(ex.toString());
        }
    }

    public static void main(String[] args) {
        Client client = new Client();
        client.SocketClient();
    }
}
