<?php 
	$path = '/home3/johangau/orcapilot';
	set_include_path(get_include_path() . PATH_SEPARATOR . $path);	
require_once('framework_0_2/_include.inc'); 
$session = new Session();

	include 'framework_0_2/_header.php'; 
	
	
	if(isset($_GET['step'])){
		if($_GET['step'] == 2){
			
			
			
				
			include 'framework_0_2/wizards/operation/_create_step2_refine.inc';			
		}elseif($_GET['step'] == 3){
			include 'framework_0_2/wizards/operation/_create_step3_prices.inc';
		}elseif($_GET['step'] == 4){
			include 'framework_0_2/wizards/operation/_create_step4_margin.inc';
		}elseif($_GET['step'] == "confirm"){
			include 'framework_0_2/wizards/operation/_create_stepconfirm.inc';
		}else{
			echo 'oops, something went wrong!';
		}
	}else{
		include 'framework_0_2/wizards/operation/_create_step1_type.inc';
	}

?>
