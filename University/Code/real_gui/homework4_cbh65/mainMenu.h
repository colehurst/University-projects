// Assignment I3: Due June 25
// Written by: Cole Hurst (cbh65)
// GUI Summer session 1, Dr. Dan Tamir
// mainMenu.h



#pragma once

#include <QMainWindow>
#include <QApplication>
#include <QObject>
#include <QSettings>
#include <QKeyEvent>

class QAction;
class QMenu;
class QLabel;

class mainMenu : public QMainWindow {

    Q_OBJECT

public:
   mainMenu(QWidget *parent = 0);
protected:
   void QKeyEvent;

private slots:
    void open();
    void save();
    void quit();
    void about();
    void aboutQt();

private:
    void createActions();
    void createMenus();



};



