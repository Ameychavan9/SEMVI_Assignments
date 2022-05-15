import java.sql.*;
import java.io.*;
import java.lang.Math;

class Student{
	static Connection conn = null;
	static Statement st = null;
	static ResultSet rs = null;

	public static void main(String[] args) throws IOException{
		int total_stds;

		Student.createConnection(); // create connection to database

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println("How many students are there :");
		total_stds = Integer.parseInt(br.readLine());

		for(int i = 0; i < total_stds; i++) // Accepting & storing data to database.
			Student.insertRecord();
		Student.printSummary();
		
	}

	static void createConnection(){
		try{
			Class.forName("org.postgresql.Driver");
			conn = DriverManager.getConnection("jdbc:postgresql://192.168.16.1/ty8810", "ty8810", "");
			st = conn.createStatement();

			st.execute("TRUNCATE attendance;"); // delete all previous records
		}
		catch(SQLException e){
			System.out.println(e);		
		}
		catch(ClassNotFoundException e){
			System.out.println(e);
		}
	}

	static void insertRecord(){
		int roll_no, total_atd;
		String name, class_, subject, sql_query, table_name = "attendance";

		try{
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			System.out.println("\nEnter details.");

			System.out.print("Roll No :");
			roll_no = Integer.parseInt(br.readLine());

			System.out.print("Name :");
			name = br.readLine();

			System.out.print("Class :");
			class_ = br.readLine();

			System.out.print("Subject :");
			subject = br.readLine();
		
			System.out.print("No of lectures attended :");
			total_atd = Integer.parseInt(br.readLine());

			sql_query = "INSERT INTO " + table_name + " VALUES(" +roll_no +",'" + name + "', '"+class_+"','"+subject+ "'," + total_atd +");";
			Student.st.executeUpdate(sql_query);
			System.out.println("Data added..");
							
		}
		catch(IOException e){
			System.out.println(e);
		}
		catch(SQLException e){
			System.out.println(e);
		}
	}

	static void printSummary(){
		int total_conducted = 10;
		float std_atd_per;
		String sql_query = "Select name, total_atd from attendance;";
		
		try{
			Student.rs = Student.st.executeQuery(sql_query);
			System.out.println("\nSummery\nName\tPercentage\n");
			while(rs.next()){
				std_atd_per = rs.getInt("total_atd") * (100/total_conducted);
				System.out.println(rs.getString("name") + " " + Math.ceil(std_atd_per/10));
			}	
		}
		catch(SQLException e){
			System.out.println(e);
		}
		/*catch(IOExceptin e){
			System.out.println(e);
		}*/
	}

}































