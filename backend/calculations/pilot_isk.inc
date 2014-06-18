<?php 

class PilotISK{
	
	
	static function calculateISK($pilot,$operation){						
		
		$p = dBc::escape($pilot);
		$o = dBc::escape($operation);
		
		// $query ="SELECT round(
							// sum(
								// (amount/refinmentsunits*mineralunits*price)
								// ) -	(SELECT sum(amount) from payments WHERE pilot=$p AND operation=$o),0) as pilot_isk
				// FROM `transactions` as t
				// JOIN ore_ice_conversion as c ON(oretype = c.idore)
				// JOIN prices as p ON(p.idmineral = c.idmineral)
				// WHERE t.pilot = $p AND t.operation = $o AND t.approved = 1 AND p.idoperation = $o					
				// GROUP BY(t.pilot)";
		
		
		$not_null_safe_query_with_payments = "
			SELECT  
				round( sum( (amount/refinmentsunits*mineralunits*price) ) *(1-(tax/100)) 
						+ (SELECT -sum(amount) from payments WHERE pilot=$p AND operation=$o)
						,0) as iski

			FROM `transactions` as t 
			JOIN ore_ice_conversion as c 
			    ON(oretype = c.idore) 
			JOIN prices as p 
			    ON(p.idmineral = c.idmineral) 
			JOIN operation as op
			    ON(op.idoperation = t.operation) 
			WHERE t.pilot = $p
			    AND t.operation = $o 
			    AND t.approved = 1 
			    AND p.idoperation = $o 
			GROUP BY(t.pilot)";
		
		$null_safe_no_payments = "
			SELECT  
				round( sum( (amount/refinmentsunits*mineralunits*price) ) *(1-(tax/100)) ,0) as iski

			FROM `transactions` as t 
			JOIN ore_ice_conversion as c 
			    ON(oretype = c.idore) 
			JOIN prices as p 
			    ON(p.idmineral = c.idmineral) 
			JOIN operation as op
			    ON(op.idoperation = t.operation) 
			WHERE t.pilot = $p
			    AND t.operation = $o 
			    AND t.approved = 1 
			    AND p.idoperation = $o 
			GROUP BY(t.pilot)";

		$db = new dBc();		
					
		if($db->isResultEmpty("SELECT amount FROM payments WHERE pilot=$p AND operation=$o")){
			$query = $null_safe_no_payments;
		}else{
			$query = $not_null_safe_query_with_payments;
		}
		//print_r("<pre>".$query."</pre>");
		$amount = $db->getSingleResult($query);
		//print_r($amount);
		return Pretty::amount($amount,"ISK");
	}
	

}

?>