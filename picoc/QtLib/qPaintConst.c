
#include "../../main.h"
#include "../interpreter.h"
#include "qPaint.h"


// intern.c

static const long qPaintConst_100 		=      _qPaintConst_100	  ; 
 

// ********** 
// extern
// ********** 

void qPaintSetupFunc(Picoc *pc)
{

    VariableDefinePlatformVar(pc, NULL, "qPaintConst_100"		, &pc->IntType, (union AnyValue *)&qPaintConst_100		, FALSE);	
 
}


 