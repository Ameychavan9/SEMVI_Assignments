import java.io.*;
import java.net.*;

import java.util.*;

public class Server {
    public static void main(String[] args)throws UnknownHostException, IOException{
        ServerSocket ss = new ServerSocket(4000);

        System.out.println("Server started.");

        Socket s = ss.accept();
        System.out.println("Connected to client.");

        DataOutputStream out = new DataOutputStream(s.getOutputStream());

        Date now = new Date();
        out.writeUTF(now.toString());

        out.close();
        s.close();
        ss.close();
    }
}
