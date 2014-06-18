<?php

class Payment{
	
	private $idpayment; 	
	private $amount;
	private $timest;	
	private $operation; 	
	private $pilot;
	
	public function getNewVerificationCode(){
		return hash("sha256",time().mt_rand(0, 999999));
	}
	
	/**
	 * GETTERS and SETTERS
	 */
	public function setId($id){ $this->id = $id;}
	public function getId(){return $this->id;}
	public function setAmount($amount){ $this->amount = $amount;}
	public function getAmount(){return $this->amount;}
	public function setTime($time){$this->timest = $time;}
	public function getTime(){return $this->timest;}
	public function setOperation($operation){$this->operation = $operation;}
	public function getOperation(){return $this->operation;}
	public function setPilot($pilot){$this->pilot = $pilot;}
	public function getPilot(){return $this->pilot;}
	
}
