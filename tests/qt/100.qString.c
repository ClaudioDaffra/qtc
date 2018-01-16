
#include <stdio.h>
#include <qString.h>

int main() 
{
	// ........................................ Create two new Strings
	qString* s1 = qstrNew() ;
	qString* s2 = qstrNew() ; 

	stringc  *str  = "World!" ;

	// ........................................ set strings 
	s1 = qstrFromStringc ( "Hello" )  ;
	s2 = qstrFromStringc ( str )  ;

	// ........................................ cout 
	qstrDebug ( s1 )  ;
	qstrDebug ( s2 )  ;

	// ........................................ Check string with Compare Operators
	int result = -1; 

	printf ( "\n<%d> == \n",qstrCheck ( s1 , "==" , s2 ) ) ;
	printf ( "<%d> != \n",qstrCheck ( s1 , "!=" , s2 ) ) ;
	printf ( "<%d> <= \n",qstrCheck ( s1 , "<=" , s2 ) ) ; 
	printf ( "<%d> >= \n",qstrCheck ( s1 , ">=" , s2 ) ) ; 
	printf ( "<%d> <  \n",qstrCheck ( s1 , "<"  , s2 ) ) ; 
	printf ( "<%d> >  \n",qstrCheck ( s1 , ">"  , s2 ) ) ; 

	// ........................................ Copy Strings 
	qstrCopy ( s1 , s2 ) ;

	qstrDebug ( s1 )  ;
	qstrDebug ( s2 )  ;

	// ........................................ Convert String to c string 
	char* cstr = NULL ;
	cstr = qstrToStringc( s1 ) ;
	printf ("\n<<%s>>\n",cstr) ;

	// ........................................ qstrFromInteger , qstrFromReal 

	integer x=123;
	qString* x1 = qstrFromInteger ( x ) ;
	qString* x2 = qstrFromReal ( (float)456.768 ) ; 

	qstrDebug ( x1 )  ;
	qstrDebug ( x2 )  ;  

	// ........................................ qstrToIntefer , qstrToReal

	integer a = (integer) 	qstrToInteger( x1 ) ;
	real 	 b = (real) 	qstrToReal( x2 ) ;

	printf ( "\n <%d> <%f>\n" ,a,b);

	// ........................................ qchar

	qChar* qc ;

	qc = qcharFromString ( s1 , 1 ) ;

	qcharToString ( s1 , qc , 2 ) ;

	qstrDebug ( s1 ) ;

	char c = (char)qcharToInteger( qc ) ;
	printf ( "\n%c" , c ) ;

	qc = qcharFromInteger( (int)'x' ) ;

	c = (char)qcharToInteger( qc ) ;
	printf ( "\n%c" , c ) ; 

 return 0;
}

/**/











