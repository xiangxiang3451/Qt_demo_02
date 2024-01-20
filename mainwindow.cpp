#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMenuBar>
#include<QMenu>
#include<QAction>
#include<QToolBar>
#include<QStatusBar>
#include<QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    resize(400,800);
    //创建菜单栏
    QMenuBar *menubar=new QMenuBar(this);
    this->setMenuBar(menubar);
    //创建菜单
    QMenu *menu1=new QMenu("文件");
    QMenu *menu2=new QMenu("编辑");
    QMenu *menu3=new QMenu("构建");

    menubar->addMenu(menu1);
    menubar->addMenu(menu2);
    menubar->addMenu(menu3);
    //创建菜单项
    QAction *act1=new QAction("打开文件");
    QAction *act2=new QAction("另存为");
    QAction *act3=new QAction("关闭文件");

    menu1->addAction(act1);
    menu1->addAction(act2);
    menu1->addAction(act3);

    //点击关闭文件时，可以关闭整个窗口
    connect(act3,&QAction::triggered,this,&QMainWindow::close);
    //创建工具栏
    QToolBar *toolBar=new QToolBar(this);
    this->addToolBar(Qt::LeftToolBarArea,toolBar);
    QAction *act4=new QAction("工具");
    toolBar->addAction(act1);
    toolBar->addAction(act2);
    toolBar->addAction(act3);
    toolBar->addAction(act4);
    //设置工具栏的属性
    toolBar->setMovable(false);
    //创建状态栏
    QStatusBar *status=statusBar();
    this->setStatusBar(status);
//    //临时信息
//    status->showMessage("显示成功",3000);
    //正式信息
    QLabel *lab1=new QLabel("打开文件",this);
    status->addWidget(lab1);
    //永久信息
    QLabel *lab2=new QLabel("cpx7777.top",this);
    status->addPermanentWidget(lab2);



}

MainWindow::~MainWindow()
{
    delete ui;
}

