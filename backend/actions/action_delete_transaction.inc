<?php

class ActionDeleteTransaction{
	
		private $id;
	
		function __construct(){		
		
			$this->setId($_GET['transaction']);
			
			/**TODO calculate the stuff with the k and M and also make sure that decimal comma is point **/		
			$query = "DELETE FROM `transactions` WHERE `transactions`.`idtransaction` = ".$this->getId();
			$db = new dBc();	
			$db->runInsert($query);
			unset($db);		
		}
		
		function setId($id){
			$this->id = dBc::escape($id);
		}
		function getId(){
			return $this->id;
		}
		
}

?>



