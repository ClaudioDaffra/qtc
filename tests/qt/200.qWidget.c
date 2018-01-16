

#include <qWidget.h>
#include <qString.h>
#include <stdio.h>

int main() 
{
 
 qWidget *w0 = qwNewWidget();
 
 qWidget *pb = qwNewPushButton( w0 ); 
 
 //qWidget *ll = qwNewLabel( w0 ); 
 
 /**/
 
 qwSetWindowTitle( w0,qstr("First Widget") ) ;
 qwResize( w0,320,200 ) ;
 qwMove( pb ,50,100 ) ; 

 
 qwPushButtonSetText ( pb, qstr("Click me!") );
 qwPushButtonResize  ( pb, 100,50 );
 
/*
 qwLabelSetText ( ll, qstr("LABEL") );
 qwLabelResize  ( ll, 100,30 );
 qwMove( ll ,30,40 ) ; 
*/ 
 
 
 qwShow( pb ) ;
 //qwShow( w0 ) ;
 
  printf ( "\n%d %d\n",qPushButton,qClick );

 return 0;
}

/**/











