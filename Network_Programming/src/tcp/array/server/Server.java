package tcp.array.server;

import java.io.*;
import java.net.*;
import java.util.Arrays;
import java.util.Random;
import java.util.logging.*;

/*
    Đề bài: Viết chương trình TCP Client/Server trong đó Client gửi lên một số nguyên dương n.
    Server tạo mảng có kích thước bằng n. Sinh ngẫu nhiên các phần tử trong mảng. Server gửi trả
    danh sách mảng ngẫu nhiên cho Client và Gửi Danh sách đã sắp xếp theo chiều tăng dần, giảm dần, phần tử MAX và MIN trong mảng
 */
public class Server {

    ServerSocket serverSocket = null;
    Socket socket = null;
    DataInputStream dataInputStream = null;
    DataOutputStream dataOutputStream = null;
    Random random = null;

    public void SocketServer() {

        try {
            serverSocket = new ServerSocket(2016);
            System.out.println("Server is Running . . .");
            socket = serverSocket.accept();
            System.out.println("Client successful connections!");

            dataInputStream = new DataInputStream(socket.getInputStream());
            int a = dataInputStream.readInt();

            int[] Mang = new int[a]; // Tạo mảng theo kích thước nhận đc
            System.out.println("Tạo mảng có kích thước bằng " + Mang.length);

            random = new Random();
            String danhSachMang = "";
            for (int i = 0; i < Mang.length; i++) {
                Mang[i] = random.nextInt(100); // Random: 0..99 các phần tử trong mảng
                danhSachMang += Mang[i] + " | "; // Lưu danh sách các phần tử trong mảng thành dạng chuỗi
                // danhSachMang = danhSachMang + Mang[i] + " | ";
            }
            System.out.println("Mảng ngẫu nhiên các phần tử: " + danhSachMang);// Show kết quả trên Server

            // Max, Min
            int _max = Process.TimMax(Mang);
            int _min = Process.TimMin(Mang);

            Arrays.sort(Mang); // Sắp xếp tăng dần
            String tangDan = "";
            for (int i = 0; i < Mang.length; i++) {
                tangDan += Mang[i] + " | "; // Lưu danh sách sắp xếp tăng dần thành chuỗi
            }
            
            // Sắp xếp giảm dần sau khi mảng đã được sắp xếp tăng dần
            String giamDan = "";
            for (int i = Mang.length - 1; i >= 0; i--) {
                giamDan += Mang[i] + " | "; // Lưu danh sách sắp xếp giảm dần thành chuỗi
            }

            dataOutputStream = new DataOutputStream(socket.getOutputStream());
            // Gom tất cả các kết quả thành một chuỗi để gửi
            String result = "DS Mảng: " + danhSachMang + "\n" + "Max: " + _max + " | " + "Min: " + _min + "\nTăng dần: " + tangDan + "\nGiảm dần: " + giamDan;
            // Gửi
            dataOutputStream.writeUTF(result);

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
