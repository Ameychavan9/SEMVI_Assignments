import java.util.*;
import java.io.*;

class SetUseingList{

	static LinkedList A = new LinkedList();
	static LinkedList B = new LinkedList();
	static LinkedList unionSet = new LinkedList();
	static LinkedList intersectionSet = new LinkedList();

	public static void main(String[] args){
		
		int n;
		String data;

		try{
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

			System.out.print("How many data elements are there  :");
			n = Integer.parseInt(br.readLine());
			
			for(int i = 0; i < n; i++){
				System.out.print("Enter data :");
				data = br.readLine();
				
				if(A.contains(data) && B.contains(data))
					continue;
				else if(A.contains(data))
					B.add(data);
				else
					A.add(data);
			}	

			System.out.println("Set A");
			print(A);
			System.out.println("B");
			print(B);
			union();
			System.out.println("union");
			print(unionSet);
			System.out.println("Intersection");
			intersection();
			print(intersectionSet);
			
		}
		catch(IOException e){
			System.out.println(e);
		}

		
	}


	static void print(LinkedList list){
		System.out.print("{");
		for(int i = 0; i < list.size(); i++)
			System.out.print(list.get(i) + ",");
		System.out.println("}");	
	}

	static void union(){

		for(int i = 0; i < A.size(); i++)
		{
			if(!unionSet.contains(A.get(i)))
				unionSet.add(A.get(i));
		}

		for(int i = 0; i < B.size(); i++)
		{
			if(!unionSet.contains(B.get(i)))
				unionSet.add(B.get(i));
		}
		
	}

	static void intersection(){
		for(int i = 0; i < A.size(); i++)
		{
			if(B.contains(A.get(i)))
				intersectionSet.add(A.get(i));
		}


		
	}
}





