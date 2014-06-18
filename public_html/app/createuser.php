<?php
	$path = '/home3/johangau/orcapilot';
	set_include_path(get_include_path() . PATH_SEPARATOR . $path);	
include 'framework_0_2/_header.php';
require_once('framework_0_2/_include.inc');
$session = new Session();
?>
<h3>Add a new pilot</h3>
<form action="addpilot.php">
<table class="usertable">	
	<tr><td>username</td><td><input type="text" name="username" class="dark"/></td></tr>
	<tr><td>password</td><td><input type="password" name="password" class="dark"/></td></tr>
	<tr><td>retype password</td><td><input type="password" name="" class="dark"/></td></tr>
	<tr><td>email</td><td><input type="text" name="email" class="dark"/></td></tr>
	<tr><td>evename</td><td><input type="text" name="evename" class="dark"/></td></tr>
</table><br>
	<input class="button" type="image" width="88" height="19" border="0" src="images/addpilot.png" />
	<a href="singleoperation.php"><img class="button" src="images/abort.png" /></a>
	<input type="hidden" name="operation" value="<?php if(isset($_GET['operation']))echo $_GET['operation'];?>" />
	<input type="hidden" name="session" value="<?php echo $session->getSessionHash();?>">

</form>