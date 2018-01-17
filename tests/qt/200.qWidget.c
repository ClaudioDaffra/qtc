

#include <qWidget.h>
#include <qString.h>
#include <stdio.h>

int main() 
{
 
 qWidget *w0 = qWindowNew();
 qWidget *pb = qPushButtonNew( w0 ); 
 qWidget *ll = qLabelNew( w0 ); 
 
 /**/
 
 qWindowSetTitle( w0,qstr("First Widget") ) ;
 qWindowResize( w0,320,200 ) ;
 qWindowMove( pb ,50,100 ) ; 

 
 qPushButtonSetText ( pb, qstr("Click me!") );
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


  while( qAsync() )
  {
	  if ( qWidgetEventCheck ( qClick , qPushButton , pb ) ) 
	  { 
			printf ( "\nCLICK me to Exit\n" ) ;
			break ;
	  }
	   
  }
  
 qQuit() ; 
 return 0;
}

/**/











