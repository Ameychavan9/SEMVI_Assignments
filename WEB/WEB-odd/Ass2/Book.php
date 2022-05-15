
<?php
	class Book
	{
		var $book_name;
		var $book_quantity;
		var $book_price;
		var $book_stock;

		function __construct($b_name,$b_quantity,$b_price,$b_stock)
		{
			$this-> book_name = $b_name;
			$this-> book_quantity = $b_quantity;
			$this-> book_price = $b_price;
			$this-> book_stock = $b_stock;
		}
		
		function display()
		{	
			echo "\n\nBook Information<br>==================<br>";
			echo	"<br>Book Name : ".$this-> book_name;
			echo 	"<br>Book Quantiy :".$this-> book_quantity;
			echo	"<br>Book Price :".$this-> book_price;
			echo	"<br>Book Stock :".$this-> book_stock;
		}
	}
/*	$b_name = readLine('Enter the Name of Book :');
	$b_quantity = readLine('Enter the quantity of Book :');
	$b_price = readLine('Enter the Price of Book :');
	$b_stock = readLine('Enter the stocks of Book :');
*/	
	$b_name = $_GET['b_name'];
	$b_quantity = $_GET['b_quantity'];
	$b_price = $_GET['b_price'];
	$b_stock = $_GET['b_stock'];
	$b1 = new Book($b_name,$b_quantity,$b_price,$b_stock);
	$b1->display();
?>
