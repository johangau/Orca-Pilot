<?php
require_once 'framework_0_2/objects/operation.inc';
require_once 'framework_0_2/objects/pilot.inc';
require_once 'framework_0_2/calculations/pilot_isk.inc';

class PilotArray {

	private $pilots;

	function loadPilots($user) {
		$this -> pilots = new ArrayObject();
		$db = new dBc();
		$result = $db -> getResult("SELECT iduser FROM users WHERE corporate_account = 0");
		for ($i = 0; $i < $result -> count(); $i++) {
			$post = $result -> offsetGet($i);
			$pilot = new Pilot();
			$pilot -> loadUser($post["iduser"]);
			$this -> pilots -> append($pilot);
		}
	}

	function loadOperationPilots($operationid) {
		$this -> pilots = new ArrayObject();
		$db = new dBc();
		$result = $db -> getResult("SELECT * FROM `operation_pilots` JOIN users AS pilots ON(pilots.iduser = pilot) WHERE operation = " . $operationid);
		for ($i = 0; $i < $result -> count(); $i++) {
			$post = $result -> offsetGet($i);
			$pilot = new Pilot();
			$pilot -> loadUser($post["iduser"]);
			$this -> pilots -> append($pilot);
		}
	}

	function getHTMLdropdown() {
		echo '<select class="dark" name="pilot">';
		for ($i = 0; $i < $this -> pilots -> count(); $i++) {
			$pilot = $this -> pilots -> offsetGet($i);

			assert($pilot instanceof Pilot);
			echo '<option value="' . $pilot -> getId() . '">' . $pilot -> getPilotname() . "</option>";
		}
		echo '</select>';
	}

	function test() {
		for ($i = 0; $i < $this -> pilots -> count(); $i++) {
			$pilot = $this -> pilots -> offsetGet($i);
			assert($pilot instanceof Pilot);
			$pilot -> selftest();
		}
	}

	function getHTMLtable() {		echo '<table class="usertable">';
		$session = new Session();
		for ($i = 0; $i < $this -> pilots -> count(); $i++) {
			$pilot = $this -> pilots -> offsetGet($i);
			assert($pilot instanceof Pilot);
			if ($i % 2 == 0) {
			/* show the first gray if $i is even */
				echo '<tr class="yxi" 
					onMouseOver="this.className=\'kolme\'" 
					onMouseOut="this.className=\'yxi\'" 
					onclick="parent.location=\'addore.php?session='.$session->getSessionHash().'&pilot=' . $pilot->getId() . '&operation=' . $_GET['operation'] . '\'">';
			}else{ 
			/* and the second grey of it is odd */echo '
					<tr class="kaxi"
					onMouseOver="this.className=\'kolme\'"
					onMouseOut="this.className=\'kaxi\'" 
					onclick="parent.location=\'addore.php?session='.$session->getSessionHash().'&pilot=' . $pilot->getId() . '&operation=' . $_GET['operation'] . '\'">';
			}
		echo '<td><img src="images/face.png" class="operationicon"></td>';
		echo '<td width="100">'.$pilot -> getPilotname().'</td>';
		echo '<td>' . PilotISK::calculateISK($pilot -> getId(), $_GET['operation']) . '</td>';
		echo '</tr>';
		}
		echo '</table>';
	}

}
?>