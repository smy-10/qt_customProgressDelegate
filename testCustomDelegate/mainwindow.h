#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>
#include <QStandardItemModel>
#include <QTimer>

#include "progressbardelegate.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void initUI();

    void initModel();

    void initDelegate();

public slots:
    void download();

private:
    QTableView* tableView;

    QStandardItemModel* model;

    ProgressBarDelegate* delegate;

    QTimer* timer;
};

#endif // MAINWINDOW_H
