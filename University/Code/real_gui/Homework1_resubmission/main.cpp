// Assignment I1: Due June 18
// Written by: Cole Hurst (cbh65)
// GUI Summer session 1, Dr. Dan Tamir
// main.cpp


#include <QApplication>
#include "mainWindow.h"
#include "mainWindow.cpp"


int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    // main and menu window
    mainWindow window;

    window.resize(700, 400);
    window.setWindowTitle("Boat Sim");
    window.show();

    return app.exec();
}
