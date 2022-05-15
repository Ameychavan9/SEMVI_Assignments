import java.io.*;
import java.net.*;

public class FileClient{
	public static void main(String args[])throws UnknownHostException,IOException{
		try{
			Socket s = new Socket("localhost",4444);
			System.out.println("Client Connected");
			BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));
			BufferedReader Br = new BufferedReader(new InputStreamReader(System.in));
			PrintStream ps= new PrintStream(s.getOutputStream());
			System.out.println("Enter File name : ");
			String fname=Br.readLine();
			ps.println(fname);
			String s1;
			s1=br.readLine();
			while(s1!=null){
				System.out.println(s1);
				s1=br.readLine();
			}
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
