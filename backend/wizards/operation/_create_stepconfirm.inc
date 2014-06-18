<!--h3> Confirm and create the operation.</h3-->
<table><td colspan="2" height="90" style="vertical-align:top;"><img src="images/wizard4x.png"></td><td>
<table class="usertable">
<tr><td width="100">Mining type</td><td width="100"><?php echo $_GET['miningtype']; ?></td><td></td></tr>
<tr><td>Selling system</td><td><?php echo $_GET['place']; ?></td></tr>
<tr><td>&nbsp;</td><td></td></tr>
<tr><td>Margin</td><td><?php echo $_GET['margin']; ?>%</td></tr>
<tr><td>&nbsp;</td><td></td></tr>

<?php 
		if($_GET['miningtype']=="ore"||$_GET['miningtype']=="both"){?>
			<tr><td>Tritanium</td><td><?php echo $_GET['Tritanium']; ?> ISK</td></tr>
			<tr><td>Pyerite</td><td><?php echo $_GET['Pyerite']; ?> ISK</td></tr>
			<tr><td>Mexallon</td><td><?php echo $_GET['Mexallon']; ?> ISK</td></tr>
			<tr><td>Isogen</td><td><?php echo $_GET['Isogen']; ?> ISK</td></tr>
			<tr><td>Nocxium</td><td><?php echo $_GET['Nocxium']; ?> ISK</td></tr>
			<tr><td>Zydrine</td><td><?php echo $_GET['Zydrine']; ?> ISK</td></tr>
			<tr><td>Megacyte</td><td><?php echo $_GET['Megacyte']; ?> ISK</td></tr>
			<tr><td>Morphite</td><td><?php echo $_GET['Morphite']; ?> ISK</td></tr>
	<?php }
		if($_GET['miningtype']=="ice"||$_GET['miningtype']=="both"){?>
			<tr><td>Helium</td><td><?php echo $_GET['Helium']; ?> ISK</td></tr>
			<tr><td>Hydrogen</td><td><?php echo $_GET['Hydrogen']; ?> ISK</td></tr>
			<tr><td>Nitrogen</td><td><?php echo $_GET['Nitrogen']; ?> ISK</td></tr>
			<tr><td>Oxygen</td><td><?php echo $_GET['Oxygen']; ?> ISK</td></tr>
			<tr><td>Heavy water</td><td><?php echo $_GET['Heavy']; ?> ISK</td></tr>
			<tr><td>Liquid ozone</td><td><?php echo $_GET['Liquid']; ?> ISK</td></tr>
			<tr><td>Strontium</td><td><?php echo $_GET['Strontium']; ?> ISK</td></tr>
	<?php } ?>

<tr>
<td colspan="2">
<br>
</td></tr></table><form action="operations.php">	
	<input type="hidden" value="<?php echo $session->getSessionHash(); ?>" name="session" />
	<input type="hidden" value="<?php echo $_GET['miningtype']; ?>" name="miningtype" />
	<input type="hidden" value="<?php echo $_GET['place']; ?>" name="sellingsystem" />
	<input type="hidden"  name="tax" value="<?php if(isset($_GET['margin']))echo $_GET['margin']; ?>">
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
	<input type="hidden" value="yes" name="createoperation" />
	<a href="operations.php"><img class="button" src="images/abort.png" /></a>
	<input class="button" type="image" width="88" height="19" border="0" src="images/createop.png" />
	<input type="hidden" value="<?php echo $_GET['submenu']; ?>" name="submenu" />
	<input type="hidden" value="<?php echo $_GET['menu']; ?>" name="menu" />
	</form>

</td></table>
