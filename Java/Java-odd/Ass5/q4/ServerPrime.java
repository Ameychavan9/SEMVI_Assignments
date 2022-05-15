import java.io.*;
import java.net.*;

public class ServerPrime{
	public static void main(String args[])throws UnknownHostException,IOException{
		try{
			boolean flag=false;
			ServerSocket ss = new ServerSocket(4444);
			System.out.println("Server waiting for client...");
			Socket client = ss.accept();
			System.out.println(" Client Connected");
			BufferedReader br = new BufferedReader(new InputStreamReader(client.getInputStream()));
			PrintStream ps= new PrintStream(client.getOutputStream());
			int number = Integer.parseInt(br.readLine());
			File fp = new File(number);
			ps.println(number);
			  for(int i=2;i<number/2;++i)
				{
					if(number%i==0)
					 {flag=true;
					  break;
					 }
				}   
			  		
			if(!flag)
			{	
				ps.println(number+ " is a prime number");
					System.out.println(number+ "is a prime number");
			}
			else
			{	
				ps.println(number+ " is not a prime number");
					System.out.println(number+ "is not a prime number");
			}
			
			br.close();
			ps.close();
			client.close();
			}
		catch(IOException e){
			System.out.println(e);
		}
	}
}
