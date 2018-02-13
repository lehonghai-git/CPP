package rmi;

import java.rmi.RemoteException;
import java.rmi.server.*;

public class TrienKhai extends UnicastRemoteObject implements MyInterface {

    Process process = new Process();

    // Constructor
    public TrienKhai() throws RemoteException {
    }

    @Override
    public boolean KiemTraNT(int number) throws RemoteException {
        System.out.println("Đang kiểm tra số nguyên tố");
        return process.KiemTraNT(number);
    }

    @Override
    public String showNguyenTo(int number) throws RemoteException {
        System.out.println("Đang gọi hàm Show Nguyên Tố");
        return process.showNguyenTo(number);
    }

    @Override
    public int UCLN(int a, int b) throws RemoteException {
        System.out.println("Đang tìm ước chung lớn nhất");
        return process.UCLN(a, b);
    }

    @Override
    public int BCNN(int a, int b) throws RemoteException {
        System.out.println("Đang tìm bội chung nhỏ nhất");
        return process.BCNN(a, b);
    }

    @Override
    public int Tong(int a, int b) {
        System.out.println("Đang Gọi hàm tính tổng ");
        return process.Tong(a, b);
    }

    @Override
    public String monthYear(int month, int year) throws RemoteException {
        System.out.println("Đang tìm số ngày trong tháng");
        return process.monthYear(month, year);
    }

}

// Lớp UnicastRemoteObject: Điểu khiển các hàm đã Triển Khai ra ngoài cổng thông qua Object của lớp TrienKhai
// Client kết nối tới để gọi hàm thực chất là kết nối tới Object của lớp TrienKhai
