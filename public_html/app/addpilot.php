<?php 

$path = '/home3/johangau/orcapilot';
set_include_path(get_include_path() . PATH_SEPARATOR . $path);	

require_once 'framework_0_2/_include.inc';

$session = new Session();

if(isset($_GET['username'])){
	if($_GET['username'] != ""){
		new ActionCreateUser($_GET['username'],$_GET['password'],$_GET['email'],$_GET['evename']);
	}
}



include 'framework_0_2/_header.php';
$pa = new PilotArray();

$pa->loadPilots(1);
?>
<h3>Add a pilot to the operation</h3>
<p>select from the list</p>
<p><form action="singleoperation.php?addpilot=yes"><?php $pa->getHTMLdropdown(); ?><br>
	<input class="button" type="image" width="88" height="19" border="0" src="images/addpilot.png" />
	<a href="createuser.php?session=<?php echo $session->getSessionHash();?>&operation=<?php if(isset($_GET['operation']))echo $_GET['operation'];?>"><img src="images/newpilot.png" class="button"></a>
	<input type="hidden" name="operation" value="<?php if(isset($_GET['operation']))echo $_GET['operation'];?>" />
	<input type="hidden" name="addpilot" value="yes" />
	<input type="hidden" name="session" value="<?php echo $session->getSessionHash();?>">
</form></p>
<p>Or add a new pilot/user</p>
