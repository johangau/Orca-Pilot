<?php 
	$path = '/home3/johangau/orcapilot';
	set_include_path(get_include_path() . PATH_SEPARATOR . $path);	
	
	require_once 'framework_0_2/_include.inc';	
	
	$session = new Session();
	
	if(isset($_GET['pilot']))$pi = $_GET['pilot'];
	if(isset($_GET['operation']))$op = $_GET['operation'];

	if(isset($_GET['deletetransaction'])){
		if($_GET['deletetransaction'] == "true"){
				new ActionDeleteTransaction();		
		}	
	}	

	$transactionArray = new TransactionArray();
	$transactionArray->loadHistoryArray();
	
	include 'framework_0_2/_header.php';
	
	?>
<h3>History of: <?php if(isset($_GET['name']))echo $_GET['name']; ?></h3>
<div align="center">
	<a href="addore.php?
	<?php 
		if(isset($_GET['session'])) echo "session=".$session->getSessionHash();
		echo "&";
		if(isset($_GET['operation']))
			echo "operation=".$_GET['operation'];	
		echo "&"; 		
		if(isset($_GET['operation']))
			echo "pilot=".$_GET['pilot'];		
	?>">
		<img class="button" src="images/back.png">	</a>				
</div>

<p align="center">You can click on an entry to delete it.</p></div>

<?php 		
			
	$transactionArray->getHistoryHTMLtable();
?>

<?php include 'framework_0_2/_footer.php'; ?>