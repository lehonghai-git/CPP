package rmi;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface MyInterface extends Remote {
    // Lớp Remote: Tượng trưng cho kiểu tham chiếu từ xa
    // Để gọi được từ xa cần extends Remote

    public int Tong(int a, int b) throws RemoteException;

    public boolean KiemTraNT(int number) throws RemoteException;

    public String showNguyenTo(int number) throws RemoteException;

    public int UCLN(int a, int b) throws RemoteException;

    public int BCNN(int a, int b) throws RemoteException;

    public String monthYear(int month, int year) throws RemoteException;

}
