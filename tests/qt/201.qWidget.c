

#include <qWidget.h>
#include <qString.h>
#include <stdio.h>

int main() 
{
 qWidget *w0 = qWidgetNew ( NULL , NULL , qWindow ) ;
 
 qwSetWindowTitle( w0,qstr("First Widget") ) ;
 qwResize( w0,320,200 ) ;
 qwShow( w0 ) ;
 
 qWidget *pb = qWidgetNew ( qWindow , w0 , qPushButton ) ;
 
 qwPushButtonSetText ( pb, qstr("Click me!") );
 qwPushButtonResize  ( pb, 100,50 );
 qwMove( pb ,50,100 ) ;   
 qwShow( pb ) ;
 
 return 0;
}

/**/











