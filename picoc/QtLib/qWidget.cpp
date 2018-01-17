
// ******************************
//
// qWidget Lib
//
// qtc , Claudio Daffra 
// daffra.claudio@gmail.com
//
// ******************************


#include "../../main.h"
#include "qWidget.h"

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



// ********** 
// extern
// ********** 

extern 	int qfEventLoop ; // qWidgetConst.c
 
// ********** 
// Global
// ********** 

//
// qEventType , qWidgetType , sender
//

std::vector<int> qVectorEventType ;  
std::vector<int> qVectorWidgetType ;  
std::vector<void*> qVectorSender ;  

//
// Creiamo la finestra principale ,
// gestiamo ESC key, nel loop eventi
// 

// ********** 
// class
// ********** 

class MainWindow : public QMainWindow 
{
	public:
		MainWindow(QWidget *parent = 0) : QMainWindow(parent) 
		{

		}
	public:
/*
        void keyPressEvent(QKeyEvent *ke)
		{
			 printf ( "\n OUT MAIN %d",qfEventLoop);
			 if (ke->key() == Qt::Key_Escape)
			 {
				qfEventLoop=0;
				printf ( "\n IN MAIN %d",qfEventLoop);	
				QApplication::exit();
				QApplication::quit();				
			 }			
		}
*/
	    int fClick=0;
		void closeEvent (QCloseEvent *event);

    public:		
		void mousePressEvent(QMouseEvent *event);	
};


void MainWindow::closeEvent (QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "Exit ?",
                                                                tr("Are you sure?\n"),
                                                                QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
                                                                QMessageBox::Yes);
    if (resBtn != QMessageBox::Yes) 
	{
		qfEventLoop=1;		
        event->ignore();
    } 
	else 
	{
		qfEventLoop=0;
        event->accept();
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
	// se abbiamo ricevuto l'ok dall'utente allora possiamo gesireil click sulla finestra.
	if ( fClick )
	{
		if(event->button()==Qt::LeftButton)
		{
			qVectorEventType.push_back  ( _qClick ) ;
			qVectorWidgetType.push_back ( _qWindow ) ;
			qVectorSender.push_back ( (void*) this ) ;	
		}
	}
}

/**/

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
			 printf ( "\n WidgetEsc out %d",qfEventLoop);
			 if (ke->key() == Qt::Key_Escape)
			 {
				qfEventLoop=0;
				printf ( "\n WidgetEsc in  %d",qfEventLoop);
				
				QApplication::closeAllWindows();				
				QApplication::exit();
				QApplication::quit();
				
			 }
		}
};

// ********** 
// Function
// ********** 

// ...................................................................................................................... NEW

void qWindowNew(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	MainWindow *p = new MainWindow() ;
	
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



void qWidgetEventClick(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	int 	qWidgetType 	= (int) Param[0]->Val->Integer  ;

	// non c'è un vero segnale di click per la finestra principale, tuttavia possiamo simularlo con un override del button press
	// e quando si verifica nella MainWindow, salverà sui vettori di controllo le informazioni della finestra che ha generato l'evento click
	
	// ............................................................................. qWindow 
	if ( ( qWidgetType == _qWindow )  )
	{
		MainWindow *sender	= (MainWindow*) Param[1]->Val->Pointer  ;
		// attiva l'evento nella finestra principale
		(*sender).fClick=1;
	}
	// ............................................................................. qPushButton	
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
	// ............................................................................. qLabel 
 	if ( qWidgetType == _qLabel ) 
	{
		printf ( "\n?! info : qLabel Click , not implemeted yet.\n" );
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
			// ............................................................................. Push Button
			if ( qWidgetType == _qPushButton ) 
			{
				if ( (void*) Param[2]->Val->Pointer == (void*) qVectorSender[i] )
				{
					ReturnValue->Val->Integer =  1 ;
					fRemove=i;
					break ;
				}
			}
			// ............................................................................. Window
			if ( qWidgetType == _qWindow ) 
			{
				if ( (void*) Param[2]->Val->Pointer == (void*) qVectorSender[i] )
				{
					ReturnValue->Val->Integer =  1 ;
					fRemove=i;
					break ;
				}
			}	
			// ............................................................................. qLabel 
			if ( qWidgetType == _qLabel ) 
			{
				printf ( "\n?! info : qLabel Check Click , not implemeted yet.\n" );
			}			
			
		}
	}
	// .................................................................................... rimuovi il segnale
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
}
void qEventLoop(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{ 
	QCoreApplication::processEvents();
	ReturnValue->Val->Integer =  qfEventLoop  ;
}

void qQuit(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{ 
 QApplication::exit();
 QApplication::quit();

}

//int _qWindowTitleHint				= Qt::WindowTitleHint ;
//int _qWindowMaximizeButtonHint	= Qt::WindowMaximizeButtonHint ;
//int _qWindowMinimizeButtonHint	= Qt::WindowMinimizeButtonHint ; 

void qWindowSetFlags(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	MainWindow 	 	*sender 	= (MainWindow*) Param[0]->Val->Pointer  ;		
	int 	flags 		= (int) Param[1]->Val->Integer  ;	
	
	(*sender).setWindowFlags( Qt::CustomizeWindowHint );

}	
 
// ******
// HEADER
// ******

	struct LibraryFunction qWidget[] =
	{
		
		// .............................................................. FLAG	
		
		{ qWindowSetFlags		,   "void  qWindowSetFlags	( void*, int );" },
		{ qWindowSetFlags		,   "void  qWindowSetFlag	( void*, int );" },
		
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
		
 		{ qAsync			,   "int    qAsync		( void  );" }, 
        { qEventLoop		,   "int    qEventLoop	( void  );" },
 		{ qQuit				,   "void   qQuit		( void  );" }, 		
 
		
		
		/**/
		
		{ NULL,             NULL }
	};


/**/



