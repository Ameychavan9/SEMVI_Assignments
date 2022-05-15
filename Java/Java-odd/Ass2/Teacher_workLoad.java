import java.sql.*;
import java.io.*;
 
public class Teacher_workLoad{
	static Statement st = null;
	static Connection conn = null;
	static ResultSet rs = null;
	
	public static void main(String[] args)throws IOException,SQLException,ClassNotFoundException{
		
	try{
		int ch,n;
		Class.forName("org.postgresql.Driver");
		conn = DriverManager.getConnection("jdbc:postgresql://192.168.16.1/ty8803","ty8803","");
		if(conn == null)
			System.out.println("Connection Failed");
		else
			System.out.println("Connection Sucessfull!!");

		st = conn.createStatement();
		BufferedReader Br=new BufferedReader(new InputStreamReader(System.in));
		while(true)
		{	
		System.out.print("\n \t\t MENU \n\t 1 : ADD RECORD \n\t 2 : Display Date wise Lecture Details \n\t 3 :Display Class Wise time Table\n\t 4 : Modify Record of specific Teacher \n\t 5 :Exit\n\n\t Enter your choice ==> ");	
		ch =Integer.parseInt(Br.readLine());
			switch(ch)
			{
			case 1:	Add_Record();
				break;
			case 2: Display_dateWiseLec();
				break;
			case 3: Display_classWise();
				break;
			case 4: Update_Record();
				break;
			case 5: System.exit(0);
		}
		}
		
	}
	catch( Exception e){
		System.out.println(e);
	}

/*	finally{
		rs.close();
		conn.close();
		st.close();
	}
*/	}


	static void Add_Record() throws IOException,SQLException
	{
		int t_id;
		String t_name,sqlQuery;
		
		BufferedReader Br=new BufferedReader(new InputStreamReader(System.in));
			System.out.println("\n Enter Teacher Id    : ");
			t_id =Integer.parseInt(Br.readLine());
			System.out.println("\n Enter Teacher Name  : ");	
			t_name =Br.readLine();
			sqlQuery = "Insert into Teacher Values (" +t_id+",'"+t_name+"');";  
			st = conn.createStatement();
			int p=st.executeUpdate(sqlQuery);	
			if(p==1)
				System.out.println("Record Added Sucessfully!!");					
	}

	static void Display_dateWiseLec()
	{
		
		int sub_code;
		String t_name,sub,date,time,Class,sqlQuery;
		try{
		BufferedReader Br=new BufferedReader(new InputStreamReader(System.in));
			System.out.println("\n Enter Teacher Name  : ");	
			t_name =Br.readLine();
		rs=st.executeQuery("Select teacher_name,workLoad.* from Teacher,workLoad where Teacher.teacher_id=workLoad.t_id and teacher_name ='"+t_name+"';");	
		System.out.println("Teacher_name |Sub_code| Subject| Date | Time  | Class | Teacher_ID |");
		while(rs.next())
		{
			System.out.print(rs.getString("teacher_name") +"\t| ");
			System.out.print(rs.getString("sub_code") + "\t| ");
			System.out.print(rs.getString("subject") + "\t| ");
			System.out.print(rs.getString("da") + "| ");
			System.out.print(rs.getString("time") + "| ");
			System.out.print(rs.getString("class") + " |");
			System.out.println(rs.getString("t_id") + " |");
		}
	}
		catch(Exception e){
		System.out.println(e);
			
		}
	}

	static void Display_classWise()
	{
		
		int sub_code;
		String c_name,sub,date,time,Class,sqlQuery;
		try{
		BufferedReader Br=new BufferedReader(new InputStreamReader(System.in));
			System.out.println("\n Enter Class Name  : ");	
			c_name =Br.readLine();
		rs=st.executeQuery("Select * from workLoad where class ='"+c_name+"';");	
			System.out.println("Sub_code| Subject| Date | Time  | Class |");
			while(rs.next())
			{
				System.out.print(rs.getString("sub_code") + "\t ");
				System.out.print(rs.getString("subject") + "\t ");
				System.out.print(rs.getString("da") + " ");
				System.out.print(rs.getString("time") + " ");
				System.out.println(rs.getString("class") + " ");
			}
		   }		
		catch(Exception e){
			System.out.println(e);		
		}
	}

	
	static void Update_Record()
	{
		
		int sub_code;
		String c_name,sub,date,time,Class,sqlQuery;
		try{
		 Display_dateWiseLec();	
		BufferedReader Br=new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter the Subject Code whose data is to be Modified==> ");
		sub_code =Integer.parseInt(Br.readLine());
		System.out.println("Enter Date (yyyy-mm-dd) ==> " );
		date =Br.readLine();
		System.out.println("Enter Time (hh:mm:ss)   ==> ");
		time =Br.readLine();
		System.out.println("Enter Class ==> ");
		Class =Br.readLine();
		sqlQuery = "Update workLoad Set da ='"+date+"',time='"+time+"',class='"+Class+"' where sub_code = "+sub_code+";";
		st = conn.createStatement();
		int p=st.executeUpdate(sqlQuery);	
		if(p==1)
			System.out.println("Record Updated Sucessfully!!");					
			
		   }		
		catch(Exception e){
			System.out.println(e);		
		}
	}

}


