#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QFileDialog"
#include "highlighter.h"
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

   connect(ui->actionbianyi,SIGNAL(triggered()),this,SLOT(on_compile()));
   connect(ui->actionyunxing,SIGNAL(triggered()),this,SLOT(on_run()));


}
MainWindow::~MainWindow()
{
    delete ui;
}
bool MainWindow::on_compile(){
    if(ui->plainTextEdit->document()->isModified()){
        if(currentName.isEmpty()){
            QString fileName = QFileDialog::getSaveFileName(this);
            if(fileName.isEmpty())
                return false;
            else
            {
               saveFile(fileName);
               compile(fileName);
               return true;
            }
        }
        else{//先保存后编译
            saveFile(currentName);
            compile(currentName);
        }


    }
    else{//如果没有改动 那么就直接编译
        compile(currentName);
    }
}
bool MainWindow::compile(const QString &fileName){

    QString filePath = fileName;
    QString exePath;
    QString cPath;
    QString file;
    if(filePath.endsWith(".c")){
        cPath = filePath;
        int heihei= filePath.lastIndexOf(".");
        file = filePath.left (heihei);
        exePath = file +".exe";
    }
    else{
        file = filePath;
         cPath = filePath+".c";
        QFile::rename(filePath,cPath);
        exePath = filePath+".exe";
    }

         QProcess p(0);
        p.start("cmd");
        p.waitForStarted();

        filePath = QDir::toNativeSeparators(filePath);
        QString gcccode = "gcc "+cPath+" -o "+file+" 2>"+file+"err";
        QByteArray a = gcccode.toUtf8();
        a=gcccode.toLocal8Bit();
        p.write(a);
        p.write("\n\r");
        p.closeWriteChannel();
        p.waitForFinished();
        QString ferr = (file+"err");
        QFile filein(ferr);
        filein.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream in1(&filein);
        QString errmes = in1.readAll();

        if(errmes.isEmpty()){
            ui->plainTextEdit_2->setPlainText("编译成功！");
        }
        else{
            QString allmes = "编译失败！\n"+errmes;
             ui->plainTextEdit_2->setPlainText(allmes);
        }

        QString finalpath = fileName;
        QByteArray b = finalpath.toUtf8();
        b=fileName.toLocal8Bit();
}
bool MainWindow::compile2(const QString &fileName){

    QString filePath = fileName;
    QString exePath;
    QString cPath;
    QString file;
    if(filePath.endsWith(".c")){
        cPath = filePath;
        int heihei= filePath.lastIndexOf(".");
        file = filePath.left (heihei);
        exePath = file +".exe";
    }
    else{
        file = filePath;
         cPath = filePath+".c";
        QFile::rename(filePath,cPath);
        exePath = filePath+".exe";
    }

         QProcess p(0);
        p.start("cmd");
        p.waitForStarted();

        filePath = QDir::toNativeSeparators(filePath);
        QString gcccode = "gcc "+cPath+" -o "+file+" 2>"+file+"err";
        QByteArray a = gcccode.toUtf8();
        a=gcccode.toLocal8Bit();

        p.write(a);
        p.write("\n\r");
        p.closeWriteChannel();
        p.waitForFinished();
        QString ferr = (file+"err");
        QFile filein(ferr);
        filein.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream in1(&filein);
        QString errmes = in1.readAll();

        qDebug()<<errmes;
        if(errmes.isEmpty()){
            ui->plainTextEdit_2->setPlainText("编译成功！");
        }
        else{
            QString allmes = "编译失败！\n"+errmes;
             ui->plainTextEdit_2->setPlainText(allmes);
        }

        QString finalpath = fileName;
        QByteArray b = finalpath.toUtf8();
        b=fileName.toLocal8Bit();
        char * ch;
        QByteArray ba = exePath.toLatin1();
        ch = ba.data();
        system(ch);
}
bool MainWindow::on_run(){
    if(ui->plainTextEdit->document()->isModified()){
        if(currentName.isEmpty()){
            QString fileName = QFileDialog::getSaveFileName(this);
            if(fileName.isEmpty())
                return false;
            else
            {
               saveFile(fileName);
               compile2(fileName);
               return true;
            }
        }
        else{//先保存后编译
            saveFile(currentName);
            compile2(currentName);
        }


    }
    else{//如果没有改动 那么就直接编译
        compile2(currentName);
    }
}
