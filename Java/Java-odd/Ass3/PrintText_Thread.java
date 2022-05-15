import java.util.*;
import java.io.*;

class PrintText_Thread extends Thread
{
	String msg="";
	int n;
	PrintText_Thread(String msg,int n){
		this.msg=msg;
		this.n=n;
	}

	public void run()
	{
		try{
			for(int i=0;i<n;++i)
			{
				
			}
		}
	}
	
	
	public static void main(String[] args) throws IOException,InterruptedException{
		PrintText_Thread P[] = new PrintText_Thread[3]  ;
		BufferedReader Br = new BufferedReader(new InputStreamReader(System.in));
		for(int i=0;i<3;++i)
		{
		System.out.println("\n Enter the value of n ==> ");
		int n = Integer.parseInt(Br.readLine());
		System.out.println("\n Enter the text  ==> ");
		String text = Br.readLine();
		P[i]  = new PrintText_Thread(text,n);
		P[i].start();
		}
	}
}
