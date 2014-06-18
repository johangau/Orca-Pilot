<?php 
	$path = '/home3/johangau/orcapilot';
	set_include_path(get_include_path() . PATH_SEPARATOR . $path);		
	require_once 'framework_0_2/_include.inc';
	$session = new Session();

if(isset($_GET['createoperation'])){
		if($_GET['createoperation'] == "yes"){
					new ActionCreateOperation();	
		}
}

if(isset($_GET['closeoperation'])){
	if($_GET['closeoperation'] == "yes"){
		new ActionCloseOperation();
	}
}

include 'framework_0_2/_header.php'; ?>

<div align="center">
<!--a href="createoperation.php?session=<?php echo $session->getSessionHash()."&menu=".$_GET['menu']."&submenu=".$_GET['submenu'];?>">
<img class="button" src="images/createop.png"></a-->
<!--img class="button" src="images/statistics.png">
<a href="payments.php?session=<?php echo $session->getSessionHash();?>"><img class="button" src="images/payments.png"></a>
<a href="payments.php?session=<?php echo $session->getSessionHash();?>"><img class="button" src="images/pilots.png"></a-->
</div><?php 
$pa = new OperationsArray();
$pa->loadOperations($session->getUserId());
$pa->getHTMLtable();?> 
<?php include 'framework_0_2/_footer.php'; ?>