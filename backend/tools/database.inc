<?php

class dBc{
	
	private $link;
	private $result;
	private $line;
	private $arrayresult;
	
	/**
	 * connecting to the database
	 */
	function connect(){
		$this->link = mysql_connect('localhost', 'orcapilo_tt', 'muppeli01!!') or die('Could not connect: ' . mysql_error());
		mysql_select_db('orcapilo_orcapilot_0_2') or die('Could not select database');

	}
	
	/**
	 * closing the database connection
	 */
	function close(){
		// Closing connection		mysql_close($this->link);
	}
	
	static function escape($string){
		$tmplink = mysql_connect('localhost', 'orcapilo_tt', 'muppeli01!!') or die('Could not connect: ' . mysql_error());
		$escaped_string = mysql_real_escape_string($string,$tmplink);
		mysql_close($tmplink);
		return $escaped_string;
	}
	
	
	/**
	 * running a database query
	 */
	function runQuery($query){
		$this->result = mysql_query($query) or die('Query failed: ' . mysql_error());		
		$this->arrayresult = new ArrayObject();			while ($line = mysql_fetch_array($this->result, MYSQL_ASSOC)) {			$this->arrayresult->append($line);		}    	
	}
	
	function runInsert($query){
		$this->connect();		
		mysql_query($query) or die('Query failed: ' . mysql_error());		
		$this->close();			
	}
	
	function getSingleResult($query){
		$this->connect();		
		$this->result = mysql_query($query) or die('Query failed: ' . mysql_error());					
		$line = mysql_fetch_array($this->result, MYSQL_NUM);		
		$this->close();		
		return $line[0];	
	}
	/**
	 * gets the result as a ArrayObject
	 */
	function getResult($query){
		$this->connect();
		$this->runQuery($query);			
		$this->close();

				
		return $this->arrayresult;
	}
	
	
	/*********
	 * Clears data older then one month...approx...
	 * This is really important since the program will crash at too many transactions
	 * called by action_create_operation.inc
	 */
	function clearOldData(){
		$this->connect();
		mysql_query("DELETE from transactions where time < NOW() - 50000000");
		mysql_query("DELETE from operation where date < NOW() - 50000000");
		$this->close();
	}

	
	function isResultEmpty($query){
		$this->connect();
		$result = mysql_query($query);
		$num_rows = mysql_num_rows($result);
		$this->close();
		if($num_rows!=0){ return false; }else{ return true;}
	}
	
}

?>