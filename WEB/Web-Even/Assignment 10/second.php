<?php
    session_start();
    $eno=$_GET['eno'];
    $enm=$_GET['enm'];
    $eadd=$_GET['eadd'];



   $_SESSION['eno']=$eno;
   $_SESSION['enm']=$enm;
   $_SESSION['eadd']=$eadd;
?>
<html>
<body>
 
<form action="third.php" method="post">
<center>
<h2> Enter earnings of employee:</h2>
<table>
<tr><td>Basic: </td>
<td><input type="text" name="e1"></td></tr>
<tr><td>DA: </td>
<td><input type="text" name="e2"></td></tr>
<tr><td>HRA: </td>
<td><input type="text" name="e3"></td></tr>
<tr><td></td><td><input type="submit" value=next></td></tr>
</table>
</center>
</form>
</body>
</html>



