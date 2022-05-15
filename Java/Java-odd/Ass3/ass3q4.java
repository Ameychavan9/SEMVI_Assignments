import java.io.*;
import java.lang.String.*;

class ass3q4 extends Thread
{
	String msg="";
	int n;
	ass3q4(String msg,int n)
	{
		this.msg=msg;
		this.n=n;
	}
	public void run()
	{
		try
		{
			for(int i=1;i<=n;i++)
			{
				System.out.println("msg "+i+" times");
			}
			System.out.println("\n");
		}
		catch(Exception e)
		{}
	}
}
	class PrintText
	{
		public static void main(String[] a)
		{
			int n=Integer.parseInt(a[0]);
			ass3q4 t1=new ass3q4("This is message from thread 1",n);
			t1.start();
			ass3q4 t2=new ass3q4("This is message from thread 2",n+10);
			t2.start();
			ass3q4 t3=new ass3q4("This is message from thread 3",n+20);
			t3.start();
		}
	}

