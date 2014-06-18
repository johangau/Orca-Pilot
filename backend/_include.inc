<?php



/************************ 
 * TOOLS 
 ************************/

require_once '../../orcapilot/framework_0_2/tools/database.inc'; 
require_once '../../orcapilot/framework_0_2/tools/get_pretty.inc';
require_once '../../orcapilot/framework_0_2/tools/menuoptions.inc';

/************************** 
 * OBJECTS 
 **************************/

require_once '../../orcapilot/framework_0_2/objects/operation.inc';
require_once '../../orcapilot/framework_0_2/objects/ore.inc';
require_once '../../orcapilot/framework_0_2/objects/payment.inc';


require_once '../../orcapilot/framework_0_2/objects/transaction.inc';

require_once '../../orcapilot/framework_0_2/objects/user.inc';
require_once '../../orcapilot/framework_0_2/objects/pilot.inc';

/***************************
 * SECURITY 
 ***************************/
require_once '../../orcapilot/framework_0_2/security/session.inc';
 
/***************************
 * ARRAYS 
 ***************************/
require_once '../../orcapilot/framework_0_2/objects/arrays/operationsarray.inc';
require_once '../../orcapilot/framework_0_2/objects/arrays/orearray.inc';
require_once '../../orcapilot/framework_0_2/objects/arrays/pilotarray.inc';
require_once '../../orcapilot/framework_0_2/objects/arrays/transactionarray.inc';
require_once '../../orcapilot/framework_0_2/objects/arrays/paymentarray.inc';

/***************************
 * ACTIONS
 ***************************/
/** add stuff **/
require_once '../../orcapilot/framework_0_2/actions/action_add_pilot.inc';
require_once '../../orcapilot/framework_0_2/actions/action_approve_transaction.inc';

/** create stuff **/
require_once '../../orcapilot/framework_0_2/actions/action_create_newuser.inc';
require_once '../../orcapilot/framework_0_2/actions/action_create_operation.inc';
require_once '../../orcapilot/framework_0_2/actions/action_create_transaction.inc';
require_once '../../orcapilot/framework_0_2/actions/action_create_payment.inc';
/** delete stuff **/
require_once '../../orcapilot/framework_0_2/actions/action_delete_transaction.inc';
require_once '../../orcapilot/framework_0_2/actions/action_close_operation.inc';

/***************************
 * CALCULATIONS
 ***************************/
require_once '../../orcapilot/framework_0_2/calculations/pilot_isk.inc';
?>