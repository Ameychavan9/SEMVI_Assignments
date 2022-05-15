<?php
	
    date_default_timezone_set("Asia/Calcutta");
	$dir_name = readLine("Enter directory name :");	
	$file_ext = readLine("Enter file extension :");

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
