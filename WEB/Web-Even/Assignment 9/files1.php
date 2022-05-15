	<html>
		<head>
			<title>Book</title>
		</head>

		<body>
			<form method="POST">
				<input type="text" name="dir" placeholder="Directory Name">
				<input type="text" name="ext" placeholder="File extension">
				<input type="submit" value="Submit">
			</form>
	
		</body>
	</html>


<?php
    	date_default_timezone_set("Asia/Calcutta");

	


	$dir_name = $_POST["dir"];	
	$file_ext = $_POST["ext"];

	$dir = opendir($dir_name);
	echo "\n\nFiles :\n";

	while(($file = readdir($dir)) !== false)
	{
		if(strpos($file, $file_ext) != false) 
		{
            echo "\n".$file."\n";
            echo "size :".filesize("$dir_name/$file")."\n";
            echo "last access :".date("F d Y H:i:s", fileatime("$dir_name/$file"))."\n";
        }
	}

	closedir($dir);


?>
