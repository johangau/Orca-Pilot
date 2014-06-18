<?php

class PaymentArray{
	
	private $payment;
	private $pilot;
	private $operation;
	
	function __construct(){
		$this->setPilot($_GET['pilot']);
		$this->setOperation($_GET['operation']);
		$this->loadArray();
	}
	
	private function loadArray(){

		$this->setArray(new ArrayObject());

		$db = new dBc();	

		$result = $db->getResult("
				SELECT * FROM payments WHERE pilot = ".$this->getPilot()." AND operation = ".$this->getOperation());				

		for($i=0;$i<$result->count();$i++){
			$post = $result->offsetGet($i);
			$payment = new Payment();
			$payment->setId($post["idpayment"]);
			$payment->setAmount($post["amount"]);
			$payment->setPilot($post["pilot"]);
			$payment->setTime($post["timest"]);
			$payment->setOperation($post["operation"]);
			$this->getArray()->append($payment);
			print_r($payment);
		}

	}
	
	function getHTMLtable(){

		$session = new Session();

		echo '<table class="usertable">';
				for($i=0;$i<$this->getCount();$i++){
				$payment = $this->getTransaction($i);
				assert($payment instanceof Transaction);	
				
				if($i%2==0){
				/* otherwise show the first gray if $i is even */
					echo '<tr class="yxi" 
							onMouseOver="this.className=\'kolme\'" 
							onMouseOut="this.className=\'yxi\'" 
							onclick="parent.location=\'addore.php?session='.$session->getSessionHash().'&pilot='.$payment->getPilot().'&operation='.$payment->getOperation().'&paypilot=true&amount='.$payment->getId().'\'">';
				}else{
					/* and the second grey of it is odd */
					echo '<tr class="kaxi" 
							onMouseOver="this.className=\'kolme\'" 
							onMouseOut="this.className=\'kaxi\'" 
							onclick="parent.location=\'addore.php?session='.$session->getSessionHash().'&pilot='.$payment->getPilot().'&operation='.$payment->getOperation().'&deletetransaction=true&transaction='.$payment->getId().'\'">';
				}
					echo '<td><img src="images/ore/'.$payment->getIcon().'" class="operationicon"></td>';
					echo '<td width="100">'.$payment->getOrename().'</td>';
					echo '<td>'.Pretty::amount($payment->getAmount(),"Units").'</td>';
					 
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
		return $this->payments;
	}
	public function setArray($payments){
		$this->payments = $payments;
	}
	
	public function getCount(){
		return $this->payments->count();
	}
	public function getTransaction($index){
		return $this->getArray()->offsetGet($index);
	}

	
}
?>