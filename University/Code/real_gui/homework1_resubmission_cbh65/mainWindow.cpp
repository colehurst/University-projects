// Assignment I1: Due June 18
// Written by: Cole Hurst (cbh65)
// GUI Summer session 1, Dr. Dan Tamir
// mainMenu.cpp


#include "mainWindow.h"
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

mainWindow::mainWindow(QWidget *parent)
: QMainWindow(parent) {


    // declaring widgets
    QSpinBox *spinBox = new QSpinBox;
    QSlider *slider = new QSlider(Qt::Horizontal);
    QSpinBox *maxTicsSpinBox = new QSpinBox;
    QSlider *maxTicsSlider = new QSlider(Qt::Horizontal);
    QDial *dial = new QDial;
    QLCDNumber *lcd = new QLCDNumber;
    QRadioButton *x = new QRadioButton("X");
    QRadioButton *y = new QRadioButton("Y");
    QRadioButton *z = new QRadioButton("Z");
    QLabel *gridSize = new QLabel("Grid Size (N * N)");
    QLabel *maxNumTicksLabel = new QLabel("Max. # of Tics");
    QSpinBox *boatX_X = new QSpinBox;
    QSpinBox *boatX_Y = new QSpinBox;
    QSpinBox *boatY_X = new QSpinBox;
    QSpinBox *boatY_Y = new QSpinBox;
    QSpinBox *boatZ_X = new QSpinBox;
    QSpinBox *boatZ_Y = new QSpinBox;
    QLabel *simulationDuration = new QLabel("Simulation Duration");
    simulationDuration->setBuddy(lcd);
    QLabel *x_xCoor = new QLabel("X : X-Coor");
    QLabel *x_yCoor = new QLabel("X : Y-Coor");
    QLabel *y_xCoor = new QLabel("Y : X-Coor");
    QLabel *y_yCoor = new QLabel("Y : Y-Coor");
    QLabel *z_xCoor = new QLabel("Z : X-Coor");
    QLabel *z_yCoor = new QLabel("Z : Y-Coor");
    QLabel *boatSelect = new QLabel("Boat Selection");
    QLabel *boatActionSelect = new QLabel("Boat Action Selection");
    QLabel *exitConditionSelect = new QLabel("Termination Condition");
    QComboBox *boatActionComboBox = new QComboBox;
    boatActionComboBox->addItem("Follow");
    boatActionComboBox->addItem("Chase");
    boatActionComboBox->addItem("Circle");
    QComboBox *exitConditionComboBox = new QComboBox;
    exitConditionComboBox->addItem("Boat Y is “close” to boat X, spec. in Euclidean pixels");
    exitConditionComboBox->addItem("Boat Y is close to boat Z");
    exitConditionComboBox->addItem("Boat Y is in subregion A");
    QPushButton *exitButton = new QPushButton("QUIT");


    boatSelect->setBuddy(x);


    setWindowTitle(tr("Menus"));
    setMinimumSize(160, 160);
    resize(480, 320);

    // Left side Spinboxes / Sliders
    spinBox->setRange(100, 2000);
    slider->setRange(100, 2000);
    spinBox->setValue(1000);
    gridSize->setBuddy(slider);

    QObject::connect(spinBox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
    QObject::connect(slider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));

    maxTicsSpinBox->setRange(100, 2000);
    maxTicsSlider->setRange(100, 2000);
    maxTicsSpinBox->setValue(1000);
    maxNumTicksLabel->setBuddy(maxTicsSlider);

    QObject::connect(maxTicsSpinBox, SIGNAL(valueChanged(int)), maxTicsSlider, SLOT(setValue(int)));
    QObject::connect(maxTicsSlider, SIGNAL(valueChanged(int)), maxTicsSpinBox, SLOT(setValue(int)));

    // Middle Boat Coordinate Constraints
    boatX_X->setRange(-1, 800);
    boatX_X->setValue(-1);
    boatX_Y->setRange(-1, 800);
    boatX_Y->setValue(-1);

    boatY_X->setRange(-1, 800);
    boatY_X->setValue(-1);
    boatY_Y->setRange(-1, 800);
    boatY_Y->setValue(-1);

    boatZ_X->setRange(-1, 800);
    boatZ_X->setValue(-1);
    boatZ_Y->setRange(-1, 800);
    boatZ_Y->setValue(-1);

    QObject::connect(boatX_Y, SIGNAL(valueChanged(int)), boatX_Y, SLOT(setValue(int)));

    // connecting volume dial to lcd
    dial->setRange(0, 1000);
    QObject::connect(dial, SIGNAL(valueChanged(int)), lcd , SLOT(display(int)));

    // layouts
    QVBoxLayout *farLeftLayout = new QVBoxLayout;
    farLeftLayout->addWidget(simulationDuration);
    farLeftLayout->addWidget(lcd);
    farLeftLayout -> addWidget(dial);


    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout ->addWidget(boatSelect);
    leftLayout->addWidget(x);
    leftLayout->addWidget(y);
    leftLayout->addWidget(z);
    leftLayout ->addWidget(boatActionSelect);
    leftLayout ->addWidget(boatActionComboBox);
    leftLayout->addWidget(gridSize);
    leftLayout->addWidget(spinBox);
    leftLayout->addWidget(slider);
    leftLayout->addWidget(maxNumTicksLabel);
    leftLayout->addWidget(maxTicsSpinBox);
    leftLayout->addWidget(maxTicsSlider);

    QVBoxLayout *middleLayout = new QVBoxLayout;
    middleLayout->addWidget(exitConditionSelect);
    middleLayout->addWidget(exitConditionComboBox);
    middleLayout->addWidget(exitButton);

    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(x_xCoor);
    rightLayout->addWidget(boatX_X);
    rightLayout->addWidget(x_yCoor);
    rightLayout->addWidget(boatX_Y);
    rightLayout->addWidget(y_xCoor);
    rightLayout->addWidget(boatY_X);
    rightLayout->addWidget(y_yCoor);
    rightLayout->addWidget(boatY_Y);
    rightLayout->addWidget(z_xCoor);
    rightLayout->addWidget(boatZ_X);
    rightLayout->addWidget(z_yCoor);
    rightLayout->addWidget(boatZ_Y);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addLayout(farLeftLayout);
    layout->addLayout(leftLayout);
    layout->addLayout(middleLayout);
    layout->addLayout(rightLayout);


    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    centralWidget->setLayout(layout);

}




