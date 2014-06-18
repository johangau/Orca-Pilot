<?php 

$url = 'http://api.eve-central.com/api/marketstat?typeid=34&typeid=35&typeid=36&typeid=37&typeid=38&typeid=39&typeid=40&typeid=11399&typeid=16274&typeid=17889&typeid=17888&typeid=17887&typeid=16272&typeid=16273&typeid=16275&usesystem='.$_GET['place'];
// $xml = simplexml_load_file($url);
$file = file_get_contents($url);
//echo $file;

$evec_api = new SimpleXMLElement($file);

$tritanium = $evec_api->marketstat->type[0]->buy->avg;//34
$pyerite = $evec_api->marketstat->type[1]->buy->avg;//35
$mexallon = $evec_api->marketstat->type[2]->buy->avg;//36
$isogen = $evec_api->marketstat->type[3]->buy->avg;//37
$nocxium = $evec_api->marketstat->type[4]->buy->avg;//38
$zydrine = $evec_api->marketstat->type[5]->buy->avg;//39
$megacyte = $evec_api->marketstat->type[6]->buy->avg;//40
$morphite = $evec_api->marketstat->type[7]->buy->avg;//11399

$helium = $evec_api->marketstat->type[8]->buy->avg;//16274
$hydrogen = $evec_api->marketstat->type[9]->buy->avg;//17889
$nitrogen = $evec_api->marketstat->type[10]->buy->avg;//17888
$oxygen = $evec_api->marketstat->type[11]->buy->avg;//17887
$heavywater = $evec_api->marketstat->type[12]->buy->avg;//16272
$liquidzone = $evec_api->marketstat->type[13]->buy->avg;//16273
$strontium = $evec_api->marketstat->type[14]->buy->avg;//16275
?>

<!--h3> Set the prices of the refined products</h3-->
<table>
	<tr><td colspan="2" height="90" style="vertical-align:top;"><img src="images/wizard3x.png"></td><td width="240"></td><td>

<form action="createoperation.php" method="get">
<table class="usertable">
	<?php 
		if($_GET['miningtype']=="ore"||$_GET['miningtype']=="both"){?>
	<tr ><td>Tritanium</td><td><input type="text" class="dark" size="6" name="Tritanium" value="<?php echo $tritanium; ?>"> ISK</td></tr>
	<tr ><td>Pyerite</td><td><input type="text" class="dark" size="6" name="Pyerite" value="<?php echo $pyerite; ?>"> ISK</td></tr>
	<tr ><td>Mexallon</td><td><input type="text" class="dark" size="6" name="Mexallon" value="<?php echo $mexallon; ?>"> ISK</td></tr>
	<tr ><td>Isogen</td><td><input type="text" class="dark" size="6" name="Isogen" value="<?php echo $isogen; ?>"> ISK</td></tr>
	<tr ><td>Nocxium</td><td><input type="text" class="dark" size="6" name="Nocxium" value="<?php echo $nocxium; ?>"> ISK</td></tr>
	<tr ><td>Zydrine</td><td><input type="text" class="dark" size="6" name="Zydrine" value="<?php echo $zydrine; ?>"> ISK</td></tr>
	<tr ><td>Megacyte</td><td><input type="text" class="dark" size="6" name="Megacyte" value="<?php echo $megacyte; ?>"> ISK</td></tr>
	<tr ><td>Morphite</td><td><input type="text" class="dark" size="6" name="Morphite" value="<?php echo $morphite; ?>"> ISK</td></tr>
	<?php 
	}
	if($_GET['miningtype']=="ice"||$_GET['miningtype']=="both"){?>
	<tr ><td>Helium</td><td><input type="text" class="dark" size="6" name="Helium" value="<?php echo $helium; ?>"> ISK</td></tr>
	<tr ><td>Hydrogen</td><td><input type="text" class="dark" size="6" name="Hydrogen" value="<?php echo $hydrogen; ?>"> ISK</td></tr>
	<tr ><td>Nitrogen</td><td><input type="text" class="dark" size="6" name="Nitrogen" value="<?php echo $nitrogen; ?>"> ISK</td></tr>
	<tr ><td>Oxygen</td><td><input type="text" class="dark" size="6" name="Oxygen" value="<?php echo $oxygen; ?>"> ISK</td></tr>
	<tr ><td>Heavy water</td><td><input type="text" class="dark" size="6" name="Heavy" value="<?php echo $heavywater; ?>"> ISK</td></tr>
	<tr ><td>Liquid oxygen</td><td><input type="text" class="dark" size="6" name="Liquid" value="<?php echo $liquidzone; ?>"> ISK</td></tr>
	<tr ><td>Strontium</td><td><input type="text" class="dark" size="6" name="Strontium" value="<?php echo $strontium; ?>"> ISK</td></tr>
	<?php }?> 
<tr>
<td colspan="2">
<br>
 This will affect the prices that are calculated.<br>
</td></tr></table>


<img src="images/cancel.png" class="button"> <img src="images/back.png" class="button">
<input class="button" type="image" width="94" height="32" border="0" src="images/wizard_next.png" />
<input type="hidden" value="4" name="step" />
<input type="hidden" value="<?php echo $_GET['miningtype']; ?>" name="miningtype" />
<input type="hidden" value="<?php echo $_GET['place']; ?>" name="place" />
<input type="hidden" value="<?php echo $session->getSessionHash(); ?>" name="session" />
<input type="hidden" value="<?php echo $_GET['submenu']; ?>" name="submenu" />
<input type="hidden" value="<?php echo $_GET['menu']; ?>" name="menu" />

</form>
</td></tr></table>
<br>

