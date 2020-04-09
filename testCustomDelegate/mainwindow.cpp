#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)

{
    initUI();

    initModel();

    initDelegate();

    timer = new QTimer();

    connect(timer,&QTimer::timeout,this,&MainWindow::download);

    timer->setInterval(1000);
    timer->start();
}

MainWindow::~MainWindow()
{

}

void MainWindow::initUI()
{
    this->setMinimumSize(QSize(400,200));

    tableView = new QTableView();

    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    this->setCentralWidget(tableView);
}

void MainWindow::initModel()
{
    model = new QStandardItemModel();

    model->setColumnCount(2);

    model->setHeaderData(0,Qt::Horizontal,"影片名字");
    model->setHeaderData(1,Qt::Horizontal,"下载进度");

    model->setItem(0,0,new QStandardItem("英雄本色.mp4"));
    model->setItem(0,1,new QStandardItem("18"));

    model->setItem(1,0,new QStandardItem("霸王别姬.mp4"));
    model->setItem(1,1,new QStandardItem("3"));

    model->setItem(2,0,new QStandardItem("肖申克的救赎.mp4"));
    model->setItem(2,1,new QStandardItem("69"));

    tableView->setModel(model);

}

void MainWindow::initDelegate()
{
    delegate = new ProgressBarDelegate();

    tableView->setItemDelegate(delegate);
}

void MainWindow::download()
{
    for(auto i = 0; i < model->rowCount();i++)
    {
        int value = model->index(i,1).data().toInt();
        value++;

        model->setData(model->index(i,1),value);
    }

}
