<?php

class ActionCreateUser{
	
	private $user;
	private $pass;
	private $mail;
	private $evename;
	
	function __construct(){
		
		$this->setUser($_GET['username']);
		$this->setPassword($_GET['password']);
		$this->setEmail($_GET['email']);
		$this->setEvename($_GET['evename']);
		
		/**TODO calculate the stuff with the k and M and also make sure that decimal comma is point **/		
		$query = "INSERT INTO `users` (`username`, `password`, `email`, `evename`) 
		VALUES ( '".$this->getUser()."', '".$this->getPassword()."', '".$this->getEmail()."', '".$this->getEvename()."' );";
		$db = new dBc();	
		$db->runInsert($query);
		unset($db);		
	}
	
	function setUser($u){
		$this->user = dBc::escape($u);
	}
	function getUser(){
		return $this->user;
	}		

	function setPassword($u){
		$this->pass = dBc::escape($u);
	}
	function getPassword(){
		return $this->pass;
	}		
	
	function setEmail($u){
		$this->mail = dBc::escape($u);
	}
	function getEmail(){
		return $this->mail;
	}		
	
	function setEvename($u){
		$this->evename = dBc::escape($u);
	}
	function getEvename(){
		return $this->evename;
	}		

}

?>