<?php 
	$path = '/home3/johangau/orcapilot';
	set_include_path(get_include_path() . PATH_SEPARATOR . $path);	
		
	require_once 'framework_0_2/_include.inc';	
	
	$session = new Session();

	
	if(isset($_GET['pilot'])){
		$pi = $_GET['pilot'];
		$pilot = new Pilot();
		$pilot->loadUser($_GET['pilot']);
	}
	if(isset($_GET['operation']))$op = $_GET['operation'];
	
	if(isset($_GET['addore'])){
		if($_GET['addore'] == "true"){
				new CreateTransaction();		
		}	
	}	
	
	if(isset($_GET['deletetransaction'])){
		if($_GET['deletetransaction'] == "true"){
				new ActionDeleteTransaction();		
		}	
	}
	
	$transactionArray = new TransactionArray();
	$transactionArray->loadArray();
	
	$oreArray = new OREArray();
	include 'framework_0_2/_header.php';
	
	?>
<h3>Adding to: <?php if(isset($pilot))echo $pilot->getPilotname(); ?></h3>
<div align="center">
	<a href="singleoperation.php?
	<?php 
		if(isset($_GET['session'])) echo "session=".$session->getSessionHash();
		echo "&";
		if(isset($_GET['operation']))
			echo "operation=".$_GET['operation'];	
		echo "&"; 		
		if(isset($_GET['operation']))
			echo "pilot=".$_GET['pilot'];		
		echo "&approvetransaction=yes";		
	?>">
		<img class="button" src="images/done.png">	</a>
		
		
			<a href="transactionhistory.php?
	<?php 
		if(isset($_GET['session'])) echo "session=".$session->getSessionHash();
		echo "&";
		if(isset($_GET['operation']))
			echo "operation=".$_GET['operation'];	
		echo "&"; 		
		if(isset($_GET['operation']))
			echo "pilot=".$_GET['pilot'];		
		echo "&approvetransaction=yes";		
	?>">
		<img class="button" src="images/history.png">	</a>
		
			
		<a href="singleoperation.php?<?php 
		echo "session=".$session->getSessionHash();
		echo "&operation=".$op; ?>">
		<img class="button" src="images/abort.png">	</a>
	
</div>
<p align="center">Hint: you can type M,m,K or k after the amount to get kilo or Mega.</p></div>

<form name="myform">	
	<table class="usertable">		
		<tr>	
			<td>
				<?php
					$oreArray->getHTMLdropdown();
					?>	
			</td>	
			<td>		
				<input type="text" class="dark" size="8" name="amount"/>
			</td>
		</tr>
		<tr>
			<td>Type "ve" for Veld, "ke" for Kernite and so on...</td>
			<td>Press enter when done.</td>
		</tr>
	<table>		
<input type="hidden" name="pilot" value="<?php echo $pi; ?>" />
<input type="hidden" name="operation" value="<?php echo $op; ?>" />
<input type="hidden" name="session" value="<?php echo $session->getSessionHash();?>">
<input type="hidden" name="verificationcode" value="<?php echo Transaction::getNewVerificationCode();?>">
<input type="hidden" name="addore" value="true" />
</form>
<?php 		
			
	$transactionArray->getHTMLtable();
?>
<br><script type="text/javascript"> document.myform.ore.focus();</script>
<p align="center">Another hint: Click on a transaction to delete it.</p>

<?php include 'framework_0_2/_footer.php'; ?>
