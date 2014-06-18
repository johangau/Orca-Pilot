<?php

class ActionCreatePayment{
	
		private $amount;
		private $pilot;
		private $operation;
		private $hash;
	
		function __construct(){
		
			$this->setAmount($_GET['amount']);
			$this->setPilot($_GET['pilot']);
			$this->setOperation($_GET['operation']);
			$this->setVerificationCode($_GET['verification']);
					
			if(!$this->verificationCodeExists()){
				/**TODO calculate the stuff with the k and M and also make sure that decimal comma is point **/		
				$query = "INSERT INTO `payments` ( `amount`,  `operation`, `pilot`, `payment_verification`) 
							VALUES ('".$this->getAmount()."','".$this->getOperation()."','".$this->getPilot()."','".$this->getVerificationCode()."')";
							
				$db = new dBc();	
				$db->runInsert($query);
				unset($db);
			}
		}
		
		function verificationCodeExists(){
			$db = new dBc();	
			$exists = $db->isResultEmpty("SELECT * FROM payments WHERE payment_verification = '".$this->getVerificationCode()."'");
			unset($db);
			return !$exists;	
		}
		
		
		function setAmount($amount){
			$this->amount = dBc::escape($amount);
		}
		function setPilot($pilot){
			$this->pilot = dBc::escape($pilot);
		}
		function setOperation($operation){
			$this->operation = dBc::escape($operation);
		}
		
		function setVerificationCode($hash){
			$this->hash = dBc::escape($hash);
		}
		
		function getAmount(){
			return $this->amount;
		}
		function getPilot(){
			return $this->pilot;
		}
		function getOperation(){
			return $this->operation;
		}
		function getVerificationCode(){
			return $this->hash;
		}
		
}

?>