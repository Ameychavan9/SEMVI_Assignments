<%@ page import="java.sql.*"%>
<%@ page import="java.util.*"%>
<!DOCTYPE html>
<head>
<title>Mentor Registration Form</title>
<style>
   body{
        font-size:20px;
       }
   h2{
      text-align:center;
     }
   input{
     width:200px;
     }
</style>
</head>
<body>
<h2>Registration Form</h2>
<div class="container">
 <form action="mentor1.jsp" method="post">
  <pre>
      <B>Current Year : </B><input type="number" name="currentyear" id="current" placeholder="Enter Your Current Year" required><br>
      <B>Name : </B><input type="text" name="name" id="Nam" placeholder="Enter Your Name" required><br>
      <B>Roll_No : </B><input type="number" name="rollno" id="roll" placeholder="Enter Your Roll no" required><br>
      <B>Contact_No : </B><input type="number" name="contactno" id="contact" placeholder="Enter Your Contact Number" require><br>
      <B>Email_id : </B><input type="email" name="email" id="emai" placeholder="Enter Your Email" required><br>
      <B>Class : </B><input type="text" name="class" id="cls" placeholder="Enter Class Name(fy,sy,ty)" required><br>
      <B>Division : </B><input type="text" name="division" id="div" placeholder="Enter Your Division" required><br>
      <B>Mentor_Name : </B><input type="text" name="mentorname" id="ment" placeholder="Enter Mentor Name" required><br>
      </B><input type="submit" name="submit" value="Register"></B><br>
 </pre>
</form>
</div>
    
<form action="mentor1.jsp" action="POST">
 <pre>
    <B>Mentor_Name : </B><input type="text" name="mentor" id="men" placeholder="Enter Mentor Name" required><br>
    </B><input type="submit" name="submit1" value="Get Details1"></B><br>
 </pre>
</form>
<form action="mentor1.jsp" action="POST">
 <pre>
     <B>Class : </B><input type="text" name="cls" id="cl" placeholder="Enter Class Name(fy,sy,ty)" required><br>
    </B><input type="submit" name="submit2" value="Get Details2"></B><br>
 </pre>
</form>
