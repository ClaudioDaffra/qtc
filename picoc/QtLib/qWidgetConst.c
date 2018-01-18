
#include "../../main.h"
#include "qWidget.h"
#include "../interpreter.h"

// qWidget.cpp

extern long _qCustomizeWindowHint		;
extern long _qWindowTitleHint			;
extern long _qWindowMaximizeButtonHint	;
extern long _qWindowMinimizeButtonHint	;
extern long _qWindowCloseButtonHint		; 


// qWidget.cpp
// qWidgetConst.c

static const int qWidget 		=        _qWidget ; 
static const int qWindow 		=        _qWindow ;   
static const int qPushButton 	=        _qPushButton ;    
static const int qLabel 		=        _qLabel ;  

static const int qClick  		=        _qClick ;   
static const int qKey	  		=        _qKey ;  

int qfEventLoop=1;
 
// need only here

// ********** 
// extern
// ********** 

void qWdigetSetupFunc(Picoc *pc)
{
	// Widgets
	
    VariableDefinePlatformVar(pc, NULL, "qWidget"		, &pc->IntType, (union AnyValue *)&qWidget		, FALSE);	
    VariableDefinePlatformVar(pc, NULL, "qWindow"		, &pc->IntType, (union AnyValue *)&qWindow		, FALSE);
    VariableDefinePlatformVar(pc, NULL, "qPushButton"	, &pc->IntType, (union AnyValue *)&qPushButton	, FALSE);
    VariableDefinePlatformVar(pc, NULL, "qLabel"		, &pc->IntType, (union AnyValue *)&qLabel		, FALSE);

	// Events
		
	VariableDefinePlatformVar(pc, NULL, "qClick"		, &pc->IntType, (union AnyValue *)&qClick, FALSE);
	VariableDefinePlatformVar(pc, NULL, "qKey"			, &pc->IntType, (union AnyValue *)&qKey, FALSE);
	
	// Flags

	VariableDefinePlatformVar(pc, NULL, "qCustomizeWindowHint"		, &pc->IntType, (union AnyValue *)&_qCustomizeWindowHint		, FALSE);	
	VariableDefinePlatformVar(pc, NULL, "qWindowTitleHint"			, &pc->IntType, (union AnyValue *)&_qWindowTitleHint			, FALSE);
	VariableDefinePlatformVar(pc, NULL, "qWindowMaximizeButtonHint"	, &pc->IntType, (union AnyValue *)&_qWindowMaximizeButtonHint	, FALSE);
	VariableDefinePlatformVar(pc, NULL, "qWindowMinimizeButtonHint"	, &pc->IntType, (union AnyValue *)&_qWindowMinimizeButtonHint	, FALSE);
	VariableDefinePlatformVar(pc, NULL, "qWindowCloseButtonHint"	, &pc->IntType, (union AnyValue *)&_qWindowCloseButtonHint		, FALSE);
	
}


 