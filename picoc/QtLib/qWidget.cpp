
// ******************************
//
// qWidget Lib
//
// qtc , Claudio Daffra 
// daffra.claudio@gmail.com
//
// ******************************


#include "../../main.h"

#include <QApplication>
#include <QtWidgets>
#include "../interpreter.h"



// ********** 
// functions
// ********** 
 
void qwWidgetNew(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    QWidget *p  = new QWidget();
    ReturnValue->Val->Pointer =  (void*) p  ;
}

void qwPushButtonNew(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	QWidget *w0 = (QWidget*) Param[0]->Val->Pointer  ;	
    QPushButton *p  = new QPushButton( w0 );
    ReturnValue->Val->Pointer =  (void*) p  ;
}

void qwLabelNew(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    QWidget *w0 = (QWidget*) Param[0]->Val->Pointer  ;
    QLabel *p  = new QLabel( w0 );
    ReturnValue->Val->Pointer =  (void*) p  ;
}


void qwShow(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	QWidget *w0 = (QWidget*) Param[0]->Val->Pointer  ;

	(*w0).show() ;

	ReturnValue->Val->Pointer =  NULL  ;
}
void qwWindowSetTitle(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	QWidget *w0 = (QWidget*) Param[0]->Val->Pointer  ;
    QString *pstr = (QString*) Param[1]->Val->Pointer  ;

	(*w0).setWindowTitle( *pstr );

	ReturnValue->Val->Pointer =  NULL  ;
}
void qwResize(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	QWidget *w0 = (QWidget*) Param[0]->Val->Pointer  ;	
	int width  = (int) Param[1]->Val->Integer  ;
	int height  = (int) Param[2]->Val->Integer  ;

	(*w0).resize( width , height );

	ReturnValue->Val->Pointer =  NULL  ;
}

void qwMove(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	QWidget *w0 = (QWidget*) Param[0]->Val->Pointer  ;	
	int x  = (int) Param[1]->Val->Integer  ;
	int y  = (int) Param[2]->Val->Integer  ;

    (*w0).move( x , y );

	ReturnValue->Val->Pointer =  NULL  ;
}

void qwPushButtonSetText(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	QPushButton *w0 = (QPushButton*) Param[0]->Val->Pointer  ;	
    QString *pstr = (QString*) Param[1]->Val->Pointer  ;

	(*w0).setText( *pstr );

	ReturnValue->Val->Pointer =  NULL  ;
}

void qwPushButtonResize(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	QPushButton *w0 = (QPushButton*) Param[0]->Val->Pointer  ;	
	int width  = (int) Param[1]->Val->Integer  ;
	int height  = (int) Param[2]->Val->Integer  ;

	(*w0).resize( width , height );

	ReturnValue->Val->Pointer =  NULL  ;
}


void qwLabelSetText(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	QLabel *w0 = (QLabel*) Param[0]->Val->Pointer  ;	
    QString *pstr = (QString*) Param[1]->Val->Pointer  ;

	(*w0).setText( *pstr );

	ReturnValue->Val->Pointer =  NULL  ;
}

void qwLabelResize(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	QLabel *w0 = (QLabel*) Param[0]->Val->Pointer  ;	
	int width  = (int) Param[1]->Val->Integer  ;
	int height  = (int) Param[2]->Val->Integer  ;

	(*w0).resize( width , height );

	ReturnValue->Val->Pointer =  NULL  ;
}

/**/

void qWidgetNew(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	int 	qParentType 	= (int) Param[0]->Val->Integer  ;
	QWidget 	 *p 		= (QWidget*) Param[1]->Val->Pointer  ;	 
	int 	qChildType 		= (int) Param[2]->Val->Integer  ;
 

	if ( qParentType == _qWindow ) 		
	{
			QWidget 	 *p = (QWidget*) Param[1]->Val->Pointer  ;	
	}
 	if ( qParentType == _qPushButton ) 		
	{
			QPushButton 	 *p = (QPushButton*) Param[1]->Val->Pointer  ;	
	}
	
	// ......................................................................... new qWindow
 
	if ( ( qParentType == (int)NULL ) && ( qChildType == _qWindow ) )	
	{
		QWidget *w  = new QWidget();
		ReturnValue->Val->Pointer =  (void*) w  ;
	}
	else
	{
		QWidget *w  = new QWidget(p);
		ReturnValue->Val->Pointer =  (void*) w  ;
	}		
 
	// ......................................................................... new qPushButton
 
	if ( ( qParentType == (int)NULL ) && ( qChildType == _qPushButton ) )	
	{
		QPushButton *w  = new QPushButton();
		ReturnValue->Val->Pointer =  (void*) w  ;
	}
	else
	{
		QPushButton *w  = new QPushButton(p);
		ReturnValue->Val->Pointer =  (void*) w  ;
	}	
 
}

// ******
// HEADER
// ******

 
	struct LibraryFunction qWidget[] =
	{
		// .............................................................. NEW	
		
		{ qwWidgetNew		,   "void*  qwWidgetNew			( void );" },
		{ qwWidgetNew		,   "void*  qwWindowNew			( void );" },
		
		{ qwPushButtonNew	,   "void*  qwPushButtonNew		( void* );" },
        { qwLabelNew		,   "void*  qwLabelNew			( void* );" },
		
		// .............................................................. WIDGET
		
 		{ qwShow				,   "void*  qwShow				( void* );" },
 		{ qwResize				,   "void   qwResize			( void*,long,long );" },
 		{ qwMove				,   "void   qwMove				( void*,long,long );" },
		
 		{ qwPushButtonSetText	,   "void   qwPushButtonSetText	( void*,void* );" },
 		{ qwPushButtonResize	,   "void   qwPushButtonResize	( void*,long,long );" },

 		{ qwLabelSetText		,   "void   qwLabelSetText		( void*,void* );" },
 		{ qwLabelResize			,   "void   qwLabelResize		( void*,long,long );" },
		
		// .............................................................. SET ATTRIBUTE	
		

 		{ qwWindowSetTitle	,   "void*  qwWindowSetTitle	( void* , void* );" },
		
		/**/
		
 		{ qWidgetNew		,   "void*  qWidgetNew	( int , void* , int );" }, // DEPRECATED
		
		{ NULL,             NULL }
	};


/**/



