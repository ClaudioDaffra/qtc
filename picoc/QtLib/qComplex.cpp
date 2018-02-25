
// ******************************
//
// qcx Lib
//
// qtc , Claudio Daffra 
// daffra.claudio@gmail.com
//
// ******************************


#include "../../main.h"
#include "../interpreter.h"
#include <complex>


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
 

void qcxNew(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    std::complex<double> *p = new std::complex<double> ;

    ReturnValue->Val->Pointer =  (void*) p  ;
}	
void qcxSet(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    std::complex<double> *c      = (std::complex<double>*) Param[0]->Val->Pointer  ;
    double          real        = (double) Param[1]->Val->FP  ;
    double          imaginary   = (double) Param[2]->Val->FP  ;

    (*c) = { real,imaginary } ;

    ReturnValue->Val->Pointer = (void*) c  ;
}
void qcxRealGet(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    std::complex<double> *c      = (std::complex<double>*) Param[0]->Val->Pointer  ;

    ReturnValue->Val->FP = std::real(*c)  ;
}
void qcxImagGet(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    std::complex<double> *c      = (std::complex<double>*) Param[0]->Val->Pointer  ;

    ReturnValue->Val->FP = std::imag(*c)  ;
}

void qcxAbs(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    std::complex<double> *c      = (std::complex<double>*) Param[0]->Val->Pointer  ;
    *c=std::abs(*c);
    ReturnValue->Val->Pointer = (void*) c ;
}
void qcxACos(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    std::complex<double> *c      = (std::complex<double>*) Param[0]->Val->Pointer  ;
    *c=std::acos(*c);
    ReturnValue->Val->Pointer = (void*) c ;
}
void qcxACosh(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    std::complex<double> *c      = (std::complex<double>*) Param[0]->Val->Pointer  ;
    *c=std::acosh(*c);
    ReturnValue->Val->Pointer = (void*) c ;
}
void qcxASin(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    std::complex<double> *c      = (std::complex<double>*) Param[0]->Val->Pointer  ;
    *c=std::acos(*c);
    ReturnValue->Val->Pointer = (void*) c ;
}
void qcxASinh(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    std::complex<double> *c      = (std::complex<double>*) Param[0]->Val->Pointer  ;
    *c=std::acosh(*c);
    ReturnValue->Val->Pointer = (void*) c ;
}
void qcxATan(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    std::complex<double> *c      = (std::complex<double>*) Param[0]->Val->Pointer  ;
    *c=std::acos(*c);
    ReturnValue->Val->Pointer = (void*) c ;
}
void qcxATanh(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    std::complex<double> *c      = (std::complex<double>*) Param[0]->Val->Pointer  ;
    *c=std::acosh(*c);
    ReturnValue->Val->Pointer = (void*) c ;
}
void qcxCos(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    std::complex<double> *c      = (std::complex<double>*) Param[0]->Val->Pointer  ;
    *c=std::acos(*c);
    ReturnValue->Val->Pointer = (void*) c ;
}
void qcxCosh(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    std::complex<double> *c      = (std::complex<double>*) Param[0]->Val->Pointer  ;
    *c=std::acosh(*c);
    ReturnValue->Val->Pointer = (void*) c ;
}
void qcxSin(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    std::complex<double> *c      = (std::complex<double>*) Param[0]->Val->Pointer  ;
    *c=std::acos(*c);
    ReturnValue->Val->Pointer = (void*) c ;
}
void qcxSinh(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    std::complex<double> *c      = (std::complex<double>*) Param[0]->Val->Pointer  ;
    *c=std::acosh(*c);
    ReturnValue->Val->Pointer = (void*) c ;
}
void qcxTan(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    std::complex<double> *c      = (std::complex<double>*) Param[0]->Val->Pointer  ;
    *c=std::acos(*c);
    ReturnValue->Val->Pointer = (void*) c ;
}
void qcxTanh(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    std::complex<double> *c      = (std::complex<double>*) Param[0]->Val->Pointer  ;
    *c=std::acosh(*c);
    ReturnValue->Val->Pointer = (void*) c ;
}
void qcxArg(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    std::complex<double> *c      = (std::complex<double>*) Param[0]->Val->Pointer  ;
    *c=std::arg(*c);
    ReturnValue->Val->Pointer = (void*) c ;
}
void qcxConj(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    std::complex<double> *c      = (std::complex<double>*) Param[0]->Val->Pointer  ;
    *c=std::conj(*c);
    ReturnValue->Val->Pointer = (void*) c ;
}
void qcxProj(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    std::complex<double> *c      = (std::complex<double>*) Param[0]->Val->Pointer  ;
    *c=std::proj(*c);
    ReturnValue->Val->Pointer = (void*) c ;
}
void qcxExp(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    std::complex<double> *c      = (std::complex<double>*) Param[0]->Val->Pointer  ;
    *c=std::exp(*c);
    ReturnValue->Val->Pointer = (void*) c ;
}
void qcxSqrt(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    std::complex<double> *c      = (std::complex<double>*) Param[0]->Val->Pointer  ;
    *c=std::sqrt(*c);
    ReturnValue->Val->Pointer = (void*) c ;
}
void qcxLog(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    std::complex<double> *c      = (std::complex<double>*) Param[0]->Val->Pointer  ;
    *c=std::log(*c);
    ReturnValue->Val->Pointer = (void*) c ;
}
void qcxLog10(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    std::complex<double> *c      = (std::complex<double>*) Param[0]->Val->Pointer  ;
    *c=std::log10(*c);
    ReturnValue->Val->Pointer = (void*) c ;
}
void qcxNorm(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    std::complex<double> *c      = (std::complex<double>*) Param[0]->Val->Pointer  ;
    *c=std::norm(*c);
    ReturnValue->Val->Pointer = (void*) c ;
}
void qcxPolar(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    double rho      = Param[0]->Val->FP  ;
    double theta    = Param[1]->Val->FP  ;
    std::complex<double> *c      = new std::complex<double>    ;

    *c=std::polar(rho,theta);

    ReturnValue->Val->Pointer = (void*) c ;
}
void qcxPow(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    std::complex<double> *x      = (std::complex<double>*) Param[0]->Val->Pointer  ;
    std::complex<double> *y      = (std::complex<double>*) Param[1]->Val->Pointer  ;
    std::complex<double> *c      = new std::complex<double>    ;

    *c=std::pow(*x,*y);

    ReturnValue->Val->Pointer = (void*) c ;
}


// ******
// HEADER
// ******
 
    struct LibraryFunction qComplex[] =
	{
        // .............................................................. NEW,SET

        { qcxNew        ,   "void*  qcxNew		( void );" },
        { qcxSet        ,   "void*  qcxSet		( void*,double,double );" },
        { qcxRealGet    ,   "double qcxRealGet	( void* );" },
        { qcxImagGet    ,   "double qcxImagGet	( void* );" },

        { qcxAbs        ,   "void* qcxAbs	( void* );" },

        { qcxACos       ,   "void* qcxACos	( void* );" },
        { qcxACosh      ,   "void* qcxACosh	( void* );" },
        { qcxASin       ,   "void* qcxASin	( void* );" },
        { qcxASinh      ,   "void* qcxASinh	( void* );" },
        { qcxATan       ,   "void* qcxATan	( void* );" },
        { qcxATanh      ,   "void* qcxATanh	( void* );" },

        { qcxCos        ,   "void* qcxCos	( void* );" },
        { qcxCosh       ,   "void* qcxCosh	( void* );" },
        { qcxSin        ,   "void* qcxSin	( void* );" },
        { qcxSinh       ,   "void* qcxSinh	( void* );" },
        { qcxTan        ,   "void* qcxTan	( void* );" },
        { qcxTanh       ,   "void* qcxTanh	( void* );" },

        { qcxArg        ,   "void* qcxArg	( void* );" },
        { qcxConj       ,   "void* qcxConj	( void* );" },
        { qcxProj       ,   "void* qcxProj	( void* );" },
        { qcxExp        ,   "void* qcxExp	( void* );" },
        { qcxSqrt       ,   "void* qcxSqrt	( void* );" },

        { qcxLog        ,   "void* qcxLog	( void* );" },
        { qcxLog10      ,   "void* qcxLog10	( void* );" },
        { qcxNorm       ,   "void* qcxNorm	( void* );" },

        { qcxPolar      ,   "void* qcxPolar	( double,double );" },
        { qcxPow        ,   "void* qcxPow	( void*,void* );" },

        /**/
		
		{ NULL,             NULL }
	};

 
/**/



