import java.io.*;
import java.net.Socket;
import java.util.*;

public class ClientForChat {
    public static void main(String[] args) throws Exception{

        Socket socket = new Socket("localhost",4000);
        System.out.println("Connected to the server");
    
        DataInputStream dis  =  new DataInputStream(socket.getInputStream());
        DataOutputStream dos =  new DataOutputStream(socket.getOutputStream());
        Scanner scan         =  new Scanner(System.in);

        System.out.println("Enter message (to exit type 'EXIT')\nMe : ");
        
        String s1,s4=null;
        while(true){
            s1 = scan.nextLine();
            if(s1.equals("EXIT"))
                break;
            dos.writeUTF(s1);
            s4 = dis.readUTF();
            System.out.println("Server said : "+s4);
            System.out.print("Me : ");

        }
        
        System.out.println("Client left");
        dos.writeUTF("EXIT");

        dos.close();
        dis.close();
        socket.close();

    }
}