// Assignment I3: Due June 25
// Written by: Cole Hurst (cbh65)
// GUI Summer session 1, Dr. Dan Tamir
// mainMenu.h


#include <QApplication>
#include <QtGui>
#include "mainMenu.h"
#include "mainMenu.cpp"


int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    // main and menu window
    mainMenu window;

    window.resize(1000, 350);
    window.setWindowTitle("Boat Sim");
    window.show();

    return app.exec();
}
