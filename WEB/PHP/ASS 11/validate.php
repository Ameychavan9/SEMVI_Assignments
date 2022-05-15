<?php
	function validate($name)
{	
	if($name=='')
	return 'Plz enter any username';
	if(strlen($name)<3)
		return'Username is too short ';
			
	if(strlen($name)>10)
		return'Username is too long ';
	
	return'Username is valid ';
}
	echo validate($_GET['name']);

?>
