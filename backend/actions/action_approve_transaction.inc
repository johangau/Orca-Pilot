<?php

class ApproveTransaction{
	
	private $pilot;
	private $operation;
	
	function __construct(){
					
		$this->setOperation($_GET['operation']);
		$this->setPilot($_GET['pilot']);
							
		$query = "UPDATE transactions SET approved = 1 WHERE pilot = ".$this->getPilot()." AND operation = ".$this->getOperation();
		$db = new dBc();	
		$db->runInsert($query);
		unset($db);
	}
		
		function setPilot($pilot){$this->pilot = dBc::escape($pilot);}
		function setOperation($operation){$this->operation = dBc::escape($operation);}
		function getPilot(){return $this->pilot;}
		function getOperation(){return $this->operation;}
}

?>
