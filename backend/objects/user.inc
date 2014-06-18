<?php 

//require_once 'framework_0_2/tools/database.inc';
//require_once 'framework_0_2/objects/arrays/operationsarray.inc';

class User{
	public $id;
	public $name;
	public $firstname;
	public $lastname;
	public $email;
	public $evename;
	public $operations;
	
	function loadUser($idx){		
		$this->setId($idx);			
		$db = new dBc();
		$dbr = $db->getResult("SELECT username,email,evename FROM users WHERE iduser = ".$this->getId());
		assert($dbr instanceof ArrayObject);		
		$userdata = $dbr->offsetGet(0);		
		$this->name = $userdata['username'];	
		$this->email = $userdata['email'];
		$this->evename = $userdata['evename'];
		unset($db);
	}
	
	function loadOperations(){
		$this->operations = new OperationsArray();
		$this->operations->loadOperations($this->id);
	}

	function test(){
		echo "<p><b>Running user test.</b></p>";
		echo "<p>id: ".$this->id."</p>";
		echo "<p>name: ".$this->name."</p>";
		echo "<p>firstname: ".$this->firstname."</p>";
		echo "<p>lastname: ".$this->lastname."</p>";
		echo "<p>email: ".$this->email."</p>";
		echo "<p>evename: ".$this->evename."</p>";
		echo "<p><b>User test ended.</b></p>";
	}
	
	function testLoadedOperations(){
		$this->operations->test();
	}
	
	function setId($i){ $this->id = dBc::escape($i);}
	function getId(){ return $this->id;}
	
}

?>