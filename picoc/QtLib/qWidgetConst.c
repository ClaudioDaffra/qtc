
#include "../../main.h"
#include "../interpreter.h"

static const int qWidget 		=        _qWidget ; 
static const int qWindow 		=        _qWidget ;   
static const int qPushButton 	=        _qPushButton ;    

static const int qClick  		=        _qClick ;   



/* creates various system-dependent definitions */
void qWdigetSetupFunc(Picoc *pc)
{
    VariableDefinePlatformVar(pc, NULL, "qWidget", &pc->IntType, (union AnyValue *)&qWidget, FALSE);	
    VariableDefinePlatformVar(pc, NULL, "qWindow", &pc->IntType, (union AnyValue *)&qWindow, FALSE);
	
    VariableDefinePlatformVar(pc, NULL, "qPushButton", &pc->IntType, (union AnyValue *)&qPushButton, FALSE);
	/**/
	VariableDefinePlatformVar(pc, NULL, "qClick", &pc->IntType, (union AnyValue *)&qClick, FALSE);
}


 