<?php 

	//print_r($_GET);
	// echo "Hi";
	$u=$_GET['url'];
	$des=$_GET['des'];
	// $id=$_GET['num'];
	// $up=$_GET['upname'];
	// $uid=$_GET['uid'];

	// echo $emid;
	// echo $ename;

	$con=pg_connect("host=localhost dbname=postgres user=postgres password=123") or die("Connection Faield");

	$q=("insert into urltable values('$u','$des')");

	 	pg_query($con,$q);
	$display="select * from urltable;";
	$result = pg_query($con,$display);
	if(!$result)
	{
		echo "Invalid";
		exit;
	}
	echo ("Details:\n");
	while($row=pg_fetch_row($result))
	{
		echo $row[0];
		echo $row[1];
	}

	
?>