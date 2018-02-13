package rmi;

public class Process {

    public boolean KiemTraNT(int number) {
        if (number == 1 || number <= 0) {
            return false;
        } else if (number == 2) {
            return true;
        } else {
            for (int i = 2; i <= Math.sqrt(number); i++) {
                if (number % i == 0) {
                    return false;
                }
            }
        }
        return true;
    }

    public String showNguyenTo(int number) {
        String result = "";
        int tong = 0;
        for (int i = 0; i <= number; i++) {
            if (KiemTraNT(i)) {
                tong = tong + i;
                result = result + i + " | ";
            }
        }
        return result + "\nTổng NT là: " + tong;
    }

    public int UCLN(int a, int b) {
        a = Math.abs(a);
        b = Math.abs(b);
        if (a == 0 || b == 0) {
            return a + b;
        }
        while (a != b) {
            if (a > b) {
                a = a - b;
            } else {
                b = b - a;
            }
        }
        return a;
    }

    public int BCNN(int x, int y) {
        x = Math.abs(x);
        y = Math.abs(y);
        return (x * y) / UCLN(x, y);
    }

    public int Tong(int a, int b) {
        return a + b;
    }

    public String monthYear(int month, int year) {
        String result = "";
        switch (month) {
            case 4:
            case 6:
            case 9:
            case 11:
                result = "Có 30 ngày";
                break;
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                result = "Có 31 ngày";
                break;
            case 2:
                if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                    result = "Có 28 ngày";
                } else {
                    result = "Có 29 ngày";
                }
                break;
            default:
                result = "Nhập sai!";
        }
        return result;
    }
}
