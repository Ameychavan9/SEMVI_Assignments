<?php

$r = $_GET['a'];
echo $r;
$conn = pg_connect("host=192.168.16.1 dbname = ty8803 user=ty8803 password=");
if($r==1)
{
	$actor_name = $_GET['actor_name1'];

	$qr = "SELECT movie.movie_name from movie,actor,ma where movie.movie_no=ma.movie_no and actor.actor_no = ma.actor_no and actor.actor_name='".$_GET['actor_name1']."';";

	$result = pg_query($conn,$qr);

	if(!$result)
	{
		echo "INVALID";
		exit;
	}
	echo ("Movie Name :\n");
	while($row=pg_fetch_row($result))
	{
		echo $row[0];
	}
}

else if($r==2)
{
	$movie_no = $_GET['movie_no'];
	$movie_name = $_GET['movie_name'];
	$release_year = $_GET['release_year'];
	$actor_no = $_GET['actor_no'];
	$actor_name = $_GET['actor_name'];

}

pg_close($conn);

?>
