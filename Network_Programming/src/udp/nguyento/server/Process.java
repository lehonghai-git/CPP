package udp.nguyento.server;

public class Process {

    public static boolean KiemTraNT(int number) {
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

    public static String showNguyenTo(int number) {
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

}
