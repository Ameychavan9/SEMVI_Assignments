<html>
<body>
    <form method="get">
    <b>Enter Date One</b>
    <input type=date name=sdate>
    <br><b>Enter Date 2</b>
    <input type=date name=edate>
    <input type=submit value=submit>


    </form>
</body>
</html>


<?php

//$sdate = $_GET['sdate'];
//$edate = $_GET['edate'];

$sdate = new DateTime("1981-11-03");
$edate = new DateTime("2013-09-04");
$interval = $sdate->diff($edate);
echo "Difference : " . $interval->y . " years, " . $interval->m." months, ".$interval->d." days ";
?>