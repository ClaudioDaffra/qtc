
#include "../../main.h"
#include "qWidget.h"
#include "../interpreter.h"



// qWidget.cpp
// qWidgetConst.c

static const int qWidget 		=        _qWidget ; 
static const int qWindow 		=        _qWindow ;   
static const int qPushButton 	=        _qPushButton ;    
static const int qLabel 		=        _qLabel ;  

static const int qClick  		=        _qClick ;   

int qfEventLoop=1;
 
// need only here

// ********** 
// extern
// ********** 

void qWdigetSetupFunc(Picoc *pc)
{
    VariableDefinePlatformVar(pc, NULL, "qWidget", &pc->IntType, (union AnyValue *)&qWidget, FALSE);	
    VariableDefinePlatformVar(pc, NULL, "qWindow", &pc->IntType, (union AnyValue *)&qWindow, FALSE);
	
    VariableDefinePlatformVar(pc, NULL, "qPushButton", &pc->IntType, (union AnyValue *)&qPushButton, FALSE);
    VariableDefinePlatformVar(pc, NULL, "qLabel", &pc->IntType, (union AnyValue *)&qLabel, FALSE);
	/**/
	VariableDefinePlatformVar(pc, NULL, "qClick", &pc->IntType, (union AnyValue *)&qClick, FALSE);
	/**/

}


 