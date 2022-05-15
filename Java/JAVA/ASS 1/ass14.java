import java.io.*;
import java.util.*;
class student
{
	int roll,age;
	String Name;
	
	student(int r ,int a, String n)
	{	
		this.roll=r;
		this.age=a;
		this.Name=n;
	}
}
class SortbyName implements Comparator<student>
{
	public int compare(student a ,student b)
	{
		return a.Name.compareTo(b.Name);
	}
}
class SortbyAge implements Comparator<student>
{
	public int compare(student a, student b)
	{
		return a.age-b.age;
	}
}
public class ass14{
	public  static void main(String a[]) throws IOException{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		ArrayList<student> stud = new ArrayList<student>() ;
		
	stud.add(new student(101,24,"Jay"));
	stud.add(new student(102,22,"Arjun"));
	stud.add(new student(103,20,"Harshit"));
	
	System.out.print("\n-----------------------");
	System.out.print("\nSorted By Name:  ");
	System.out.print("\n-----------------------");
	
	Collections.sort(stud,new SortbyName());
	
		for(int i=0; i<stud.size();i++)
		{
		System.out.println("\n Name : "+stud.get(i).Name+"\nRoll: "+stud.get(i).roll+"\nAge: "+stud.get(i).age);
		}
	System.out.print("\n-----------------------");
        System.out.print("\nSorted By Age:  ");
        System.out.print("\n-----------------------");

        Collections.sort(stud,new SortbyAge());

	for(int i=0; i<stud.size();i++)
                {
                System.out.println("\n Name : "+stud.get(i).Name+"\nRoll: "+stud.get(i).roll+"\nAge: "+stud.get(i).age);
		}

	}

}
			
