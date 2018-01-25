
#include "../../main.h"
#include "../interpreter.h"

#include "qComplex.h"

// intern.c

static const long qComplexConst_100 		=      _qComplexConst_100	  ; 
 

// ********** 
// extern
// ********** 

void qComplexSetupFunc(Picoc *pc)
{

    VariableDefinePlatformVar(pc, NULL, "qComplexConst_100"		, &pc->IntType, (union AnyValue *)&qComplexConst_100		, FALSE);	
 
}


 