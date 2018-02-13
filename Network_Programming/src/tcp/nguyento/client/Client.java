package tcp.nguyento.client;

import java.io.*;
import java.net.Socket;
import java.util.Scanner;
import java.util.logging.*;

/*
    Đề bài: Viết Chương trình TCP Client/Server trong đó Client gửi lên Server một số
    nguyên dương n, Server nhận giá trị và trả về cho Client thông báo số đó có là số
    nguyên tố hay không và nếu là số nguyên tố thì trả về danh sách các số nguyên tố <= n
    và tổng các số nguyên tố đó.
 */
public class Client {

    Socket socket;
    Scanner input;
    DataOutputStream dataOutputStream;
    DataInputStream dataInputStream;

    public void SocketClient() {

        try {
            socket = new Socket("localhost", 2016); // 127.0.0.1 = localhost
            System.out.println("Connect to Server . . .");

            input = new Scanner(System.in);
            System.out.print("Nhập số nguyên dương n = ");
            int a = input.nextInt();

            dataOutputStream = new DataOutputStream(socket.getOutputStream());
            dataInputStream = new DataInputStream(socket.getInputStream());

            try {
                // Gửi dữ liệu lên Socket để đưa đến Server
                dataOutputStream.writeInt(a);
                // Nhận kết quả từ Socket mà Server đã gửi lên
                String result = dataInputStream.readUTF();
                // In kết quả
                if (result != null) {
                    System.out.println(result);
                } else {
                    System.out.println("Chưa nhận được kết quả");
                }
            } catch (Exception e) {
                System.out.println(e.toString());
            }

        } catch (IOException ex) {
            Logger.getLogger(Client.class.getName()).log(Level.SEVERE, null, ex);
        } finally {
            try {
                dataInputStream.close();
                dataOutputStream.close();
                socket.close();
                System.out.println("Client closed!");
            } catch (IOException ex) {
                Logger.getLogger(Client.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }

    public static void main(String[] args) {
        Client client = new Client();
        client.SocketClient();
    }
}
