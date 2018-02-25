	#include <qComplex.h>
	#include <stdio.h>

	int main()
	{
		qPointer* c1=qcxNew() ;
		
		c1 = qcxSet ( c1 , 1.2 , 2.3 ) ;

		printf ( "\n %f %f \n",qcxRealGet(c1),qcxImagGet(c1) ) ;

		qcxAbs ( c1 ) ;
		
		qcxACos ( c1 ) ;	qcxACosh ( c1 ) ;	
		
		qcxASin ( c1 ) ;	qcxASinh ( c1 ) ;

		qcxATan ( c1 ) ;	qcxATanh ( c1 ) ;	

		qcxCos ( c1 ) ;		qcxCosh ( c1 ) ;

		qcxSin ( c1 ) ;		qcxSinh ( c1 ) ;

		qcxTan ( c1 ) ;		qcxTanh ( c1 ) ;
		
		qcxArg( c1 ) ;

		qcxConj( c1 ) ;

		qcxProj( c1 ) ;
		
		qcxExp( c1 ) ;	
		
		qcxSqrt( c1 ) ;	
		
		qcxLog ( c1 ) ;		qcxLog10 ( c1 ) ;

		c1 = qcxPolar ( 1.0 , 2.0 ) ; 	
		
		c1 = qcxPow ( c1 , c1 ) ; 
		
		printf ( "\nThe End\n");
		
		return 0 ;
	}