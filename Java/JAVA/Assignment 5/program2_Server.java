import java.io.*;
import java.net.*;

class program2_Server
{
  public static void main(String args[])throws Exception
  {
   String str1,str2="",line;

   ServerSocket ss = new ServerSocket(2101);

   System.out.println("Server is Running.....");

   Socket s = ss.accept();

   System.out.println("Connection is Successfully established...");

   PrintStream ps = new PrintStream(s.getOutputStream());

   BufferedReader br1 = new BufferedReader(new InputStreamReader(s.getInputStream()));

   BufferedReader br2 = new BufferedReader(new InputStreamReader(System.in));

   str1=br1.readLine();
   File file = new File(str1);

   if(file.exists())
   {
    FileReader fr = new FileReader(str1);
    BufferedReader bobj = new BufferedReader(fr);

    while((line=bobj.readLine())!=null)
    {
     str2+=line;
    }
    ps.println(str2);
   }
   else
   {
    System.out.println("File is not there");
   }

   ps.close();
   br1.close();
   br2.close();
  }
}

