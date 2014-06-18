<?php 

class Transaction{
	
	private $idtransaction; 
	private $oretype;
	private $amount;
	private $pilot;
	private $time;
	private $operation;
	private $approved;
	private $orename;
	private $oreicon;
	
	public static function getNewVerificationCode(){
		return hash("sha256",time().mt_rand(0, 999999));
	}

	public function getId(){
		return $this->idtransaction;
	}
	public function setId($x){
		$this->idtransaction = $x;
	}
	
	public function getOREtype(){
		return $this->oretype;
	}
	public function setOREtype($x){
		$this->oretype = $x;
	}

	public function getAmount(){
		return $this->amount;
	}
	public function setAmount($x){
		$this->amount = $x;
	}

	public function getPilot(){
		return $this->pilot;
	}
	public function setPilot($x){
		$this->pilot = $x;
	}

	public function getTime(){
		return $this->time;
	}
	public function setTime($x){
		$this->time = $x;
	}

	public function getOperation(){
		return $this->operation;
	}
	public function setOperation($x){
		$this->operation = $x;
	}

	public function isApproved(){
		return $this->approved;
	}
	public function setApproved($x){
		$this->approved = $x;
	}
	
	public function getOrename(){
		return $this->orename;
	}
	public function setOrename($x){
		$this->orename = $x;
	}
	
	public function getIcon(){
		return $this->oreicon;
	}
	public function setIcon($x){
		$this->oreicon = $x;
	}
}

?>