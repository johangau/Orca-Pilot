<?php 



class AddPilot{
	
	private $pilot;
	private $operation;
	
	function __construct(){
		
		$this->setPilot($_GET['pilot']);
		$this->setOperation($_GET['operation']);
		
		$db = new dBc();
		$query = "SELECT * FROM operation_pilots WHERE pilot = ".$this->getPilot()." AND operation = ".$this->getOperation();
		if($db->isResultEmpty($query)){	
		$db->runInsert("INSERT INTO `operation_pilots` (`idoperation_pilots`, `operation`, `pilot`, `paid`) 
						VALUES (NULL, '".$this->getOperation()."', '".$this->getPilot()."', '0');");
		}else{
			include 'framework_0_2/_header.php';
			echo "Pilot exists already"; 
			include 'framework_0_2/_footer.php';
			die();
		}
	}
	
		function setPilot($pilot){$this->pilot = dBc::escape($pilot);}
		function setOperation($operation){$this->operation = dBc::escape($operation);}
		function getPilot(){return $this->pilot;}
		function getOperation(){return $this->operation;}
	
}

?>