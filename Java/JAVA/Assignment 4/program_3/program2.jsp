<%@ page language="java"%>
<html>
<head>
<title>Bill</title>
</head>
<body>
  <div class="container">
   <h2>color options</h2>
   <br>
   <hr>
   <%!
      int qnt1=0,qnt2=0,qnt3=0,qnt4=0,sum=0;
   %>
   <%
     String button1Click =request.getParameter("color");
	if(button1Click.equals("red")){
   %>
   <h1>you have clicked the red button</h1>
   <body style="background-color:red;">
<%}
   else if(button1Click.equals("green")){
   %>
   <h1>you have clicked the green button</h1>
   <body style="background-color:green;">
  <%}
	else if(button1Click.equals("blue")){
   %>
   <h1>you have clicked the blue button</h1>
   <body style="background-color:blue;">
  <%}%>
  </div>
</body>
</html>
