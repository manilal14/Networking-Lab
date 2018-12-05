import java.rmi.Remote;

public interface ServerInterface extends Remote{
    double add(double d1 ,double d2) throws Exception;  
}