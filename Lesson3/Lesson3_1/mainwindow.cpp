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

    formatToolBar = new QToolBar;
    formatToolBar = addToolBar(tr("Property"));
    copyIcon = QIcon::fromTheme("",QIcon(":/Imadge/icon-copy.png"));
    pasteIcon = QIcon::fromTheme("",QIcon(":/Imadge/icon-paste.png"));
    fontIcon = QIcon::fromTheme("",QIcon(":/Imadge/icon-font.png"));
    alignLeftIcon = QIcon::fromTheme("",QIcon(":/Imadge/icon-align-left.png"));
    alignRightIcon = QIcon::fromTheme("",QIcon(":/Imadge/icon-align-right.png"));
    alignCenterlIcon = QIcon::fromTheme("",QIcon(":/Imadge/icon-align-center.png"));
    dateIcon = QIcon::fromTheme("",QIcon(":/Imadge/icon-data.png"));

    addMenu();

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
    if (sender() == languageRusAction)
    {
        translator.load(":/tr/QtLanguage_ru.qm");
        qApp->installTranslator(&translator);
    }
    else if (sender() == languageEngAction) {
        translator.load(":/tr/QtLanguage_en.qm");
        qApp->installTranslator(&translator);
    }
    delMenu();
    addMenu();
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
                mdiArea->currentSubWindow()->setWindowTitle(findNameFile(filename));
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
                mdiArea->currentSubWindow()->setWindowTitle(findNameFile(filename));
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
    formatToolBar->removeAction(copyPropirtiesAction);
    formatToolBar->removeAction(pastePropirtiesAction);
    formatToolBar->removeAction(fontPropirtiesAction);
    formatToolBar->removeAction(alignLeftAction);
    formatToolBar->removeAction(alignCenterAction);
    formatToolBar->removeAction(alignRightAction);
    formatToolBar->removeAction(dateAction);
}

void MainWindow::activWindow()
{
    QWidget *wdg = mdiArea->activeSubWindow()->widget();
    plainTextEdit = reinterpret_cast<QPlainTextEdit*>(wdg);
}

QString MainWindow::findNameFile(QString str)
{
    int index_1 = str.lastIndexOf("/")+1;
    return str.mid(index_1,str.length());
}

void MainWindow::addMenu()
{

    openButton = new QPushButton(tr("Open"),this);
    layout->addWidget(openButton,11,0,2,2);
    connect(openButton, SIGNAL(clicked()), this, SLOT(on_openButton_clicked()));

    openOnlyReadButton = new QPushButton(tr("Open only read"),this);
    layout->addWidget(openOnlyReadButton,11,2,2,2);
    connect(openOnlyReadButton, SIGNAL(clicked()), this, SLOT(on_openReadOnlyButton_clicked()));

    saveButton = new QPushButton(tr("Save"),this);
    layout->addWidget(saveButton,11,4,2,2);
    connect(saveButton, SIGNAL(clicked()), this, SLOT(on_saveButton_clicked()));

    helpButton = new QPushButton(tr("Help"),this);
    layout->addWidget(helpButton,11,6,2,2);
    connect(helpButton, SIGNAL(clicked()), this, SLOT(on_helpButton_clicked()));

    printButton = new QPushButton(tr("Print"),this);
    layout->addWidget(printButton,11,8,2,2);
    connect(printButton, SIGNAL(clicked()), this, SLOT(on_printButton_clicked()));

    fileMenu = menuBar()->addMenu(tr("File"));
    openAction = fileMenu->addAction(tr("Open"));
    openAction->setIcon(QIcon(QApplication::style()->standardIcon(QStyle::SP_DialogOpenButton)));
    connect(openAction, SIGNAL(triggered()), this, SLOT(on_openButton_clicked()));

    openReadAction = fileMenu->addAction(tr("Open only Read"));
    openReadAction->setIcon(QIcon(QApplication::style()->standardIcon(QStyle::SP_DirClosedIcon)));
    connect(openReadAction, SIGNAL(triggered()), this, SLOT(on_openReadOnlyButton_clicked()));

    saveAction = fileMenu->addAction(tr("Save as"));
    saveAction->setIcon(QIcon(QApplication::style()->standardIcon(QStyle::SP_DialogSaveButton)));
    connect(saveAction, SIGNAL(triggered()), this, SLOT(on_saveButton_clicked()));

    fileMenu->addSeparator();
    exitAction = fileMenu->addAction(tr("Exit"));
    exitAction->setIcon(QIcon(QApplication::style()->standardIcon(QStyle::SP_DialogCloseButton)));
    connect(exitAction, SIGNAL(triggered()), qApp, SLOT(quit()));

    settingsMenu = menuBar()->addMenu(tr("Settings"));
    styleAction = settingsMenu->addAction(tr("Dark style"));
    styleAction->setCheckable(true);
    styleAction->setChecked(false);
    connect(styleAction, SIGNAL(toggled(bool)), this, SLOT(on_styleCheckBox_clicked()));

    languageAction = settingsMenu->addMenu(tr("Language"));
    languageRusAction = languageAction->addAction("Русский");
    languageEngAction = languageAction->addAction("English");

    connect(languageRusAction, SIGNAL(triggered()), this, SLOT(on_translationCheckBox_clicked()));
    connect(languageEngAction, SIGNAL(triggered()), this, SLOT(on_translationCheckBox_clicked()));

    printMenu = new QMenu(this);
    printMenu = menuBar()->addMenu(tr("Print"));
    printAction = printMenu->addAction(tr("Print"));
    printAction->setIcon(QIcon(QApplication::style()->standardIcon(QStyle::SP_DriveDVDIcon)));
    connect(printAction, SIGNAL(triggered()), this, SLOT(on_printButton_clicked()));

    helpMenu = menuBar()->addMenu(tr("Help"));
    helpAction = helpMenu->addAction(tr("Help"));
    helpAction->setIcon(QIcon(QApplication::style()->standardIcon(QStyle::SP_MessageBoxQuestion)));
    connect(helpAction, SIGNAL(triggered()), this, SLOT(on_helpButton_clicked()));


    copyPropirtiesAction = formatToolBar->addAction(copyIcon,tr("Copy properties"));
    connect(copyPropirtiesAction,SIGNAL(triggered()),this, SLOT (copyProperties()));

    pastePropirtiesAction = formatToolBar->addAction(pasteIcon,tr("Paste properties"));
    connect(pastePropirtiesAction,SIGNAL(triggered()),this, SLOT (pasteProperties()));

    fontPropirtiesAction = formatToolBar->addAction(fontIcon,tr("Font properties"));
    connect(fontPropirtiesAction,SIGNAL(triggered()),this, SLOT (fontProperties()));

    formatToolBar->addSeparator();

    alignLeftAction = formatToolBar->addAction(alignLeftIcon,tr("Align left"));
    connect(alignLeftAction,SIGNAL(triggered()),this, SLOT (alignLeft()));

    alignCenterAction = formatToolBar->addAction(alignCenterlIcon,tr("Align center"));
    connect(alignCenterAction,SIGNAL(triggered()),this, SLOT (alignCenter()));

    alignRightAction = formatToolBar->addAction(alignRightIcon,tr("Align right"));
    connect(alignRightAction,SIGNAL(triggered()),this, SLOT (alignRight()));

    formatToolBar->addSeparator();

    dateAction = formatToolBar->addAction(dateIcon,tr("Insert date"));
    connect(dateAction,SIGNAL(triggered()),this, SLOT (dateInsert()));



}


void MainWindow::on_styleCheckBox_clicked()
{

    if(styleAction->isChecked()){

        this->setStyleSheet("QMainWindow{background-color:gray}"
                            "QPushButton {background-color:gray; color:blue}"
                            "QPlainTextEdit {background-color:black; color:white}"
                            "QCheckBox {color:blue}"
                            );
    }
    else {
        this->setStyleSheet("QMainWindow{background-color:white} ");
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

void MainWindow::copyProperties()
{
    activWindow();
    format = plainTextEdit->textCursor().charFormat();
}

void MainWindow::pasteProperties()
{
    activWindow();
    plainTextEdit->textCursor().setCharFormat(format);
}

void MainWindow::fontProperties()
{
    activWindow();
    QFont font = plainTextEdit->textCursor().charFormat().font();
    QFontDialog fntDlg(font,this);
    bool b[] = {true};
    font = fntDlg.getFont(b);
    if (b[0]){
        QTextCharFormat fmt;
        fmt.setFont(font);
        plainTextEdit->textCursor().setCharFormat(fmt);
    }
}

void MainWindow::alignLeft()
{
    activWindow();
    plainTextEdit->document()->setDefaultTextOption(QTextOption(Qt::AlignLeft));
}

void MainWindow::alignRight()
{
    activWindow();
    plainTextEdit->document()->setDefaultTextOption(QTextOption(Qt::AlignRight));
}

void MainWindow::alignCenter()
{
    activWindow();
    plainTextEdit->document()->setDefaultTextOption(QTextOption(Qt::AlignCenter));
}

void MainWindow::dateInsert()
{
    QDate date = QDate::currentDate();
    //QString datestring = QString::number(date.year()) + "." + QString::number(date.month()) + "." + QString::number(date.day());
    //QString datestring = QDate::toString(dd.mm.yyyy,date);
    plainTextEdit->insertPlainText(datestring);

}
