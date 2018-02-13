package tcp.nguyento.server;

import java.io.*;
import java.net.*;
import java.util.logging.*;

/*
    Đề bài: Viết Chương trình TCP Client/Server trong đó Client gửi lên Server một số
    nguyên dương n, Server nhận giá trị và trả về cho Client thông báo số đó có là số
    nguyên tố hay không và nếu là số nguyên tố thì trả về danh sách các số nguyên tố <= n
    và tổng các số nguyên tố đó.
 */
public class Server {

    ServerSocket serverSocket;
    Socket socket;
    DataInputStream dataInputStream;
    DataOutputStream dataOutputStream;

    public void SocketServer() {

        try {
            serverSocket = new ServerSocket(2016);
            System.out.println("Server is Running . . .");

            socket = serverSocket.accept();
            System.out.println("Client successful connections!");

            dataInputStream = new DataInputStream(socket.getInputStream());
            int a = dataInputStream.readInt();

            dataOutputStream = new DataOutputStream(socket.getOutputStream());

            if (Process.KiemTraNT(a)) {
                dataOutputStream.writeUTF("Là Nguyên tố \nDanh sách NT: " + Process.showNguyenTo(a));
            } else {
                dataOutputStream.writeUTF("Không là Nguyên tố");
            }

        } catch (IOException ex) {
            Logger.getLogger(Server.class.getName()).log(Level.SEVERE, null, ex);
        } finally {
            try {
                dataInputStream.close();
                dataOutputStream.close();
                serverSocket.close();
                System.out.println("Server closed!");
            } catch (IOException ex) {
                Logger.getLogger(Server.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }

    public static void main(String[] args) {
        Server server = new Server();
        server.SocketServer();
    }
}
