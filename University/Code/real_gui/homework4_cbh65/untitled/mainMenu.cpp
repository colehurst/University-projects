// Assignment I3: Due June 25
// Written by: Cole Hurst (cbh65)
// GUI Summer session 1, Dr. Dan Tamir
// mainMenu.h


#include "mainMenu.h"
#include <QWidget>
#include <QApplication>
#include <QSlider>
#include <QSpinBox>
#include <QDial>
#include <QLCDNumber>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QRadioButton>
#include <QLabel>
#include <QPushButton>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QMainWindow>
#include <QStatusBar>
#include <QAction>
#include <QTextEdit>
#include <QWidget>
#include <QHeaderView>
#include <QToolBar>
#include <QCoreApplication>
#include <QKeySequence>
#include <QtGui>
#include <QObject>
#include <QComboBox>
#include <QMessageBox>
#include <QMouseEvent>
#include <QApplication>
#include <QKeyEvent>

#include <QCoreApplication>
#include <cstdlib>
int counter = 0;

mainMenu::mainMenu(QWidget *parent)
: QMainWindow(parent) {


    // declaring widgets

    //QLabel *currentNumberOfClicksa = new QLabel("Current Number of Clicks: ");
//    QLCDNumber *numberOfClicksDisplay = new QLCDNumber;
//    QObject::connect(numberOfClicksDisplay, SIGNAL(counter()), this, SLOT(keyPressEvent(0)));
//    QLabel *currentNumberOfClicks = new QLabel("Current Number of Clicks: ");
//    numberOfClicksDisplay = new QLabel;
//    numberOfClicksDisplay->setSegmentStyle(QLCDNumber::Filled);
//    QObject::connect(numberOfClicksDisplay, SIGNAL(clicked()), this, SLOT(keyPressEvent(0)));


}

// This function allows you to increment the number in the LCD by 1 after each key press.
void mainMenu::keyPressEvent(QKeyEvent *event) {
        if (event->key())
            counter++;


}









