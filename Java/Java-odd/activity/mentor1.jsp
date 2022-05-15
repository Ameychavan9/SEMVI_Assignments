<%@ page import="java.util.*"%>
<%@ page import="java.sql.*"%>
<%@ page language="java"%>
<!DOCTYPE html>
<head>
<title>Registration</title>
</head>
<body>
 <%
        Connection conn = null;
        Statement stat = null;
        ResultSet res = null;
        PreparedStatement insert = null;
        Scanner input = new Scanner(System.in);
        try
        {
         Class.forName("org.postgresql.Driver");
         conn = DriverManager.getConnection("jdbc:postgresql://192.168.16.1/ty8801","ty8801","");
         if(conn==null)
         {
                System.out.println("Connection failed");
         }
         else
         {
                System.out.println("Connetion successful..");
         }
         stat = conn.createStatement();

      if("Register".equals(request.getParameter("submit")))
      {
        String year=request.getParameter("currentyear");
        String name=request.getParameter("name");
        String roll=request.getParameter("rollno");
        String contact=request.getParameter("contactno");
        String email=request.getParameter("email");
        String cls = request.getParameter("class");
        String division=request.getParameter("division");
        String mentor = request.getParameter("mentorname");

        insert = conn.prepareStatement("insert into mentor values(?,?,?,?,?,?,?,?)");

         insert.setString(1,year);
         insert.setString(2,name);
         insert.setString(3,roll);
         insert.setString(4,contact);
         insert.setString(5,email);
         insert.setString(6,cls);
         insert.setString(7,division);
         insert.setString(8,mentor);


        int a=insert.executeUpdate();
        if(a>0)
        {
         out.println("Record Added");
        }
      }
      else if("Get Details1".equals(request.getParameter("submit1")))
      {
       String y=request.getParameter("mentor");
       out.println(y);
       res = stat.executeQuery("select * from mentor where mentor_name= "+y);
       out.println(res);
       while(res.next())
       {
       %>
       <table border="1">
       <tr>
       <td><%out.print(res.getString(1));%></td>
       <td><%out.print(res.getString(2));%></td>
       <td><%out.print(res.getString(3));%></td>
       <td><%out.print(res.getString(4));%></td>
       <td><%out.print(res.getString(5));%></td>
       <td><%out.print(res.getString(6));%></td>
       <td><%out.print(res.getString(7));%></td>
       <td><%out.print(res.getString(8));%></td>
       </tr>
       </table>
      <%
      }
      }
      else
      {
       String x=request.getParameter("cls");
        out.println(x);
       res = stat.executeQuery("select * from mentor where class= "+x);
       out.println(res);
       while(res.next())
       {
       %>
       <table border="1">
       <tr><td><%out.print(res.getString(1));%></td>
       <td><%out.print(res.getString(2));%></td>
       <td><%out.print(res.getString(3));%></td>
       <td><%out.print(res.getString(4));%></td>
       <td><%out.print(res.getString(5));%></td>
       <td><%out.print(res.getString(6));%></td>
       <td><%out.print(res.getString(7));%></td>
       <td><%out.print(res.getString(8));%></td>
       </tr>
       </table>
       <%
       }
      }
      }
      catch(Exception e)
      {
      }
      %>
  </body>
</html>
