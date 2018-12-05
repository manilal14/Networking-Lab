import java.io.*;
import java.net.*;
import java.util.Scanner;

public class ServerForChat{
    public static void main(String[] args) throws Exception{

        ServerSocket ss = new ServerSocket(4000);
        System.out.println("Server is ready");
        Socket socket = ss.accept();

        System.out.println("Request accepted by the server");
        
        DataInputStream dis  =  new DataInputStream(socket.getInputStream());
        DataOutputStream dos =  new DataOutputStream(socket.getOutputStream());
        Scanner scan         = new Scanner(System.in);
        
        String s2 ="",s3 ="";
        
        while(true) {
            s2 = dis.readUTF();
            if(s2.equals("EXIT"))
                break;
            System.out.println("client said : "+s2);
            System.out.print("Me : ");
            s3 = scan.nextLine();
            dos.writeUTF(s3);
        }
        
        System.out.println("Server Terminated");

        dis.close();
        dos.close();
        scan.close();
        socket.close();
        ss.close();
    }
}