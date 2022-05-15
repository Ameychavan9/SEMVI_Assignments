
import java.io.*;
import java.net.*;

public class Client {
    public static void main(String[] args)throws UnknownHostException, IOException, FileNotFoundException, EOFException{
        Socket s = new Socket("localhost",4444);
        System.out.println("Connected to " + s.getInetAddress());

        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        DataInputStream in = new  DataInputStream(s.getInputStream());
        DataOutputStream out = new DataOutputStream(s.getOutputStream());
        
        System.out.print("Enter file name:");
        String fileName = input.readLine();

        out.writeUTF(fileName);

        while(true){

            String str = in.readUTF();
            System.out.println(str);

            if(str.equalsIgnoreCase("exit"))
                break;
        }

        s.close();
    }
}
