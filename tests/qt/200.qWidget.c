

#include <qWidget.h>
#include <qString.h>
#include <stdio.h>

int main() 
{
	// ............................................ w0
	qWidget *w0 = qWindowNew();
	qWidget *ll = qLabelNew( w0 ); 

	qWindowSetTitle( w0,qstr("First Widget") ) ;
	qWindowResize( w0,320,200 ) ; 
	
	qLabelSetText ( ll, qstr("LABEL") );
	qLabelResize  ( ll, 100,30 );
	qWindowMove( ll ,30,40 ) ;  
	// ............................................ w1 
	qWidget *w1 = qWindowNew(); 
	qWidget *pb = qPushButtonNew( w1 ); 	

	qWindowMove( w1 ,50,50) ;
	qWindowSetFlags( w1, qWindowMaximizeButtonHint |  qWindowMinimizeButtonHint | qWindowTitleHint ) ; // 
	qWindowShow( w1 ) ;	
	
	qWindowMove( pb ,50,100 ) ; 
	qPushButtonSetText ( pb, qstr("EXIT") );
	qPushButtonResize  ( pb, 100,50 );
	qPushButtonMove  ( pb, 0,0 ); 	
	qWindowResize( w1,320,200 ) ;
	

	// set events

	qWidgetEventClick ( qPushButton , pb ) ;
	qWidgetEventClick ( qWindow	   , w0 ) ;

	// show

	qPushButtonShow( pb ) ;
	qLabelShow( ll ) ;
	qWindowShow( w0 ) ;


	while( qEventLoop() )
	{
		if ( qWidgetEventCheck ( qClick , qPushButton , pb ) ) 
		{ 
			printf ( "\nCLICK qPushButton\n" ) ;
			qWindowClose(w1);
			qEventLoopStop();
			break ;
		}
		if ( qWidgetEventCheck ( qClick , qWindow , w0 ) ) 
		{ 
			printf ( "\nCLICK qWindow 0 \n" ) ;
		}
		if ( qWidgetEventCheck ( qKey , qWindow , w0 ) ) 
		{ 
			printf ( "\nKey qWindow w0 key: %d specialKey: %d\n", qWindowGetKey(w0) ,qWindowGetSpecialKey(w0) );
		}

	}

	qQuit() ; 
	return 0;
}

/**/











