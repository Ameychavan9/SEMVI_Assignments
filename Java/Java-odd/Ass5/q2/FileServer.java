import java.io.*;
import java.net.*;

public class FileServer{
	public static void main(String args[])throws UnknownHostException,IOException{
		try{
			ServerSocket ss = new ServerSocket(4444);
			System.out.println("Server waiting for client...");
			Socket client = ss.accept();
			System.out.println(" Client Connected");
			BufferedReader br = new BufferedReader(new InputStreamReader(client.getInputStream()));
			PrintStream ps= new PrintStream(client.getOutputStream());
			String fname=br.readLine();
			File fp = new File(fname);
			ps.println(fname);
			if(fp.exists()){
				FileReader fr = new FileReader(fname);
				BufferedReader Br = new BufferedReader(fr);
				String s,rs="";
				while((s=Br.readLine())!=null){
					ps.println(s);
					System.out.println(s);
				}
				fr.close();
				Br.close();
			}
			else{
				ps.println("File not found Enter correct path..");
				br.close();
				ps.close();
				client.close();
			}
		}
		catch(IOException e){
			System.out.println(e);
		}
	}
}
