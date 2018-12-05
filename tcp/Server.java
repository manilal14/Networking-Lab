import java.io.*;
import java.net.*;

public class Server{
    public static void main(String[] args) throws Exception{

        ServerSocket ss = new ServerSocket(4000);
        System.out.println("Server is ready");

        Socket socket = ss.accept();

        DataInputStream dis = new DataInputStream(socket.getInputStream());
        System.out.println(dis.readUTF());

        dis.close();
        socket.close();
        ss.close();
    }
}