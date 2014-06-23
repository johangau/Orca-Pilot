<?php



?>

<div align="center">
<!--form action="operations.php?"-->
<form action="lounge/">
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
<input type="hidden" name="menu" value="operations" />
<input type="hidden" name="submenu" value="viewoperations" />


</form>
<br><br>
Don't have an account yet? <a href="create.php">Click here to create an account</a>