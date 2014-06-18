<h3> Set the margin to give to the corp.</h3>
<form action="createoperation.php" method="get">
<table class="usertable">
	
	<tr><td>Margin</td><td><input type="text" class="dark" name="margin">%</td></tr>

<tr>
<td colspan="2">
<br>
 This will affect the prices that are calculated.<br>
</td></tr></table>


<img src="images/cancel.png" class="button"> <img src="images/back.png" class="button">
<input class="button" type="image" width="88" height="19" border="0" src="images/next.png" />
<input type="hidden" value="confirm" name="step" />
<input type="hidden" value="<?php echo $_GET['miningtype']; ?>" name="miningtype" />
<input type="hidden" value="<?php echo $_GET['place']; ?>" name="place" />
<input type="hidden"  name="Tritanium" value="<?php if(isset($_GET['Tritanium']))echo $_GET['Tritanium']; ?>">
<input type="hidden"  name="Pyerite" value="<?php if(isset($_GET['Pyerite']))echo $_GET['Pyerite']; ?>">
<input type="hidden"  name="Mexallon" value="<?php if(isset($_GET['Mexallon']))echo $_GET['Mexallon']; ?>">
<input type="hidden"  name="Isogen" value="<?php if(isset($_GET['Isogen']))echo $_GET['Isogen']; ?>">
<input type="hidden"  name="Nocxium" value="<?php if(isset($_GET['Nocxium']))echo $_GET['Nocxium']; ?>">
<input type="hidden"  name="Zydrine" value="<?php if(isset($_GET['Zydrine']))echo $_GET['Zydrine']; ?>">
<input type="hidden"  name="Megacyte" value="<?php if(isset($_GET['Megacyte']))echo $_GET['Megacyte']; ?>">
<input type="hidden"  name="Morphite" value="<?php if(isset($_GET['Morphite']))echo $_GET['Morphite']; ?>">
<input type="hidden"  name="Helium" value="<?php if(isset($_GET['Helium']))echo $_GET['Helium']; ?>">
<input type="hidden"  name="Hydrogen" value="<?php if(isset($_GET['Hydrogen']))echo $_GET['Hydrogen']; ?>">
<input type="hidden"  name="Nitrogen" value="<?php if(isset($_GET['Nitrogen']))echo $_GET['Nitrogen']; ?>">
<input type="hidden"  name="Oxygen" value="<?php if(isset($_GET['Oxygen']))echo $_GET['Oxygen']; ?>">
<input type="hidden"  name="Heavy" value="<?php if(isset($_GET['Heavy']))echo $_GET['Heavy']; ?>">
<input type="hidden"  name="Liquid" value="<?php if(isset($_GET['Liquid']))echo $_GET['Liquid']; ?>">
<input type="hidden"  name="Strontium" value="<?php if(isset($_GET['Strontium']))echo $_GET['Strontium']; ?>">
<input type="hidden" value="<?php echo $session->getSessionHash(); ?>" name="session" />
<input type="hidden" value="<?php echo $_GET['submenu']; ?>" name="submenu" />
<input type="hidden" value="<?php echo $_GET['menu']; ?>" name="menu" />

</form>