import java.io.*;
import java.net.*;

class program2_Client
{
  public static void main(String args[])throws Exception
  {
   String str1,str2;

   System.out.println("Client is running....");

   Socket s = new Socket("localhost",2101);

   PrintStream ps = new PrintStream(s.getOutputStream());

   BufferedReader br1 = new BufferedReader(new InputStreamReader(s.getInputStream()));

   BufferedReader br2 = new BufferedReader(new InputStreamReader(System.in));

   System.out.println("Enter the Name of text file : ");
   str1=br2.readLine();

   ps.println(str1);

   str2=br1.readLine();
   System.out.println(str2);

   ps.close();
   br1.close();
   br2.close();
  }
}

