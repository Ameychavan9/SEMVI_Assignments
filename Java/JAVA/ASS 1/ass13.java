import java.util.*;
import java.io.*;
	public class ass13{
			public static void main(String a[]) throws IOException{
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			System.out.print("\n enter the number of flavors: ");
			int n =Integer.parseInt(br.readLine());
			String c,s;
			Hashtable<String,Integer> flav=new Hashtable	<String,Integer>();
			for(int i=0;i<n;i++)	
			{
				System.out.print("\nEnter the name of flavor : "+(i+1)+" :");
				s=br.readLine();
				if(flav.containsKey(s))
				{	
					System.out.println("\nDuplicate Entries are not allowed : ");
					i--;
					continue;
				}	
				System.out.println("\nEnter the price of flavor : ");
				int price=Integer.parseInt(br.readLine());
				flav.put(s,price);
			}	
			while(true)	
			{
				System.out.print("\n1.Search specific Flavor:");
				 System.out.print("\n2.Sort all the flavor:");
				 System.out.print("\n3.Exit:");
				 System.out.print("\n\n Enter Your Choise:");	
				
				c=br.readLine();
				switch(c)
				{
					case "1":
						System.out.print("\n Enter the name of Flavor:");
						s=br.readLine();
						if(flav.containsKey(s))
						{
							System.out.print("\n Flavor Name :"+s+"\nprice : "+flav.get(s));
						}
						else
							System.out.print("\nFlavor Not Found\n");	
							break;
				case "2":
						TreeMap<String,Integer> tm=new TreeMap<String,Integer>(flav)	;
						Set<String> keys = tm.keySet();
						Iterator<String> itr=keys.iterator();
						System.out.print("\nFlavors in sorted order:\n");
						while(itr.hasNext())
						{
							String i=itr.next();
							System.out.println(i+" "+ tm.get(i));
						}		
					case "3":		
						System.exit(0);
				}
			}
	}
}
				
