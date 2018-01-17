
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
#include <vector>
#include "../interpreter.h"

#include <QKeyEvent>
#include <QMainWindow>
#include <QKeyEvent>
#include <QWidget>
#include <QtGui>

#include <stdio.h>

extern 	int qfEventLoop ;
 
// ********** 
// functions
// ********** 

// ....................
//
// Creiamo la finestra principale ,
// gestiamo ESC key, nel loop eventi
// 
//

class MainWindow : public QMainWindow 
{
	public:
		MainWindow(QWidget *parent = 0) : QMainWindow(parent) 
	{
		
	}
	protected:
		void keyPressEvent(QKeyEvent *ke) 
		{
		}
};

class WidgetEsc : public QWidget 
{
	public:
		WidgetEsc(QWidget *parent = 0) : QWidget(parent) 
		{
			setFocusPolicy(Qt::StrongFocus);
		}
	protected:
		void keyPressEvent(QKeyEvent *ke) 
		{
			 printf ( "\n%d",qfEventLoop);
			 if (ke->key() == Qt::Key_Escape)
			 {
				qfEventLoop=0;
			 }
			
		}
};


// ...................................................................................................................... NEW

void qWindowNew(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	QWidget *p  = new QWidget();
	(*p).setWindowFlags(Qt::SubWindow);	

	WidgetEsc *w = new WidgetEsc(p); // bind check key press ESC

	ReturnValue->Val->Pointer =  (void*) p  ;
}

void qPushButtonNew(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	QWidget *w0 = (QWidget*) Param[0]->Val->Pointer  ;	
    QPushButton *p  = new QPushButton( w0 );
    ReturnValue->Val->Pointer =  (void*) p  ;
}

void qLabelNew(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    QWidget *w0 = (QWidget*) Param[0]->Val->Pointer  ;
    QLabel *p  = new QLabel( w0 );
    ReturnValue->Val->Pointer =  (void*) p  ;
}

// ...................................................................................................................... (WIDGET) SHOW RESIZE MOVE

void qWidgetShow(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	QWidget *w0 = (QWidget*) Param[0]->Val->Pointer  ;

	(*w0).show() ;

	ReturnValue->Val->Pointer =  NULL  ;
}


void qWidgetResize(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	QWidget *w0 = (QWidget*) Param[0]->Val->Pointer  ;	
	int width  = (int) Param[1]->Val->Integer  ;
	int height  = (int) Param[2]->Val->Integer  ;

	(*w0).resize( width , height );

	ReturnValue->Val->Pointer =  NULL  ;
}

void qWidgetMove(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	QWidget *w0 = (QWidget*) Param[0]->Val->Pointer  ;	
	int x  = (int) Param[1]->Val->Integer  ;
	int y  = (int) Param[2]->Val->Integer  ;

    (*w0).move( x , y );

	ReturnValue->Val->Pointer =  NULL  ;
}

// ...................................................................................................................... Set Title


void qWindowSetTitle(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	QWidget *w0 = (QWidget*) Param[0]->Val->Pointer  ;
    QString *pstr = (QString*) Param[1]->Val->Pointer  ;

	(*w0).setWindowTitle( *pstr );

	ReturnValue->Val->Pointer =  NULL  ;
}

// ...................................................................................................................... Set Text

void qPushButtonSetText(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	QPushButton *w0 = (QPushButton*) Param[0]->Val->Pointer  ;	
    QString *pstr = (QString*) Param[1]->Val->Pointer  ;

	(*w0).setText( *pstr );

	ReturnValue->Val->Pointer =  NULL  ;
}


void qLabelSetText(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	QLabel *w0 = (QLabel*) Param[0]->Val->Pointer  ;	
    QString *pstr = (QString*) Param[1]->Val->Pointer  ;

	(*w0).setText( *pstr );

	ReturnValue->Val->Pointer =  NULL  ;
}

// ...................................................................................................................... RESIZE

void qPushButtonResize(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	QPushButton *w0 = (QPushButton*) Param[0]->Val->Pointer  ;	
	int width  = (int) Param[1]->Val->Integer  ;
	int height  = (int) Param[2]->Val->Integer  ;

	(*w0).resize( width , height );

	ReturnValue->Val->Pointer =  NULL  ;
}


void qLabelResize(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	QLabel *w0 = (QLabel*) Param[0]->Val->Pointer  ;	
	int width  = (int) Param[1]->Val->Integer  ;
	int height  = (int) Param[2]->Val->Integer  ;

	(*w0).resize( width , height );

	ReturnValue->Val->Pointer =  NULL  ;
}


// **********
// 
// EVENT
//
// **********

//
// qEventType , qWidgetType , sender
//

std::vector<int> qVectorEventType ;  
std::vector<int> qVectorWidgetType ;  
std::vector<void*> qVectorSender ;  

void qWidgetEventClick(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	int 	qWidgetType 	= (int) Param[0]->Val->Integer  ;
	
	if ( ( qWidgetType == _qWidget ) || ( qWidgetType == _qWidget ) )
	{
		/*
		QPushButton *sender	= (QPushButton*) Param[1]->Val->Pointer  ;	
		QObject::connect( sender, &QPushButton::clicked, [=] () 
		{
			qVectorEventType.push_back  ( _qClick ) ;
			qVectorWidgetType.push_back ( _qPushButton ) ;
			qVectorSender.push_back ( (void*) sender ) ;			
        } );
		*/
		printf ( "\n? Error : qWidget / qWindow has not : click event \n" );
	}
	if ( qWidgetType == _qPushButton ) 
	{
		QPushButton *sender	= (QPushButton*) Param[1]->Val->Pointer  ;	
		QObject::connect( sender, &QPushButton::clicked, [=] () 
		{
			qVectorEventType.push_back  ( _qClick ) ;
			qVectorWidgetType.push_back ( _qPushButton ) ;
			qVectorSender.push_back ( (void*) sender ) ;			
        } );
	}
 
}

void qWidgetEventCheck(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	int 	qEventType 		= (int) Param[0]->Val->Integer  ;
	int 	qWidgetType 	= (int) Param[1]->Val->Integer  ;
	QWidget 	 *sender 	= (QWidget*) Param[2]->Val->Pointer  ;		
	int fRemove=-1;

	ReturnValue->Val->Integer =  0 ;
	
	int i=0;
	for (i=0; i< qVectorEventType.size(); i++ )
	{
		if ( ( qVectorEventType[i] == qEventType ) && ( qVectorWidgetType[i] == qWidgetType )  )
		{
			// ................................................................... Push Button
			if ( qWidgetType == _qPushButton ) 
			{
				if ( (void*) Param[2]->Val->Pointer == (void*) qVectorSender[i] )
				{
					ReturnValue->Val->Integer =  1 ;
					fRemove=i;
					break ;
				}
			}
		}
	}
	if ( fRemove>=0 )
	{
		qVectorEventType.erase  (qVectorEventType.begin()+fRemove);
		qVectorWidgetType.erase (qVectorWidgetType.begin()+fRemove);
		qVectorSender.erase     (qVectorSender.begin()+fRemove);		
	}
}
// ........................................................................................................ ASYNC

void qAsync(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{ 
	QCoreApplication::processEvents();
	ReturnValue->Val->Integer =  qfEventLoop  ;
}
void qQuit(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{ 
 QApplication::exit();
 QApplication::quit();

}


// ******
// HEADER
// ******

	struct LibraryFunction qWidget[] =
	{
		// .............................................................. NEW	
		
		{ qWindowNew		,   "void*  qWindowNew			( void );" },
		{ qPushButtonNew	,   "void*  qPushButtonNew		( void* );" },
        { qLabelNew			,   "void*  qLabelNew			( void* );" },
		
		// .............................................................. SHOW 

		 { qWidgetShow				,   "void*  qWindowShow		( void* );" },
		 { qWidgetShow				,   "void*  qPushButtonShow	( void* );" },		
		 { qWidgetShow				,   "void*  qLabelShow		( void* );" },
		 
		// .............................................................. RESIZE 
		
 		{ qWidgetResize				,   "void   qWindowResize		( void*,long,long );" },
 		{ qWidgetResize				,   "void   qPushButtonResize	( void*,long,long );" },
 		{ qWidgetResize				,   "void   qLabelResize		( void*,long,long );" },	
		
		// .............................................................. MOVE
				
 		{ qWidgetMove				,   "void   qWindowMove				( void*,long,long );" },
 		{ qWidgetMove				,   "void   qPushButtonMove			( void*,long,long );" },
 		{ qWidgetMove				,   "void   qLabelMove				( void*,long,long );" },
		
		// .............................................................. SET TEXT , SET TITLE
		
 		{ qWindowSetTitle		,   "void*  qWindowSetTitle		( void* , void* );" },
 		{ qPushButtonSetText	,   "void   qPushButtonSetTitle	( void*,void* );" },
 		{ qLabelSetText			,   "void   qLabelSetTitle		( void*,void* );" },	
		
 		{ qWindowSetTitle		,   "void*  qWindowSetText		( void* , void* );" },
 		{ qPushButtonSetText	,   "void   qPushButtonSetText	( void*,void* );" },
 		{ qLabelSetText			,   "void   qLabelSetText		( void*,void* );" },	

	
		// .............................................................. SET ATTRIBUTE	
		

		// .............................................................. EVENT

 		{ qWidgetEventClick		,   "void   qWidgetEventClick	( int , void*  );" },  	
  		{ qWidgetEventCheck		,   "int    qWidgetEventCheck	( int , int , void*  );" },  		

		// .............................................................. CORE / ASYNC
		
 		{ qAsync			,   "int    qAsync	( void  );" }, 
 		{ qQuit				,   "void   qQuit	( void  );" }, 		

		
		/**/
		
		{ NULL,             NULL }
	};


/**/



