import java.io.*;
public class ass32 extends Thread{
	static int n;
	public void run()
	{
		if((this.getName()).equals("1"))
		{
		System.out.print("hello");
		for(int i=0;i<n;i++)
		{
			System.out.print("\nWelcome To FY\n:");
			try{
			Thread.sleep(2000);
			}
			catch(Exception e){
				System.out.print(e);
			}
		}
		}
		else if((this.getName()).equals("2"))
		{	
		for(int i=0;i<n;i++)	
			{
				System.out.print("\n Welcome To SY\n: ");
				try{
				Thread.sleep(1000);
				}
				catch(Exception e){
				System.out.print(e);
			}
		}
		}
		else if((this.getName()).equals("3"))
		{
		for(int i=0;i<n;i++)	
			{
				System.out.print("\n Welcome To TY\n: ");
				try{
				Thread.sleep(1000);
				}
				catch(Exception e){
				System.out.print(e);
			}
		}	

		}
}
 public static void main(String a[]) throws IOException{
	BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	System.out.print("Enter N:");
	n=Integer.parseInt(br.readLine());
	ass32 t1=new ass32();
	t1.setName("1");
	ass32 t2=new ass32();
        t2.setName("2");
	ass32 t3=new ass32();
        t3.setName("3");
	t1.start();
	t2.start();
	t3.start();
}
}


 
