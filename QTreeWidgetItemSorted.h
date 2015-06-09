#ifndef QTREEWIDGETITEMSORTED_H
#define QTREEWIDGETITEMSORTED_H

#include <QTreeWidgetItem>

class QTreeWidgetItemSorted : public QTreeWidgetItem
{
public:
    QTreeWidgetItemSorted(QTreeWidget *parent = nullptr) :
        QTreeWidgetItem(parent) { }

private:
    bool operator<(const QTreeWidgetItem &other) const
    {
        int column = treeWidget()->sortColumn();

        // check if the columns are integers
        bool isColumn1Int, isColumn2Int;
        int column1Int = text(column).toInt(&isColumn1Int);
        int column2Int = other.text(column).toInt(&isColumn2Int);

        if (isColumn1Int && isColumn2Int)
            return column1Int < column2Int;
        else
            return text(column) < other.text(column);
    }
};

#endif // QTREEWIDGETITEMSORTED_H
