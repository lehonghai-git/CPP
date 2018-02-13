package tcp.month.year.server;

public class Process {

    public static String monthYear(int month, int year) {
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
