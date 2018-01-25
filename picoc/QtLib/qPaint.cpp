
// ******************************
//
// qPaint Lib
//
// qtc , Claudio Daffra 
// daffra.claudio@gmail.com
//
// ******************************


#include "../../main.h"
#include "../interpreter.h"

#include "qPaint.h"



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
 

void qPaintConst_xxx(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
  printf ( "\nqPaintConst_xxx\n" );
}	
 
// ******
// HEADER
// ******

	struct LibraryFunction qPaint[] =
	{

		// .............................................................. KEY	
		
		{ qPaintConst_xxx			,   "long  qPaintConst_xxx		( void );" },

		/**/
		
		{ NULL,             NULL }
	};


/**/



