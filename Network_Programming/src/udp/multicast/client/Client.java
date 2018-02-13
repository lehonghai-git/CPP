package udp.multicast.client;

import java.net.*;

/*
    Đề bài: Viết chương trình UDP Client/Server trong đó có nhiều client kết nối đến Server
    Server gửi cùng một lúc thông điệp đến tất cả các Client kết nối tới nó
 */
public class Client {

    public void Receiver() {
        try {
            MulticastSocket socket = new MulticastSocket(2016);
            InetAddress addr = InetAddress.getByName("224.2.2.2");
            socket.joinGroup(addr);

            byte[] receiveData = new byte[1024];
            while (true) {
                // Đóng gói nhận
                DatagramPacket datagramPacket = new DatagramPacket(receiveData, receiveData.length);
                // Nhận
                socket.receive(datagramPacket);

                // String Result = new String(receiveData, 0, receiveData.length);
                String Result = new String(datagramPacket.getData());
                System.out.println("From Server: " + Result);
            }
        } catch (Exception ex) {
            System.out.println(ex.toString());
        }
    }

    public static void main(String[] args) {
        Client client = new Client();
        client.Receiver();
    }
}
/*
    - Địa chỉ Multicast chính là các địa chỉ trong dải địa chỉ lớp D.
    - Dải địa chỉ lớp D: 224.x.x.x đến 239.x.x.x
    - Địa chỉ Multicast đại diện cho một nhóm các client
 */
