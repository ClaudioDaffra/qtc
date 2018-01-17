

#include <qWidget.h>
#include <qString.h>
#include <stdio.h>

int main() 
{

	qWidget *w0 = qWindowNew();


	qWidget *pb = qPushButtonNew( w0 ); 
	qWidget *ll = qLabelNew( w0 ); 

 
	qWidget *w1 = qWindowNew(); 
	qWindowResize( w1,320,200 ) ;
	qWindowMove( w1 ,50,50) ;
	qWindowSetFlags( w1,1 ) ; // TODO
	qWindowShow( w1 ) ;
 
	
	/**/

	qWindowSetTitle( w0,qstr("First Widget") ) ;
	qWindowResize( w0,320,200 ) ;
	qWindowMove( pb ,50,100 ) ; 


	qPushButtonSetText ( pb, qstr("EXIT") );
	qPushButtonResize  ( pb, 100,50 );
	qPushButtonMove  ( pb, 0,0 ); 

	qLabelSetText ( ll, qstr("LABEL") );
	qLabelResize  ( ll, 100,30 );
	qWindowMove( ll ,30,40 ) ; 

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

		}
		if ( qWidgetEventCheck ( qClick , qWindow , w0 ) ) 
		{ 
			printf ( "\nCLICK qWindow 0 \n" ) ;
		}
	
	}

	qQuit() ; 
	return 0;
}

/**/











