import java.net.*;
import java.io.*;

public class Client_{

	public static void main(String[] args) throws UnknownHostException, IOException{

		InputStream in = null;
		String fn;
		Socket s = new Socket("localhost", 4444);
		System.out.println(s.getInetAddress());
		

		PrintStream ps = new PrintStream(s.getOutputStream());
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		System.out.println("Enter file name.");
		
		fn = br.readLine();
		ps.print(fn);

		BufferedReader bs = new BufferedReader(new InputStreamReader(s.getInputStream()));

		System.out.println("File content\n"+bs.readLine());		

		s.close();
	}
}
