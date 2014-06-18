<?php

require_once 'framework_0_2/tools/database.inc';
require_once 'framework_0_2/objects/ore.inc';

class OREArray{
	
	private $ORElist;
	
	function __construct(){
		$this->loadORE();
	}
	
	function loadORE(){

		$this->ORElist = new ArrayObject();

		$db = new dBc();	

		$result = $db->getResult("SELECT * FROM `ore_or_ice`");				

		for($i=0;$i<$result->count();$i++){
			$post = $result->offsetGet($i);
			$ore = new ORE($post["idore_or_ice"],$post["name"]);
			$this->ORElist->append($ore);
		}

	}
	
	function getHTMLdropdown(){
		
		echo '<select class="dark" name="ore">';
				for($i=0;$i<$this->ORElist->count();$i++){
				$ore = $this->ORElist->offsetGet($i);
				assert($ore instanceof ORE);
				if($i%3==0)echo '<option></option>';
				echo '<option value="'.$ore->getId().'">'.$ore->getName().'</option>';				
			}
		echo '</select>';
		
	}
}

?>