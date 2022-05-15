import java.io.*;
import java.net.*;
import java.text.SimpleDateFormat;
import java.util.*;

class program1_Client
{
  public static void main(String args[])throws Exception
  {
   String str1,str2;

   System.out.println("Client is running....");

   Socket s = new Socket("localhost",2101);

   PrintStream ps = new PrintStream(s.getOutputStream()); 
  
   BufferedReader br1 = new BufferedReader(new InputStreamReader(s.getInputStream()));

   BufferedReader br2 = new BufferedReader(new InputStreamReader(System.in));

   SimpleDateFormat simple = new SimpleDateFormat("dd/MM/yyyy HH:mm:ss");

   Date dt = new Date();

   simple.setTimeZone(TimeZone.getTimeZone("IST"));

   str1=simple.format(dt);

   String Arr[]=str1.split(" "); 

   System.out.println(Arr[1]);

   ps.println(Arr[0]);

   ps.close();
   br1.close();
   br2.close();  
  }
}
