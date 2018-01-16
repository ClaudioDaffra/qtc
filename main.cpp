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
    QApplication app(argc, argv);

    picoc_main ( argc, argv );

    return app.exec();
}
