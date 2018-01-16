
// ******************************
//
// qString Lib
//
// qtc , Claudio Daffra 
// daffra.claudio@gmail.com
//
// ******************************


#include "../../main.h"
#include <string.h>
#include <string>
#include <iostream>
#include <QString>
#include "../interpreter.h"

// ********** 
// functions
// ********** 
 
void qstrNew(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    QString *pstr = new QString();
    ReturnValue->Val->Pointer =  (void*) pstr ;
}

void qcharNew(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	QChar *pchar = new QChar();
	ReturnValue->Val->Pointer =  (void*) pchar ;
}

void qstrDebug(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    QString *pstr = (QString*) Param[0]->Val->Pointer  ;
	
	std::cout << pstr->toStdString() << " [ " << pstr->size() << " / " << pstr->capacity() <<" ] ";
	
    ReturnValue->Val->Pointer = NULL;
}

void qstrFromStringc(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	QString *pstr = new QString ( (char*) Param[0]->Val->Pointer ) ;
	
    ReturnValue->Val->Pointer =  pstr ;	
}

void qstrToStringc(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	QString *qstr = (QString*) Param[0]->Val->Pointer  ;

	std::string cppstring = qstr->toStdString() ;

	const char *c_str = cppstring.c_str();

	ReturnValue->Val->Pointer =  strdup( (char*)c_str ) ;
}

void qstrFromInteger(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	QString qstr;
	qstr.setNum( Param[0]->Val->Integer );

	QString *pstr = new  QString();
	*pstr = qstr ;
	
    ReturnValue->Val->Pointer =  pstr ;	
}
void qstrToInteger(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    QString *s1 = (QString*) Param[0]->Val->Pointer  ;
	bool ok ;
    QString x = *s1 ;	
	long ret = (long) x.toLong(&ok) ;
    ReturnValue->Val->Integer = ret ;
}

void qstrFromReal(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	QString qstr;
	qstr.setNum( Param[0]->Val->FP );

	QString *pstr = new  QString();
	*pstr = qstr ;
	
    ReturnValue->Val->Pointer =  pstr ;	
}
void qstrToReal(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    QString *s1 = (QString*) Param[0]->Val->Pointer  ;
	bool ok ;
    QString x = *s1 ;	
	double ret = (double) x.toDouble(&ok) ;
    ReturnValue->Val->FP = ret ;
}

void qcharToInteger(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    QChar *s1 = (QChar*) Param[0]->Val->Pointer  ;
    QChar qc = *s1 ;
 
	char c = qc.toLatin1() ;
	
    ReturnValue->Val->Integer = c ;
	
}

void qcharFromInteger(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    long num =  Param[0]->Val->Integer  ;
	
	QString temp1 = QString( (char) num) ;
    QChar temp2 = temp1[0] ;
	QChar *qc = new QChar(temp2);
	
    ReturnValue->Val->Pointer = qc ;
}

void qcharFromString(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    QString *s1 = (QString*) Param[0]->Val->Pointer  ;
	int pos = (int) Param[1]->Val->Integer ; 
	
	QString temp = *s1 ;
	
    QChar *qc = new QChar();
	
	*qc = temp.at( pos ) ;
	
    ReturnValue->Val->Pointer = qc ;
}

void qcharToString(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    QString *s1 = (QString*) Param[0]->Val->Pointer  ;
	QChar *qc = (QChar*) Param[1]->Val->Pointer; 	
	int pos = (int) Param[2]->Val->Integer ; 
	
	QString temp = *s1 ;
	temp[pos]= *qc;
	*s1=temp;
	
    ReturnValue->Val->Pointer = NULL ; ;
	
}

void qstrCheck(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    QString 	*s1 = (QString*)    Param[0]->Val->Pointer  ;
    char        *op = (char*)       Param[1]->Val->Pointer  ;
    QString 	*s2 = (QString*)    Param[2]->Val->Pointer  ;
	
    int Result = -1 ;
	
    if ( strcmp ( op , "==" )==0 ) 
	{
		Result = (*s1==*s2) ? 1 : 0 ;
	}
    else
	{
		if ( strcmp ( op , "!=" )==0 ) 
		{
			Result = (*s1!=*s2) ? 1 : 0 ;
		}
		else
		{
			if ( strcmp ( op , "<" )==0 )  
			{
				Result = (*s1<*s2) ? 1 : 0 ;
			}
			else
			{
				if ( strcmp ( op , ">" )==0 )  
				{
					Result = (*s1>*s2) ? 1 : 0 ;
				}
				else
				{
					if ( strcmp ( op , "<=" )==0 )  
					{
						Result = (*s1<=*s2) ? 1 : 0 ;
					}
					else
					{
						if ( strcmp ( op , ">=" )==0 )  
						{	
							Result = (*s1>=*s2) ? 1 : 0 ;
						}
					}
				}
			}
		}
	}
	
    ReturnValue->Val->Integer = Result ;
 
}

void qcharCheck(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	Param[0]->Val->Pointer  = (void*) new QString ( (QChar*)    Param[0]->Val->Pointer )  ;
    Param[2]->Val->Pointer  = (void*) new QString ( (QChar*)    Param[2]->Val->Pointer ) ; 
	
    qstrCheck (  Parser,ReturnValue,Param,NumArgs ) ;
}

void qstrContains(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    QString *s1 = (QString*) Param[0]->Val->Pointer  ;
    QString *s2 = (QString*) Param[1]->Val->Pointer  ; 
	
	QString temp = *s1 ;
	
	long ret = temp.contains ( *s2 ) ;
	
    ReturnValue->Val->Integer = ret;
}

void qstrEndsWith(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    QString *s1 = (QString*) Param[0]->Val->Pointer  ;
    QString *s2 = (QString*) Param[1]->Val->Pointer  ; 
	
	QString temp = *s1 ;
	
    long ret = temp.endsWith ( *s2 ) ;
	
    ReturnValue->Val->Integer = ret;
}

void qstrStartsWith(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    QString *s1 = (QString*) Param[0]->Val->Pointer  ;
    QString *s2 = (QString*) Param[1]->Val->Pointer  ; 
	
	QString temp = *s1 ;
	
    long ret = temp.startsWith ( *s2 ) ;
	
    ReturnValue->Val->Integer = ret;
}

void qstrIndexOf(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    QString *s1 = (QString*) Param[0]->Val->Pointer  ;
    QString *s2 = (QString*) Param[1]->Val->Pointer  ; 
	
	QString temp = *s1 ;
	
    long ret = temp.indexOf ( *s2 ) ;
	
    ReturnValue->Val->Integer = ret;
}

void qstrLastIndexOf(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    QString *s1 = (QString*) Param[0]->Val->Pointer  ;
    QString *s2 = (QString*) Param[1]->Val->Pointer  ; 
	
	QString temp = *s1 ;
	
    long ret = temp.lastIndexOf ( *s2 ) ;
	
    ReturnValue->Val->Integer = ret;
}

void qstrCopy(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    QString *s1 = (QString*) Param[0]->Val->Pointer  ;
    QString *s2 = (QString*) Param[1]->Val->Pointer  ; 
	
	*s1 = *s2 ;
	
    ReturnValue->Val->Pointer = NULL;
}

void qstrAppend(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    QString *s1 = (QString*) Param[0]->Val->Pointer  ;
    QString *s2 = (QString*) Param[1]->Val->Pointer  ; 
	
	*s1 += *s2 ;
	
    ReturnValue->Val->Pointer = NULL;
}

void qstrReplace(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    QString *s1 = (QString*) Param[0]->Val->Pointer  ;
    QString *s2 = (QString*) Param[1]->Val->Pointer  ; 
    QString *s3 = (QString*) Param[2]->Val->Pointer  ; 
	
	QString temp = *s1 ;
	
	temp.replace ( *s2 , *s3 ) ;
	*s1 = temp ;
	
    ReturnValue->Val->Pointer = NULL;
}

void qstrToLower(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    QString *s1 = (QString*) Param[0]->Val->Pointer  ;
  	QString temp = *s1 ;
	
	*s1 = temp.toLower () ;
	
    ReturnValue->Val->Pointer = s1;
}

void qstrToUpper(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    QString *s1 = (QString*) Param[0]->Val->Pointer  ;
  	QString temp = *s1 ;
	
	*s1 = temp.toUpper () ;
	
    ReturnValue->Val->Pointer = s1;
} 

void qstrInsert(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    QString *s1 = (QString*) Param[0]->Val->Pointer  ;
    QString *s2 = (QString*) Param[1]->Val->Pointer  ; 
    long pos = (long) Param[2]->Val->Integer  ; 
	
	QString temp = *s1 ;
	*s1 = temp.insert ( pos , *s2 ) ;
	
    ReturnValue->Val->Pointer = s1;
}

void qstrLength(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    QString *s1 = (QString*) Param[0]->Val->Pointer  ;
	
	QString temp = *s1 ;
	
	long ret = temp.length () ;
	
    ReturnValue->Val->Integer = ret;
}

void qstrLeft(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    QString *s1 = (QString*) Param[0]->Val->Pointer  ;
	int pos = (int) Param[1]->Val->Integer ; 
	
	QString temp = *s1 ;
	
    QString *ret = new QString() ;
	*ret= temp.left ( pos ) ;
	
    ReturnValue->Val->Pointer = ret ;
}

void qstrRight(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    QString *s1 = (QString*) Param[0]->Val->Pointer  ;
	int pos = (int) Param[1]->Val->Integer ; 
	
	QString temp = *s1 ;
	
    QString *ret = new QString() ;
	*ret= temp.right ( pos ) ;
	
    ReturnValue->Val->Pointer = ret ;
}

void qstrMid(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    QString *s1 = (QString*) Param[0]->Val->Pointer  ;
	int start = (int) Param[1]->Val->Integer ; 
	int length = (int) Param[2]->Val->Integer ; 
	
	QString temp = *s1 ;
	
    QString *ret = new QString() ;
	*ret= temp.mid ( start,length ) ;
	
    ReturnValue->Val->Pointer = ret ;
}

void qstrCount(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    QString *s1 = (QString*) Param[0]->Val->Pointer  ;
    QString *s2 = (QString*) Param[1]->Val->Pointer  ;
	
	QString temp = *s1 ;
	long ret= temp.count ( *s2 ) ;
	
    ReturnValue->Val->Integer = ret ;
}


// ******
// HEADER
// ******

extern "C"
{
	struct LibraryFunction qString[] =
	{
		// .............................................................. NEW	
		
		{ qstrNew			,   "void* qstrNew			( void );" },
		{ qcharNew			,   "void* qcharNew			( void );" },
		
		{ qstrDebug			,   "void  qstrDebug		( void* );" },	
		
		// .............................................................. CONVERT STRING FROM TO
		
		{ qstrFromStringc   ,   "void*  qstrFromStringc	( char * );" },
		{ qstrFromStringc	,   "void*  qstr            ( char * );" },		
		{ qstrToStringc		,   "char*  qstrToStringc	( void * );" },

		{ qstrFromInteger 	,   "void*  qstrFromInteger	( long   );" },
		{ qstrToInteger 	,   "long   qstrToInteger	( void*  );" },	
		
		{ qstrFromReal   	,   "void*  qstrFromReal	( double );" },
		{ qstrToReal   		,   "double qstrToReal		( void*  );" },	
		
		{ qcharFromString  	,   "void* qcharFromString	( void *, int  );" },
		{ qcharFromString  	,   "void* qstrAt			( void *, int  );" },		
		{ qcharToString		,   "void  qcharToString	( void *, void* , int );" },

		{ qcharFromInteger	,   "void* qcharFromInteger	( long   );" },
		{ qcharToInteger	,   "long  qcharToInteger	( void*  );" },
	
		// .............................................................. TEST	
		
		{ qstrCheck			,   "int   qstrCheck		( void* , char* , void* );" },
		{ qcharCheck		,   "int   qcharCheck		( void* , char* , void* );" },		
		{ qstrContains		,   "long  qstrContains		( void* , void* );" },	
		
		{ qstrEndsWith		,   "long  qstrEndsWith		( void* , void* );" },	
		{ qstrStartsWith	,   "long  qstrStartsWith	( void* , void* );" },	
		{ qstrEndsWith		,   "long  qstrEndWith		( void* , void* );" },	
		{ qstrStartsWith	,   "long  qstrStartWith	( void* , void* );" },	

		{ qstrIndexOf		,   "long  qstrIndexOf		( void* , void* );" },	
		{ qstrLastIndexOf	,   "long  qstrLastIndexOf	( void* , void* );" },	
		
		// .............................................................. MANIPULATION	
		
		{ qstrCopy			,   "void  qstrCopy			( void* , void* );" },
		{ qstrAppend		,   "void  qstrAppend		( void* , void* );" },
		{ qstrReplace		,   "void  qstrReplace		( void* , void*, void* );" },
		{ qstrToLower		,   "void* qstrToLower		( void* );" },		
		{ qstrToUpper		,   "void* qstrToUpper		( void* );" },	
		{ qstrInsert		,   "void* qstrInsert		( void* , void*, long );" },	
		
		// .............................................................. INFO / GET
				
		{ qstrLength		,   "long  qstrLength		( void*  );" },
		{ qstrLength		,   "long  qstrSize			( void*  );" },		
		{ qstrLength		,   "long  qstrLen			( void*  );" },		
		
		{ qstrLeft  		,   "void* qstrLeft			( void *, int  );" },
		{ qstrRight  		,   "void* qstrRight		( void *, int  );" },
		{ qstrMid 			,   "void* qstrMid			( void *, int , int );" },		

		{ qstrCount			,   "long  qstrCount		( void* , void* );" },
		
		{ NULL,             NULL }
	};

}

/**/



