import java.util.*;
import java.io.*;

public class q3
	{
		public static void main(String args[])throws IOException{
			BufferedReader Br = new BufferedReader(new InputStreamReader(System.in));
			System.out.println("Enter the number of flavours: -");
			int n=Integer.parseInt(Br.readLine());
			String s;
			Hashtable<String,Integer> flav = new Hashtable <String,Integer>();
			for(int i=0;i<n;++i)
			{
				System.out.println("\n Enter the name of Flavour  "+(i+1)+" :");
				s= Br.readLine();
				if(flav.containsKey(s))
				{
					System.out.println("\n Duplicate Entries are not allowed ");
					i--;
					continue;
				}
				System.out.println("\n Enter the Price of Flavour  "+(i+1)+" :");
				int Price=Integer.parseInt(Br.readLine());
				flav.put(s,Price);
			}

			while(true)
			{
				System.out.print("\n 1. Search Specific Flavour\n 2. Sort all the flavours\n 3. Exit\n Enter your Choice ==> ");
				int c=Integer.parseInt(Br.readLine());
				switch(c)
				{
					case 1:System.out.print("\n Enter the name of Flavour ==> ");
						s=Br.readLine();
						if(flav.containsKey(s))
						{
						System.out.print("\n Name of Flavour ==> "+s+" \n Price ==> "+ flav.get(s));
						}
						else
						System.out.print("\n Flavour Not Found");
						break;
					case 2:
						TreeMap<String,Integer> tmp = new TreeMap <String,Integer>(flav);
						Set<String> keys = tmp.keySet();
						Iterator<String> itr = keys.iterator();
						System.out.print("\n Flavours in Sorted order :\n");

						while(itr.hasNext())
						{
							String i = itr.next();
							System.out.println(i+" "+tmp.get(i));
						}
						break;
					case 3:System.exit(0);
				}
			}
		}
	}
