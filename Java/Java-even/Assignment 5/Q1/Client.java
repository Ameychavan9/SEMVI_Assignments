import java.io.*;
import java.net.*;

public class Client {
    public static void main(String[] args)throws UnknownHostException, IOException{
        Socket s = new Socket("localhost", 4000);

        DataInputStream out = new DataInputStream(s.getInputStream());

        System.out.println("Server machine Date & time :"+out.readUTF());
        s.close();
        out.close();
    }
}
