<?php 
	$path = '/home3/johangau/orcapilot';
	set_include_path(get_include_path() . PATH_SEPARATOR . $path);	
	include 'framework_0_2/_header.php'; 
	?>
<div align="center">
<form action="operations.php?">
<table width="900" height="684" background="images/loginbg.png">
	<tr>
		<td valign="top">
			<br>
			<div align="center">
				<table>
				<tr><td>username </td><td><div align="center"><input type="text" class="dark" name="username"/></div></td></tr>
				<tr><td>password </td><td><div align="center"><input type="password" class="dark" name="password"/></div></td></tr>				
				<tr><td></td><td><div align="center"><input class="button" type="image" width="88" height="19" border="0" src="images/login.png" /></td></tr>
				</table>
			</div>
		</td>
	</tr>
</table>
</div>
<input type="hidden" name="login" value="true" />
<input type="hidden" name="menu" value="home" />
<input type="hidden" name="submenu" value="home" />

</form>

<?php include 'framework_0_2/_footer.php'; ?>