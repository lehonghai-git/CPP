package tcp.ucbc.server;

import java.io.*;
import java.net.*;

/*
    Đề bài: Viết Chương trình TCP Client/Server trong đó Client gửi lên Server hai số
    nguyên a và b, Server nhận giá trị và trả về cho Client giá trị Bội chung nhỏ nhất
    của 2 số đó
 */
public class Server {

    public void SocketServer() {
        try {
            ServerSocket serverSocket = new ServerSocket(2016);
            System.out.println("Server is Running . . .");

            Socket socket = serverSocket.accept();
            System.out.println("Đã chấp nhận kết nối");

            DataInputStream dataInputStream = new DataInputStream(socket.getInputStream());
            DataOutputStream dataOutputStream = new DataOutputStream(socket.getOutputStream());

            try {
                // Nhận dữ liệu
                int a = dataInputStream.readInt();
                int b = dataInputStream.readInt();
                // Xử lý và gửi trả kết quả
                dataOutputStream.writeInt(Process.BCNN(a, b));
                dataOutputStream.writeInt(Process.UCLN(a, b));
            } catch (Exception e) {
                dataOutputStream.writeUTF(e.toString());
            }

            dataInputStream.close();
            dataOutputStream.close();
            serverSocket.close();
            System.out.println("Server is close!");

        } catch (IOException ex) {
            System.out.println(ex.toString());
        }

    }

    public static void main(String[] args) {
        Server server = new Server();
        server.SocketServer();
    }
}
