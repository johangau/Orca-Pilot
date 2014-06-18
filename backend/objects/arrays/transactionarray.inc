<?php

class TransactionArray{
	
	private $transactions;
	private $pilot;
	private $operation;
	
	function __construct(){
		$this->setPilot($_GET['pilot']);
		$this->setOperation($_GET['operation']);
		
	}
	
	public function loadArray(){

		$this->setArray(new ArrayObject());

		$db = new dBc();	

		$result = $db->getResult("
				SELECT * FROM transactions 
				JOIN ore_or_ice on oretype = idore_or_ice
				WHERE pilot = ".$this->getPilot()." AND operation = ".$this->getOperation()." AND approved = 0;");				

		for($i=0;$i<$result->count();$i++){
			$post = $result->offsetGet($i);
			$transaction = new Transaction();
			$transaction->setId($post["idtransaction"]);
			$transaction->setOREtype($post["oretype"]);
			$transaction->setAmount($post["amount"]);
			$transaction->setPilot($post["pilot"]);
			$transaction->setTime($post["time"]);
			$transaction->setOperation($post["operation"]);
			$transaction->setApproved($post["approved"]);
			$transaction->setOrename($post["name"]);
			$transaction->setIcon($post["icon"]);
			$this->getArray()->append($transaction);
		}

	}

	public function loadHistoryArray(){

		$this->setArray(new ArrayObject());

		$db = new dBc();	

		$result = $db->getResult("
				SELECT * FROM transactions 
				JOIN ore_or_ice on oretype = idore_or_ice
				WHERE pilot = ".$this->getPilot()." AND operation = ".$this->getOperation()." AND approved = 1;");				

		for($i=0;$i<$result->count();$i++){
			$post = $result->offsetGet($i);
			$transaction = new Transaction();
			$transaction->setId($post["idtransaction"]);
			$transaction->setOREtype($post["oretype"]);
			$transaction->setAmount($post["amount"]);
			$transaction->setPilot($post["pilot"]);
			$transaction->setTime($post["time"]);
			$transaction->setOperation($post["operation"]);
			$transaction->setApproved($post["approved"]);
			$transaction->setOrename($post["name"]);
			$transaction->setIcon($post["icon"]);
			$this->getArray()->append($transaction);
		}

	}
	
	function getHTMLtable(){

		$session = new Session();

		echo '<table class="usertable">';
				for($i=0;$i<$this->getCount();$i++){
				$transaction = $this->getTransaction($i);
				assert($transaction instanceof Transaction);	
				
				if($i%2==0){
				/* otherwise show the first gray if $i is even */
					echo '<tr class="yxi" 
							onMouseOver="this.className=\'kolme\'" 
							onMouseOut="this.className=\'yxi\'" 
							onclick="parent.location=\'addore.php?session='.$session->getSessionHash().'&pilot='.$transaction->getPilot().'&operation='.$transaction->getOperation().'&deletetransaction=true&transaction='.$transaction->getId().'\'">';
				}else{
					/* and the second grey of it is odd */
					echo '<tr class="kaxi" 
							onMouseOver="this.className=\'kolme\'" 
							onMouseOut="this.className=\'kaxi\'" 
							onclick="parent.location=\'addore.php?session='.$session->getSessionHash().'&pilot='.$transaction->getPilot().'&operation='.$transaction->getOperation().'&deletetransaction=true&transaction='.$transaction->getId().'\'">';
				}
					echo '<td><img src="images/ore/'.$transaction->getIcon().'" class="operationicon"></td>';
					echo '<td width="100">'.$transaction->getOrename().'</td>';
					echo '<td>'.Pretty::amount($transaction->getAmount(),"Units").'</td>';
					 
					echo '</tr>';				
			}
		echo '</table>';					
	}

	function getHistoryHTMLtable(){

		$session = new Session();

		echo '<table class="usertable">';
				for($i=0;$i<$this->getCount();$i++){
				$transaction = $this->getTransaction($i);
				assert($transaction instanceof Transaction);	
				
				if($i%2==0){
				/* otherwise show the first gray if $i is even */
					echo '<tr class="yxi" 
							onMouseOver="this.className=\'kolme\'" 
							onMouseOut="this.className=\'yxi\'" 
							onclick="parent.location=\'transactionhistory.php?session='.$session->getSessionHash().'&pilot='.$transaction->getPilot().'&operation='.$transaction->getOperation().'&deletetransaction=true&transaction='.$transaction->getId().'\'">';
				}else{
					/* and the second grey of it is odd */
					echo '<tr class="kaxi" 
							onMouseOver="this.className=\'kolme\'" 
							onMouseOut="this.className=\'kaxi\'" 
							onclick="parent.location=\'transactionhistory.php?session='.$session->getSessionHash().'&pilot='.$transaction->getPilot().'&operation='.$transaction->getOperation().'&deletetransaction=true&transaction='.$transaction->getId().'\'">';
				}
					echo '<td><img src="images/ore/'.$transaction->getIcon().'" class="operationicon"></td>';
					echo '<td width="100">'.$transaction->getOrename().'</td>';
					echo '<td>'.Pretty::amount($transaction->getAmount(),"Units").'</td>';
					 
					echo '</tr>';				
			}
		echo '</table>';					
	}


	function getPilot(){
		return $this->pilot;
	}
	
	function setPilot($pilot){
		$this->pilot = dBc::escape($pilot);
	}
	
	function setOperation($op){
		$this->operation = dBc::escape($op);
	}
	
	private function getOperation(){
		return $this->operation;
	}

	public function getArray(){
		return $this->transactions;
	}
	public function setArray($transactions){
		$this->transactions = $transactions;
	}
	
	public function getCount(){
		return $this->transactions->count();
	}
	public function getTransaction($index){
		return $this->getArray()->offsetGet($index);
	}

	
}
?>