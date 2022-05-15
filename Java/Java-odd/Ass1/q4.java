import java.io.*;
import java.util.*;

class student{
	int roll,age;
	String Name;

	student(int r,int a,String n )
	{
		this.roll=r;
		this.age=a;
		this.Name=n;
	}
}

class SortbyName implements Comparator<student>
{
	public int compare(student a,student b)
	{
		return a.Name.compareTo(b.Name);
	}
}

class SortbyAge implements Comparator<student>
{
	public int compare(student a,student b)
	{
		return a.age-b.age;
	}
}

public class q4{
	public static void main(String []args) throws IOException{
		BufferedReader Br = new BufferedReader(new InputStreamReader(System.in));
		ArrayList<student> stud = new ArrayList<student> ();

		stud.add(new student(101,33,"Lalit")); 
		stud.add(new student(102,21,"Arjun")) ;
		stud.add(new student(103,23,"Rakesh"));
		
		System.out.println("\n -------------------------------------");
		System.out.println("\n Sorted by Name ");
		System.out.println("\n -------------------------------------");
		Collections.sort(stud,new SortbyName());
	
		for(int i=0;i<stud.size();i++)
		{
			System.out.println("\n Name : " +stud.get(i).Name+"\nRol no : " +stud.get(i).roll+"\nAge : "+ stud.get(i).age);		
		}		 

		System.out.println("\n -------------------------------------");
		System.out.println("\n Sorted by Age ");
		System.out.println("\n -------------------------------------");	
		Collections.sort(stud,new SortbyAge());
		for(int i=0;i<stud.size();i++)
		{
			System.out.println("\n Name : " +stud.get(i).Name+"\nRol no : " +stud.get(i).roll+"\nAge : "+ stud.get(i).age);		
		}		 
		
	}
} 








