<?php

	$a[] = "In search of lost time";
	$a[] = "One hundred years of solitude.";
	$a[] = "The great gatsby";
	$a[] = "Think and grow rich";

    	$q = $_REQUEST["q"];

	$output = "";
  	foreach($a as $book){
		if(strpos($book, $q) !== false){
			$output = $output."<br>".$book;
		}
	}

	if(strcmp($output, "") == 0)
		echo "No result found.";
	else
    	echo $output;
?>
