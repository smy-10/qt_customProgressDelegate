#ifndef PROGRESSBARDELEGATE_H
#define PROGRESSBARDELEGATE_H

#include <QObject>
#include <QProgressBar>
#include <QModelIndex>
#include <QPainter>
#include <QStyledItemDelegate>
#include <QApplication>


class ProgressBarDelegate :public QStyledItemDelegate
{
    Q_OBJECT
public:
    ProgressBarDelegate();

protected:

    // painting
    void paint(QPainter *painter,
               const QStyleOptionViewItem &option, const QModelIndex &index) const override;



};

#endif // PROGRESSBARDELEGATE_H
