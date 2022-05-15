<?php
 
	$cname=$_POST['cname'];	
	$conn = pg_connect("host=192.168.16.1 port=5432 dbname=ty8810 user=ty8810 password=");	
	if(!$conn){
		echo "Error during connection.";
	}
	else{
		if(strcmp($_POST['operation'], "display") == 0){
			$sql_query = "select name from student where std_id in (select std_id from std_comp where c_no = (select c_no from competition where c_name='".$cname."'));";

			$result = pg_query($conn, $sql_query);

	
			if(pg_num_rows($result) == 0)
			{
				echo "No record found.";
			}
			else {
				while($row = pg_fetch_array($result)){
					echo $row[0]."<br>";
				}
			}



		}
		else if(strcmp($_POST['operation'], "delete") == 0)
		{
			$sql_query = "select * from student where std_id in (select std_id from std_comp where c_no = (select c_no from competition where c_name='".$cname."'));";
			$result = pg_query($conn, $sql_query);
			while($row = pg_fetch_assoc($result)){
				$query = "Delete from std_comp where std_comp.std_id=".$row['std_id'].";";
				pg_query($conn, $query);
				$query = "Delete from student"."where std_id=".$row['std_id'].";";
				pg_query($conn, $query);
			} 
			if($result){
				echo "Data deleted successfully."."<br>";
			}

		}
		else{
			echo "Select an operation.<br>";
		}
	}

?>

