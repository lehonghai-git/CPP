package udp.ucbc.server;

public class Process {

    public static int UCLN(int a, int b) {
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

    public static int BCNN(int x, int y) {
        x = Math.abs(x);
        y = Math.abs(y);
        return (x * y) / UCLN(x, y);
    }

}
