<?php

	setcookie("basic", $_POST["basic"]);
	setcookie("da", $_POST["da"]);
	setcookie("hra", $_POST["hra"]);

        echo "<br>Employee Information";
        
        echo "<br>Eno :".$_COOKIE['eno'];
        echo "<br>Ename :".$_COOKIE['ename'];
        echo "<br>Address :".$_COOKIE['eadd'];
        echo "<br>Basic :".$_COOKIE['basic'];
        echo "<br>DA :".$_COOKIE['da'];
        echo "<br>HRA".$_COOKIE['hra'];
?>
