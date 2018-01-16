
#include <stdio.h>
#include <qString.h>

int main() 
{
	// ........................................ Create two new Strings
	qString* s1 = qstrNew() ;
	qString* s2 = qstrNew() ; 

	s1 = qstr ( "Hello World! World!" ) ;

	// ........................................ qstrCount
	printf ( "\nWorld repeated  %d times\n" , qstrCount ( s1 , qstr("World!") ) );

	//......................................... ends starts With
	printf ( "\n starts with %d , ends with %d \n" , qstrStartsWith ( s1 , qstr("Hello") ) , qstrStartsWith ( s1 , qstr("World!") ) ) ;

	//......................................... ends starts With
	printf ( "\n index of World %d Last index of %d  \n" , qstrIndexOf( s1 , qstr("World") ) , qstrLastIndexOf( s1 , qstr("World") ) );

	// ........................................ qstrReplace and shortcut
	qstrReplace ( s1 , qstr("World") , qstr("People") );

	qstrDebug ( s1 ) ;

	// ........................................ check if stirng contains and puts Length 
	printf ( "\n s1 conatins World ? <%d> length :: <%d> " , qstrContains (s1 , qstr("World")) , qstrLength ( s1 ) ) ;

	qChar* qc = qstrAt ( s1 , 1 ) ; // shortcut  qcharFromString ( s1 , 1 ) ;
	qChar* qc2 = qstrAt ( s1 , 2 ) ; // shortcut  qcharFromString ( s1 , 2 ) ;
	
	// ........................................ Check string with Compare Operators
	int result = -1; 

	printf ( "\n<%d> == \n",qcharCheck ( qc , "==" , qc2 ) ) ;
	printf ( "<%d> != \n",qcharCheck ( qc , "!=" , qc2 ) ) ;
	printf ( "<%d> <= \n",qcharCheck ( qc , "<=" , qc2 ) ) ; 
	printf ( "<%d> >= \n",qcharCheck ( qc , ">=" , qc2 ) ) ; 
	printf ( "<%d> <  \n",qcharCheck ( qc , "<"  , qc2 ) ) ; 
	printf ( "<%d> >  \n",qcharCheck ( qc , ">"  , qc2 ) ) ; 	
	
	//......................................... qstr Left Right Mid
	
	qstrDebug ( qstrLeft(s1,3) ) ;  // first 3 char
	qstrDebug ( qstrRight(s1,3) ) ; // last 3 char
	qstrDebug ( qstrMid(s1,3,3) ) ;	// start,length
	
	//......................................... to lower , to UPPER

	char* cstr = NULL ;
	
	cstr = qstrToStringc( qstrToLower(s1) ) ;
	printf ("\n<<%s>>\n",cstr) ;
	
	cstr = qstrToStringc( qstrToUpper(s1) ) ;
	printf ("\n<<%s>>\n",cstr) ; 

	//......................................... insert
	
	qstrDebug ( qstrInsert ( s1 , qstr("_CIAO_") , 5 ) ) ;

	
 return 0;
}

/**/











