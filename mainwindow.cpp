#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QFileDialog"
#include "QProcess"
#include <QApplication>
#include <qclipboard.h>
#include <QMessageBox>
#include <QDebug>
#include <QDataStream>
#include <QFile>
#include <QTextEdit>
#include <QFontDialog>

#include <qclipboard.h>
#include <QFile>

#include <QFileDialog>
#include <QDebug>
#include <QDataStream>
#include <QProcess>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Highlighter * h = new Highlighter(ui->plainTextEdit->document());
    searchLineEdit=new QLineEdit();
    replaceLineEdit=new QLineEdit();
    searchInputLineEdit=new QLineEdit();

   connect(ui->actionfuzhi,SIGNAL(triggered()),this,SLOT(on_copy()));
   connect(ui->actionjianqie,SIGNAL(triggered()),this,SLOT(on_cut()));
   connect(ui->actionzhantie,SIGNAL(triggered()),this,SLOT(on_paste()));
   connect(ui->actionquanxuan,SIGNAL(triggered()),this,SLOT(on_selectall()));
   connect(ui->actionchexiao,SIGNAL(triggered()),this,SLOT(on_undo()));
   connect(ui->actionhuifu,SIGNAL(triggered()),this,SLOT(on_redo()));
   connect(ui->actionshanchu,SIGNAL(triggered()),this,SLOT(on_delete()));
   connect(ui->actionziti,SIGNAL(triggered()),this,SLOT(on_character()));
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_copy()
{
    ui->plainTextEdit->copy();
}
void MainWindow::on_paste()
{
    ui->plainTextEdit->paste();
}

void MainWindow::on_cut()
{
   ui->plainTextEdit->cut();
}
void MainWindow::on_selectall()
{
    ui->plainTextEdit->selectAll();
}
void MainWindow::on_redo()
{
    ui->plainTextEdit->redo();
}
void MainWindow::on_undo()
{
    ui->plainTextEdit->undo();
}
void MainWindow::on_delete()
{
   on_selectall();
   on_cut();
}

void MainWindow::on_character()
{
    bool ok;
    //设置默认字体为 Helvetica [Cronyx], 10
    QFont font = QFontDialog::getFont(&ok, QFont("Helvetica [Cronyx]", 10), this);
    if (ok)
    {
        ui->plainTextEdit->setFont(font);
        //用户点击ok完成修改
    }
    else
    {
        //用户点击cancel则恢复为默认字体 Helvetica [Cronyx], 10
    }
}
