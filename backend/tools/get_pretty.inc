<?php

class Pretty{
	static function amount($amount,$unit){
		$amountrev = strrev($amount);
		$newstring = "";
		for($i=0;$i<strlen($amount);$i=$i+2){
			$substring = substr($amountrev, $i,3);
			$newstring .= $substring." ";
			$i+=1;
		}
		return  strrev($newstring)." ".$unit;		
	}
}
?>