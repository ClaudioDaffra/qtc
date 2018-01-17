#include <QtCore/QCoreApplication>
#include <string>
#include <QApplication>
#include <QtWidgets>



extern "C"
{
    int picoc_main(int argc, char **argv) ;
 
}

int main(int argc, char *argv[])
{
	// fix, app.exec necessita che il widget venga chiuso, 
	//		altrimenti non è in grado di determinare quando uscire
	//      occorre forzarlo in questo modo, attraverso un qMetaObject()
	 
	QApplication app(argc, argv);
	
 	QWidget* x = new QWidget(nullptr);// nogui ok
    picoc_main ( argc, argv );
	QMetaObject::invokeMethod( x, "close", Qt::QueuedConnection); // nogui ok
 
    app.exec();  
	
	return 0 ;
}
