<?php

	interface shape{
		function area();
	}

	class Rectangle implements shape{

		var $width;
		var $height;
		
		function __construct(){
			$this->width = (int)readLine("Enter width :");
			$this->height = (int)readLine("Enter height :");
		}

		function area(){
			echo "Area of Rectangle :".($this->width*$this->height)."\n";
		}
	}

	class Square extends Rectangle{
		var $side;

		function __construct(){
			$this->side = (float)readLine("Enter side length of square");
		}

		function area(){
			echo "Area of square ".($this->side * $this->side)."\n";
		}

	}

	class Circle implements shape{
		var $r;
		function __construct(){
			$this->r = (float)readLine("Enter radius :");
		}

		function area(){
			echo "Area of circle ".($this->r*$this->r*3.147)."\n";
		}
	}

	$rec = new Rectangle(); 
	$rec->area();

	$sqr = new Square();
	$sqr->area();

	$c = new Circle();
	$c->area();

?>
