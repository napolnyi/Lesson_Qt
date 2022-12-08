#ifndef MAINWINDOWPLAINTEXT_H
#define MAINWINDOWPLAINTEXT_H

#include <QMainWindow>

namespace Ui {
class MainWindowPlainText;
}

class MainWindowPlainText : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowPlainText(QWidget *parent = nullptr);
    ~MainWindowPlainText();

private slots:
    void on_addTextButton_clicked();
    void on_rplTextButton_clicked();

    void on_HtmlTextButton_clicked();

private:
    Ui::MainWindowPlainText *ui;
};

#endif // MAINWINDOWPLAINTEXT_H
