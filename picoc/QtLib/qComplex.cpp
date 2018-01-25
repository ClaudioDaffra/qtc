
// ******************************
//
// qComplex Lib
//
// qtc , Claudio Daffra 
// daffra.claudio@gmail.com
//
// ******************************


#include "../../main.h"
#include "../interpreter.h"



// ********** 
// extern
// ********** 

 
 
// ********** 
// Global
// ********** 

 
// ********** 
// class
// ********** 

 
// ********** 
// Function
// ********** 
 

void qComplexConst_xxx(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
  printf ( "\nqPaintConst_xxx\n" );
}	
 
// ******
// HEADER
// ******
 
	struct LibraryFunction qComplex[] =
	{

		// .............................................................. KEY	
		
		{ qComplexConst_xxx			,   "long  qComplexConst_xxx		( void );" },

		/**/
		
		{ NULL,             NULL }
	};

 
/**/



