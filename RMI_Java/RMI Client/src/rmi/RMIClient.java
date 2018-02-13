package rmi;

import java.rmi.*;
import java.rmi.registry.*;

public class RMIClient {

    public static void main(String[] args) {
        try {

            // Cách 1:
            Registry registry = LocateRegistry.getRegistry("localhost", 2016); // GET Registry về
            MyInterface myInterface = (MyInterface) registry.lookup("process1"); // Tìm kiếm đối tượng có thể triệu gọi hàm thông qua tên (process1) đã đăng ký
            System.out.println("Server trả về: " + myInterface.monthYear(6, 2020));
            System.out.println("Server trả về: " + myInterface.showNguyenTo(17));


/*
            // Cách 2 dùng Naming.lookup
            MyInterface myInterface = (MyInterface) Naming.lookup("process2"); // Tìm kiếm đối tượng có thể triệu gọi hàm thông qua tên (process2) đã đăng ký
            System.out.println("Server trả về: " + myInterface.Tong(10, 15));
            System.out.println("Server trả về: " + myInterface.BCNN(4, 6));
*/
        } catch (Exception ex) {
            System.out.println(ex.toString());
        }

    }
}
/*
- Naming.lookup("rmi://localhost/TrienKhai") => Trả về một Object kiểu Remote
- Phía Server Object này sẽ thông nối với Lớp Skel
- Phía Client Object này sẽ thông nối với Lớp Stub
 */

 /*
   * Lập trình phân tán RMI (Remote Method Invocation)
    - Server:
        1. Khai báo và cài đặt thủ tục
        2. Đăng ký thủ tục lên RMI Registry
    - RMI Registry
        1. Tiếp nhận các đăng ký thủ tục từ phía Server
        2. Trả về thủ tục khi phía Client có yêu cầu tìm kiếm thủ tục
    - Client:
        1. Tìm kiếm thủ tục trên RMI Registry
        2. Thực hiện thủ tục
 */
