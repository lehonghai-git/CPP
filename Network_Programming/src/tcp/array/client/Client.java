package tcp.array.client;

import java.io.*;
import java.net.Socket;
import java.util.Scanner;
import java.util.logging.*;

/*
    Đề bài: Viết chương trình TCP Client/Server trong đó Client gửi lên một số nguyên dương n.
    Server tạo mảng có kích thước bằng n. Sinh ngẫu nhiên các phần tử trong mảng. Server gửi trả
    danh sách mảng ngẫu nhiên cho Client và Gửi Danh sách đã sắp xếp theo chiều tăng dần, giảm dần, phần tử MAX và MIN trong mảng
 */
public class Client {

    Socket socket;
    Scanner input;
    DataOutputStream dataOutputStream;
    DataInputStream dataInputStream;

    public void SocketClient() {

        try {
            socket = new Socket("localhost", 2016);
            System.out.println("Connect to Server . . .");

            input = new Scanner(System.in);
            System.out.print("Nhập số nguyên dương n = ");
            int a = input.nextInt();

            dataOutputStream = new DataOutputStream(socket.getOutputStream());
            dataOutputStream.writeInt(a);

            dataInputStream = new DataInputStream(socket.getInputStream());
            String nhanDS = dataInputStream.readUTF();
            System.out.println(nhanDS);

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
