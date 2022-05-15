<?php
	echo "style is".$_GET['st']."<br>size is ".$_GET['s']."<br>color is ".$_GET['c']."<br>BAckgroud color is ".$_GET['bc'];
	setcookie("set1",$_GET['st'],time()+3600);
	setcookie("set2",$_GET['s'],time()+3600);
	setcookie("set3",$_GET['c'],time()+3600);
	setcookie("set4",$_GET['bc'],time()+3600);
?>

<html>
<body>
<form action= "Ass4_2.php">
<input type=submit value = OK>
</form>
</body>
</html>
