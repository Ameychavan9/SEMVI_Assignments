<%@ page import="java.sql.*" %>
<%@ page import="java.util.*" %>
<%@ page import="java.io.*" %>
<!DOCTYPE html>
<head>
<!--<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">-->
<title>Registration</title>
<style>
     body
     {
      font-size:x-large;    
     }
     h2
     {
      text-align:center;
      font-size:x-large;
     }
</style>
</head>
<body>
    <h2>Registration Form</h2>
    <form action="program1.jsp" method="post">
      Name : <input type="text" name="name" id="Name" placeholder="Enter Your Name" required><br><br>
      Email : <input type="email" name="email" id="Email" placeholder="Enter Your Email id" required><br><br>
      Contact Number : <input type="text" name="contact" id="Contact" placeholder="Enter Your Contact Number" required><br><br>
      Present Occupation : <input type="text" name="occupation" id="Occupation" placeholder="Enter Your Present Occupation" required><br><br>
      Year Of Passing : <input type="text" name="year" id="Year" placeholder="Enter Year Of Passing" required><br><br>
      Program Name : <select name="select">
                     <option value="Undergraduate">Undergraduate</option>
                     <option value="Graduate">Graduate</option>
                    </select><br>
      <input type="submit" value="Register"><br>
	<!--int year=Integer.parseInt(request.getParameter("year"));
	
	Intetger year=request.getParameter("year");	
	-->
    <%
      out.print ("in jsp code");
        String name=request.getParameter("name");
        String email=request.getParameter("email");
        String contact=request.getParameter("contact");
        String occupation=request.getParameter("occupation");
		
        int year = 1999;
        String select=request.getParameter("select");
	Statement stat = null;
	try
        {

		Connection conn = null;
		
		ResultSet res = null;
		PreparedStatement insert = null;
		Scanner input = new Scanner(System.in);
		
		 Class.forName("org.postgresql.Driver").newInstance();
		out.print ("testing.");
		 conn = DriverManager.getConnection("jdbc:postgresql://192.168.16.1/ty8806","ty8806","");
		 insert = conn.prepareStatement("insert into alumni values(?,?,?,?,?,?);");

		 if(conn==null)
		 {
		        out.println("Connection failed");
		 }
		 else
		 {
		        out.println("Connetion succesful..");
		 }
		 stat = conn.createStatement();

		 insert.setString(1,"name");
		 insert.setString(2,"email");
		 insert.setString(3,"contact");
		 insert.setString(4,"occupation");
		 insert.setInt(5,year);
		 insert.setString(6,"select");

		insert.executeUpdate();
	}catch(Exception e){}
    %>
    <br><br>
<%--     Year Of Passing : <input type="text" name="y" id="Yea" placeholder="Enter Year Of Passing" required><br><br>
      <input type="submit" value="Register"><br>
    <%
      String y=request.getParameter("y");
      ResultSet res = stat.executeQuery("select * from alumni where year_of_passing=1999");
      while(res.next())
      {
      %>
        <table>
            <tr><td><%res.getString(1);%></td></tr>
            <tr><td><%res.getString(2);%></td></tr>
            <tr><td><%res.getString(3);%></td></tr>
            <tr><td><%res.getString(4);%></td></tr>
            <tr><td><%res.getString(5);%></td></tr>
            <tr><td><%res.getString(6);%></td></tr>
        </table>                    
     <% 
     }
     %>--%>
</form>
</body>
</html>

