<?php


class ActionCreateOperation{
	
	public $tax;
	public $tritanium;
	public $pyerite;
	public $mexallon;
	public $isogen;
	public $nocxium;
	public $zydrine;
	public $megacyte;
	public $morphite;
	public $helium;
	public $hydrogen;
	public $nitrogen;
	public $oxygen;
	public $heavywater;
	public $liquidzone;
	public $strontium; 
	
	
	// function createICEoperation($he,$hy,$ni,$ox,$wa,$li,$st){
// 
		// $this->helium = $he;
		// $this->hydrogen = $hy;
		// $this->nitrogen = $ni;
		// $this->oxygen = $ox;
		// $this->heavywater = $wa;
		// $this->liquidzone = $li;
		// $this->strontium = $st;
// 		
// 		
	// }
// 	
	// function createOREoperation($tr,$py,$me,$is,$no,$zy,$meg,$mo){
// 		
		// $this->tritanium = $tr;
		// $this->pyerite = $py;
		// $this->mexallon = $me;
		// $this->isogen = $is;
		// $this->nocxium = $no;
		// $this->zydrine = $zy;
		// $this->megacyte = $meg;
		// $this->morphite = $mo;
// 		
	// }
	
	
	function createICEOREoperation($ta,$ss,$tr,$py,$me,$is,$no,$zy,$meg,$mo,$he,$hy,$ni,$ox,$wa,$li,$st){
		
		$this->tax = dBc::escape($ta);
		$this->sellingsystem = dBc::escape($ss);
		$this->tritanium = dBc::escape($tr);
		$this->pyerite = dBc::escape($py);
		$this->mexallon = dBc::escape($me);
		$this->isogen = dBc::escape($is);
		$this->nocxium = dBc::escape($no);
		$this->zydrine = dBc::escape($zy);
		$this->megacyte = dBc::escape($meg);
		$this->morphite = dBc::escape($mo);
		$this->helium = dBc::escape($he);
		$this->hydrogen = dBc::escape($hy);
		$this->nitrogen = dBc::escape($ni);
		$this->oxygen = dBc::escape($ox);
		$this->heavywater = dBc::escape($wa);
		$this->liquidzone = dBc::escape($li);
		$this->strontium = dBc::escape($st);
		
		
		$db = new dBc();	
		$db->clearOldData();
		$db->runInsert("INSERT INTO `operation` ( `tax`, `sellingsystem`) VALUES ('".$this->tax."', '".$this->sellingsystem."');");
		
		$pid = $db->getSingleResult("SELECT max(idoperation) FROM `operation`"); 
		
		$db->runInsert("INSERT INTO `prices` (`idprices`, `idoperation`, `idmineral`, `price`) VALUES 
						(NULL, '$pid', '1', '$this->tritanium'),
						(NULL, '$pid', '2', '$this->pyerite'),
						(NULL, '$pid', '3', '$this->mexallon'),
						(NULL, '$pid', '4', '$this->isogen'),
						(NULL, '$pid', '5', '$this->nocxium'),
						(NULL, '$pid', '6', '$this->zydrine'),
						(NULL, '$pid', '7', '$this->megacyte'),
						(NULL, '$pid', '8', '$this->morphite'),
						(NULL, '$pid', '9', '$this->helium'),
						(NULL, '$pid', '10', '$this->hydrogen'),
						(NULL, '$pid', '11', '$this->nitrogen'),
						(NULL, '$pid', '12', '$this->oxygen'),
						(NULL, '$pid', '13', '$this->heavywater'),
						(NULL, '$pid', '14', '$this->liquidzone'),
						(NULL, '$pid', '15', '$this->strontium');");
		
	}	
	
	function __construct(){
				
			if(isset($_GET['tax']))$ta = $_GET['tax'];
			if(isset($_GET['sellingsystem']))$ss = $_GET['sellingsystem'];
			if(isset($_GET['Tritanium']))$tr = $_GET['Tritanium'];
			if(isset($_GET['Pyerite']))$py = $_GET['Pyerite']; 
			if(isset($_GET['Mexallon']))$me = $_GET['Mexallon'];
			if(isset($_GET['Isogen']))$is = $_GET['Isogen'];
			if(isset($_GET['Nocxium']))$no = $_GET['Nocxium'];
			if(isset($_GET['Zydrine']))$zy = $_GET['Zydrine']; 
			if(isset($_GET['Megacyte']))$meg = $_GET['Megacyte'];
			if(isset($_GET['Morphite']))$mo = $_GET['Morphite'];
			if(isset($_GET['Helium']))$he = $_GET['Helium']; 
			if(isset($_GET['Hydrogen']))$hy = $_GET['Hydrogen'];
			if(isset($_GET['Nitrogen']))$ni = $_GET['Nitrogen'];
			if(isset($_GET['Oxygen']))$ox = $_GET['Oxygen'];
			if(isset($_GET['Heavy']))$wa = $_GET['Heavy'];
			if(isset($_GET['Liquid']))$li = $_GET['Liquid'];
			if(isset($_GET['Strontium']))$st = $_GET['Strontium'];
						
			$this->createICEOREoperation($ta, $ss, $tr, $py, $me, $is, $no, $zy, $meg, $mo, $he, $hy, $ni, $ox, $wa, $li, $st);
		
	}
}

?>