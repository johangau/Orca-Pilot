<?php

class Menues{

	private $menuchoise;
	private $submenuchoise;
	private $session;
	
	function printmenu(){
		$this->session = new Session();				
		$this->setMenuchoise($_GET['menu']);
		$this->setSubMenuchoise($_GET['submenu']);
		
		
		
		
		switch ($this->getMenuchoise()) {
			case 'home':
					$this->home_menu();
					switch ($this->getSubMenuchoise()) {
						case 'home':
							$this->operations_submenu_view();
							break;
						case 'operations' :
							$this->operations_submenu_view();
							break;							
					}
			break;
			case 'operations' :
				$this->operations_menu();
				switch ($this->getSubMenuchoise()) {
					case 'newoperation':
							$this->operations_submenu_new();
						break;
					case 'closeoperation':
							$this->operations_submenu_view();							
						break;
					case 'viewoperations':
							$this->operations_submenu_view();
						break;
				}
			break;
			case 'pilot' :
				$this->pilot_menu();
				switch ($this->getSubMenuchoise()) {
					case 'viewpilot':
							$this->operations_submenu_view();
						break;
					case 'addpilot':
							$this->operations_submenu_view();							
						break;
					case 'removepilot':
							$this->operations_submenu_view();
						break;
				}
			break;
			case 'settings' :
				$this->settings_menu();
				switch ($this->getSubMenuchoise()) {
					case 'viewpilot':
						$this->operations_submenu_view();
						break;
					case 'addpilot':
						$this->operations_submenu_view();
						break;
					case 'removepilot':
						$this->operations_submenu_view();
						break;
				}
				break;
		}

}

	function home_menu(){
		echo '
			<tr>
				<td width="151" height="66"><a href="home.php?session='.$this->session->getSessionHash()."&menu=".$_GET['menu']."&submenu=".$_GET['submenu'].'"><img src="images/menu/green-menu-item-home.png"></a></td>
				<td width="151" height="66"><a href="operations.php?session='.$this->session->getSessionHash()."&menu=operations&submenu=viewoperations".'"><img src="images/menu/Green-menu-item-operations.png"></a></td>
				<td width="151" height="66"><a href="operations.php?session='.$this->session->getSessionHash()."&menu=pilot&submenu=viewpilot".'"><img src="images/menu/Black-menu-item-pilots.png"></a></td>
				<td width="151" height="66"><a href="operations.php?session='.$this->session->getSessionHash()."&menu=settings&submenu=viewpilot".'"><img src="images/menu/Black-menu-item-settings.png"></a></td>
				<td width="100%"></td>
			</tr>
		';
	}
	
	function home_submenu(){
		echo '
			<tr>
				<td height="29" ><img src="images/menu/view-operation-active.png"></td>
				<td height="29" ><img src="images/menu/new-operation.png"></td> 
				<td height="29" ><img src="images/menu/close-operation-inactve.png"></td> 
				<td></td>
			</tr>
			';
	}

	function operations_menu(){
		echo '<tr>
				<td width="151" height="66"><a href="home.php?session='.$this->session->getSessionHash().'&menu=home&submenu=home"><img src="images/menu/Black-menu-item-home.png"></a></td>
				<td width="151" height="66"><a href="operations.php?session='.$this->session->getSessionHash()."&menu=operations&submenu=viewoperations".'"><img src="images/menu/Green-menu-item.png"></a></td>
				<td width="151" height="66"><a href="pilot.php?session='.$this->session->getSessionHash()."&menu=pilot&submenu=viewpilot".'"><img src="images/menu/Black-menu-item-pilots.png"></a></td>
				<td width="151" height="66"><a href="operations.php?session='.$this->session->getSessionHash()."&menu=pilot&submenu=viewpilot".'"><img src="images/menu/Black-menu-item-settings.png"></a></td>
				<td width="100%"></td>
			</tr>
		';
	}

	function operations_submenu_view(){
		echo '
			<tr>
				<td height="29"><a href=""><img src="images/menu/view-operation-active.png"></a></td>
				<td height="29"><a href="createoperation.php?session='.$this->session->getSessionHash()."&menu=operations&submenu=newoperation".'"><img src="images/menu/new-operation.png"></a></td> 
				<td height="29"><a href=""><img src="images/menu/close-operation-inactve.png"></a></td> 
				<td></td>
			</tr>
			';
	}
	function operations_submenu_new(){
		echo '
			<tr>
				<td height="29"><a href="operations.php?session='.$this->session->getSessionHash()."&menu=operations&submenu=viewoperations".'"><img src="images/menu/view-operation.png"></a></td>
				<td height="29"><a href="createoperation.php?session='.$this->session->getSessionHash()."&menu=operations&submenu=newoperation".'"><img src="images/menu/new-operation-active.png"></a></td> 
				<td height="29"><a href="operations.php?session='.$this->session->getSessionHash()."&menu=operations&submenu=closeoperations".'"><img src="images/menu/close-operation-inactve.png"></a></td> 
				<td></td>
			</tr>
			';
	}

	function pilot_menu(){
		echo '<tr>
				<td width="151" height="66"><a href="home.php?session='.$this->session->getSessionHash().'&menu=home&submenu=home"><img src="images/menu/Black-menu-item-home.png"></a></td>
				<td width="151" height="66"><a href="operations.php?session='.$this->session->getSessionHash()."&menu=operations&submenu=viewoperations".'"><img src="images/menu/Green-menu-item-operations.png"></a></td>
				<td width="151" height="66"><a href="pilot.php?session='.$this->session->getSessionHash()."&menu=pilot&submenu=viewpilot".'"><img src="images/menu/Green-menu-item-pilots.png"></a></td>
				<td width="151" height="66"><a href="operations.php?session='.$this->session->getSessionHash()."&menu=pilot&submenu=viewpilot".'"><img src="images/menu/Black-menu-item-settings.png"></a></td>
				<td width="100%"></td>
			</tr>
		';
	}
	
	function settings_menu(){
		echo '<tr>
				<td width="151" height="66"><a href="home.php?session='.$this->session->getSessionHash().'&menu=home&submenu=home"><img src="images/menu/Black-menu-item-home.png"></a></td>
				<td width="151" height="66"><a href="operations.php?session='.$this->session->getSessionHash()."&menu=operations&submenu=viewoperations".'"><img src="images/menu/Black-menu-item-operations.png"></a></td>
				<td width="151" height="66"><a href="pilot.php?session='.$this->session->getSessionHash()."&menu=pilot&submenu=viewpilot".'"><img src="images/menu/Black-menu-item-pilots.png"></a></td>
				<td width="151" height="66"><a href="operations.php?session='.$this->session->getSessionHash()."&menu=pilot&submenu=viewpilot".'"><img src="images/menu/green-menu-item-settings.png"></a></td>
				<td width="100%"></td>
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
/*<td width="151" height="66"><a href="operations.php?session='.$this->session->getSessionHash()."&menu=".$_GET['menu']."&submenu=".$_GET['submenu'];?>"><img src="images/menu/Black-menu-item-home.png"></a></td>*/
?>