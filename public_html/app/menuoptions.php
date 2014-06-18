<?php

class Menues{

	private $menuchoise;
	private $submenuchoise;
	
	function printmenu(){
		
		//$this->setMenuchoise($_GET['menu']);
		//$this->setSubMenuchoise($_GET['submenu']);
		
		$this->operations_menu();
		$this->operations_submenu();
	}

	function operations_menu(){
		echo 'buffel';	
		echo '
			<tr>
				<td width="151" height="66"><img src="images/menu/Black-menu-item-home.png"></td>
				<td width="151" height="66"><img src="images/menu/Green-menu-item.png"></td>
				<td width="151" height="66"><img src="images/menu/Black-menu-item-pilots.png"></td>
				<td></td>
			</tr>
		';
	}

	function home_menu(){
		echo '
			<tr>
				<td width="151" height="66" background="images/menu/Green-menu-item-home.png"></td>
				<td width="151" height="66" background="images/menu/Black-menu-item.png"></td>
				<td width="151" height="66" background="images/menu/Black-menu-item-pilots.png"></td>
				<td></td>
			</tr>
		';
	}
	
	function operations_submenu(){
		echo '
			<tr>
				<td height="29" ><img src="images/menu/view-operation.png"></td>
				<td height="29" ><img src="images/menu/new-operation-active.png"></td> 
				<td height="29" ><img src="images/menu/close-operation.png"></td> 
				<td></td>
			</tr>
			';
	}
	
	function home_submenu(){
		echo '
			<tr>
				<td height="29" ><img src="images/menu/view-operation-active.png"></td>
				<td height="29" ><img src="images/menu/new-operation	.png"></td> 
				<td height="29" ><img src="images/menu/close-operation.png"></td> 
				<td></td>
			</tr>
			';
	}
	
	function setMenuchoise($choise){
		$this->menuchoise = $choise;
	}
	
	function getMenuchoise(){
		return $this->menuchoise;
	}
	function setSubMenuchoise($choise){
		$this->submenuchoise = $choise;
	}
	
	function getSubMenuchoise(){
		return $this->submenuchoise;
	}
}
?>