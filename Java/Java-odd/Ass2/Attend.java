import java.sql.*;
import java.io.*;
import java.util.Date;
import java.text.SimpleDateFormat;
//import java.sql.time.*;
 
public class Attend{
	static Statement st = null;
	static Connection conn = null;
	static ResultSet rs = null;
	
	public static void main(String[] args)throws IOException,SQLException,ClassNotFoundException{
		
	BufferedReader Br=new BufferedReader(new InputStreamReader(System.in));
		
	try{
		int n;		
		Class.forName("org.postgresql.Driver");
		conn = DriverManager.getConnection("jdbc:postgresql://192.168.16.1/ty8803","ty8803","");
		
		if(conn == null)
			System.out.println("Connection Failed");
		else
			System.out.println("Connection Sucessfull!!");

		st = conn.createStatement();	
	
		System.out.print("\n Enter the number of Students ==> ");;
		n=Integer.parseInt(Br.readLine());
		for(int i=0;i<n;++i)
		{
			Accept();
		}
		for(int i=0;i<n;++i)
		{
			Marks();
	
		}
	}
	catch( Exception e){
		System.out.println(e);
	}

	finally{
		//rs.close();
		//conn.close();
		//st.close();
		}
	}

	public static void Accept() throws IOException,SQLException
	{
		BufferedReader Br=new BufferedReader(new InputStreamReader(System.in));
		int rollno,total;
		String name,Class,Sub,sql_query;
		System.out.print("\n Enter the Roll no  ==>  ");	
		rollno=Integer.parseInt(Br.readLine());
		System.out.print("\n Enter the Name     ==>  ");	
		name=Br.readLine();
		System.out.print("\n Enter the Class    ==>  ");	
		Class=Br.readLine();
		System.out.print("\n Enter the Subject  ==>  ");	
		Sub=Br.readLine();
		System.out.print("\n Enter the total Attendance  ==>  ");	
		total=Integer.parseInt(Br.readLine());
	//	rs=st.executeQuery("DELETE FROM attendance");
		sql_query = "insert into attendance values("+rollno+",'"+name+"','"+Class+"','"+Sub+"',"+total+");";
		st = conn.createStatement();	
		int p = st.executeUpdate(sql_query);
		if(p==1)
			System.out.println("Data Added Sucessful");
	}
		
	public static void Marks()
	{
		int total_att =10;
		float per;
		String sql_query="Select * from attendance";
		try{
			rs = st.executeQuery(sql_query);
			System.out.println("\n Name \t| Marks\t|");
			while(rs.next())
			{
				per = rs.getInt(5)*(100/total_att);
				System.out.println(rs.getString("name")+"\t"+Math.ceil(per/10));
			}			
		}
		catch(Exception e)
		{
			System.out.println(e);
		}	
	}

}










































