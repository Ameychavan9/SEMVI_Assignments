
import java.io.*;
import java.net.*;

public class Server{
    public static void main(String[] args) throws UnknownHostException, IOException, FileNotFoundException {
        ServerSocket ss = new ServerSocket(4444);
	int i =0, count = 0;

        System.out.println("Server started.");

        Socket s = ss.accept();
        System.out.println("Connected to client.");
        
        DataInputStream in = new DataInputStream(s.getInputStream());

        DataOutputStream out = new DataOutputStream(s.getOutputStream());

	int num = Integer.parseInt(in.readUTF());
	System.out.println(num);

	for(i = 1; i <= num; i++)
	{
		if(num%i == 0)
			count++;
	}
	if(count > 2)
		System.out.println(num + "is not prime.");
	else 
				System.out.println(num + "is prime.");
     
        s.close();
        ss.close();
    }
}
