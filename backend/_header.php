<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01//EN">
<html>
<head>
  <title>OrcaPilot - Mining operation manager</title>
  <link rel="stylesheet" href="css/styles.css">
</head>

<body background="images/backgroundimage.png">
	<table  width="100%" cellspacing="0" cellpadding="0"  background="images/menu/menubg.png">
	<?php
		if(isset($_GET['menu'])&&isset($_GET['submenu'])){
			$p = new Menues();/*from menuoptions.php*/
			$p->printmenu();
		}
	?>
	</table>   