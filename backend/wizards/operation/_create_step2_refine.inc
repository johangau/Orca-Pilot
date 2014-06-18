


<form action="createoperation.php" method="get">
<table class="usertable">
	<td width="210"><img src="images/wizard2x.png">
	</td>
	
	<td style="vertical-align:top;">
		<br><br><h2> Select station to sell the goods</h2>
<select class="dark" name="place">
	<option value="30002187">Amarr VIII (Oris) - Emperor Family Academy (1.0)</option>
	<option value="30000142">Jita IV - Moon 4 - Caldari Navy Assembly Plant (0.9)</option>
</select><br>
 Margin <input type="text" class="dark" size="6" name="margin" value=""> %<br>
<input class="button" type="image" width="94" height="32" border="0" src="images/wizard_next.png" />

<input type="hidden" value="3" name="step" />
<input type="hidden" value="<?php echo $_GET['miningtype']; ?>" name="miningtype" />
<br>
 This will affect the prices in the next step.<br>
</td></table>
<img src="images/cancel.png" class="button"> 

<img src="images/back.png" class="button" onClick="history.go(-1)">
<input type="hidden" value="<?php echo $session->getSessionHash(); ?>" name="session" />
<input type="hidden" value="<?php echo $_GET['submenu']; ?>" name="submenu" />
<input type="hidden" value="<?php echo $_GET['menu']; ?>" name="menu" />
</form> 