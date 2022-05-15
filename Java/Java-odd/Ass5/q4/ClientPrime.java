import java.io.*;
import java.net.*;

public class ClientPrime{
	public static void main(String args[])throws UnknownHostException,IOException{
		try{
			Socket s = new Socket("localhost",4444);
			System.out.println("Client Connected");
			BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));
			BufferedReader Br = new BufferedReader(new InputStreamReader(System.in));
			PrintStream ps= new PrintStream(s.getOutputStream());
			System.out.println("Enter the number : ");
			int number=Integer.parseInt(Br.readLine());
			ps.println(number);
			Br.close();
			br.close();
			ps.close();
			s.close();
		}
		catch(IOException e){
			System.out.println(e);
		}
	}
}
