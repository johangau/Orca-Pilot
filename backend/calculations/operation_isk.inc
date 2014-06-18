<?php 

class OperationISK{
	
	static function calculateISK($operation){		
				
		$margin = 0.2;
		
		$query ="SELECT round(sum((amount/refinmentsunits*mineralunits*price)),0) as pilot_isk					
					FROM `transactions` as t
					JOIN ore_ice_conversion as c ON(oretype = c.idore)
					JOIN prices as p ON(p.idmineral = c.idmineral)
					WHERE t.operation = $operation AND t.approved = 1 AND p.idoperation = $operation					
					GROUP BY(t.operation)";
		
		
		$db = new dBc();
		$amount = round($db->getSingleResult($query));
		
		return Pretty::amount($amount,"ISK");
	}
	
	static function calculateISKprofit($operation){		
				
		$margin = 0.2;
		
		$query ="SELECT round(sum((amount/refinmentsunits*mineralunits*price)),0) as pilot_isk					
					FROM `transactions` as t
					JOIN ore_ice_conversion as c ON(oretype = c.idore)
					JOIN prices as p ON(p.idmineral = c.idmineral)
					WHERE t.operation = $operation AND t.approved = 1 AND p.idoperation = $operation					
					GROUP BY(t.operation)";
		
		
		$db = new dBc();
		$amount = round($db->getSingleResult($query)*0.2,0);

		return Pretty::amount($amount,"ISK"); 
	}
	

	
}


?>