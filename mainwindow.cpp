#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QFileDialog"
#include "highlighter.h"
#include "QProcess"
#include <QApplication>
#include <qclipboard.h>
#include <QFile>
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>
#include <QDataStream>
#include <QProcess>
int Flag_isOpen = 0;       //标记：判断是否打开或创建了一个文件
int Flag_IsNew = 0;        //标记：如果新建了文件就为1，初始值为0
QString Last_FileName;     //最后一次保存的文件的名字
QString Last_FileContent;  //最后一次保存文件的内容
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Highlighter * h = new Highlighter(ui->plainTextEdit->document());
    searchLineEdit=new QLineEdit();
    replaceLineEdit=new QLineEdit();
    searchInputLineEdit=new QLineEdit();
    //Qt的消息槽机制
   connect(ui->actiondakai,SIGNAL(triggered()),this,SLOT(on_open()));
   connect(ui->actionYYbangzhu,SIGNAL(triggered()),this,SLOT(on_about()));
   connect(ui->actiontuichu,SIGNAL(triggered()),this,SLOT(on_exit()));
   connect(ui->actionfuzhi,SIGNAL(triggered()),this,SLOT(on_copy()));
   connect(ui->actionjianqie,SIGNAL(triggered()),this,SLOT(on_cut()));
   connect(ui->actionzhantie,SIGNAL(triggered()),this,SLOT(on_paste()));
   connect(ui->actionquanxuan,SIGNAL(triggered()),this,SLOT(on_selectall()));
   connect(ui->actionbaocun,SIGNAL(triggered()),this,SLOT(on_save()));
   connect(ui->actionbianyi,SIGNAL(triggered()),this,SLOT(on_compile()));
   connect(ui->actionyunxing,SIGNAL(triggered()),this,SLOT(on_run()));
   connect(ui->actionchexiao,SIGNAL(triggered()),this,SLOT(on_undo()));
   connect(ui->actionhuifu,SIGNAL(triggered()),this,SLOT(on_redo()));
   connect(ui->actionshanchu,SIGNAL(triggered()),this,SLOT(on_delete()));
   connect(ui->actionsousuo,SIGNAL(triggered()),this,SLOT(on_search()));
   connect(ui->actiontihuan,SIGNAL(triggered()),this,SLOT(on_replace()));
   connect(ui->actionhuanjingxuanxiang,SIGNAL(triggered()),this,SLOT(on_environment()));
   connect(ui->actionziti,SIGNAL(triggered()),this,SLOT(on_character()));
   connect(ui->actionxinjian,SIGNAL(triggered()),this,SLOT(on_new()));

}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_search()
{
    QGridLayout *nanGridLayouts = new QGridLayout() ;
    QHBoxLayout *nanHBoxLayouts = new QHBoxLayout() ;
    searchInputDialog=new QDialog(this);
    searchInputDialog->setModal(true);
    searchInputDialog->setWindowTitle("搜索");
    searchInputLabel=new QLabel();
    searchForwardBtn=new QPushButton();

    searchForwardBtn->setText("搜索下一个");
    searchInputLabel->setText("输入：");
    connect(searchForwardBtn,&QPushButton::clicked,this,&MainWindow::searchString);


    nanGridLayouts->addWidget( searchInputLabel , 1 , 1 ) ;
    nanGridLayouts->addWidget( searchInputLineEdit , 1 , 2 ) ;
    nanGridLayouts->addWidget( searchForwardBtn , 2 , 3 ) ;
    nanGridLayouts->addLayout( nanHBoxLayouts , 2 , 2 ) ;
    searchInputDialog->setLayout(nanGridLayouts);
    searchInputDialog->show();
//    bool ok;
//    QString string = searchInputDialog->getText(this,tr("搜索"),tr("输入要查找的字符"),QLineEdit::Normal,tr("admin"),&ok);//获得对话框的内容
//    if(ok)
//    {
//        if(ui->plainTextEdit->find(string,QTextDocument::FindBackward))//查找后一个
//        {
//            // 查找到后高亮显示
//            QPalette palette = ui->plainTextEdit->palette();
//            palette.setColor(QPalette::Highlight,palette.color(QPalette::Active,QPalette::Highlight));
//            ui->plainTextEdit->setPalette(palette);
//        }
//        else
//        {
//            QMessageBox::information(this,tr("注意"),tr("没有找到内容"),QMessageBox::Ok);
//        }
//    }






}

void MainWindow::on_replace()
{
    QGridLayout *nanGridLayout = new QGridLayout() ;
    QHBoxLayout *nanHBoxLayout = new QHBoxLayout() ;

    replaceDialog=new QDialog(this);
    replaceDialog->setModal(true);
    replaceDialog->setWindowTitle("替换");
    searchLabel=new QLabel();
    replaceLabel=new QLabel();
    sureBtn=new QPushButton();
    connect(sureBtn,&QPushButton::clicked,this,&MainWindow::replaceString);
    searchLabel->setText("输入需替换的");
    replaceLabel->setText("替换为");
    sureBtn->setText("替换");


    nanGridLayout->addWidget( searchLabel , 1 , 1 ) ;
    nanGridLayout->addWidget( searchLineEdit, 1 , 2 ) ;
    nanGridLayout->addWidget( replaceLabel, 2 , 1 ) ;
    nanGridLayout->addWidget( replaceLineEdit , 2 , 2 ) ;
    nanGridLayout->addWidget( sureBtn , 3 , 2 ) ;
    nanGridLayout->addLayout( nanHBoxLayout , 3 , 2 ) ;
    replaceDialog->setLayout(nanGridLayout);
    replaceDialog->show();


}

void MainWindow::searchString()
{
    QString searchIputString = searchInputLineEdit->text();//获得对话框的内容
    if(ui->plainTextEdit->find(searchIputString,QTextDocument::FindBackward))//查找后一个
    {
        // 查找到后高亮显示
        QPalette palette = ui->plainTextEdit->palette();
        palette.setColor(QPalette::Highlight,palette.color(QPalette::Active,QPalette::Highlight));
        ui->plainTextEdit->setPalette(palette);
    }
    else
    {
        QMessageBox::information(this,tr("注意"),tr("没有找到内容"),QMessageBox::Ok);
    }
}

void MainWindow::replaceString()
{
    QString searchString = searchLineEdit->text();//获得对话框的内容
    QString replaceString = replaceLineEdit->text();//获得对话框的内容
    QString plainTextEditString=ui->plainTextEdit->toPlainText();

    plainTextEditString.replace(searchString,replaceString);
     ui->plainTextEdit->clear();
    ui->plainTextEdit->appendPlainText(plainTextEditString);

}
