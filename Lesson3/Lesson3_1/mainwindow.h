#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>
#include <QTranslator>
#include <QKeyEvent>
#include <QMenuBar>
#include <QApplication>
#include <QAction>
#include <QStyle>
#include <QPrinter>
#include <QPrintDialog>
#include <QMdiArea>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QMdiSubWindow>
#include <QWidget>
#include <QGridLayout>



//QT_BEGIN_NAMESPACE
//namespace Ui { class MainWindow; }
//QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_openButton_clicked();

    void on_saveButton_clicked();

    void on_helpButton_clicked();

    void on_translationCheckBox_clicked();

    void on_styleCheckBox_clicked();

    void on_openReadOnlyButton_clicked();

    void on_printButton_clicked();

protected:
    void keyPressEvent(QKeyEvent* event) override;



private:
    //Ui::MainWindow *ui;
    QTranslator translator;

    void saveAsFile();
    void openFile(bool readOnly);
    void addMenu();
    void delMenu();
    void activWindow();
    QString findNameFile(QString str);

    QGridLayout *layout;
    QMdiArea *mdiArea;

    QPlainTextEdit *plainTextEdit;

    QPushButton *openButton;
    QPushButton *openOnlyReadButton;
    QPushButton *saveButton;
    QPushButton *helpButton;
    QPushButton *printButton;

    QMenu *fileMenu;
    QAction *openAction;
    QAction *openReadAction;
    QAction *saveAction;
    QAction *exitAction;

    QMenu *settingsMenu;
    QAction *styleAction;

    QMenu *languageAction;
    QAction *languageRusAction;
    QAction *languageEngAction;

    QMenu *printMenu;
    QAction *printAction;

    QMenu *helpMenu;
    QAction *helpAction;


};
#endif // MAINWINDOW_H
