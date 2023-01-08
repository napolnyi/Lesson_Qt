#include "mainwindow.h"
//#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    //, ui(new Ui::MainWindow)
{
    //ui->setupUi(this);


    mdiArea = new QMdiArea(this);
    QWidget *centralW = new QWidget(this);
    setCentralWidget(centralW);
    layout = new QGridLayout(this);
    centralW->setLayout(layout);
    layout->addWidget(mdiArea,1,0,10,10);
    mdiArea->setMaximumSize(700,600);

    addMenu();

    connect(openButton, SIGNAL(clicked()), this, SLOT(on_openButton_clicked()));
    connect(openOnlyReadButton, SIGNAL(clicked()), this, SLOT(on_openReadOnlyButton_clicked()));
    connect(saveButton, SIGNAL(clicked()), this, SLOT(on_saveButton_clicked()));
    connect(helpButton, SIGNAL(clicked()), this, SLOT(on_helpButton_clicked()));
    connect(printButton, SIGNAL(clicked()), this, SLOT(on_printButton_clicked()));
    connect(translationCheckBox, SIGNAL(stateChanged(int)), this, SLOT(on_translationCheckBox_clicked()));
    connect(styleCheckBox, SIGNAL(stateChanged(int)), this, SLOT(on_styleCheckBox_clicked()));
    connect(openAction, SIGNAL(triggered()), this, SLOT(on_openButton_clicked()));
    connect(openReadAction, SIGNAL(triggered()), this, SLOT(on_openReadOnlyButton_clicked()));
    connect(saveAction, SIGNAL(triggered()), this, SLOT(on_saveButton_clicked()));
    connect(exitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(styleAction, SIGNAL(toggled(bool)), this, SLOT(on_styleCheckBox_clicked()));
    connect(languageRus, SIGNAL(toggled(bool)), this, SLOT(on_translationCheckBox_clicked()));
    connect(printAction, SIGNAL(triggered()), this, SLOT(on_printButton_clicked()));
    connect(helpAction, SIGNAL(triggered()), this, SLOT(on_helpButton_clicked()));

    plainTextEdit = new QPlainTextEdit(this);
    mdiArea->addSubWindow(plainTextEdit);
    mdiArea->setViewMode(QMdiArea::TabbedView);


}

MainWindow::~MainWindow()
{
    //delete ui;
}

void MainWindow::on_openButton_clicked()
{
    openFile(false);
}

void MainWindow::on_openReadOnlyButton_clicked()
{
    openFile(true);
}

void MainWindow::on_saveButton_clicked()
{
    saveAsFile();
}

void MainWindow::on_helpButton_clicked()
{
    QFile file(":/hlp/help.txt");
    if (file.open(QFile::ReadOnly | QFile::ExistingOnly)){
        QTextStream stream(&file);
        activWindow();
        plainTextEdit->setPlainText(stream.readAll());
        plainTextEdit->setReadOnly(true);
        file.close();
    }
}


void MainWindow::on_translationCheckBox_clicked()
{
    qDebug()<<"111";
    if (translationCheckBox->isChecked())
    {
        qDebug()<<"222";
        translator.load(":/tr/QtLanguage_ru.qm");
        qApp->installTranslator(&translator);
        qDebug()<<"333";
        delMenu();
        addMenu();
    }
    else {
        qDebug()<<"444";
        translator.load(":/tr/QtLanguage_en.qm");
        qApp->installTranslator(&translator);
        delMenu();
        addMenu();
    }
//    if (sender() == languageRus){
//      if (languageRus->isChecked()) translationCheckBox->setChecked(true);
//      else translationCheckBox->setChecked(false);
//    }
//    else{
//      if (translationCheckBox->isChecked()) languageRus->setChecked(true);
//      else languageRus->setChecked(false);
//    }

}


void MainWindow::keyPressEvent(QKeyEvent *event)
{


     if ((event->key() == Qt::Key_S) && (event->modifiers() | Qt::Key_Control)) {
         saveAsFile();
         }
     else if ((event->key() == Qt::Key_N) && (event->modifiers() | Qt::Key_Control)){
         activWindow();
         plainTextEdit->clear();
         }
     else if ((event->key() == Qt::Key_Q) && (event->modifiers() | Qt::Key_Control)){
         qApp->quit();
         }

}


void MainWindow::saveAsFile()
{
    activWindow();
    QString filename = QFileDialog::getSaveFileName(this,"Сохранение файла",QDir::currentPath(),"(*.txt);;(*.bin)");
    if (filename.length()){
        int index = filename.indexOf(".txt");
        if (index != -1 && filename.length()-4 == index ){

            QFile file(filename);
            if (file.open(QFile::ReadWrite /*| QFile::NewOnly*/)){
                QTextStream stream(&file);
                stream << plainTextEdit->toPlainText();
                file.close();
            }
        }

    }
}

void MainWindow::openFile(bool readOnly)
{
    QString filename = QFileDialog::getOpenFileName(this,"Загрузка файла",QDir::currentPath(),"(*.txt);;(*.bin)");
    if (filename.length()){
        int index = filename.indexOf(".txt");
        if (index != -1 && filename.length()-4 == index ){

            QFile file(filename);
            if (file.open(QFile::ReadOnly | QFile::ExistingOnly)){
                plainTextEdit = new QPlainTextEdit(this);
                mdiArea->addSubWindow(plainTextEdit);
                QTextStream stream(&file);
                plainTextEdit->setPlainText(stream.readAll());
                if (readOnly) plainTextEdit->setReadOnly(true);
                else plainTextEdit->setReadOnly(false);
                file.close();
            }
        }

    }
}

void MainWindow::delMenu()
{
    fileMenu->deleteLater();
    settingsMenu->deleteLater();
    printMenu->deleteLater();
    helpMenu->deleteLater();
}

void MainWindow::activWindow()
{
    QWidget *wdg = mdiArea->activeSubWindow()->widget();
    plainTextEdit = reinterpret_cast<QPlainTextEdit*>(wdg);
}

void MainWindow::addMenu()
{
    openButton = new QPushButton(tr("Open"),this);
    layout->addWidget(openButton,11,0,2,2);

    openOnlyReadButton = new QPushButton(tr("Open only read"),this);
    layout->addWidget(openOnlyReadButton,11,2,2,2);

    saveButton = new QPushButton(tr("Save"),this);
    layout->addWidget(saveButton,11,4,2,2);

    helpButton = new QPushButton(tr("Help"),this);
    layout->addWidget(helpButton,11,6,2,2);

    printButton = new QPushButton(tr("Print"),this);
    layout->addWidget(printButton,11,8,2,2);

    translationCheckBox = new QCheckBox(tr("Russian"),this);
    layout->addWidget(translationCheckBox,13,0,1,2);

    styleCheckBox = new QCheckBox(tr("Dark style"),this);
    layout->addWidget(styleCheckBox,14,0,1,2);

    fileMenu = menuBar()->addMenu(tr("File"));
    openAction = fileMenu->addAction(tr("Open"));
    openAction->setIcon(QIcon(QApplication::style()->standardIcon(QStyle::SP_DialogOpenButton)));

    openReadAction = fileMenu->addAction(tr("Open only Read"));
    openReadAction->setIcon(QIcon(QApplication::style()->standardIcon(QStyle::SP_DirClosedIcon)));

    saveAction = fileMenu->addAction(tr("Save as"));
    saveAction->setIcon(QIcon(QApplication::style()->standardIcon(QStyle::SP_DialogSaveButton)));

    fileMenu->addSeparator();
    exitAction = fileMenu->addAction(tr("Exit"));
    exitAction->setIcon(QIcon(QApplication::style()->standardIcon(QStyle::SP_DialogCloseButton)));

    settingsMenu = menuBar()->addMenu(tr("Settings"));
    styleAction = settingsMenu->addAction(tr("Dark style"));
    styleAction->setCheckable(true);
    styleAction->setChecked(false);

    languageRus = settingsMenu->addAction(tr("Russian"));
    languageRus->setCheckable(true);
    languageRus->setChecked(false);

    printMenu = new QMenu(this);
    printMenu = menuBar()->addMenu(tr("Print"));
    printAction = printMenu->addAction(tr("Print"));
    printAction->setIcon(QIcon(QApplication::style()->standardIcon(QStyle::SP_DriveDVDIcon)));

    helpMenu = menuBar()->addMenu(tr("Help"));
    helpAction = helpMenu->addAction(tr("Help"));
    helpAction->setIcon(QIcon(QApplication::style()->standardIcon(QStyle::SP_MessageBoxQuestion)));

}


void MainWindow::on_styleCheckBox_clicked()
{

    if(styleCheckBox->isChecked()){

        this->setStyleSheet("QMainWindow{background-color:gray}"
                            "QPushButton {background-color:gray; color:blue}"
                            "QPlainTextEdit {background-color:black; color:white}"
                            "QCheckBox {color:blue}"
                            );
    }
    else {
        this->setStyleSheet("QMainWindow{background-color:white} ");
    }

    if (sender() == styleAction){
      if (styleAction->isChecked()) styleCheckBox->setChecked(true);
      else styleCheckBox->setChecked(false);
    }
    else{
      if (styleCheckBox->isChecked()) styleAction->setChecked(true);
      else styleAction->setChecked(false);
    }
}


void MainWindow::on_printButton_clicked()
{
    activWindow();
    QPrinter printer;
    QPrintDialog dlg (&printer,this);
    dlg.setWindowTitle(tr("Print"));
    if (dlg.exec() != QDialog::Accepted) return;
    plainTextEdit->print(&printer);
}
