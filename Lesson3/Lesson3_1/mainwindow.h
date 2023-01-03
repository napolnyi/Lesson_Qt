#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>
#include <QTranslator>
#include <QKeyEvent>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

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

protected:
    void keyPressEvent(QKeyEvent* event) override;



private:
    Ui::MainWindow *ui;
    QTranslator translator;
    void saveAsFile();
    QList<Qt::Key> lst;


};
#endif // MAINWINDOW_H
