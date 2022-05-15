import java.sql.*;
import java.io.*;
import java.util.Scanner;


class Employee{

	
	static Connection conn = null;
	static Statement st = null;
	static ResultSet rs = null;

	
	Employee() {
		// creating connection to database
		try{
			Class.forName("org.postgresql.Driver");
			conn = DriverManager.getConnection("jdbc:postgresql://192.168.16.1/ty8810" ,"ty8810", "");
			st = conn.createStatement(); // to create statement 
		}
		catch(SQLException e){
			System.out.println(e);
		}
		catch(ClassNotFoundException e){
			System.out.println(e);
		}
	} 

	public static void main(String[] arg)throws SQLException, IOException{
		int choice;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		try{
			Employee emp = new Employee();
			do{
				System.out.println("\nChoose operation from below:");
				System.out.println("\t1.Insert Data\n\t2.Modify data\n\t3.Delete Record");
				System.out.print("\t4.Search\n\t5.View all Rcords\n\t6.Exit\n\t>>>");
				choice = Integer.parseInt(br.readLine());
				
				switch(choice){
					case 1:
						emp.insertRecord();
						break;
					case 2:
						emp.changeRecord();
						break;
					case 3:
						emp.deleteRecord();
						break;
					case 4:
						emp.searchRecord();
						break;
					case 5:
						emp.viewAll();
						break;
					case 6:
						choice = 106;
						break;
					default:
						System.out.println("Choose correct operatin");
				}
						
			}while(choice != 106);
		
			
		}
		catch(Exception e){
			System.out.println(e);
		}
		finally{
			//rs.close();
			st.close();
			conn.close();		
		}
	}

	// method to add new record to database
	void insertRecord(){
		try{
			String emp_name, sql_query, table_name = "employee";
			float salary = 0.0f;
			
			Scanner sc = new Scanner(System.in);
			System.out.println("\nEnter employee details.");
			System.out.print("Employee Name :");
			emp_name = sc.nextLine();

			System.out.print("Salary :");
			salary = sc.nextFloat();
		
			sql_query = "INSERT INTO "+ table_name +"(emp_name, salary) VALUES" + "('" + emp_name + "'," + salary +");";
			Employee.st.executeUpdate(sql_query); // insert data to database
			System.out.println("Data Added\n");
		}
		catch(SQLException e){
			System.out.println(e);
		}
		catch(Exception e){
			System.out.println(e);
		}
	}

	// method to modify a record
	void changeRecord(){
		int emp_id, choice;
		float salary;
		String emp_name,sql_query, table_name="employee";			
	
		try{
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			System.out.print("\nEnter employee id to update details :");
			emp_id = Integer.parseInt(br.readLine());
		
			System.out.println("Add updated values for employee with id = "+ emp_id + "\n");
			System.out.println("Employee Name : ");
			emp_name = br.readLine();

			System.out.println("Salary : ");
			salary = Float.parseFloat(br.readLine());		
			
			sql_query = "UPDATE " + table_name + " SET " +"emp_name=\'"+ emp_name + "\', "+ "salary=" + salary+  "WHERE empid="+emp_id+";"; 
			Employee.st.executeUpdate(sql_query);
			System.out.println("Updated...\n");
		}
		catch(SQLException e){
			System.out.println(e);
		}
		catch(IOException e){
			System.out.println(e);
		}
	}

	//method to delete records from database
	void deleteRecord(){
		int emp_id;
		String sql_query, table_name = "employee";
		try{
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			System.out.print("\nEnter employee id to delete :");
			emp_id = Integer.parseInt(br.readLine());
			sql_query = "DELETE FROM " + table_name + " WHERE empid=" + emp_id + ";";
			Employee.st.executeUpdate(sql_query);
			System.out.println("Deleted......");
			System.out.println("");
		}
		catch(SQLException e){
			System.out.println(e);
		}
		catch(IOException e){
			System.out.println(e);
		}
	}

	// method to search in database
	void searchRecord(){
		String emp_name, sql_query, table_name = "employee";
		try{
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			System.out.println("\nEnter name of employee to search :");
			emp_name = br.readLine();
				
			sql_query = "SELECT * FROM " + table_name + " WHERE emp_name=\'"+ emp_name +"\';";
			Employee.rs = Employee.st.executeQuery(sql_query);

			if(Employee.rs.next() != false){
				System.out.println("Search reasults.");
				do{
					System.out.print(Employee.rs.getInt("empid")+" ");
					System.out.print(Employee.rs.getString("emp_name")+" ");
					System.out.println(Employee.rs.getFloat("salary"));
				}while(Employee.rs.next());
				
			}
			else{
				System.out.println("Result not found.\n");
			}
			System.out.println("");
			
		}
		catch(IOException e){
			System.out.println(e);		
		}	
		catch(Exception e){
			System.out.println(e);
		}
	}

	// method to view all records from database.
	void viewAll(){
		try{
			String table_name = "employee";
			Employee.rs = Employee.st.executeQuery("Select * from "+ table_name);
		
			System.out.println("\n  All Employee records:");
			while(Employee.rs.next()){
				System.out.print("\t"+Employee.rs.getInt("empid") + " ");
				System.out.print("\t"+Employee.rs.getString("emp_name") + " ");
				System.out.println("\t"+Employee.rs.getFloat("salary"));			
			}
			System.out.println("");
		}
		catch(SQLException e){
			System.out.println(e);
		}	 
	}	

}

















