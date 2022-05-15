import java.util.*;
import java.io.*;

class Person{

	static Hashtable persons = new Hashtable();

	public static void main(String[] args){
		int n;
		String key, value;
		try{
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			
			System.out.print("Enter no of persons :");
			n = Integer.parseInt(br.readLine());

			for(int i = 0; i < n; i++){

				System.out.print("name :");
				key = br.readLine();
				
				System.out.print("Contact :");
				value = br.readLine();

				persons.put(key, value);

			}
			System.out.println("Hash Table :" + persons.toString());
			search();
			
		}
		catch(IOException e){
			System.out.println(e);
		}	
	}

	static void search(){
		Scanner sc = new Scanner(System.in);
		String key;

		System.out.print("Enter key to search :");
		key = sc.nextLine();

		if(persons.containsKey(key))
			System.out.println("Contact Number :" + persons.get(key));
		else
			System.out.println("Reasult not found.");
	}

	
}
