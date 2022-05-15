<?php
$conn=pg_connect("host=192.168.16.1 port=5432 user=ty8703 password=") or die("Something went wrong");
?>

<html>
<head>
	<title>BOOK</title>
</head>
<body>
<form onsubmit="return check();" style="border:dashed pink 2px;width:80%;margin:auto;margin-top:5%;text-align:center" method="post">
Book Name<input type="text" name="book_name" required/>
<br><br>Book Author<input type="text" name="book_author"  required/>
<br><br>Book category<input type="text" name="book_category"  required/>
<br><br>Book Price<input type="tel" name="book_price" id="stock" required/>
<br><br><br><br><center><input type="submit" name="submit" value="Save"/></center>
</form>
	<center><span id="error" style="color:red;font-size:14px;text-align:center"></span></center>
<?php
	if(isset($_POST['submit']))
	{
		$query="insert into book values('$_POST[book_name]','$_POST[book_author]','$_POST[book_category]','$_POST[book_price]' )";
		if(pg_query($conn,$query))
			echo '<center><span  style="color:red;font-size:14px;text-align:center;">Record insert successfull</span></center>';
		else
			echo '<center><span  style="color:red;font-size:14px;text-align:center;">Record insertion unsuccessfull<br>Kindly check data provided</span></center>';
	}


?>
<br><br>
<table border='1' style="margin:auto">
<form method="post">
<tr>
	<th><input type="submit" name="delete" value="delete"/></th>
	<th>Book Name</th>
	<th>Book Author</th>
	<th>Book category</th>
	<th>Boook Price</th>
</tr>
<?php
$result=pg_query("Select * from book");
global $i;
$i=0;
while($data=pg_fetch_assoc($result))
{
echo'<tr>
		<th><input type="checkbox" name="id'.$i.'" value='.$data['book_category'].' /></th>
		<th>'.$data['book_name'].'</th>
		<th>'.$data['book_author'].'</th>
		<th>'.$data['book_category'].'</th>
		<th>'.$data['book_price'].'</th>
	</tr>';
$i++;
}
?>
</form>
</table>
<?php
if(isset($_POST['delete']))
{
	$str;
	global $i;
	while($i>=0)
	{
		$id='id'.$i;
		if(isset($_POST[$id]))
		{
		$query="delete from book where book_category='$_POST[$id]'";
		pg_query($conn,$query);
		}
		$i--;
	}
}
?>

<script>
function check()
{
if(document.getElementById("stock").value<0)
{	
	document.getElementById("error").innerHTML="Price can not be less then 0";
	return false;
}
return true;
}
</script>
</body>
</html>
