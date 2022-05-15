
import java.io.*;
import java.net.*;

public class Server{
    public static void main(String[] args) throws UnknownHostException, IOException, FileNotFoundException {
        ServerSocket ss = new ServerSocket(4444);

        System.out.println("Server started.");

        Socket s = ss.accept();
        System.out.println("Connected to client.");
        
        DataInputStream in = new DataInputStream(s.getInputStream());

        DataOutputStream out = new DataOutputStream(s.getOutputStream());

        String fileName = in.readUTF();
        File f = new File("./files/"+fileName);
        if(f.exists() && !f.isDirectory()){
            System.out.print(f.getName());
            BufferedReader fip = new BufferedReader(new FileReader(f));
            String str;
            while((str = fip.readLine()) != null )
            {
                out.writeUTF(str);
            }
            out.writeUTF("exit");

            fip.close();
        }
        else
        {
            out.writeUTF("file does not exists.");
            out.writeUTF("exit");


        }
        s.close();
        ss.close();
    }
}