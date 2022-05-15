<%@ page language="java"%>
<html>
<head>
<title>Bill</title>
<style>
   .container
   {
    width:300px;
    height:400px;
    border:1px solid black;
    margin-top:100px;
    margin-left:400px;
   }
   h2{
    text-align:center;
   }
</style>
</head>
<body>
  <div class="container">
   <h2>Shopping Bill</h2>
   <br>
   <hr>
   <%!
      int qnt1=0,qnt2=0,qnt3=0,qnt4=0,sum=0;
   %>
   <%
     qnt1=Integer.parseInt(request.getParameter("quent1"));
     if(qnt1>0)
     {
      qnt1=qnt1*550;
      sum+=qnt1;
      out.println("<h3>Shirt : "+qnt1+"</h3>");
     }
   
     qnt2=Integer.parseInt(request.getParameter("quent2"));
     if(qnt2>0)
     {
      qnt2=qnt2*1050;
      sum+=qnt2;
      out.println("<h3>Pant : "+qnt2+"</h3>");
     }

     qnt3=Integer.parseInt(request.getParameter("quent3"));
     if(qnt3>0)
     {
      qnt3=qnt3*2050;
      sum+=qnt3;
      out.println("<h3>Watch : "+qnt3+"</h3>");
     }

     qnt4=Integer.parseInt(request.getParameter("quent4"));
     if(qnt4>0)
     {
      qnt4=qnt4*3000;
      sum+=qnt4;
      out.println("<h3>EarBuds : "+qnt4+"</h3>");
     }
     out.println("<hr>");
     out.println("<h3>Total : "+sum+"</h3>");
     sum=0;
   %>
  </div>
</body>
</html>
