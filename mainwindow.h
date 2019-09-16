#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTextEdit>
#include<QMenu>
#include<QMenuBar>
#include<QAction>
#include<QProcess>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMainWindow>
#include<QTextEdit>
#include <QWidget>
#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QGroupBox>
#include <QCheckBox>
#include <QRadioButton>
#include <QEvent>
#include "qinputdialog.h"
class QDialog;
class QLineEdit;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QString filename;
    QString savefilename;
    QProcess *process;
private slots:
     void on_copy();
     void on_paste();
     void on_cut();
     void on_selectall();
     void on_redo();
     void on_undo();
     void on_delete();

     void on_character();

    Ui::MainWindow *ui;
    QLineEdit *find_textLineEdit;
};
#endif //MAINWINDOW_H
