#include "AssignmentI3_DavidNguyen.h"
#include "ui_mainwindow.h"
#include <Qt>
#include <QtGui>
#include <QMainWindow>
#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QBoxLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QDial>
#include <QRadioButton>
#include <QPushButton>
#include <QScrollBar>
#include <QComboBox>
#include <QCheckBox>
#include <QSpinBox>
#include <QLabel>
#include <QLCDNumber>
#include <QSlider>
#include <QMessageBox>
#include <QDockWidget>
#include <QPlainTextEdit>
#include <QFile>
#include <QFileDialog>
#include <QLineEdit>
#include <QMap>
#include <QString>
#include <QCoreApplication>
#include <cstdlib>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget *window = new QWidget;
    window->setWindowTitle("Boat Tracking Simulator");
    infoLabel = new QLabel;
    region = new QString;
    QPushButton *quitButton = new QPushButton("Quit");
    QObject::connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
    quitButton->resize(100, 25);
    QSlider *gridXSlider = new QSlider(Qt::Horizontal);
    QSlider *gridYSlider = new QSlider(Qt::Horizontal);
    gridXSlider->setRange(0, 4096);
    gridXSlider->setValue(0);
    gridYSlider->setRange(0, 4096);
    gridYSlider->setValue(0);
    gridX = new QSpinBox;
    gridY = new QSpinBox;
    QLabel *gridXLabel = new QLabel("Size of Grid X: ");
    QLabel *gridYLabel = new QLabel("Size of Grid Y: ");
    gridX->setRange(0, 4096);
    gridX->setValue(0);
    gridY->setRange(0, 4096);
    gridY->setValue(0);
    // The values of the spinboxes for the X and Y coordinates of the grid size go up or down when the sliders
    // are moved to the left or right.
    // The sliders for the X and Y coordinates of the grid size move to the left or right when the values of the
    // spinboxes go up or down or when typed on the spinboxes.
    QObject::connect(gridXSlider, SIGNAL(valueChanged(int)), gridX, SLOT(setValue(int)));
    QObject::connect(gridX, SIGNAL(valueChanged(int)), gridXSlider, SLOT(setValue(int)));
    QObject::connect(gridYSlider, SIGNAL(valueChanged(int)), gridY, SLOT(setValue(int)));
    QObject::connect(gridY, SIGNAL(valueChanged(int)), gridYSlider, SLOT(setValue(int)));
    QLabel *ticsLabel = new QLabel("Maximum Number of Tics: ");
    QLCDNumber *finalTics = new QLCDNumber;
    finalTics->setSegmentStyle(QLCDNumber::Filled);
    maximumTics = new QSlider(Qt::Vertical);
    maximumTics->setRange(0, 10000);
    maximumTics->setValue(0);
    // The value in the LCD for the maximum # of tics increases or decreases when the slider is moved up or down.
    QObject::connect(maximumTics, SIGNAL(valueChanged(int)), finalTics, SLOT(display(int)));
    QLabel *durationLabel = new QLabel("Simulation Duration: ");
    QLCDNumber *finalDuration = new QLCDNumber;
    finalDuration->setSegmentStyle(QLCDNumber::Filled);
    QDial *simulationDuration = new QDial;
    simulationDuration->setRange(0, 10000);
    simulationDuration->setNotchesVisible(true);
    simulationDuration->setValue(0);
    // The value in the LCD for the simulation duration increases or decreases when the dial is moved to the left or right.
    QObject::connect(simulationDuration, SIGNAL(valueChanged(int)), finalDuration, SLOT(display(int)));
    QComboBox *activityList = new QComboBox;
    // The combo box lists all of the boat activities as specified by the assignment instructions and
    // allows you to select one of them to display.
    QLabel *activityDescription = new QLabel("Boat Activity: ");
    activityList->addItems(QStringList() << "Boat X is following boat Y" << "Boat X is chasing boat Y" <<
                           "Boat X is circling boat Y" << "Boat Y and boat Z are approaching each other");
    // The combo box lists all of the termination conditions as specified by the assignment instructions and
    // allows you to select one of them to display.
    QComboBox *terminationCondition = new QComboBox;
    QLabel *terminationDescription = new QLabel("Termination Condition: ");
    terminationCondition->addItems(QStringList() << "Boat Y is “close” to boat X where the distance is specified in Euclidean pixel distance"
                                   << "Boat Y is close to boat Z" << "Boat Y is in subregion A");
    QLabel *firstBoatLocation = new QLabel("Initial Location of Boat X: ");
    QLabel *secondBoatLocation = new QLabel("Initial Location of Boat Y: ");
    QLabel *thirdBoatLocation = new QLabel("Initial Location of Boat Z: ");
    // The spinboxes for the coordinates of the three boats selects a numerical X and Y coordinate for each of the three boats.
    firstBoatCoordinateX = new QSpinBox;
    QLabel *firstBoatCoordinateXLabel = new QLabel("X coordinate: ");
    firstBoatCoordinateX->setRange(-1, 4096);
    firstBoatCoordinateX->setValue(0);
    initBoatXCoordinateX = firstBoatCoordinateX->value();
    firstBoatCoordinateY = new QSpinBox;
    QLabel *firstBoatCoordinateYLabel = new QLabel("Y coordinate: ");
    firstBoatCoordinateY->setRange(-1, 4096);
    firstBoatCoordinateY->setValue(0);
    initBoatXCoordinateY = firstBoatCoordinateY->value();
    secondBoatCoordinateX = new QSpinBox;
    QLabel *secondBoatCoordinateXLabel = new QLabel("X coordinate: ");
    secondBoatCoordinateX->setRange(-1, 4096);
    secondBoatCoordinateX->setValue(0);
    initBoatYCoordinateX = secondBoatCoordinateX->value();
    secondBoatCoordinateY = new QSpinBox;
    QLabel *secondBoatCoordinateYLabel = new QLabel("Y coordinate: ");
    secondBoatCoordinateY->setRange(-1, 4096);
    secondBoatCoordinateY->setValue(0);
    initBoatYCoordinateY = secondBoatCoordinateY->value();
    thirdBoatCoordinateX = new QSpinBox;
    QLabel *thirdBoatCoordinateXLabel = new QLabel("X coordinate: ");
    thirdBoatCoordinateX->setRange(-1, 4096);
    thirdBoatCoordinateX->setValue(0);
    initBoatZCoordinateX = thirdBoatCoordinateX->value();
    thirdBoatCoordinateY = new QSpinBox;
    QLabel *thirdBoatCoordinateYLabel = new QLabel("Y coordinate: ");
    thirdBoatCoordinateY->setRange(-1, 4096);
    thirdBoatCoordinateY->setValue(0);
    initBoatZCoordinateY = thirdBoatCoordinateY->value();
    // The text edit allows you to type anything you like.
    QLabel *textEditArea = new QLabel("Text Edit Area:");
    textEdit = new QTextEdit();
    // This secion displays the number of clicks made during the execution.
    QLabel *currentNumberOfClicks = new QLabel("Current Number of Clicks: ");
    numberOfClicksDisplay = new QLCDNumber;
    numberOfClicksDisplay->setSegmentStyle(QLCDNumber::Filled);
    QObject::connect(numberOfClicksDisplay, SIGNAL(clicked()), this, SLOT(keyPressEvent(0)));
    statusLabel = new QLabel;
    QPushButton *startSimulationButton = new QPushButton("Start Simulation");
    QObject::connect(startSimulationButton, SIGNAL(clicked()), this, SLOT(simulationEngine(QString)));
    createActions();
    createMenus();
    // Layout for the maximum number of tics
    QHBoxLayout *topLeftLayout = new QHBoxLayout;
    topLeftLayout->addWidget(ticsLabel);
    topLeftLayout->addWidget(maximumTics);
    topLeftLayout->addWidget(finalTics);
    // Layout for the duration in the simulation
    QVBoxLayout *topRightLayout = new QVBoxLayout;
    topRightLayout->addWidget(durationLabel);
    topRightLayout->addWidget(simulationDuration);
    topRightLayout->addWidget(finalDuration);
    // Layout for the grid size of the widget
    QHBoxLayout *gridLayout = new QHBoxLayout;
    gridLayout->addWidget(gridXLabel);
    gridLayout->addWidget(gridX);
    gridLayout->addWidget(gridXSlider);
    gridLayout->addWidget(gridYLabel);
    gridLayout->addWidget(gridY);
    gridLayout->addWidget(gridYSlider);
    QHBoxLayout *topLayout = new QHBoxLayout;
    topLayout->addLayout(topLeftLayout);
    topLayout->addLayout(topRightLayout);
    // Layout for the boats' activities
    QHBoxLayout *activityComboBox = new QHBoxLayout;
    activityComboBox->addWidget(activityDescription);
    activityComboBox->addWidget(activityList);
    // Layout for the termination conditions
    QHBoxLayout *terminationComboBox = new QHBoxLayout;
    terminationComboBox->addWidget(terminationDescription);
    terminationComboBox->addWidget(terminationCondition);
    // Layout for the box layouts
    QVBoxLayout *comboBoxesLayout = new QVBoxLayout;
    comboBoxesLayout->addLayout(activityComboBox);
    comboBoxesLayout->addLayout(terminationComboBox);
    // Layout for the coordinates of Boat X
    QVBoxLayout *firstBoatCoordinates = new QVBoxLayout;
    firstBoatCoordinates->addWidget(firstBoatCoordinateXLabel);
    firstBoatCoordinates->addWidget(firstBoatCoordinateX);
    firstBoatCoordinates->addWidget(firstBoatCoordinateYLabel);
    firstBoatCoordinates->addWidget(firstBoatCoordinateY);
    QVBoxLayout *firstBoatLayout = new QVBoxLayout;
    firstBoatLayout->addWidget(firstBoatLocation);
    firstBoatLayout->addLayout(firstBoatCoordinates);
    // Layout for the coordinates of Boat Y
    QVBoxLayout *secondBoatCoordinates = new QVBoxLayout;
    secondBoatCoordinates->addWidget(secondBoatCoordinateXLabel);
    secondBoatCoordinates->addWidget(secondBoatCoordinateX);
    secondBoatCoordinates->addWidget(secondBoatCoordinateYLabel);
    secondBoatCoordinates->addWidget(secondBoatCoordinateY);
    QVBoxLayout *secondBoatLayout = new QVBoxLayout;
    secondBoatLayout->addWidget(secondBoatLocation);
    secondBoatLayout->addLayout(secondBoatCoordinates);
    // Layout for the coordinates of Boat Z
    QVBoxLayout *thirdBoatCoordinates = new QVBoxLayout;
    thirdBoatCoordinates->addWidget(thirdBoatCoordinateXLabel);
    thirdBoatCoordinates->addWidget(thirdBoatCoordinateX);
    thirdBoatCoordinates->addWidget(thirdBoatCoordinateYLabel);
    thirdBoatCoordinates->addWidget(thirdBoatCoordinateY);
    QVBoxLayout *thirdBoatLayout = new QVBoxLayout;
    thirdBoatLayout->addWidget(thirdBoatLocation);
    thirdBoatLayout->addLayout(thirdBoatCoordinates);
    // Layout for the boat locations
    QHBoxLayout *boatLocations = new QHBoxLayout;
    boatLocations->addLayout(firstBoatLayout);
    boatLocations->addLayout(secondBoatLayout);
    boatLocations->addLayout(thirdBoatLayout);
    // Layout for the text edit area
    QVBoxLayout *textEditLayout = new QVBoxLayout;
    textEditLayout->addWidget(textEditArea);
    textEditLayout->addWidget(textEdit);
    // Main layout of all the layouts
    QHBoxLayout *numberOfClicksLayout = new QHBoxLayout;
    numberOfClicksLayout->addWidget(currentNumberOfClicks);
    numberOfClicksLayout->addWidget(numberOfClicksDisplay);
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(gridLayout);
    mainLayout->addLayout(boatLocations);
    mainLayout->addLayout(comboBoxesLayout);
    mainLayout->addLayout(textEditLayout);
    mainLayout->addLayout(numberOfClicksLayout);
    mainLayout->addWidget(startSimulationButton);
    mainLayout->addWidget(quitButton);
    // Central widget set to main layout prior to setting the central widget to the dock widget
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    centralWidget->setLayout(mainLayout);
    QDockWidget *finalDockWidget = new QDockWidget(this);
    finalDockWidget->setWidget(centralWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::simulationEngine(QString &region) {
    int currentTics = 0;
    while (currentTics <= maximumTics->value() || ((secondBoatCoordinateX->value() < 1792 &&
           secondBoatCoordinateX->value() > 2304) && (secondBoatCoordinateY->value() < 1792
           && secondBoatCoordinateY->value() > 2304))) {
        // This section checks the initial system status of the boat locations.
        checkAndUpdateStatus(firstBoatCoordinateX, firstBoatCoordinateY, region);
        checkAndUpdateStatus(secondBoatCoordinateX, secondBoatCoordinateY, region);
        checkAndUpdateStatus(thirdBoatCoordinateX, thirdBoatCoordinateY, region);
        // This section updates the cuurent positions of the boats.
        updatePosition(firstBoatCoordinateX, firstBoatCoordinateY, initBoatXCoordinateX, initBoatXCoordinateY);
        updatePosition(secondBoatCoordinateX, secondBoatCoordinateY, initBoatYCoordinateX, initBoatYCoordinateY);
        updatePosition(thirdBoatCoordinateX, thirdBoatCoordinateY, initBoatZCoordinateX, initBoatZCoordinateY);
        // This section updates the current system status of the boats.
        checkAndUpdateStatus(firstBoatCoordinateX, firstBoatCoordinateY, region);
        checkAndUpdateStatus(secondBoatCoordinateX, secondBoatCoordinateY, region);
        checkAndUpdateStatus(thirdBoatCoordinateX, thirdBoatCoordinateY, region);
        // This section outputs the current pixel coordinates and current region to a CSV file.
        QString BoatX_X = QString::number(firstBoatCoordinateX->value());
        QString BoatX_Y = QString::number(firstBoatCoordinateY->value());
        QString BoatY_X = QString::number(secondBoatCoordinateX->value());
        QString BoatY_Y = QString::number(secondBoatCoordinateY->value());
        QString BoatZ_X = QString::number(thirdBoatCoordinateX->value());
        QString BoatZ_Y = QString::number(thirdBoatCoordinateY->value());
        textEdit->insertPlainText("X Coordinate of Boat X: ");
        textEdit->insertPlainText(BoatX_X);
        textEdit->insertPlainText(", ");
        textEdit->insertPlainText("Y Coordinate of Boat X: ");
        textEdit->insertPlainText(BoatX_Y);
        textEdit->insertPlainText(", ");
        textEdit->insertPlainText("Region of Boat X: ");
        textEdit->insertPlainText(region);
        textEdit->insertPlainText("\n");
        textEdit->insertPlainText("X Coordinate of Boat Y: ");
        textEdit->insertPlainText(BoatY_X);
        textEdit->insertPlainText(", ");
        textEdit->insertPlainText("Y Coordinate of Boat Y: ");
        textEdit->insertPlainText(BoatY_Y);
        textEdit->insertPlainText(", ");
        textEdit->insertPlainText("Region of Boat Y: ");
        textEdit->insertPlainText(region);
        textEdit->insertPlainText("\n");
        textEdit->insertPlainText("X Coordinate of Boat Z: ");
        textEdit->insertPlainText(BoatZ_X);
        textEdit->insertPlainText(", ");
        textEdit->insertPlainText("Y Coordinate of Boat Z: ");
        textEdit->insertPlainText(BoatZ_Y);
        textEdit->insertPlainText(", ");
        textEdit->insertPlainText("Region of Boat Z: ");
        textEdit->insertPlainText(region);
        textEdit->append("\n");
        QFile file("Final Data.csv");
        if (file.open(QIODevice::WriteOnly|QIODevice::Append)) {
            QTextStream stream(&file);
            stream << "X Coordinate of Boat X: " << initBoatXCoordinateX << ", "
                   << "Y Coordinate of Boat X: " << initBoatXCoordinateY << ", "
                   << "Region of Boat X: " << region << "\n";
            stream << "X Coordinate of Boat Y: " << initBoatYCoordinateX << ", "
                   << "Y Coordinate of Boat Y: " << initBoatYCoordinateY << ", "
                   << "Region of Boat Y: " << region << "\n";
            stream << "X Coordinate of Boat Z: " << initBoatZCoordinateX << ", "
                   << "Y Coordinate of Boat Z: " << initBoatZCoordinateY << ", "
                   << "Region of Boat Z: " << region << "\n";
            file.close();
        }
        // This section checks for exceptions prior to breaking out of the loop.
        currentTics++;
        maximumTics->setValue(currentTics);
        if (currentTics > maximumTics->value()) {
            break;
        }
        else if ((secondBoatCoordinateX->value() >= 1792 && secondBoatCoordinateX->value() <= 2304)
                 && (secondBoatCoordinateY->value() >= 1792 && secondBoatCoordinateY->value() <= 2304)) {
            QMessageBox::warning(this, tr("Warning"), tr("Boat Y is in Region A."));
            break;
        }
    }
}

// This function opens the text file to display on the text edit area. I credit some of the code to the dock widgets demo.
void MainWindow::open() {
    infoLabel->setText(tr("Invoked <b>File|Open</b>"));
    QMimeDatabase mimeDatabase;
    QString fileName = QFileDialog::getOpenFileName(this,
                        tr("Choose a file name"), ".",
                        mimeDatabase.mimeTypeForName("text").filterString());
    if (fileName.isEmpty())
        return;
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Dock Widgets"),
                             tr("Cannot open file %1:\n%2.")
                             .arg(QDir::toNativeSeparators(fileName), file.errorString()));
        return;
    }

    QTextStream in(&file);
    QGuiApplication::setOverrideCursor(Qt::WaitCursor);
    in << textEdit->toPlainText();
    QGuiApplication::restoreOverrideCursor();
    statusBar()->showMessage(tr("Opened '%1'").arg(fileName), 2000);
}

// This function saves the text file with changes made. I credit some of the code to the dock widgets demo.
void MainWindow::save() {
    infoLabel->setText(tr("Invoked <b>File|Save</b>"));
    QMimeDatabase mimeDatabase;
    QString fileName = QFileDialog::getSaveFileName(this,
                        tr("Choose a file name"), ".",
                        mimeDatabase.mimeTypeForName("text").filterString());
    if (fileName.isEmpty())
        return;
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Dock Widgets"),
                             tr("Cannot write file %1:\n%2.")
                             .arg(QDir::toNativeSeparators(fileName), file.errorString()));
        return;
    }

    QTextStream out(&file);
    QGuiApplication::setOverrideCursor(Qt::WaitCursor);
    out << textEdit->toPlainText();
    QGuiApplication::restoreOverrideCursor();
    statusBar()->showMessage(tr("Saved '%1'").arg(fileName), 2000);
}

// This function enables you to exit the application.
void MainWindow::quit() {
    infoLabel->setText(tr("Invoked <b>Quit|Quit Application</b>"));
}

// This function displays the message about this boat simulation.
void MainWindow::about() {
    infoLabel->setText(tr("Invoked <b>Help|About</b>"));
    QMessageBox::about(this, tr("About Boat Tracker Simulation"),
                    tr("The Boat Tracker Simulation can "
                       "set the positions and coordinates of "
                       "the three boats, the number of tics, "
                       "the duration, the grid size, the "
                       "the types of activites, and the "
                       "termination conditions."));
}

// This function displays the window about the QT application.
void MainWindow::aboutQt() {
    infoLabel->setText(tr("Invoked <b>Help|About QT</b>"));
}

// This function enables the actions for the following menus.
void MainWindow::createMenus() {
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAction);
    helpMenu->addAction(aboutQTAction);
    quitMenu = menuBar()->addMenu(tr("&Quit"));
    quitMenu->addAction(quitAction);
}

// This function creates the menu actions for the boat simulation.
void MainWindow::createActions() {
    openAction = new QAction(tr("&Open"), this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an existing file"));
    QObject::connect(openAction, &QAction::triggered, this, &MainWindow::open);
    saveAction = new QAction(tr("&Save"), this);
    saveAction->setShortcuts(QKeySequence::Save);
    saveAction->setStatusTip(tr("Save the document to disk"));
    QObject::connect(saveAction, &QAction::triggered, this, &MainWindow::save);
    aboutAction = new QAction(tr("&About"), this);
    aboutAction->setStatusTip(tr("Show the application's About box"));
    QObject::connect(aboutAction, &QAction::triggered, this, &MainWindow::about);
    aboutQTAction = new QAction(tr("&About QT"), this);
    aboutQTAction->setStatusTip(tr("Show the QT library's About box"));
    QObject::connect(aboutQTAction, &QAction::triggered, qApp, &QApplication::aboutQt);
    QObject::connect(aboutQTAction, &QAction::triggered, this, &MainWindow::aboutQt);
    quitAction = new QAction(tr("&Quit application"), this);
    quitAction->setShortcuts(QKeySequence::Quit);
    quitAction->setStatusTip(tr("Exit the application"));
    QObject::connect(quitAction, &QAction::triggered, this, &MainWindow::close);
}

// This function allows you to increment the number in the LCD by 1 after clicking.
void MainWindow::mousePressEvent(QMouseEvent *event) {
    if (event->buttons() == Qt::LeftButton && counter == 0) {
        counter++;
        numberOfClicksDisplay->display(counter);
    }
    else if (event->buttons() == Qt::LeftButton) {
        counter++;
        numberOfClicksDisplay->display(counter);
    }
}

// This function updates the X and Y coordinates of a boat.
void MainWindow::updatePosition(QSpinBox *boatCoordinateX, QSpinBox *boatCoordinateY, int updatedBoatXCoordinate, int updatedBoatYCoordinate) {
    int randomInputValue = rand() % 10 + 1;
    switch (randomInputValue) {
        case 1: updatedBoatXCoordinate = boatCoordinateX->value()-1;
                updatedBoatYCoordinate = boatCoordinateY->value()+1;
                boatCoordinateX->setValue(updatedBoatXCoordinate);
                boatCoordinateY->setValue(updatedBoatYCoordinate);
                break;
        case 2: updatedBoatXCoordinate = boatCoordinateX->value();
                updatedBoatYCoordinate = boatCoordinateY->value()+1;
                boatCoordinateX->setValue(updatedBoatXCoordinate);
                boatCoordinateY->setValue(updatedBoatYCoordinate);
                break;
        case 3: updatedBoatXCoordinate = boatCoordinateX->value()+1;
                updatedBoatYCoordinate = boatCoordinateY->value()+1;
                boatCoordinateX->setValue(updatedBoatXCoordinate);
                boatCoordinateY->setValue(updatedBoatYCoordinate);
                break;
        case 4: updatedBoatXCoordinate = boatCoordinateX->value()-1;
                updatedBoatYCoordinate = boatCoordinateY->value();
                boatCoordinateX->setValue(updatedBoatXCoordinate);
                boatCoordinateY->setValue(updatedBoatYCoordinate);
                break;
        case 5: updatedBoatXCoordinate = boatCoordinateX->value();
                updatedBoatYCoordinate = boatCoordinateY->value();
                boatCoordinateX->setValue(updatedBoatXCoordinate);
                boatCoordinateY->setValue(updatedBoatYCoordinate);
                break;
        case 6: updatedBoatXCoordinate = boatCoordinateX->value()+1;
                updatedBoatYCoordinate = boatCoordinateY->value();
                boatCoordinateX->setValue(updatedBoatXCoordinate);
                boatCoordinateY->setValue(updatedBoatYCoordinate);
                break;
        case 7: updatedBoatXCoordinate = boatCoordinateX->value()-1;
                updatedBoatYCoordinate = boatCoordinateY->value()-1;
                boatCoordinateX->setValue(updatedBoatXCoordinate);
                boatCoordinateY->setValue(updatedBoatYCoordinate);
                break;
        case 8: updatedBoatXCoordinate = boatCoordinateX->value();
                updatedBoatYCoordinate = boatCoordinateY->value()-1;
                boatCoordinateX->setValue(updatedBoatXCoordinate);
                boatCoordinateY->setValue(updatedBoatYCoordinate);
                break;
        case 9: updatedBoatXCoordinate = boatCoordinateX->value()+1;
                updatedBoatYCoordinate = boatCoordinateY->value()-1;
                boatCoordinateX->setValue(updatedBoatXCoordinate);
                boatCoordinateY->setValue(updatedBoatYCoordinate);
                break;
        case 10: boatCoordinateX->setValue(-1);
                 boatCoordinateY->setValue(-1);
                 break;
    }
}

// This function checks the system status of a boat and updates it after changing the X and Y coordinates of a boat.
void MainWindow::checkAndUpdateStatus(QSpinBox *boatCoordinateX, QSpinBox *boatCoordinateY, QString &region) {
    if ((boatCoordinateX->value() >= 1792 && boatCoordinateX->value() <= 2304) &&
        (boatCoordinateY->value() >= 1792 && boatCoordinateY->value() <= 2304)) {
        region = "A";
    }
    else if ((boatCoordinateX->value() >= 1536 && boatCoordinateX->value() <= 2560) &&
             (boatCoordinateY->value() >= 1536 && boatCoordinateY->value() <= 2560)) {
        region = "B";
    }
    else if ((boatCoordinateX->value() >= 1024 && boatCoordinateX->value() <= 3072) &&
             (boatCoordinateY->value() >= 1024 && boatCoordinateY->value() <= 3072)) {
        region = "C";
    }
    else if ((boatCoordinateX->value() >= 0 && boatCoordinateX->value() <= 4096) &&
             (boatCoordinateY->value() >= 0 && boatCoordinateY->value() <= 4096)) {
        region = "D";
    }
}
