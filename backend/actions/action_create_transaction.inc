<?php

class CreateTransaction{
	
		private $ore;
		private $amount;
		private $pilot;
		private $operation;
	
		function __construct(){
		
			$this->setOre($_GET['ore']);
			$this->setAmount($_GET['amount']);
			$this->setPilot($_GET['pilot']);
			$this->setOperation($_GET['operation']);
			$this->setVerificationCode($_GET['verificationcode']);
			
			$amount = $this->correctAmount();
			
			if(!$this->verificationCodeExists()){
				/**TODO calculate the stuff with the k and M and also make sure that decimal comma is point **/		
				$query = "INSERT INTO `transactions` (`idtransaction`, `oretype`, `amount`, `pilot`, `time`, `operation`, `approved`, `verificationcode`) 
							VALUES (NULL, 
							'".$this->getOre()."', 
							'".$this->getAmount()."', 
							'".$this->getPilot()."', CURRENT_TIMESTAMP, 
							'".$this->getOperation()."', '0','".$this->getVerificationCode()."')";
							
				$db = new dBc();	
				$db->runInsert($query);
				unset($db);		
			}
		}
		
		function correctAmount(){
			/*check amount for , and replace with . for say 0,16m*/		
			$this->setAmount(str_replace(",", ".", $this->getAmount()));
			
			/* check for m or k */
			$smallk = strpos($this->getAmount(), "k");
			$largek = strpos($this->getAmount(), "K");
			$smallm = strpos($this->getAmount(), "m");
			$largem = strpos($this->getAmount(), "M");
			
			/* if m or k was found multiply with that value */
			if(($smallk != 0) || ($largek != 0))$this->setAmount($this->getAmount() * 1000);
			if($smallm != 0 || $largem != 0)$this->setAmount($this->getAmount() * 1000000);
			
			return $this->getAmount();			
		}

		function verificationCodeExists(){
			$db = new dBc();	
			$exists = $db->isResultEmpty("SELECT * FROM transactions WHERE verificationcode = '".$this->getVerificationCode()."'");
			unset($db);
			return !$exists;	
		}
		
		function setOre($ore){$this->ore = dBc::escape($ore);}
		function setAmount($amount){$this->amount = dBc::escape($amount);}
		function setPilot($pilot){$this->pilot = dBc::escape($pilot);}
		function setOperation($operation){$this->operation = dBc::escape($operation);}
		function setVerificationCode($code){$this->verificationcode = dBc::escape($code);}
		
		function getOre(){return $this->ore;}
		function getAmount(){return $this->amount;}
		function getPilot(){return $this->pilot;}
		function getOperation(){return $this->operation;}
		function getVerificationCode(){return $this->verificationcode;}
		
}

?>