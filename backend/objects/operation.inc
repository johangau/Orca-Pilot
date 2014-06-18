<?php
/***********************************
 * 
 * OrcaPilot 
 * 
 * Last edit v 0.1 2012-01-11
 * 
 * written by Johan Gauffin
 * http://www.johangauffin.com
 * 
 * Description:
 * This object is a single operation
 * and what ever that brings like pilots
 * and stuff.
 * 
 **********************************/

require_once 'framework_0_2/tools/database.inc';
//require_once 'framework_0_2/objects/pilot.inc';
//require_once 'framework_0_2/calculations/operation_isk.inc';
//require_once 'framework_0_2/objects/arrays/pilotarray.inc';
//require_once 'framework_0_2/objects/arrays/operationsarray.inc';


class Operation{
	
	private $operationid;
	private $closed;
	private $date;
	private $tax;
	private $sellingsystem;
	
	private $isk;
	private $payments;
	private $pilots;
// 
	function load($id,$da,$cl,$ta,$ss){
		$this->setId($id);
		$this->setDate($da);
		$this->setClosed($cl);
		$this->setTax($ta);
		$this->setSellingSystem($ss);
		$this->loadPilots();
	}		
		
	function loadOperationFromId($id){
		$this->setId($id);		
		$db = new dBc();				
		$result = $db->getResult("SELECT TOP 20 * FROM operation WHERE idoperation = ".$this->getId());						
		$post = $result->offsetGet(0);							
		$this->load($post["idoperation"],$post["date"],$post["closed"],$post["tax"],$post["sellingsystem"]);
				
	}		
	
	function loadPilots(){
		$db = new dBc();		
		$this->pilots = new PilotArray();
		$this->pilots->loadOperationPilots($this->getId());		
		// $query = "SELECT * FROM `operation_pilots` JOIN users AS pilots ON(pilots.iduser = pilot) WHERE operation = ".$this->operationid;		
		// $result = $db->getResult($query);			
		// for($i=0;$i<$result->count();$i++){
			// $post = $result->offsetGet($i);			
			// $pilot = new Pilot();			
			// $pilot->setId($post["iduser"]);			
			// $pilot->setPaid($post["paid"]);				
			// $pilot->setPilotname($post["evename"]);			
			// $this->pilots->append($pilot);			
			// $pilot->selftest();		
		// }	
	}
	
	function __toAltString(){
		$altstring ="";
		$altstring .= "--------Operation ".$this->operationid." start---------&#13;";
		$altstring .= "date ".$this->getDate()."&#13;";		
		$altstring .= "closed".$this->isClosed()."&#13;";
		$altstring .= "tax".$this->getTax()."&#13;";
		$altstring .= "selling".$this->getSellingsSystem()."&#13;";
		$altstring .= "--------Operation end---------";
		return $altstring;
		
	}
	
	function __toString(){
		echo "<p>--------Operation ".$this->operationid." start---------</p>";
		echo "date ".$this->getDate()."<br>";		
		echo "closed".$this->isClosed()."<br>";
		echo "tax".$this->getTax()."<br>";
		echo "selling".$this->getSellingsSystem()."<br>";		
		echo "<p>--------Operation end---------</p>";
	}
	
	
	/*****************************
	 * GETTERS AND SETTERS
	 *****************************/

	function setId($id){
		$this->operationid = $id;
	}
	
	function getId(){
		return $this->operationid;
	}
	  	
	function setClosed($closed){
		$this->closed = $closed;
	}
	
	function isClosed(){
		return $this->closed;	
	}	
	
	function setDate($date){
		$this->date = $date;
	}
	
	function getDate(){
		return $this->date;	
	}	
	
	function setTax($tax){
		$this->tax = $tax;
	}
	
	function getTax(){
		return $this->tax;	
	}	
	
	function setSellingSystem($ss){
		$this->sellingsystem = $ss;
	}
	
	function getSellingsSystem(){
		return $this->sellingsystem;	
	}	
	
}

?>