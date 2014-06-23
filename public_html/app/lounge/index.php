<?php

?>

welcome to the lounge!

<?php

$keyId = 3453128;
$vCode = "f2rqnJBcmwAQdfli1IBrfawZXrpB7pqsEuB0lMHp0jNMqqWjdomsL4rgqA7Xkw8B";
$AccessMask = 268435455;

https://api.eveonline.com/account/Characters.xml.aspx

 require_once '/home/losteve/backend/eveapi/ale/factory.php';
 //get ALE object
 try {
     $ale = AleFactory::getEVEOnline();
     //set user credentials, third parameter $characterID is also possible;
     $ale->setKey($keyId, $vCode);

     //all errors are handled by exceptions
     //let's fetch characters first.
     $account = $ale->account->Characters();
     //you can traverse <rowset> element with attribute name="characters" as array
     foreach ($account->result->characters as $character) {
         //this is how you can get attributes of element
         $characterID = (string) $character->characterID;
         //set characterID for CharacterSheet
         $ale->setCharacterID($characterID);
         $characterSheet = $ale->char->CharacterSheet();
         //$a = new AleParserXMLElement($account);

         //print_r($characterSheet->toArray()['result']['name']);
         //print_r($characterSheet);
     }
 }
 //and finally, we should handle exceptions
 catch (Exception $e) {
     echo $e->getMessage();
 }

 try {

     $ale2 = AleFactory::getEVECentral();
     print_r($ale2);
     //set user credentials, third parameter $characterID is also possible;
     $ale->setKey($keyId, $vCode);
 
     //all errors are handled by exceptions
     //let's fetch characters first.
     $account = $ale->account->Characters();
     //you can traverse <rowset> element with attribute name="characters" as array
     foreach ($account->result->characters as $character) {
         //this is how you can get attributes of element
         $characterID = (string) $character->characterID;
         //set characterID for CharacterSheet
         $ale->setCharacterID($characterID);
         $characterSheet = $ale->char->CharacterSheet();
         //$a = new AleParserXMLElement($account);

         //print_r($characterSheet->toArray()['result']['name']);
         //print_r($characterSheet);
     }
 }
 //and finally, we should handle exceptions
 catch (Exception $e) {
     echo $e->getMessage();
 }

?>