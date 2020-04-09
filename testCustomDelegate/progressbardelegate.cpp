#include "progressbardelegate.h"
ProgressBarDelegate::ProgressBarDelegate()
{

}

void ProgressBarDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
                                const QModelIndex &index) const
{
    if(index.isValid()  && index.column() == 1)
    {

        QStyleOptionProgressBar bar ;

        bar.rect = option.rect;

        bar.progress = index.data().toInt();
        bar.maximum = 100;
        bar.minimum = 0;
        bar.text = QString::number(bar.progress)+"%";
        bar.textVisible = true;

        QApplication::style()->drawControl(QStyle::CE_ProgressBar,&bar,painter);
    }
    else
    {
        QStyledItemDelegate::paint(painter,option,index);
    }

}






