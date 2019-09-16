#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTextEdit>
#include<QMenu>
#include<QMenuBar>
#include<QAction>
#include<QProcess>
#include <QWidget>
#include <QDialog>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QGroupBox>
#include <QPushButton>
#include <QCheckBox>
#include <QRadioButton>
#include <QEvent>
#include "qinputdialog.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
//替换
    QLabel *searchLabel;

    QLabel *replaceLabel;

    QLineEdit *searchLineEdit;

    QLineEdit *replaceLineEdit;

    QPushButton *sureBtn;
//搜索
    QLabel *searchInputLabel;
    QPushButton *searchForwardBtn;
    QLineEdit *searchInputLineEdit;

    QDialog *searchInputDialog;
    QDialog *replaceDialog;

private:
    QString filename;
    QString savefilename;
    QProcess *process;
private slots:
     //void on_copy();
     //void on_paste();
     //void on_cut();
     //void on_about();
     //void on_exit();
     //void on_selectall();
     //void on_redo();
     //void on_undo();
     //void on_delete();
     //void on_open();
     //void on_compile();
     //void on_save();
     //void on_run();
     //void on_new();
     void on_search();
     void on_replace();
     void searchString();
     void replaceString();
//   void on_character();
//   void on_environment();

private:
    Ui::MainWindow *ui;

};
#endif //MAINWINDOW_H
