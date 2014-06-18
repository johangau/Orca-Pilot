<?php

class ActionCloseOperation{
		
		private $operationid;
	
		function __construct(){		
			$this->setOperation($_GET['operation']);
			$query = "UPDATE operation SET closed = 1 WHERE idoperation = ".$this->getOperation();
			$db = new dBc();	
			$db->runInsert($query);
			unset($db);
			
		}
		
		function setOperation($operation){
			$this->operation = dBc::escape($operation);
		}				
		function getOperation(){
			return $this->operation;
		}
}

?>