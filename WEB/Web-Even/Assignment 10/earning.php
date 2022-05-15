<?php
	setcookie("eno", $_POST["eno"]);
	setcookie("ename", $_POST["ename"]);
	setcookie("eadd", $_POST["eadd"]);
?>
<html>
    <head>
        <title>Earning</title>
    </head>
    <body>
        <form action="Info.php" method="POST">
            <input type="text" placeholder="basic" name="basic"><br><br>
            
            <input type="text" placeholder="da" name="da"><br><br>
            
            <input type="text" placeholder="hra" name="hra"><br><br>
            
            <input type="submit" value="Add">
        </form>
    </body>
</html>
