import java.io.*;
import java.net.*;

class program3_Client
{
  public static void main(String args[])throws Exception
  {
   String str1,str2;

   System.out.println("Client is running....");

   Socket s = new Socket("localhost",2101);

   PrintStream ps = new PrintStream(s.getOutputStream());

   BufferedReader br2 = new BufferedReader(new InputStreamReader(s.getInputStream()));

   BufferedReader br1 = new BufferedReader(new InputStreamReader(System.in));

   int i=1;
   while(i!=10)
   {
    str1=br2.readLine();
    str2=br2.readLine();
    System.out.println(str1);
    String Arr[]=str2.split(" ");
    System.out.println(Arr[0]);
    System.out.println(Arr[1]);
    System.out.println(Arr[2]);
    System.out.println(Arr[3]);

    String res;
    System.out.println("Enter Your Choice : ");
    res=br1.readLine();
    ps.println(res);
    i++;
   }
   System.out.println("Your Score is : "+br2.readLine());

   s.close();
   ps.close();
   br1.close();
   br2.close();
  }
}

