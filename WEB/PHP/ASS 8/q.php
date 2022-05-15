<?php
class Book
{
	var $book_name;
	var $book_qty;
	var $book_price;
	var $book_stock;

	function Book($name,$quant,$price,$stok)
	{
		
		$this->book_name=$name;
		$this->book_qty=$quant;
		$this->book_price=$price;
		$this->book_stock=$stok;
	}

	function Display_info()
	{

		echo "\n Book Information";
		echo "\n Book Name: ".$this->book_name;
		echo "\n Book Quantity: ".$this->book_qty;
		echo "\n Book Price: ".$this->book_price;
		echo "\n Book Stock: ".$this->book_stock;

	}
}
	$name = readLine('Enter Book Name: ');
	$quant = readLine('Enter Book Qty: ');
	$price = readLine('Enter Book Price: ');
	$stok = readLine('Enter Book Stock: ');
	$books = new Book($name,$quant,$price,$stok);
	$books->Display_Info();
?>
