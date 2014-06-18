<?php 
	$path = '/home3/johangau/orcapilot';
	set_include_path(get_include_path() . PATH_SEPARATOR . $path);	
require_once 'framework_0_2/_include.inc';

$session = new Session();

if(isset($_GET['addpilot'])){
	if($_GET['addpilot'] == "yes"){
		new AddPilot();
	}
}

if(isset($_GET['approvetransaction'])){
	if($_GET['approvetransaction'] == "yes"){
		new ApproveTransaction();
	}
}

if(isset($_GET['makepayment'])){
	if($_GET['makepayment'] == "yes"){
		new ActionCreatePayment();
	}
}

include 'framework_0_2/_header.php'; ?>
 
<div align="center">
<a href="operations.php?session=<?php echo $session->getSessionHash();?>&menu=home&submenu=home"><img class="button" src="images/backtooplist.png"></a>
<a href="operations.php?session=<?php echo $session->getSessionHash();?>&closeoperation=yes&operation=<?php echo $_GET['operation'];?>&menu=home&submenu=home"><img class="button" src="images/closeoperation.png"></a>
<a href="addpilot.php?session=<?php echo $session->getSessionHash();?>&operation=<?php echo $_GET['operation']?>&menu=home&submenu=home"><img class="button" src="images/addpilot.png"></a>
<a href="paypilot.php?session=<?php echo $session->getSessionHash();?>&operation=<?php echo $_GET['operation'];?>&menu=home&submenu=home"><img class="button" src="images/paypilot.png"></a>
</div>
<?php $pa = new PilotArray();$pa->loadOperationPilots($_GET['operation']);$pa->getHTMLtable();?><br>
<table class="usertable">
	<tr>
		<th width="100">Total</th>
		<th width="200"><?php echo OperationISK::calculateISK($_GET['operation']);?> (estimated)</th>
		<td></td>
	</tr>
	<tr>
		<th>Corp tax(20%)</th>
		<th><?php echo OperationISK::calculateISKprofit($_GET['operation']);?> (estimated)</th> 
		<td></td>
</table>
<br>
<br>

<div align="center">PayPilot&reg; and DirectlyPaid&reg; are registred tradmarks of The Lost and Forgotten Inc.</div>
<?php include 'framework_0_2/_footer.php'; ?>