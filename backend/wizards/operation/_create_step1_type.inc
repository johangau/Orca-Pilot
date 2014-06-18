<!--h3> Type of operation</h3>
<form action="createoperation.php" method="get">
	<img src="images/wizard1.png">
<table class="usertable">
	<td>
<input type="radio" name="miningtype" value="ice" disabled/> Ice<br />
<input type="radio" name="miningtype" value="ore" disabled/> Ore<br />
<input type="radio" name="miningtype" value="both" checked/> Both<br />
<input type="hidden" value="2" name="step" />
<input type="hidden" value="<?php echo $session->getSessionHash(); ?>" name="session" />
<input type="hidden" value="<?php echo $_GET['submenu']; ?>" name="submenu" />
<input type="hidden" value="<?php echo $_GET['menu']; ?>" name="menu" />

<br>
 This will affect what kind of different types you will be able to add to your cargo.<br>
</td></table>
<img src="images/cancel.png" class="button">
<input class="button" type="image" width="88" height="19" border="0" src="images/next.png" />
</form--> 


<!--h3> Type of operation</h3-->
<form action="createoperation.php" method="get">
<table class="usertable" >
	<tr><td width="210"><img src="images/wizard1x.png"></td>
	
	<td>
	
	 <h2>Create a new operation</h2>
	 There are two ways to create a new operation:<br><br>
	 1) Just press the FAST OPERATION button below and the default values will be used.<br><br>
	 2) Press the CUSTOMIZE button to control what values to use prices/margins/selleing system and so on<br><br><br>
	 
	 <input class="button" type="image" width="92" height="32" border="0" src="images/wizard_fast_operation.png">
	 <input class="button" type="image" width="92" height="32" border="0" src="images/wizard_customize.png">	
	
	</td></tr>
	
	<tr><td></td><td>
<input type="hidden" name="miningtype" value="both"/><br />
<input type="hidden" value="2" name="step" />
<input type="hidden" value="<?php echo $session->getSessionHash(); ?>" name="session" />
<input type="hidden" value="<?php echo $_GET['submenu']; ?>" name="submenu" />
<input type="hidden" value="<?php echo $_GET['menu']; ?>" name="menu" />

<br>
</td></table>
<img src="images/cancel.png" class="button">
<input class="button" type="image" width="88" height="19" border="0" src="images/next.png" />
</form> 
