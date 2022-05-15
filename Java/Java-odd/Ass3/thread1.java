import java.util.*;
import java.io.*;

public class thread1
{
	public static void main(String[] args)throws InterruptedException ,IOException
	{
		BufferedReader Br = new BufferedReader(new InputStreamReader(System.in));
		int n;
		System.out.print("\n Enter the Value of n :  ");
		n=Integer.parseInt(Br.readLine());
		Thread t1 = new Thread("Welcome to FY");
		Thread t2 = new Thread("Welcome to SY");
		Thread t3 = new Thread("Welcome to TY");
		t1.start();
		t2.start();
		t3.start();
		for(int i=0;i<n;++i)
		{
			String st;
			st = t1.getName();
			System.out.println(st);
		//	t1.sleep(10000);
			st = t2.getName();
			System.out.println(st);
		//	t2.sleep(10000);
			st = t3.getName();
			System.out.println(st+"\n");
		//	t1.sleep(10000);
		//	t2.sleep(10000);
			Thread.sleep(10000);
			if(i<n-1)
			t3.sleep(10000);
		}
	}
}
