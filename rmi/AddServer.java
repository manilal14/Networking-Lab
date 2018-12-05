import java.rmi.Naming;

public class AddServer {
    public static void main(String args[]) throws Exception{

        ServerClass obj =  new ServerClass();
        Naming.rebind("abcd", obj);
        System.out.println("Server is running");
    }
}