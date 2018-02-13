package rmi;

import java.rmi.*;
import java.rmi.registry.*;

public class RMIServer {

    public static void main(String[] args) {
        try {
            TrienKhai trienKhai = new TrienKhai();

            // Cách 1:
            LocateRegistry.createRegistry(2016); // Tạo RMI Registry
            Registry registry = LocateRegistry.getRegistry(2016); // GET Registry về
            registry.bind("process1", trienKhai); // Đăng ký đối tượng lên RMI Registry 

/*
            // Cách 2: Dùng Naming.rebind
            // Cách này dùng Port mặc định của RMI Registry là 1099
            LocateRegistry.createRegistry(1099); // Tạo RMI Registry
            Naming.rebind("process2", trienKhai); // Đăng ký đối tượng lên RMI Registry 

            System.out.println("Server is Running...");
            System.out.println("Đang chờ Client gọi hàm");
*/
        } catch (Exception ex) {
            System.out.println(ex.toString());
        }
    }
}
/*
- Lớp Interface dùng chung
    + Quy ước ra những hàm gọi từ xa. Triển khai nó trên Server
    + Client dựa vào nó để biết có những hàm gì mà gọi
 */
