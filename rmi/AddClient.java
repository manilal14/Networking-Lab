import java.rmi.Naming;

public class AddClient{
    public static void main(String[] args) throws Exception{

        ServerInterface obj = (ServerInterface) Naming.lookup("rmi://localhost/abcd");
        double d = obj.add(8.2, 5.1);
        System.out.println("Sum "+d);
    }
}