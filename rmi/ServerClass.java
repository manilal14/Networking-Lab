import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class ServerClass extends UnicastRemoteObject implements ServerInterface{

    public ServerClass() throws RemoteException {super();}

    public double add(double d1 , double d2 ) throws RemoteException{
        return d1+d2;
    }

}