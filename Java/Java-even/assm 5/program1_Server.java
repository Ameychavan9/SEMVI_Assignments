import java.io.*;
import java.net.*;

class program1_Server
{
  public static void main(String args[])throws Exception
  {
   String str1,str2;

   ServerSocket ss = new ServerSocket(2101);

   System.out.println("Server is Running.....");

   Socket s = ss.accept();

   System.out.println("Connection is Successfully established...");

   PrintStream ps = new PrintStream(s.getOutputStream());

   BufferedReader br1 = new BufferedReader(new InputStreamReader(s.getInputStream()));

   BufferedReader br2 = new BufferedReader(new InputStreamReader(System.in));

   str1=br1.readLine();

   System.out.println(str1);

   ps.close();
   br1.close();
   br2.close();
  }
}
