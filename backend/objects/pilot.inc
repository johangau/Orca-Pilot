<?php

require_once 'framework_0_2/objects/user.inc';

class Pilot extends User{
	
	private $paid;
	private $isk;
	
	function setId($id){
		$this->id = $id;
	}
	function setPilotname($name){
		$this->pilotname = $name;
	}
	
	function setPaid($paid){
		$this->paid = $paid;
	}
	
	function setISK($isk){
		$this->isk = $isk;
	}
	
	function getId(){
		return $this->id;
	}
	function getPilotname(){
		return $this->evename;
	} 
	
	function getPaid(){
		return $this->paid;
	}
	
	function getISK(){
		return $this->isk;
	}
	
	function __toString(){
		echo "<p>--------Pilot--------<br>";
		echo "- ".$this->getPilotname()."<br>";
		echo "- ".$this->getId()."<br>";
		echo "- ".$this->getPaid()."<br>";
		echo "-----------------------</p>";
		
	}
	
}


?>