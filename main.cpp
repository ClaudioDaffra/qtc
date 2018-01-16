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
	// TODO solo quando uso le interfacce non esce bene
	
    QApplication app(argc, argv);

    picoc_main ( argc, argv );

    app.exec();
	

	return 0 ;
}
