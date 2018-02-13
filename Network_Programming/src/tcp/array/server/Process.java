package tcp.array.server;

public class Process {

    public static int TimMax(int[] Mang) {
        int _Max = Mang[0];
        for (int i = 1; i < Mang.length; i++) {
            if (_Max < Mang[i]) {
                _Max = Mang[i];
            }
        }
        return _Max;
    }

    public static int TimMin(int[] Mang) {
        int _Min = Mang[0];
        for (int i = 1; i < Mang.length; i++) {
            if (_Min > Mang[i]) {
                _Min = Mang[i];
            }
        }
        return _Min;
    }
}
