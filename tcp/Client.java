import java.io.*;
import java.net.*;

public class Client {
    public static void main(String[] args) throws Exception{

        Socket socket = new Socket("localhost",4000);
        System.out.println("connected to server");
        
        DataOutputStream dos =  new DataOutputStream(socket.getOutputStream());
        dos.writeUTF("Message from Server");

        dos.close();
        socket.close();

    }
}