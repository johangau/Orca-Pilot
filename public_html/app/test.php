<?php 
	$path = '/home3/johangau/orcapilot';
	set_include_path(get_include_path() . PATH_SEPARATOR . $path);	
include 'framework_0_2/_header.php';?><h1>Test suite 0.1</h1>
<?php

require_once 'framework_0_2/_include.inc';

new CreatePayment();

?>
