<?php

class ORE{
	private $name;
	private $id;
	
	function __construct($i,$n){
		$this->id = $i;
		$this->name = $n;		
	}
	
	function getId(){
		return $this->id;		
	}
	
	function getName(){
		return $this->name;
	}
	
	function selftest(){
		echo "<p>Selftest ORE: ".$this->getId()." -> ".$this->getName()."</p>";
	}
}	

?>