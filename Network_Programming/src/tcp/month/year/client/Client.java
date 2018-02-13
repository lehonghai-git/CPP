package tcp.month.year.client;

import java.io.*;
import java.net.Socket;
import java.util.Scanner;

/*
    Đề bài: Viết Chương trình TCP Client/Server trong đó Client gửi lên Server một chuỗi
    Gồm tháng và năm (VD: "6/2020"), Server nhận giá trị và trả về cho Client thông báo
    số ngày của tháng đó (VD: "Tháng 6 năm 2020 có 30 ngày").
 */
public class Client {

    public void SocketClient() {

        try {
            Socket socket = new Socket("127.0.0.1", 2016);
            System.out.println("Connect to Server . . .");

            Scanner input = new Scanner(System.in);
            System.out.print("Nhập Tháng/Năm: ");
            String message = input.nextLine();

            DataOutputStream dataOutputStream = new DataOutputStream(socket.getOutputStream());
            DataInputStream dataInputStream = new DataInputStream(socket.getInputStream());

            // Gửi dữ liệu đi
            dataOutputStream.writeUTF(message); // writeUTF: Có hỗ trợ cả chuỗi dạng tiếng việt có dấu

            // Nhận kết quả
            String result = dataInputStream.readUTF();
            if (result != null) {
                System.out.println(result);
            } else {
                System.out.println("Chưa nhận được dữ liệu");
            }

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
