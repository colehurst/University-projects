

 #include <QtGui>

 #include "MainWindow.h"

 MainWindow::MainWindow()
 {
     textEdit = new QPlainTextEdit;
     setCentralWidget(textEdit);

     createActions();
     createMenus();
     createDockWindow();

     readSettings();

     connect(textEdit->document(), SIGNAL(contentsChanged()),
             this, SLOT(documentWasModified()));

     setCurrentFile("");
     setUnifiedTitleAndToolBarOnMac(true);

 }

 void MainWindow::closeEvent(QCloseEvent *event)
 {
     if (maybeSave()) {
         writeSettings();
         event->accept();
     } else {
         event->ignore();
     }
 }

 void MainWindow::newFile()
 {
     if (maybeSave()) {
         textEdit->clear();
         setCurrentFile("");
     }
 }

 void MainWindow::open()
 {
     if (maybeSave()) {
         QString fileName = QFileDialog::getOpenFileName(this);
         if (!fileName.isEmpty())
             loadFile(fileName);
     }
 }

 bool MainWindow::save()
 {
     if (curFile.isEmpty()) {
         return saveAs();
     } else {
         return saveFile(curFile);
     }
 }

 bool MainWindow::saveAs()
 {
     QString fileName = QFileDialog::getSaveFileName(this);
     if (fileName.isEmpty())
         return false;

     return saveFile(fileName);
 }

 void MainWindow::about()
 {
    QMessageBox::about(this, tr("About Application"),
             tr("The <b>Application</b> example demonstrates how to "
                "write modern GUI applications using Qt, with a menu bar, "
                "toolbars, and a status bar."));
 }

 void MainWindow::documentWasModified()
 {
     setWindowModified(textEdit->document()->isModified());
 }

 void MainWindow::createActions()
 {
     newAct = new QAction(QIcon(":/images/new.png"), tr("&New"), this);
     newAct->setShortcuts(QKeySequence::New);
     newAct->setStatusTip(tr("Create a new file"));
     connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));

     openAct = new QAction(QIcon(":/images/open.png"), tr("&Open..."), this);
     openAct->setShortcuts(QKeySequence::Open);
     openAct->setStatusTip(tr("Open an existing file"));
     connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

     saveAct = new QAction(QIcon(":/images/save.png"), tr("&Save"), this);
     saveAct->setShortcuts(QKeySequence::Save);
     saveAct->setStatusTip(tr("Save the document to disk"));
     connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));

     saveAsAct = new QAction(tr("Save &As..."), this);
     saveAsAct->setShortcuts(QKeySequence::SaveAs);
     saveAsAct->setStatusTip(tr("Save the document under a new name"));
     connect(saveAsAct, SIGNAL(triggered()), this, SLOT(saveAs()));

     exitAct = new QAction(tr("E&xit"), this);
     exitAct->setShortcuts(QKeySequence::Quit);
     exitAct->setStatusTip(tr("Exit the application"));
     connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

     cutAct = new QAction(QIcon(":/images/cut.png"), tr("Cu&t"), this);
     cutAct->setShortcuts(QKeySequence::Cut);
     cutAct->setStatusTip(tr("Cut the current selection's contents to the "
                             "clipboard"));
     connect(cutAct, SIGNAL(triggered()), textEdit, SLOT(cut()));

     copyAct = new QAction(QIcon(":/images/copy.png"), tr("&Copy"), this);
     copyAct->setShortcuts(QKeySequence::Copy);
     copyAct->setStatusTip(tr("Copy the current selection's contents to the "
                              "clipboard"));
     connect(copyAct, SIGNAL(triggered()), textEdit, SLOT(copy()));

     pasteAct = new QAction(QIcon(":/images/paste.png"), tr("&Paste"), this);
     pasteAct->setShortcuts(QKeySequence::Paste);
     pasteAct->setStatusTip(tr("Paste the clipboard's contents into the current "
                               "selection"));
     connect(pasteAct, SIGNAL(triggered()), textEdit, SLOT(paste()));

     aboutAct = new QAction(tr("&About"), this);
     aboutAct->setStatusTip(tr("Show the application's About box"));
     connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

     aboutQtAct = new QAction(tr("About &Qt"), this);
     aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
     connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

     cutAct->setEnabled(false);
     copyAct->setEnabled(false);
     connect(textEdit, SIGNAL(copyAvailable(bool)),
             cutAct, SLOT(setEnabled(bool)));
     connect(textEdit, SIGNAL(copyAvailable(bool)),
             copyAct, SLOT(setEnabled(bool)));


 }

 void MainWindow::createMenus()
 {
     fileMenu = menuBar()->addMenu(tr("&File"));
     fileMenu->addAction(newAct);
     fileMenu->addAction(openAct);
     fileMenu->addAction(saveAct);
     fileMenu->addAction(saveAsAct);
     fileMenu->addSeparator();
     fileMenu->addAction(exitAct);

     editMenu = menuBar()->addMenu(tr("&Edit"));
     editMenu->addAction(cutAct);
     editMenu->addAction(copyAct);
     editMenu->addAction(pasteAct);

     menuBar()->addSeparator();

     helpMenu = menuBar()->addMenu(tr("&Help"));
     helpMenu->addAction(aboutAct);
     helpMenu->addAction(aboutQtAct);
 }

 void MainWindow::createToolBars()
 {
     fileToolBar = addToolBar(tr("File"));
     fileToolBar->addAction(newAct);
     fileToolBar->addAction(openAct);
     fileToolBar->addAction(saveAct);

     editToolBar = addToolBar(tr("Edit"));
     editToolBar->addAction(cutAct);
     editToolBar->addAction(copyAct);
     editToolBar->addAction(pasteAct);
 }

 void MainWindow::createStatusBar()
 {
     statusBar()->showMessage(tr("Ready"));
 }

 void MainWindow::createDockWindow()
 {
 QDockWidget* dock = new QDockWidget(tr("Radio Controls"), this);
	 dock->setAllowedAreas(Qt::LeftDockWidgetArea);

	 QGroupBox* dockGroup = new QGroupBox();
	 QVBoxLayout* dockLayout = new QVBoxLayout;

	 QGroupBox* mainTunerGroup = new QGroupBox(tr("Tuner"));
	 QHBoxLayout* mainTunerLayout = new QHBoxLayout;

	 QGroupBox* radioButtonGroup = new QGroupBox();
	 QVBoxLayout* radioButtonLayout = new QVBoxLayout;
	 QRadioButton *fmButton = new QRadioButton();
	 fmButton->setText("FM");
	 QRadioButton *amButton = new QRadioButton();
	 amButton->setText("AM");
	 radioButtonLayout->addWidget(fmButton);
	 radioButtonLayout->addWidget(amButton);

	 radioButtonGroup->setLayout(radioButtonLayout);

	 QGroupBox* tunerGroup = new QGroupBox();
	 QVBoxLayout* tunerLayout = new QVBoxLayout;
	 QSlider* tunerSlider = new QSlider(Qt::Horizontal);
	 tunerSlider->setRange(88.7,102.7);

	 QLCDNumber* tunerLCD = new QLCDNumber;
	 tunerLCD->setDigitCount(4);

	 QObject::connect(tunerSlider, SIGNAL(valueChanged(int)), tunerLCD, SLOT(display(int)));

	 tunerLayout->addWidget(tunerSlider);
	 tunerLayout->addWidget(tunerLCD);

	 tunerGroup->setLayout(tunerLayout);

	 mainTunerLayout->addWidget(radioButtonGroup);
	 mainTunerLayout->addWidget(tunerGroup);
	 mainTunerGroup->setLayout(mainTunerLayout);

	 QGroupBox* eqGroup = new QGroupBox(tr("Eq"));
	 QVBoxLayout* eqLayout = new QVBoxLayout;

	 QGroupBox* eqDialGroup = new QGroupBox();
	 QHBoxLayout* eqDialLayout = new QHBoxLayout;
	 QDial* bassDial = new QDial();
	 bassDial->setNotchesVisible(true);
	 bassDial->setRange(-6, 6);
	 bassDial->setValue(0);

	 QDial* trebleDial = new QDial();
	 trebleDial->setNotchesVisible(true);
	 trebleDial->setRange(-6,6);
	 trebleDial->setValue(0);

	 eqDialLayout->addWidget(bassDial);
	 eqDialLayout->addWidget(trebleDial);

	 eqDialGroup->setLayout(eqDialLayout);

	 QGroupBox* eqDisplayGroup = new QGroupBox();
	 QHBoxLayout* eqDisplayLayout = new QHBoxLayout;
	 QSpinBox* bassSpinBox = new QSpinBox;
	 bassSpinBox->setRange(-6, 6);
	 bassSpinBox->setValue(0);
	 bassSpinBox->setFixedWidth(50);
	 QSpinBox* trebleSpinBox = new QSpinBox;
	 trebleSpinBox->setRange(-6, 6);
	 trebleSpinBox->setFixedWidth(50);
	 eqDisplayLayout->addWidget(bassSpinBox);
	 eqDisplayLayout->addWidget(trebleSpinBox);
	 eqDisplayGroup->setLayout(eqDisplayLayout);

	 QObject::connect(bassDial, SIGNAL(valueChanged(int)), bassSpinBox, SLOT(setValue(int)));
	 QObject::connect(bassSpinBox, SIGNAL(valueChanged(int)), bassDial, SLOT(setValue(int)));

	 QObject::connect(trebleDial, SIGNAL(valueChanged(int)), trebleSpinBox, SLOT(setValue(int)));
	 QObject::connect(trebleSpinBox, SIGNAL(valueChanged(int)), trebleDial, SLOT(setValue(int)));

	 QGroupBox* eqLabelGroup = new QGroupBox();
	 QHBoxLayout* eqLabelLayout = new QHBoxLayout;
	 QLabel* bassLabel = new QLabel;
	 QLabel* trebleLabel = new QLabel;
	 bassLabel->setText(tr("Bass"));
	 trebleLabel->setText(tr("Treble"));
	 bassLabel->setAlignment(Qt::AlignCenter);
	 trebleLabel->setAlignment(Qt::AlignCenter);
	 bassLabel->show();
	 trebleLabel->show();
	 eqLabelLayout->addWidget(bassLabel);
	 eqLabelLayout->addWidget(trebleLabel);

	 eqLabelGroup->setLayout(eqLabelLayout);

	 eqLayout->addWidget(eqDialGroup);
	 eqLayout->addWidget(eqDisplayGroup);
	 eqLayout->addWidget(eqLabelGroup);

	 eqGroup->setLayout(eqLayout);

	 QGroupBox* volumeGroup = new QGroupBox(tr("Volume"));
	 QHBoxLayout* volumeLayout = new QHBoxLayout;

	 QSlider* volumeSlider = new QSlider(Qt::Vertical);
	 volumeSlider->setRange(0,120);
	 volumeSlider->setMinimumSize(3, 200);
	 QSpinBox* volumeSpinBox = new QSpinBox;
	 volumeSpinBox->setRange(0,120);
	 volumeSpinBox->setFixedWidth(50);
	 volumeLayout->addWidget(volumeSlider);
	 volumeLayout->addWidget(volumeSpinBox);
	 volumeGroup->setLayout(volumeLayout);

	 QObject::connect(volumeSlider, SIGNAL(valueChanged(int)), volumeSpinBox, SLOT(setValue(int)));
	 QObject::connect(volumeSpinBox, SIGNAL(valueChanged(int)), volumeSlider, SLOT(setValue(int)));

	 dockLayout->addWidget(mainTunerGroup);
	 dockLayout->addWidget(eqGroup);
	 dockLayout->addWidget(volumeGroup);

	 dockGroup->setLayout(dockLayout);

	 dock->setWidget(dockGroup);

	 addDockWidget(Qt::LeftDockWidgetArea, dock);

 }

 void MainWindow::readSettings()
 {
     QSettings settings("Trolltech", "Application Example");
     QPoint pos = settings.value("pos", QPoint(200, 200)).toPoint();
     QSize size = settings.value("size", QSize(400, 400)).toSize();
     resize(size);
     move(pos);
 }

 void MainWindow::writeSettings()
 {
     QSettings settings("Trolltech", "Application Example");
     settings.setValue("pos", pos());
     settings.setValue("size", size());
 }

 bool MainWindow::maybeSave()
 {
     if (textEdit->document()->isModified()) {
         QMessageBox::StandardButton ret;
         ret = QMessageBox::warning(this, tr("Application"),
                      tr("The document has been modified.\n"
                         "Do you want to save your changes?"),
                      QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
         if (ret == QMessageBox::Save)
             return save();
         else if (ret == QMessageBox::Cancel)
             return false;
     }
     return true;
 }

 void MainWindow::loadFile(const QString &fileName)
 {
     QFile file(fileName);
     if (!file.open(QFile::ReadOnly | QFile::Text)) {
         QMessageBox::warning(this, tr("Application"),
                              tr("Cannot read file %1:\n%2.")
                              .arg(fileName)
                              .arg(file.errorString()));
         return;
     }

     QTextStream in(&file);
 #ifndef QT_NO_CURSOR
     QApplication::setOverrideCursor(Qt::WaitCursor);
 #endif
     textEdit->setPlainText(in.readAll());
 #ifndef QT_NO_CURSOR
     QApplication::restoreOverrideCursor();
 #endif

     setCurrentFile(fileName);
     statusBar()->showMessage(tr("File loaded"), 2000);
 }

 bool MainWindow::saveFile(const QString &fileName)
 {
     QFile file(fileName);
     if (!file.open(QFile::WriteOnly | QFile::Text)) {
         QMessageBox::warning(this, tr("Application"),
                              tr("Cannot write file %1:\n%2.")
                              .arg(fileName)
                              .arg(file.errorString()));
         return false;
     }

     QTextStream out(&file);
 #ifndef QT_NO_CURSOR
     QApplication::setOverrideCursor(Qt::WaitCursor);
 #endif
     out << textEdit->toPlainText();
 #ifndef QT_NO_CURSOR
     QApplication::restoreOverrideCursor();
 #endif

     setCurrentFile(fileName);
     statusBar()->showMessage(tr("File saved"), 2000);
     return true;
 }

 void MainWindow::setCurrentFile(const QString &fileName)
 {
     curFile = fileName;
     textEdit->document()->setModified(false);
     setWindowModified(false);

     QString shownName = curFile;
     if (curFile.isEmpty())
         shownName = "untitled.txt";
     setWindowFilePath(shownName);
 }

 QString MainWindow::strippedName(const QString &fullFileName)
 {
     return QFileInfo(fullFileName).fileName();
 }
