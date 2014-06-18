<?php

require_once 'framework_0_2/objects/operation.inc';
require_once 'framework_0_2/calculations/operation_isk.inc';

class OperationsArray{
	
	private $operations;
	
	
	function loadOperations($user){
		$this->operations = new ArrayObject();
		$db = new dBc();	
		$result = $db->getResult("SELECT * FROM operation ORDER BY date DESC LIMIT 20");				
		
		for($i=0;$i<$result->count();$i++){
			$post = $result->offsetGet($i);
			$operation = new Operation();
			$operation->load($post["idoperation"],$post["date"],$post["closed"],$post["tax"],$post["sellingsystem"]);							
			$this->operations->append($operation);
		}
	}

	function __test(){
		for($i=0;$i<$this->operations->count();$i++){	
				$operation = $this->operations->offsetGet($i);
				assert($operation instanceof Operation);
				$operation->selftest();
				
		}
	}
		function getHTMLtable(){
			
			$session = new Session();
			echo '
			<table class="usertable">';
			for($i=0;$i<$this->operations->count();$i++){
				
				$operation = $this->operations->offsetGet($i);
				
				assert($operation instanceof Operation);
				
				/* if the operation is running show green */				
				if(!$operation->isClosed()){
					echo '
					<tr class="mainlistitem" alt="" onMouseOver="this.className=\'kolme\'" onMouseOut="this.className=\'mainlistitem\'" onclick="parent.location=\'singleoperation.php?session='.$session->getSessionHash().'&operation='.$operation->getId().'\'">';
				}elseif($i%2==0){
					/* otherwise show the first gray if $i is even */	
					echo '
					<tr class="mainlistitem" onMouseOver="this.className=\'kolme\'" onMouseOut="this.className=\'mainlistitem\'" onclick="parent.location=\'singleoperation.php?session='.$session->getSessionHash().'&operation='.$operation->getId().'\'">';				
				}else{					
				/* and the second grey of it is odd */					
					echo '
					<tr class="mainlistitem" onMouseOver="this.className=\'kolme\'" onMouseOut="this.className=\'mainlistitem\'" onclick="parent.location=\'singleoperation.php?session='.$session->getSessionHash().'&operation='.$operation->getId().'\'">';				
				}					
				echo '<td height="33"></td>';
				echo '<td width="100">'.$operation->getDate().'</td>';					
				echo '<td>'.OperationISK::calculateISK($operation->getId()).'</td>';					
				if($operation->isClosed()){ echo '<td>Closed</td>'; }else{ echo '<td>Running</td>';}					 					
				echo '</tr>';							
			}		
			echo '
			</table>';						
	}
}

?>