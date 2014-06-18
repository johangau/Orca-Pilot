<?php 
	$path = '/home3/johangau/orcapilot';
	set_include_path(get_include_path() . PATH_SEPARATOR . $path);		
	require_once 'framework_0_2/_include.inc';
	$session = new Session();

include 'framework_0_2/_header.php'; ?>

<h3>Last 6 operations</h3>
<img src="graphs/test.php">