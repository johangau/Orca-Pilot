<?php

class Session{

	private $userid;
	private $username;
	private $password;
	private $sessionid;
	private $sessionHash;

	
	function __construct(){
		if(isset($_GET['session'])){
			$this->checkSession();
		}else{
			if(isset($_GET['username'])&&isset($_GET['password'])){
				if($_GET['username']=="" || $_GET['password']==""){
					include 'framework_0_2/_header.php';
					die("you need to specify both password and username");
				}
				$this->setUsername($_GET['username']);
				$this->setPassword($_GET['password']);
				$this->createSession();
				
			}else{
			die("you need to login first");
		}
		}		
	}
	
	/**
	 * 
	 *
	 * @return a new session id if person is logged in or the old if there is one.
	 */
	public function createSession(){
		/*get the userid with the login details*/
		$db = new dBc();
		$query_userid = "SELECT iduser FROM users WHERE username='".$this->getUsername()."' AND password='".$this->getPasswordHash()."'";	
		
		/*check that the query is not empty or die since something is wrong in that case*/
		if($db->isResultEmpty($query_userid)){		
			include 'framework_0_2/_header.php';
			die("username or password was wrong.");
		}else{			
			$this->setUserId($db->getSingleResult($query_userid));
		}
		
		
		/*this query will look to see if the user already logged in during the last 2 hours(7200 seconds)*/
		$query_last_login_time = "SELECT sessionhash  FROM sessions WHERE iduser = ".$this->getUserId()." AND TIMESTAMPDIFF(SECOND,logintime,NOW()) < 7200";
		
		
				
		if($db->isResultEmpty($query_last_login_time)){
			$hash = $this->generateNewHash();
			$get_hash_query = "INSERT into sessions (iduser,sessionhash)VALUES('".$this->getUserId()."','".$hash."')";
			$db->runInsert($get_hash_query);				
			$this->setSessionHash($hash);
		}else{
			$hash = $db->getSingleResult($query_last_login_time);
			$this->setSessionHash($hash);
		}
		//dBc::clearOldData();
	}

	private function generateNewHash(){
		return hash("sha256",time().mt_rand());
	}
	
	function checkSession(){
		
		if(isset($_GET['session'])){
			$this->setSessionHash($_GET['session']);
			return true;
		}else{
			include 'framework_0_2/_header.php';
			die("session has timed out.");	
		}
		
		$db = new dBc();
		$query_userid = "SELECT iduser FROM users WHERE sessionhash = ".$this->getSessionHash()."'";	
		
		/*check that the query is not empty or die since something is wrong in that case*/
		if($db->isResultEmpty($query_userid)){		
			include 'framework_0_2/_header.php';
			die("username or password was wrong.");
		}else{			
			$this->setUserId($db->getSingleResult($query_userid));
		}
		
		
		/*this query will look to see if the user already logged in during the last 2 hours(7200 seconds)*/
		$query_last_login_time = "SELECT sessionhash  FROM sessions WHERE iduser = ".$this->getUserId()." AND TIMESTAMPDIFF(SECOND,logintime,NOW()) < 7200";
				
		if(!$db->isResultEmpty($query_last_login_time)){
			die("your session has timed out. Please login here again.");
		}
	}
	
	public function getUser(){
		$u = new User();
		$u->loadUser($this->getUserId());
		return $u;
	}

	private function setUserId($i){
		$this->userid = $i;
	}	

	public function getUserId(){
		return $this->userid;
	}	
	
	public function setUsername($u){

		$this->username = dBc::escape($u);
	}	
	
	public function setPassword($pass){
		$this->password = dBc::escape($pass);
	}

	public function getUsername(){
		return $this->username;
	}	
	public function getPassword(){
		return $this->password;
	}
	public function getPasswordHash(){
		return hash("sha256", $this->password);
	}
	
	private function setSessionid($id){
		$this->sessionid = dBc::escape($id);
	}	
	public function getSessionid(){
		return $this->sessionid();
	}

	public function setSessionHash($hash){
		$this->sessionHash = dBc::escape($hash);
	}	
	public function getSessionHash(){
		return $this->sessionHash;
	}

	
}

?>